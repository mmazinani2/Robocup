/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef SELFMODEL_H
#define SELFMODEL_H

#include "../Types/SoccerTypes.h"
#include "../WorldModel/WorldModel.h"
#include "../Geometry/Geometry.h"
#include <cmath>
#include <math.h>
#include <iostream>

#define EPS_DATA   0.000006

extern WorldModel WM;

class SelfModel
{
  private :
    double last_Model_Turn_BodyAngel;
    double last_Model_Turn_NeckAngel;
    double t_Turn_BodyAngel;
    double t_Turn_NeckAngel;
    
    int    count_TurnBody;
    int    count_TurnNeck;
    
  public :
    SelfModel ();
    double ModelNeckWithTurn (double);
    double ModelBodyWithTurn (double);
    bool   ModelUpdateByTurn (double);
    
};

#endif