/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _TURNBODY_
#define _TURNBODY_
#include "BasicSkill.h"
#include "../WorldModel/WorldModel.h"
#include "../Geometry/Geometry.h"

extern WorldModel WM;


class TurnBody : public BasicSkill
{
	private :
		int 	      mTurnBodyCount;
		int 	      mLostCommand;
	public :
		TurnBody ( );
		bool TurnBodyToPoint( Vector2D target , double speed , int cycle = 1 , double thr = 10 );

};
 
#endif
