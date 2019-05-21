/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "DynamicModel.h"
#include "../Geometry/Geometry.h"
extern WorldModel WM;
DynamicModel::DynamicModel ():mTurnNeckCount(0),
			      mTurnBodyCount(0),
			      mDashCount(0),
			      mPointTo(0)
{   
}
double DynamicModel::DynamicNeckAngel (double moment)
{
    _Self self = WM.getSelf ();
    if (moment > WM.getServerParam  ( ).get_maxmoment() || moment < WM.getServerParam  ( ).get_minmoment())
	return -1000.00;
    double turnAngle = moment / (1 + self.getSelfType().inertia_moment * self.getObjectVel().getMagnitude());
    if (turnAngle > WM.getServerParam  ( ).get_maxmoment() || turnAngle < WM.getServerParam  ( ).get_minmoment())
	return -1000.00;
    return Vector2D::normalizeAngle(turnAngle + self.getSelfNeck());
}
double DynamicModel::DynamicBodyAngel (double moment)
{
    _Self self = WM.getSelf ();
    double turnAngle = moment;// / (1.0 + self.getSelfType().inertia_moment * self.getObjectVel().getDirection());
    //moment -= turnAngle;
    return Vector2D::normalizeAngle(self.getSelfBody() + moment);
}
Vector2D DynamicModel::DynamicDashVelocity (double dashpower)
{
    _Self self = WM.getSelf ();
    Vector2D dashAcclerate;
    Vector2D velocity;
    dashAcclerate.getVector2DFromPolar(
		  (dashpower * WM.getServerParam  ( ).get_dash_power_rate() * WM.getServerParam  ( ).get_effort_min()), self.getSelfBody());
    if (dashAcclerate.getMagnitude() > WM.getServerParam  ( ).get_player_accel_max())
	    dashAcclerate.getVector2DFromPolar(WM.getServerParam  ( ).get_player_accel_max(), dashAcclerate.getDirection());
    velocity += dashAcclerate;
    if (velocity.getMagnitude() > WM.getServerParam  ( ).get_player_speed_max())
	    velocity.getVector2DFromPolar(WM.getServerParam  ( ).get_player_speed_max(), velocity.getDirection());
    return velocity;
}
double DynamicModel::DynamicMyStamina (double dashpower)
{
    _Self self = WM.getSelf ();
    double stamina = self.getSelfStamina();
    if (dashpower >= 0)
	    stamina -= dashpower;
    else
	    stamina += 2 * dashpower;

    if (stamina < 0)
	    stamina = 0;
    return stamina;
}
Vector2D DynamicModel::DynamicAcclerate (double dashpower)
{
  
}
Vector2D DynamicModel::DynamicMovePosition (double xpos,double ypos)
{
  
}
Vector2D DynamicModel::DynamicPointTo (double xpos,double ypos)
{
  
}
