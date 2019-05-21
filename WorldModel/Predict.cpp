/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Predict.h"
#include "../GameModel/DynamicModel.h"
#include "../GameModel/SelfModel.h"
#include "../Geometry/Geometry.h"

Predict::Predict ( ):WorldModel ()
{

}
Vector2D Predict::InertiaAfterCycle( Vector2D pos, Vector2D vel, int cycle, double decay )
{
    return ( pos + vel * ( ( 1.0 - std::pow( decay, cycle ) ) / ( 1.0 - decay ) ) );
}