/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _BALL_
#define _BALL_


#include "Localization.h"
#include "../Sensor/server_param.h"
#include "../Sensor/Audio_sensor.h"
#include "../Sensor/Body_sensor.h"
#include "../Sensor/visual_sensor.h"
#include "../Util/IteratorLib.h"
#include "../Util/Timer.h"
#include "../Geometry/Geometry.h"
#include <iostream>

using namespace std;

class _Ball
{
	private :
		Server_param  ballServerData;
		
		Vector2D     ballGlobal_Pos;
		Vector2D     ballLastGlobal_Pos;
		Vector2D     ballRelativ_Pos;
		Vector2D     ballVel;
		Vector2D     ballHear;
		bool 	     ballVisible;
		
		int 	ballCountUpdate;
		int     ballPos_Array;
		
		Cycle   ballSee_Update;
		Cycle   ballHear_Update;
		double ballSpeed;

	public :
		_Ball ( );
		
		bool setBallGlobalPosition ( Vector2D );
		bool setBallRelativPosition ( Vector2D );
		bool setBallVel ( Vector2D );
		bool setBallHear ( Vector2D );
		bool setBallCountUpdate ( int );
		bool setBallPositionArray   ( int );
		bool setBallSeeUpdate  ( Cycle );
		bool setBallHearUpdate ( Cycle );
		bool setBallSpeed ( double );
		bool setBallVisible (bool b) {ballVisible = b;}
		bool		  getBallVisible () {return ballVisible;}
		Vector2D          getBallLastGlobalPosition ( );
		Vector2D          getBallGlobalPosition ( );
		Vector2D          getBallRelativPosition ( );
		Vector2D          getBallVel ( );
		Vector2D          getBallHear ( );
		int 	          getBallCountUpdate ( );
		int               getBallPositionArray   ( );
		Cycle             getBallSeeUpdate ( );
		Cycle             getBallHearUpdate ( );
		double            getBallSpeed ( );
};
#endif
