/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "SelfModel.h"

SelfModel::SelfModel ()
{
    _Self self = WM.getSelf();
    last_Model_Turn_BodyAngel = self.getSelfBody();
    last_Model_Turn_NeckAngel = self.getSelfNeck();
    t_Turn_BodyAngel = 0.00000;
    t_Turn_NeckAngel = 0.00000;
    count_TurnBody = 0;
    count_TurnNeck = 0;
}
double SelfModel::ModelNeckWithTurn (double moment)
{
      _Self self     	  = WM.getSelf();
      Server_param servep = WM.getServerParam ();
      Vector2D myVel = self.getObjectVel();
      
      double calcMoment = moment / (1.00 + myVel.getMagnitude()*self.getSelfType().inertia_moment);
      double calcAngel  = moment; //* (1.00 + myVel.getMagnitude()*self.getSelfType().inertia_moment);
      if (calcMoment < servep.get_maxmoment () && calcMoment > servep.get_minmoment ())
      {
	if (WM.getSyncTime())
	{
	    double delta_Ang = last_Model_Turn_NeckAngel - self.getSelfNeck();
	    count_TurnNeck++;
	    t_Turn_NeckAngel = delta_Ang / count_TurnNeck;
	    //cerr << "Turn Neck : " << t_Turn_NeckAngel << " BodyCount : " << count_TurnNeck << endl;
	    last_Model_Turn_NeckAngel = self.getSelfNeck();
	}
	else
	{
	    last_Model_Turn_NeckAngel += calcAngel;
	}
      }
      return Vector2D::normalizeAngle(last_Model_Turn_NeckAngel);
}
double SelfModel::ModelBodyWithTurn (double moment)
{
      _Self self     	  = WM.getSelf();
      Server_param servep = WM.getServerParam ();
      Vector2D myVel = self.getObjectVel();
      
      double calcMoment = moment / (1.00 + myVel.getMagnitude()*self.getSelfType().inertia_moment);
      double calcAngel  = moment; //* (1.00 + myVel.getMagnitude()*self.getSelfType().inertia_moment);
      if (calcMoment < servep.get_maxmoment () && calcMoment > servep.get_minmoment ())
      {
	if (WM.getSyncTime())
	{
	    double delta_Ang = last_Model_Turn_BodyAngel - self.getSelfBody();
	    count_TurnBody++;
	    t_Turn_BodyAngel = delta_Ang / count_TurnBody;
	    //cerr << "Turn Angle : " << t_Turn_BodyAngel << " BodyCount : " << count_TurnBody << endl;
	    last_Model_Turn_BodyAngel = self.getSelfBody();
	}
	else
	{
	    last_Model_Turn_BodyAngel += calcAngel;
	}
      }
      return Vector2D::normalizeAngle(last_Model_Turn_BodyAngel);
}
bool SelfModel::ModelUpdateByTurn (double angle)
{
   
}