/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _PREDICT_
#define _PREDICT_
#include "WorldModel.h"
#include "../Geometry/Geometry.h"

extern WorldModel WM;


class Predict : public WorldModel
{
	private :
	
	public :
		Predict ( );
		Vector2D InertiaAfterCycle( Vector2D pos, Vector2D vel, int cycle, double decay );
};
 
#endif
