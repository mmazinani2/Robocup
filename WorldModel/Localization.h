/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef __LOCALIZATION_
#define __LOCALIZATION_
#include <cmath>
#include <iostream>
#include "../Geometry/Geometry.h"
#include "../Types/SoccerTypes.h"

using namespace std;

class Localization 
{
	public :
		Localization ();
		void quantizeRange(float , float &min, float &max);
		float quantizeMin(float  , float );
		float quantizeMax(float  , float );
		
		Vector2D       getGlobalPositionFlag( Flag , SideT , double );
};

#endif
