/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _PLAYEROBJECT_
#define _PLAYEROBJECT_

#include "../Types/SoccerTypes.h"

class _PlayerObject
{
	private :
		SideT          TeamSide;
		int            UniNum;
		bool           Goali;
		PlayerT        PlayerID;
		int            HPlayeType;
		Vector2D       GlobalPosition;
		int 	       PosArray;
		Vector2D       HearPosition;
		Cycle          HearCycle;
		Vector2D       LastSeePosition;
		Cycle          LastSeePosTime;
		Vector2D       SeePosition;
		Cycle          SeePosTime;
		Vector2D       Vel;
		double         VelDis;
		double	       Quality;
		bool           Visible;
		AngDeg         Body;
		AngDeg         Neck;
		
		double         BallDistance;
		
		
	public :
		_PlayerObject ( );
		bool setObjectSide           ( SideT   );
		bool setObjectNumber         ( int     );
		bool setObjectIsGoali        ( bool    );
		bool setObjectPlayerID       ( PlayerT );
		bool setObjectType           ( int     );
		bool setObjectGlobalPosition ( Vector2D);
		bool setObjectPositionArray  ( int     );
		bool setObjectSeePosition    ( Vector2D);
		bool setObjectSeeTime        ( Cycle   );
		bool setObjectLastSeePosition    ( Vector2D);
		bool setObjectLastSeeTime        ( Cycle   );
		bool setObjectHearPosition    ( Vector2D);
		bool setObjectHearTime        ( Cycle   );
		bool setObjectVel	     ( Vector2D);
		bool setObjectVelDistance    ( double  );
		bool setObjectBodyAngle      ( AngDeg  );
		bool setObjectNeckAngle	     ( AngDeg  );
		bool setObjectBallDistance   ( double  );
		bool setObjectQuality    ( double  );
		bool setObjectVisible    ( bool  );

		SideT    getObjectSide           (   );
		int      getObjectNumber         (   );
		bool     getObjectIsGoali        (   );
		PlayerT  getObjectPlayerID       (   );
		int      getObjectType               (   );
		Vector2D getObjectGlobalPosition     (   );
		int      getObjectPositionArray      (   );
		Vector2D getObjectSeePosition        (   );
		Cycle    getObjectSeeTime            (   );
		Vector2D getObjectLastSeePosition    (   );
		Cycle    getObjectLastSeeTime        (   );
		Vector2D getObjectHearPosition   (   );
		Cycle    getObjectHearTime       (   );
		Vector2D getObjectVel	         (   );
		double   getObjectVelDistance    (   );
		AngDeg   getObjectBodyAngle      (   );
		AngDeg   getObjectNeckAngle	 (   );
		double   getObjectBallDistance   (   );
		double   getObjectQuality        (   );
		bool     getObjectVisible    (   );

		virtual bool isSelf ( )
			{return false;}
		virtual  bool isGoali( )
			{return Goali;}
		virtual  bool isGhost( )
			{return false;}
		
		

};
#endif
