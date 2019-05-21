/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "TurnBody.h"
#include "../GameModel/DynamicModel.h"
#include "../GameModel/SelfModel.h"
#include "../WorldModel/Predict.h"

TurnBody::TurnBody ( ):BasicSkill ()
{
	mTurnBodyCount = 0;
	mLostCommand   = 0;
}
bool TurnBody::TurnBodyToPoint( Vector2D target , double speed , int cycle , double thr )
{
    _Self self  = WM.getSelf ();
    
    Vector2D selfPosition = Predict().InertiaAfterCycle( self.getSelfGlobalPosition() , 
					Vector2D::getVector2DFromPolar( self.getSelfSpeed() , self.getSelfBody() ) , cycle , self.getSelfType().player_decay );

   // cerr<< "AF : " << self.getSelfGlobalPosition().getX() << " , " << self.getSelfGlobalPosition().getY() << "      NE :  " << selfPosition.getX() << "  ,  " << selfPosition.getY() << endl;
    
    double   Ang  = ( target - selfPosition ).getDirection();		

    Ang -= self.getSelfBody();	 	

    if (fabs(Ang) <= thr || selfPosition.getDistanceTo (target) <= 0.7 )
      return false;
	
    AngDeg FinalAngle = Ang * ( 1.0 + self.getSelfType().inertia_moment * speed );
     // cerr<<self.getSelfType().inertia_moment<<endl;

  
    
    Make_Turn( normalize_angle( FinalAngle ) );

    return true;
}
