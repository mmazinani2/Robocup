/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _VISUAL_SENSOR
#define _VISUAL_SENSOR

#include "../Util/MapLib.h"
#include "../Types/SoccerTypes.h"
#include "../Parser/ParseServer.h"
#include "../Util/IteratorLib.h"
#include "../Util/Timer.h"

#define QUALITY_MIN  5
#define QUALITY_STEP 1.2

struct PolarValue
{
	double Distance;
	AngDeg Angle;
	
	PolarValue ( ):Distance ( -0.0001 )
		      ,Angle    ( -0.0001 )
	{ }
	bool reset ( )
	{
		Distance = -0.0001;
		Angle    = -0.0001;
	}
};
struct dynamicValue:public PolarValue
{
	bool IsDynamic;
        double dist_chng;
        double dir_chng;
	dynamicValue ( ):PolarValue (         )
			,IsDynamic  (  false  )
			,dist_chng  ( -0.0001 )
			,dir_chng   ( -0.0001 )
	{}
	bool reset ()
	{
		PolarValue::reset();
		IsDynamic =  false;
		dist_chng = -0.0001;
		dir_chng  = -0.0001;
	}	
	Vector2D getVelocity ( )
	{
		return Vector2D::getVector2DFromPolar ( this->dist_chng, this->dir_chng );
	}
};

struct BallInfo : public dynamicValue
{
	double    Quality;
	Cycle     SeeTime;
	bool      Visible;
	BallInfo ( ):dynamicValue ( )
		    ,Quality ( 10 )
		    ,SeeTime (  0 )
		    ,Visible ( false )
	{ }
	bool reset ( )
        {dynamicValue::reset();}
	bool isVisible ( )
	{return Visible;}
	Cycle getVisibleTime ( )
	{return SeeTime;}
	bool operator==( BallInfo Q)  const
	{return ( Quality < Q.Quality );}

};

struct PlayerInfo : public dynamicValue
{
	double     Quality;
	AngDeg     BodyAngle;
	AngDeg     NeckAngle;
        AngDeg     ArmAngle;
	bool       goalie;
        bool       isTackling;
	bool       isKicking;
	Cycle      SeeTime;
	bool       Visible;
	PlayerT    IDPlayer;
	PlayerType TypePlayer;

	PlayerInfo ( ):dynamicValue ( )
		      ,Quality(10)
		      ,BodyAngle(0)
	              ,NeckAngle(0)
                      ,ArmAngle(0)
	              ,goalie(false)
                      ,isTackling(false)
	              ,SeeTime(0)
	              ,Visible(false)
	              ,IDPlayer(PT_UNKNOWN)
		      ,TypePlayer(PLAYER_ILLEGAL)
	{ }
	bool reset  ( )
        {
		isTackling = false;
		isKicking  = false;
		SeeTime    = 0;
		Visible    = false;
		Quality    = 10;
		IDPlayer   = PT_UNKNOWN;
		TypePlayer = PLAYER_ILLEGAL;
		goalie     = false;
		BodyAngle  = 0;
		NeckAngle  = 0;
		ArmAngle   = 0;
		dynamicValue::reset();
	}
	bool isVisible ( )
	{return Visible;}
	Cycle getVisibleTime ( )
	{return SeeTime;}
	
	bool operator ==( const PlayerInfo &Q)  const
	{return ( IDPlayer == Q.IDPlayer );}
	void operator =(const PlayerInfo &Pl )
	{
		isTackling = Pl.isTackling;
		isKicking  = Pl.isKicking;
		SeeTime    = Pl.SeeTime;
		Visible    = Pl.Visible;
		Quality    = Pl.Quality;
		IDPlayer   = Pl.IDPlayer;
		TypePlayer = Pl.TypePlayer;
		goalie     = Pl.goalie;
		Distance   = Pl.Distance;
		Angle      = Pl.Angle;
		IsDynamic  = Pl.IsDynamic;
		dist_chng  = Pl.dist_chng;
		dir_chng   = Pl.dir_chng;
		BodyAngle  = Pl.BodyAngle;
		NeckAngle  = Pl.NeckAngle;
		ArmAngle   = Pl.ArmAngle;
	}
};
struct FlagInfo : public PolarValue
{
	double    Quality;
	Cycle     SeeTime;
	bool      Visible;
	Flag      TypeFlag;
	
	FlagInfo ( ):PolarValue ( )
		    ,Quality(10)
	            ,SeeTime(0)
	            ,Visible(false)
	            ,TypeFlag(FT_UNKNOWN)
	{ }
	bool reset  ( )
        {PolarValue::reset();}
	bool isVisible ( )
	{return Visible;}
	Cycle getVisibleTime ( )
	{return SeeTime;}
	bool operator<( FlagInfo Q)  const
	{return (Q.Quality < QUALITY_MIN );}
	bool operator>(const FlagInfo &ObjFlag)  const
			{return (TypeFlag > ObjFlag.TypeFlag);}
	bool operator==(const FlagInfo &ObjFlag)  const
			{return (TypeFlag == ObjFlag.TypeFlag);}
};
struct LineInfo : public PolarValue
{
	double    Quality;
	Cycle     SeeTime;
	bool      Visible;
	Flag      TypeFlag;
	
	LineInfo ( ):PolarValue ( )
		    ,Quality(10)
	            ,SeeTime(0)
	            ,Visible(false)
	            ,TypeFlag(FT_UNKNOWN)
	{ }
	bool reset  ( )
        {PolarValue::reset();}
	bool isVisible ( )
	{return Visible;}
	Cycle getVisibleTime ( )
	{return SeeTime;}
	bool operator<( LineInfo Q)  const
	{return (Q.Quality < QUALITY_MIN );}
};
class SortCmpPlayer
	: public std::binary_function< PlayerInfo, PlayerInfo, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
                                const second_argument_type & rhs ) const
	{
		return lhs.Quality < rhs.Quality;
	}
};
class SortCmpBall
	: public std::binary_function< BallInfo, BallInfo, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
                                const second_argument_type & rhs ) const
	{
		return lhs.Quality < rhs.Quality;
	}
};
class Visual_Sensor
{
	private :
		MapLib<Flag> 		 _Flag_Map;
		Iterator_Lib<PlayerInfo> _TeammateInfo;
		Iterator_Lib<PlayerInfo> _OpponentInfo;
		Iterator_Lib<PlayerInfo> _UnknownInfo;
		Iterator_Lib<BallInfo>   _BallInfo;
		Iterator_Lib<FlagInfo>   _FlagInfo;
		Iterator_Lib<LineInfo>   _LineInfo;
		
		string Teamname;
		bool   isGoalie;
		double Quality;
		Cycle  UpdateTime;
		Cycle  LastUpdateTime;
		bool   UpdateVisual;
		AngDeg ViewAngle;
		int    SeeCount;
	public :
		Visual_Sensor         ( );
		bool Set_Flag_Map     ( );
		
/*		bool TrashPlayerComp  (PlayerInfo);*/
// 		bool TrashBallComp    ( BallInfo );
		bool Trash            (          );
		bool    LineTrash ();
		bool	FlagTrash ();
		bool UpdatePlayer     ( string , string , Cycle );
		bool UpdateBall       ( string , Cycle );
		bool UpdateLine       ( string , string , Cycle );
		bool UpdateFlag       ( string , string , Cycle );
		PlayerT ConvertSToPT  ( string );
		bool setTeamName ( string  strName )
		{
			Teamname = strName;
		}
		virtual bool Update   ( string , Cycle );
		virtual bool isUpdate (        )
		{
			return UpdateVisual;
		}
		virtual int TimeUpdate (       )
		{
			return UpdateTime;
		}
		virtual bool reset    (        )
		{
			UpdateVisual = false;
			return true;
		}
		virtual bool setQuality ( double Q)
		{
			Quality = Q;
			return true;
		}
		virtual double getQuality (    )
		{
			return Quality;
		}
		Iterator_Lib<PlayerInfo> getIteratorTeammateInfo ( )
		{
			return _TeammateInfo;
		}
		Iterator_Lib<PlayerInfo> getIteratorOpponentInfo ( )
		{
			return _OpponentInfo;
		}
		Iterator_Lib<PlayerInfo> getIteratorUnknownInfo ( )
		{
			return _UnknownInfo;
		}
		Iterator_Lib<BallInfo>   getIteratorBallInfo ( )
		{
			return _BallInfo;
		}
		Iterator_Lib<FlagInfo>   getIteratorFlagInfo ( )
		{
			return _FlagInfo;
		}
		Iterator_Lib<LineInfo>   getIteratorLineInfo ( )
		{
			return _LineInfo;
		}
		PlayerInfo getPlayerTeammateById ( PlayerT );
		PlayerInfo getPlayerOpponentById ( PlayerT );
		Iterator_Lib<PlayerInfo> getItrPlayerTeammateById ( PlayerT );
		Iterator_Lib<PlayerInfo> getItrPlayerOpponentById ( PlayerT );
};
#endif
