/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Self.h"
extern int LOG;
_Self::_Self ( ):_PlayerObject ()
		,selfGlobal_Pos (1000.00,1000.00)
		,selfRelativ_Pos (1000.00,1000.00)
		,selfPos_Array (-1)
		,selfClear_Last_Time (30)
		,selfBody_Updat (0)
		,selfSee_Updat (0)
		,selfCatch_Time (0)
		,selfVangle  (VA_ILLEGAL)
		,selfVQual   (VQ_ILLEGAL)
		,selfSeeCount (0)
		,selfStamina (8000)
		,selfSpeed   (0)
		,selfBody    (0)
		,selfNeck    (0)
		,selfCount_kick (0)
		,selfCount_Dash (0)
		,selfCount_Turn (0)
		,selfCount_Say  (0)
		,selfCount_Turn_Neck (0)
		,selfCount_Catch (0)
		,selfCount_Move (0)
		,selfCount_Change_View (0)
		,selfArm_Count_Movable (0)
		,selfArm_Count_Expires (0)
		,selfArm_Count_Target (1000.00,1000.00)
		,selfArm_Count_Count (0)
		,selfFocus_Count (0)
		,selfTackle_Count_Expires (0)
		,selfTackle_Count_Count (0)
		,selfNone_Collided (false)
    		,selfBall_Collided (false)
    		,selfPlayer_Collided (false)
    		,selfPost_Collided (false)
		,selfSynch(false)
{
	selfTimer.startTime ( );
	selfLast_Move_pos.It_clear ();
	selfLast_Send_Command.It_clear ();
}
_Self::_Self ( Server_param &sp, Player_param &pp, Hetero_Player &hp)
{
	selfServerData = sp;
	selfPlayerData = pp;
	selfHeteroData = hp;
}
bool _Self::setSelfGlobalPosition (Vector2D gpos)
{
	selfGlobal_Pos  =  gpos;
}
bool _Self::setSelfRelativPosition (Vector2D rpos)
{
	selfRelativ_Pos = rpos;
}
bool _Self::setSelfLastMovePosition(Vector2D mpos)
{
	selfLast_Move_pos.It_push ( mpos );
}
bool _Self::setSelfLastSendCommand (CommandT ct)
{
	selfLast_Send_Command.It_push ( ct );
}
bool _Self::setSelfPositionArray  (int  arr )
{
	selfPos_Array = arr;
}
bool _Self::setSelfClearLastTime  (long tm )
{
	selfClear_Last_Time = tm;
}
bool _Self::setSelfBodyUpdat    (Cycle cl )
{
	selfBody_Updat = cl;
}
bool _Self::setSelfSeeUpdat    (Cycle  cl )
{
	selfSee_Updat = cl;
}
bool _Self::setSelfCatchTime    (Cycle  cl )
{
	selfCatch_Time = cl;
}
bool _Self::setSelfViewAngle	    ( ViewAngleT vat)
{
	selfVangle = vat;
}
bool _Self::setSelffViewQuality    ( ViewQualityT vqt)
{
	selfVQual = vqt;
}
bool _Self::setSelfStamina	    ( int    st )
{
	selfStamina = st;
}
bool _Self::setSelfSpeed	    ( double   sp  )
{
	selfSpeed = sp;
}
bool _Self::setSelfBody        (AngDeg   sbody )
{
	selfBody = sbody;
}
bool _Self::setSelfNeck        (AngDeg   sneck )
{
	selfNeck = sneck;
}
bool _Self::setSelfCountkick     (int     ck )
{
	selfCount_kick = ck;
}
bool _Self::setSelfCountDash     (int     cd )
{
	selfCount_Dash = cd;
}
bool _Self::setSelfCountTurn     (int    ct  )
{
	selfCount_Turn = ct;
}
bool _Self::setSelfCountSay      (int     cs )
{
	selfCount_Say = cs;
}
bool _Self::setSelfCountTurnNeck   (int     ctn )
{
	selfCount_Turn_Neck = ctn;
}
bool _Self::setSelfCountCatch     (int     cc )
{
	selfCount_Catch = cc;
}
bool _Self::setSelfCountMove     (int      cm)
{
	selfCount_Move = cm;
}
bool _Self::setSelfCountChangeView  (int    ccv  )
{
	selfCount_Change_View = ccv;
}
bool _Self::setSelfArmCountMovable  (int      cm)
{
	selfArm_Count_Movable = cm;
}
bool _Self::setSelfArmCountExpires  (int    ce  )
{
	selfArm_Count_Expires = ce;
}
bool _Self::setSelfArmCountTarget   (Vector2D arpos  )
{
	selfArm_Count_Target = arpos;
}
bool _Self::setSelfArmCountCount   (int    arc  )
{
	selfArm_Count_Count  = arc;
}
bool _Self::setSelfFocusCount     (int  fc   )
{
	selfFocus_Count = fc;
}
bool _Self::setSelfTackleCountExpires (int tce     )
{
	selfTackle_Count_Expires = tce;
}
bool _Self::setSelfTackleCountCount  (int     tcc )
{
	selfTackle_Count_Count = tcc;
}
bool _Self::setSelfNone_Collided    (bool   nc   )
{
	selfNone_Collided = nc;
}
bool _Self::setSelfBall_Collided    (bool    bc  )
{
	selfBall_Collided = bc;
}
bool _Self::setSelfPlayer_Collided   (bool    pc  )
{
	selfPlayer_Collided = pc;
}
bool _Self::setSelfPost_Collided    (bool    poc  )
{
	selfPost_Collided = poc;
}
Vector2D _Self::getSelfGlobalPosition (    )
{
	return selfGlobal_Pos;
}
Vector2D _Self::getSelfRelativPosition (    )
{
	return selfRelativ_Pos;
}
Iterator_Lib<Vector2D> _Self::getSelfLastMovePosition (    )
{
	return selfLast_Move_pos;
}
Iterator_Lib<CommandT> _Self::getSelfLastSendCommand  (    )
{
	return selfLast_Send_Command;
}
int _Self::getSelfPositionArray  (    )
{
	return selfPos_Array;
}
Cycle _Self::getSelfClearLastTime  (    )
{
	return selfClear_Last_Time;
}
Cycle _Self::getSelfBodyUpdat    (    )
{
	return selfBody_Updat;
}
Cycle _Self::getSelfSeeUpdat     (    )
{
	return selfSee_Updat;
}
Cycle _Self::getSelfCatchTime    (    )
{
	return selfCatch_Time;
}
ViewAngleT _Self::getSelfVangle   (    )
{
	return selfVangle;
}
ViewQualityT _Self::getSelfVQual    (    )
{
	return selfVQual;
}
int _Self::getSelfStamina       (    )
{
	return selfStamina;
}
double _Self::getSelfSpeed        (    )
{
	return selfSpeed;
}
AngDeg _Self::getSelfBody       (    )
{
	return selfBody;
}
AngDeg _Self::getSelfNeck       (    )
{
	return selfNeck;
}
int _Self::getSelfCountkick   (    )
{
	return selfCount_kick;
}
int _Self::getSelfCountDash   (    )
{
	return selfCount_Dash;
}
int _Self::getSelfCountTurn   (    )
{
	return selfCount_Turn;
}
int _Self::getSelfCountSay    (    )
{
	return selfCount_Say;
}
int _Self::getSelfCountTurnNeck (    )
{
	return selfCount_Turn_Neck;
}
int _Self::getSelfCountCatch   (    )
{
	return selfCount_Catch;
}
int _Self::getSelfCountMove   (    )
{
	return selfCount_Move;
}
int _Self::getSelfCountChangeView (    )
{
	return selfCount_Change_View;
}
int _Self::getSelfArmCountMovable (    )
{
	return selfArm_Count_Movable;
}
int _Self::getSelfArmCountExpires (    )
{
	return selfArm_Count_Expires;
}
Vector2D _Self::getSelfArmCountTarget  (    )
{
	return selfArm_Count_Target;
}
int _Self::getSelfArmCountCount  (    )
{
	return selfArm_Count_Count;
}
int _Self::getSelfFocusCount      (    )
{
	return selfFocus_Count;
}
int _Self::getSelfTackleCountExpires  (    )
{
	return selfTackle_Count_Expires;
}
int _Self::getSelfTackleCountCount   (    )
{
	return selfTackle_Count_Count;
}
bool _Self::getSelfNone_Collided  (    )
{
	return selfNone_Collided;
}
bool _Self::getSelfBall_Collided  (    )
{
	return selfBall_Collided;
}
bool _Self::getSelfPlayer_Collided (    )
{
	return selfPlayer_Collided;
}
bool _Self::getSelfPost_Collided  (    )
{
	return selfPost_Collided;
}
int  _Self::getSelfSeeCount       (           )
{
	return selfSeeCount;
}
bool _Self::setSelfSeeCount       ( int   see )
{
	selfSeeCount = see;
}
bool _Self::selfUpdateBySee     ( Visual_Sensor &visualsensor )
{

	this->setSelfNeck   (  this->selfFaceAngelByLine (visualsensor));
	this->setSelfBody   (this->selfGetBodyByNeck ( ));
	this->selfLocalization  (       visualsensor          );
	this->setSelfSeeUpdat   ( visualsensor.TimeUpdate ( ) );
	this->setSelfCycle      ( visualsensor.TimeUpdate ( ) );
	selfVisualSensor = visualsensor;
// 	Iterator_Lib<BallInfo> biof = visualsensor.getIteratorBallInfo ();
// 	BallInfo b = biof.returnVector ().back ();
// 	if (b.Visible){
// 		Vector2D vec = vec.getVector2DFromPolar ( b.Distance , b.Angle + this->getSelfNeck() );
// 		vec += this->getSelfGlobalPosition();
// 		cerr << "Ball X : " << vec.getX() << "\tBall Y : " << vec.getY() << "\t" << b.Distance << endl;
// 	}
}
bool _Self::selfUpdateBySense   ( Body_Sensor &bodysenor      )
{
	this->setSelfEffort		 (bodysenor.getEffort());
	this->setSelfCapacity		 (bodysenor.getCapacity());
	this->setSelfCycle      	 (bodysenor.TimeUpdate ());
	this->setSelfBodyUpdat           (bodysenor.TimeUpdate ());
	this->setSelfViewAngle	         (bodysenor.getViewAngle());
	this->setSelffViewQuality        (bodysenor.getViewQuality( ));
	this->setSelfStamina	         (bodysenor.getStamina());
	this->setSelfSpeed	         (bodysenor.getSpeedMagnitude());
	this->setSelfCountkick           (bodysenor.getCountKick());
	this->setSelfCountDash           (bodysenor.getCountDash());
	this->setSelfCountTurn           (bodysenor.getCountTurn());
	this->setSelfCountSay            (bodysenor.getCountSay());
	this->setSelfCountTurnNeck       (bodysenor.getCountTurnNeck());
	this->setSelfCountCatch          (bodysenor.getCountCatch());
	this->setSelfCountMove           (bodysenor.getCountMove());
	this->setSelfCountChangeView     (bodysenor.getCountChangeView());
	this->setSelfArmCountMovable     (bodysenor.getArmCountMovable());
	this->setSelfArmCountExpires     (bodysenor.getArmCountExpires());
	this->setSelfArmCountTarget      (Vector2D (bodysenor.getArmDis(),bodysenor.getArmDir()));
	this->setSelfArmCountCount       (bodysenor.getCountPointto());
	this->setSelfFocusCount          (bodysenor.getCountAttentionto());
	this->setSelfTackleCountExpires  (bodysenor.getTackleExpires());
	this->setSelfRelativeNeck        (bodysenor.getRelativeNeck ());
	this->setSelfTackleCountCount    (bodysenor.getCountTackle());
	switch (bodysenor.getCollisionType( ))
	{
		case CLL_BALL :
			this->setSelfPost_Collided (false);
			this->setSelfPlayer_Collided (false);
			this->setSelfNone_Collided (false);
			this->setSelfBall_Collided (true);
			break;
		case CLL_PLAYER :
			this->setSelfPost_Collided (false);
			this->setSelfPlayer_Collided (true);
			this->setSelfNone_Collided (false);
			this->setSelfBall_Collided (false);
			break;
		case CLL_NONE :
			this->setSelfPost_Collided (false);
			this->setSelfPlayer_Collided (false);
			this->setSelfNone_Collided (true);
			this->setSelfBall_Collided (false);
			break;
		case CLL_POST :
			this->setSelfPost_Collided (true);
			this->setSelfPlayer_Collided (false);
			this->setSelfNone_Collided (false);
			this->setSelfBall_Collided (false);
			break;
	}

	//cerr << "---------------------------------- >> " <<
}
bool _Self::setSelfRelativeNeck ( double rneck)
{
    selfRelativeNeck = rneck;
}
double _Self::getSelfRelativeNeck ( )
{
    return selfRelativeNeck;
}
bool _Self::selfUpdateByHear    (  Audio_sensor &audiosensor  )
{

}
bool _Self::selfUpdateByTime      (    )
{
	selfTimer.Update( );
}
bool _Self::selfClearCommand ( )
{
	selfLast_Send_Command.It_clear ( );
}
bool _Self::selfClearMovePosition ( )
{
	selfLast_Move_pos.It_clear ();
}
bool _Self::setSelfSynch ( bool synch )
{
	selfSynch = synch;
}
bool _Self::getSelfSynch ( )
{
	return selfSynch;
}
AngDeg _Self::selfSeeAngel ( )
{
	if (selfSynch)
	{
		switch ( selfVangle )
		{
			case VA_NARROW :
				return 60.0;
			case VA_NORMAL :
				return 120.0;
			case VA_WIDE   :
				return 180.0;
			default :
				return 0.0;
		}
	}
	else
	{
		switch ( selfVangle )
		{
			case VA_NARROW :
				return 60.0;
			case VA_NORMAL :
				return 90.0;
			case VA_WIDE   :
				return 180.0;
			default :
				return 1.0;
		}
	}
}
Cycle _Self::selfSeeUpdate ( )
{
	switch ( selfVangle )
	{
		case VA_NARROW :
			return 1;
		case VA_NORMAL :
			return 2;
		case VA_WIDE   :
			return 3;
		default :
			return 1;
	}
}
bool _Self::setSelfCycle ( Cycle cycle)
{
	selfCycle = cycle;
}
Cycle _Self::getSelfCycle ( )
{
	return selfCycle;
}
bool _Self::selfLocalization  (  Visual_Sensor &visualsensor  )
{

	/// Start localize Self
	/// ///////////////////////////////////////////////////

	int Count = 0;
	Iterator_Lib<FlagInfo>  _seeFlag =  visualsensor.getIteratorFlagInfo ( );
	Iterator_Lib<double> minx, maxx , miny ,maxy ;
	Vector2D tmp = Vector2D (0.0,0.0);
 	vector <FlagInfo> :: iterator last;
	last = unique (  _seeFlag.returnVector().begin(),_seeFlag.returnVector().end(),FlagUnique());
	_seeFlag.returnVector().erase (last,_seeFlag.returnVector().end());
	float MinDis, MaxDis;
	float MinAng, MaxAng;
		
	Vector2D Pos1,Pos2;
	double Distance = _seeFlag.It_Item( ).Distance;
	double Angle;

	for ( _seeFlag.It_moveFirst() ; !_seeFlag.It_eof( ); _seeFlag.It_moveNext())
	{
		Flag Flag_Name = _seeFlag.It_Item( ).TypeFlag;
		if (Flag_Name < 0 || Flag_Name > 58) continue;
		Distance = _seeFlag.It_Item( ).Distance;
		
        Angle  =  _seeFlag.It_Item( ).Angle + this->getSelfNeck ( );

		
		Vector2D GlobalFlagPos = Localization().getGlobalPositionFlag (Flag_Name,getObjectSide(),
							selfServerData.get_goal_width ());

		Localization().quantizeRange(Distance, MinDis, MaxDis);

		MinAng = Angle-0.5;
		MaxAng = Angle+0.5;



		Pos1.setX(MinDis);
		Pos1.setY(MinAng);

		Pos2.setX(MaxDis);
		Pos2.setY(MaxAng);

		Pos1 = Pos1.getVector2DFromPolar (Pos1.getX(),Pos1.getY());
		Pos2 = Pos2.getVector2DFromPolar (Pos2.getX(),Pos2.getY());
		Pos1 -= GlobalFlagPos;
		Pos2 -= GlobalFlagPos;
		minx.It_push(Pos1.getX());
		maxx.It_push(Pos2.getX());
		miny.It_push(Pos1.getY());
		maxy.It_push(Pos2.getY());
	}
	//minx.It_sort();
	//maxx.It_sort();
	//miny.It_sort();
	//maxy.It_sort();
	//miny.It_moveNext();
	double tmpY = 0.00;
	double tmpX = 0.00;
	double tmpAvgX = 0.00;
	double tmpAvgY = 0.00;
	for (int j = 0; j < (maxy.It_countItem());j++)
	{

		tmpAvgY = (maxy.It_Item ()+miny.It_Item ())/2;
		tmpY += tmpAvgY;
		maxy.It_moveNext();
		miny.It_moveNext();
	}
	tmpY /= maxy.It_countItem();
	for(int i = 1 ; i < (minx.It_countItem());i++)
	{
		tmpAvgX = (minx.It_Item ()+maxx.It_Item ())/2 ;
		tmpX += tmpAvgX;
		maxx.It_moveNext();
		minx.It_moveNext();
		//maxx.It_moveNext();
	}
	tmpX /= maxx.It_countItem();
	double Posy;
	double Posx = tmpX * (-1);//((minx.It_Item() + maxx.It_Item()) /2) * -1;
	//if (miny.It_Item() < tmpY)
	//	Posy = ((miny.It_Item() + tmpY) /2) * -1;
	//else
		Posy = tmpY * (-1);//(miny.It_Item()) * -1;
	this->setSelfGlobalPosition ( Vector2D (Posx , Posy) );
	#if 1
		if (this->getObjectNumber() == 2)
 		cerr << "Self Cycle : " << getSelfCycle ( ) << "\t\tSelf X : " << Posx << "\t\tSelf Y : " << Posy << endl;
	#endif

}
AngDeg _Self::selfFaceAngelByLine ( Visual_Sensor &visualsensor )
{

    Iterator_Lib<LineInfo>  _seeLine = visualsensor.getIteratorLineInfo ( );
    if ( _seeLine.isEmpty () )
    {
        return -360.000;
    }
    Flag ID = _seeLine.returnVector ().back().TypeFlag;
    double angle = _seeLine.returnVector ().back().Angle;
   // cerr << "size : " << _seeLine.It_countItem ( ) << endl;
#ifdef OLD_DIR_ROUND
    if ( angle > 0.000 ) angle += 0.5;
    if ( angle < 0.0 ) angle -= 0.5;
#endif

    if ( angle < 0.0 )
    {
        angle += 90.0;
    }
    else
    {
        angle -= 90.0;
    }
    switch ( ID ) {
	case FT_LINE_L:
		angle = 180.0 - angle;
		break;
	case FT_LINE_R:
		angle = 0.0 - angle;
		break;
	case FT_LINE_T:
		angle = -90.0 - angle;
		break;
	case FT_LINE_B:
		angle = 90.0 - angle;
		break;
	default:
		return angle;
    }
    if ( _seeLine.It_countItem () >= 2 )
    {
     	angle += 180.0;
    }
    if ( getObjectSide () == SIDE_RIGHT )
    {
        angle += 180.0;
    }

    if ( angle < -360.0 || 360.0 < angle )
    {
	angle = (double)fmod( angle, 360.0 );
    }
    if ( angle < -180.0 )
    {
	angle += 360.0;
    }
    if ( angle > 180.0 )
    {
	angle -= 360.0;
    }
    #if 1
	if (this->getObjectNumber() == 2)
    		cerr << "Slef Neck Angle : " << angle << endl;
    #endif
    return angle;
}
AngDeg _Self::selfFaceDirByFlag( Visual_Sensor &visualsensor )
{
	Iterator_Lib<FlagInfo>  _seeFlag = visualsensor.getIteratorFlagInfo ( );
	AngDeg angle = -360;
	if ( _seeFlag.It_countItem() < 2 )
	{
		return angle;
	}
	int Count = 0;
	FlagInfo tmp1 = _seeFlag.returnVector().back();
	_seeFlag.returnVector().pop_back();
	FlagInfo tmp2 = _seeFlag.returnVector().back();

	Vector2D Flag2 =
Vector2D::getVector2DFromPolar(tmp1.Distance,tmp1.Angle);
	Vector2D Flag1 = Localization().getGlobalPositionFlag
(tmp1.TypeFlag,getObjectSide(),

selfServerData.get_goal_width ());
	Flag2 -= getSelfGlobalPosition ();

	double Angle1 = (Flag1 - getSelfGlobalPosition ()).getDirection();
	double Angle2 = (Flag2 - getSelfGlobalPosition ()).getDirection();
	//cerr << "Angle 2 : " << Angle2 << endl;
	return (Angle1);
}
double _Self::calculateAngleAgentWithPos(Visual_Sensor &visualsensor )
{

	Vector2D selfPos = this->getSelfGlobalPosition ();
        Iterator_Lib<FlagInfo>  _seeFlag = visualsensor.getIteratorFlagInfo ( );
        if ( _seeFlag.isEmpty () )
        {
            return -1000.0;
        }
        int    iNrFlags = 0, iIndex;
	double dCosX=0, dSinX=0 ,dAngleNow, xA, yA, aA;
	for(iNrFlags = 0; _seeFlag.returnVector().size ();iNrFlags++)
	{
	  FlagInfo tmp1 = _seeFlag.returnVector().back();
	  _seeFlag.returnVector().pop_back();
	  xA = Localization().getGlobalPositionFlag
			      (tmp1.TypeFlag,getObjectSide(),
			       selfServerData.get_goal_width()).getX();
	  yA = Localization().getGlobalPositionFlag
			      (tmp1.TypeFlag,getObjectSide(),
			       selfServerData.get_goal_width()).getY();
	  tmp1 = _seeFlag.returnVector().back();
	  aA = tmp1.Distance;

	  dAngleNow = atan2Deg( yA - selfPos.getY(), xA - selfPos.getX() );
	  dAngleNow = Vector2D::normalizeAngle( dAngleNow - aA );

	  dCosX += cosDeg( dAngleNow );
	  dSinX += sinDeg( dAngleNow );
	}
	//cerr <<"flagCount : " <<iNrFlags << endl;
	dCosX /= (double)iNrFlags;
	dSinX /= (double)iNrFlags;
	if( iNrFlags == 0 )
	  return -1000;

	return Vector2D::normalizeAngle( atan2Deg( dSinX, dCosX  ) )  ;
}
//Akrame rezai
//Motevalede 5.9.41
//3348
AngDeg _Self::selfGetBodyByNeck (  )
{
	//cerr << "Real Neck : " << bodysenor.get() << endl;
	return GetNormalizeAngleDeg(ConvertAngle2(getSelfNeck()) -
this->getSelfRelativeNeck());
}
bool _Self::selfInitParse ( string  strData )
{
#if 0
    cerr << "Init Massage : " << strData << endl;
#endif
        string data1 = Parser().Pars_Value (strData,1),data2 = "";
	if (data1 != "")
	{
		data2 = Parser().Pars_Space ( data1, 2);
 		if (data2 == "l")
 		{
 			setObjectSide (SIDE_LEFT);
 		}
 		else
 		{
 			setObjectSide (SIDE_RIGHT);
 		}
		data2 = Parser().Pars_Space ( data1, 3);
		setObjectNumber (atoi(data2.c_str()));
#if 0
    cerr << "Init Massage ( Parse ): " << data2.c_str() << endl;
#endif
		return true;
	}
	return false;
}
bool _Self::selfIsBallKickable    (        )
{
	Iterator_Lib<BallInfo>  LastBallInfo = selfVisualSensor.getIteratorBallInfo ( );
	double ballDis = LastBallInfo.returnVector().back().Distance;
	return (this->getSelfBall_Collided () || selfServerData.get_kickable_margin() >= ballDis);
}
HPlayer _Self::getSelfType      (    )
{
	return selfHeteroData.getTypeByID ( getObjectType ( ) );
}
bool _Self::setUpdateByAct(MapLib <_MapValue> maplib)
{
    _MapValue Val;
    if (!maplib.getResult("NECK"))
    {
        Val = maplib.getResult("NECK");
        this->setSelfNeck   ( this->getSelfNeck() + Val.PAR1 );
    }
    if (!maplib.getResult("BODY"))
    {
        Val = maplib.getResult("BODY");
        this->setSelfBody   ( this->getSelfBody() + Val.PAR1 );
    }
    if (!maplib.getResult("DASH"))
    {
        Val = maplib.getResult("DASH");

        double speed = 0.9;//std::min( getSelfType      (    ).player_speed_max,
                         //  ( ( std::fabs(Val.PAR1) * getSelfType (    ).dash_power_rate * getSelfEffort() )
                           //  / ( 1.0 - getSelfType      (    ).player_decay ) ) );
        this->setSelfGlobalPosition   ( this->getSelfGlobalPosition() + Vector2D::getVector2DFromPolar(speed,Val.PAR2) );
    }
    if (!maplib.getResult("MOVE"))
    {
        Val = maplib.getResult("MOVE");
        this->setSelfGlobalPosition   ( Vector2D(Val.PAR1,Val.PAR2) );
    }
}
