/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _ADVANCEDSKILL_
#define _ADVANCEDSKILL_
#include "BasicSkill.h"
#include "../WorldModel/WorldModel.h"
#include "../Geometry/Geometry.h"

extern WorldModel WM;


class AdvancedSkill : public BasicSkill
{
	private :
		Server_param  selfServerData;
		int           nextTurnCount;
		double        bufAng;
		double        mTurnNeckAngle;
		double        mTurnBodyAngle;
		double        mDashPower;
		double	      mTurnBodyLastAngle;
		double	      mTurnNeckLastAngle;
		double	      mDashLastPower;
		int 	      mTurnNeckCount;
		int 	      mTurnBodyCount;
		int 	      mDashCount;
		int 	      mPoinToCount;
		int 	      mKickCount;
		int 	      mLostCommand;
	public :
		AdvancedSkill ( );
		bool SearchBall();
		bool  GoToPoint   ( Vector2D Targ );
		bool  TurnToPoint ( Vector2D Targ );
		bool  KickToPoistion (Vector2D ,double);
		bool  StopBall       ();
};
 
#endif
