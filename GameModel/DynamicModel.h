/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef DYNAMICMODEL_H
#define DYNAMICMODEL_H

#include "../Types/SoccerTypes.h"
#include "../WorldModel/WorldModel.h"
#include "../Geometry/Geometry.h"
#include <cmath>
#include <math.h>
#include <iostream>

#define EPS_DATA   0.000006

using namespace std;

class DynamicModel
{
  public :
    DynamicModel ();
    double   DynamicNeckAngel    (double);
    double   DynamicBodyAngel    (double);
    Vector2D DynamicDashVelocity (double);
    double   DynamicMyStamina    (double);
    Vector2D DynamicAcclerate    (double);
    Vector2D DynamicMovePosition (double,double);
    Vector2D DynamicPointTo      (double,double);
    
  private :
    int mTurnNeckCount;
    int mTurnBodyCount;
    int mDashCount;
    int mPointTo;
        
};

#endif