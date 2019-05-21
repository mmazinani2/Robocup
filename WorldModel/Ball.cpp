/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Ball.h"

_Ball::_Ball ( ):ballGlobal_Pos (Vector2D(1000.00,1000.0))
		,ballRelativ_Pos(Vector2D(1000.00,1000.0))
		,ballVel(Vector2D(1000.00,1000.0))
		,ballHear(Vector2D(1000.00,1000.0))
		,ballCountUpdate (0)
		,ballPos_Array (-1)
		,ballSee_Update (0)
		,ballHear_Update (0)
		,ballSpeed (0.0000)
{
}
bool _Ball::setBallGlobalPosition ( Vector2D vec )
{
	ballLastGlobal_Pos = ballGlobal_Pos;
	ballGlobal_Pos = vec;
}
bool _Ball::setBallRelativPosition ( Vector2D vec )
{
	ballRelativ_Pos = vec;
}
bool _Ball::setBallVel ( Vector2D vec )
{
	ballVel = vec;
}
bool _Ball::setBallHear (  Vector2D vec )
{
	ballHear = vec;
}
bool _Ball::setBallCountUpdate ( int val)
{
	ballCountUpdate = val;
}
bool _Ball::setBallPositionArray   ( int val )
{
	ballPos_Array = val;
}
bool _Ball::setBallSeeUpdate  ( Cycle seeCycle)
{
	ballSee_Update = seeCycle;
}
bool _Ball::setBallHearUpdate ( Cycle hearCycle)
{
	ballHear_Update = hearCycle;
}
bool _Ball::setBallSpeed ( double ballSpeed )
{
	ballSpeed = ballSpeed;
}
Vector2D _Ball::getBallGlobalPosition ( )
{
	return ballGlobal_Pos;
}
Vector2D _Ball::getBallRelativPosition ( )
{
	return ballRelativ_Pos;
}
Vector2D _Ball::getBallVel ( )
{
	return (getBallGlobalPosition() - getBallLastGlobalPosition ());
}
Vector2D _Ball::getBallHear ( )
{
	return ballHear;
}
int _Ball::getBallCountUpdate ( )
{
	return ballCountUpdate;
}
int _Ball::getBallPositionArray   ( )
{
	return ballPos_Array;
}
Cycle _Ball::getBallSeeUpdate ( )
{
	return ballSee_Update;
}
Cycle _Ball::getBallHearUpdate ( )
{
	return ballHear_Update;
}
double _Ball::getBallSpeed ( )
{
	return ballSpeed;
}
Vector2D _Ball::getBallLastGlobalPosition ( )
{
	return ballLastGlobal_Pos;
}
