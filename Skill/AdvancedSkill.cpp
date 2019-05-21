/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "AdvancedSkill.h"
#include "../GameModel/DynamicModel.h"
#include "../GameModel/SelfModel.h"
AdvancedSkill::AdvancedSkill ( ):BasicSkill ()
{
	nextTurnCount = 0;
	mTurnNeckCount = 0;
	mTurnBodyCount = 0;
	mDashCount = 0;
	mPoinToCount = 0;
	mTurnNeckAngle = 0;
	mTurnBodyAngle = 0;
	mDashPower = 0;
	
	
	mKickCount         = 0;
	mTurnBodyLastAngle = 0;
	mTurnNeckLastAngle = 0;
	mDashLastPower	   = 0;
	
	mLostCommand       = 0;
}
bool AdvancedSkill::SearchBall ()
{
    _Ball ball = WM.getBall();
    _Self self  = WM.getSelf ();
    Vector2D selfPosition = self.getSelfGlobalPosition ();
    
    if (!ball.getBallVisible ())
    {
      if (mTurnBodyCount <= self.getSelfCountTurn())
      {
	mTurnBodyCount++;
	mTurnBodyLastAngle = SelfModel().ModelBodyWithTurn(20.0);
	Make_Turn (Vector2D::normalizeAngle(20.0));
      }
      else 
      {
	mTurnBodyLastAngle = SelfModel().ModelBodyWithTurn(20.0);
	Make_Turn (Vector2D::normalizeAngle(20.0));
      }
      return true;
    }
    else 
      return false;
}
bool AdvancedSkill::TurnToPoint ( Vector2D Targ )
{
    _Self self  = WM.getSelf ();
    Vector2D selfPosition = self.getSelfGlobalPosition () + Vector2D::getVector2DFromPolar( self.getSelfSpeed()*0.4 , self.getSelfBody() ) ;
    Vector2D vel          = (Targ-selfPosition);
    double   Ang          = vel.getDirection();		
    Ang -= mTurnBodyLastAngle;	 	
    if (fabs(Ang) <= 2 || selfPosition.getDistanceTo (Targ) <= 0.5)
	  return false;
    if (mTurnBodyCount <= self.getSelfCountTurn())
    {  
	mLostCommand = 0;
	mTurnBodyCount++;
	mTurnBodyAngle	   = Ang;
	mTurnBodyLastAngle = SelfModel().ModelBodyWithTurn(mTurnBodyAngle);
	Make_Turn (Vector2D::normalizeAngle(mTurnBodyAngle));
    }
    else 
    {
	mLostCommand++;
	if (mLostCommand < 2)
	  mTurnBodyLastAngle = SelfModel().ModelBodyWithTurn(mTurnBodyAngle);
	Make_Turn (Vector2D::normalizeAngle(mTurnBodyAngle));
    }
    return true;
}
bool AdvancedSkill::StopBall()
{
      _Ball ball = WM.getBall();
      _Self self = WM.getSelf();
      Vector2D selfPos      = self.getSelfGlobalPosition ();
      double ball_Speed     = ball.getBallVel().getMagnitude();
      double ball_Direction = ball.getBallVel().getDirection();
      Vector2D vec = ball.getBallVel();
      Vector2D BallPos = (ball.getBallGlobalPosition () + vec);
      //cerr << ball_Speed << endl;
      if (ball_Speed >= 0.3)
      {
	  if (BallPos.getDistanceTo (selfPos) <= 1.0)
	  {
	      Vector2D KickPos = ball.getBallGlobalPosition ();
	      return KickToPoistion (KickPos,ball_Speed+10.0);
	  }
	  return false;
      }
      return false;
}
bool AdvancedSkill::KickToPoistion (Vector2D v2D,double pow)
{
	_Ball ball = WM.getBall();
	_Self self = WM.getSelf();
	Vector2D posBall  = ball.getBallGlobalPosition ();
	Vector2D posTraj  = (v2D - posBall);
	double Angle = posTraj.getDirection();
	Angle -= mTurnBodyLastAngle;
	if (mKickCount == self.getSelfCountkick())
	{
	  mKickCount++;
	  return Make_Kick(pow,Angle);   
	}
	else 
	{
	  return Make_Kick(pow,Angle);  
	}
}
