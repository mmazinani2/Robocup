/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "PlayerObject.h"

_PlayerObject::_PlayerObject ( ):TeamSide(SIDE_ILLEGAL)
		,UniNum(0)
		,Goali(false)
		,PlayerID(PT_UNKNOWN)
		,HPlayeType(-1)
		,GlobalPosition(1000,1000)
		,PosArray(-1)
		,HearPosition(1000,1000)
		,HearCycle(-1)
		,SeePosition(1000,1000)
		,SeePosTime(-1)
		,LastSeePosition(1000,1000)
		,LastSeePosTime(-1)
		,Vel(1000,1000)
		,VelDis(1000)
		,Body(1000)
		,Neck(1000)
		,BallDistance(1000)
{
}
bool _PlayerObject::setObjectSide ( SideT  t )
{
	TeamSide = t;
}
bool _PlayerObject::setObjectNumber ( int   num  )
{
	UniNum = num;
}
bool _PlayerObject::setObjectIsGoali ( bool   goali )
{
	Goali = goali;
}
bool _PlayerObject::setObjectPlayerID ( PlayerT  plt )
{
	PlayerID = plt;
}
bool _PlayerObject::setObjectType ( int    objtype )
{
	HPlayeType = objtype;
}
bool _PlayerObject::setObjectGlobalPosition ( Vector2D globalpos)
{
	GlobalPosition = globalpos;
}
bool _PlayerObject::setObjectPositionArray ( int   posarry  )
{
	PosArray = posarry;
}
bool _PlayerObject::setObjectSeePosition ( Vector2D seepos)
{
	setObjectLastSeePosition ( getObjectSeePosition ( ) );
	setObjectLastSeeTime (  getObjectSeeTime ( ) );
	SeePosition = seepos;
}
bool _PlayerObject::setObjectSeeTime ( Cycle  seetime )
{
	SeePosTime = seetime;
}
bool _PlayerObject::setObjectLastSeePosition ( Vector2D lseepos)
{
	LastSeePosition = lseepos;
}
bool _PlayerObject::setObjectLastSeeTime ( Cycle  lseetime )
{
	LastSeePosTime = lseetime;
}
bool _PlayerObject::setObjectHearPosition ( Vector2D hearpos)
{
	HearPosition = hearpos;
}
bool _PlayerObject::setObjectHearTime ( Cycle  heartime )
{
	HearCycle = heartime;
}
bool _PlayerObject::setObjectVel ( Vector2D velpos)
{
	Vel = velpos;
}
bool _PlayerObject::setObjectVelDistance ( double veldis )
{
	VelDis = veldis;
}
bool _PlayerObject::setObjectBodyAngle ( AngDeg bAng )
{
	Body = bAng;
}
bool _PlayerObject::setObjectNeckAngle ( AngDeg  nAng )
{
	Neck = nAng;
}
bool _PlayerObject::setObjectBallDistance ( double bdis )
{
	BallDistance = bdis;
}
bool _PlayerObject::setObjectQuality ( double quality     )
{
	Quality = quality;
} 

bool   _PlayerObject::setObjectVisible (bool visible   )
{
	Visible = visible;
}
SideT _PlayerObject::getObjectSide (     )
{
	return TeamSide;
}
int _PlayerObject::getObjectNumber (     )
{
	return UniNum;
}
bool _PlayerObject::getObjectIsGoali (    )
{
	return Goali;
}
PlayerT _PlayerObject::getObjectPlayerID (     )
{
	return PlayerID;
}
int _PlayerObject::getObjectType (     )
{
	return HPlayeType;
}
Vector2D _PlayerObject::getObjectGlobalPosition (    )
{
	return GlobalPosition;
}
int _PlayerObject::getObjectPositionArray (     )
{
	return PosArray;
}
Vector2D _PlayerObject::getObjectSeePosition (    )
{
	return SeePosition;
}
Cycle _PlayerObject::getObjectSeeTime (     )
{
	return SeePosTime;
}
Vector2D _PlayerObject::getObjectLastSeePosition (    )
{
	return LastSeePosition;
}
Cycle _PlayerObject::getObjectLastSeeTime (     )
{
	return LastSeePosTime;
}
Vector2D _PlayerObject::getObjectHearPosition (    )
{
	return HearPosition;
}
Cycle _PlayerObject::getObjectHearTime (      )
{
	return HearCycle;
}
Vector2D _PlayerObject::getObjectVel (    )
{
	return Vel;
}
double _PlayerObject::getObjectVelDistance (     )
{
	return VelDis;
}
AngDeg _PlayerObject::getObjectBodyAngle (     )
{
	return Body;
}
AngDeg _PlayerObject::getObjectNeckAngle (     )
{
	return Neck;
}
double _PlayerObject::getObjectBallDistance (     )
{
	return BallDistance;
}
double _PlayerObject::getObjectQuality (     )
{
	return Quality;
} 
bool   _PlayerObject::getObjectVisible    (   )
{
	return Visible;
}
