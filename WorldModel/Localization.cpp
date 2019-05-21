/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Localization.h"

Localization::Localization ()
{

}
void Localization::quantizeRange(float Output, float &min, float &max)
{
	Output -= 1.0e-10;
  	if( Output < 0 )
    		min = 0.0;
  	else
    		min = exp( quantizeMin( log( quantizeMin(Output,0.1) ), 0.01 ) );
  	Output += 2.0e-10;
  	max = exp( quantizeMax( log( quantizeMax(Output,0.1) ), 0.01 ) );
}
float Localization::quantizeMin(float Output, float q)
{
	return max(1.0e-10,(rint( Output / q )-0.5 )*q);
}
float Localization::quantizeMax(float Output,float q)
{
	return (rint( Output/q) + 0.5 )*q;
}
Vector2D Localization::getGlobalPositionFlag( Flag o, SideT s, double dGoalWidth )
{
   Vector2D pos;
  switch( o )
  {
    case FT_GOAL_L:
      pos.setVector( -PITCH_LENGTH/2.0, 0.0 );                  break;
    case FT_GOAL_R:
      pos.setVector(  PITCH_LENGTH/2.0, 0.0 );                  break;
    case FT_FLAG_L_T:
      pos.setVector( -PITCH_LENGTH/2.0, -PITCH_WIDTH/2.0 );     break;
    case FT_FLAG_T_L_50:
      pos.setVector( -50.0, -PITCH_WIDTH/2.0 - PITCH_MARGIN );  break;
    case FT_FLAG_T_L_40:
      pos.setVector( -40.0, -PITCH_WIDTH/2.0 - PITCH_MARGIN );  break;
    case FT_FLAG_T_L_30:
      pos.setVector( -30.0, -PITCH_WIDTH/2.0 - PITCH_MARGIN );  break;
    case FT_FLAG_T_L_20:
      pos.setVector( -20.0, -PITCH_WIDTH/2.0 - PITCH_MARGIN );  break;
    case FT_FLAG_T_L_10:
      pos.setVector( -10.0, -PITCH_WIDTH/2.0 - PITCH_MARGIN );  break;
    case FT_FLAG_T_0:
      pos.setVector(   0.0, -PITCH_WIDTH/2.0 - PITCH_MARGIN );  break;
    case FT_FLAG_C_T:
      pos.setVector(   0.0, -PITCH_WIDTH/2.0);                  break;
    case FT_FLAG_T_R_10:
      pos.setVector(  10.0,  -PITCH_WIDTH/2.0 - PITCH_MARGIN);  break;
    case FT_FLAG_T_R_20:
      pos.setVector(  20.0,  -PITCH_WIDTH/2.0 - PITCH_MARGIN);  break;
    case FT_FLAG_T_R_30:
      pos.setVector(  30.0,  -PITCH_WIDTH/2.0 - PITCH_MARGIN);  break;
    case FT_FLAG_T_R_40:
      pos.setVector(  40.0,  -PITCH_WIDTH/2.0 - PITCH_MARGIN);  break;
    case FT_FLAG_T_R_50:
      pos.setVector(  50.0,  -PITCH_WIDTH/2.0 - PITCH_MARGIN);  break;
    case FT_FLAG_R_T:
      pos.setVector( PITCH_LENGTH/2.0,  -PITCH_WIDTH/2.0 );     break;
    case FT_FLAG_R_T_30:
      pos.setVector( PITCH_LENGTH/2.0 + PITCH_MARGIN,  -30.0 ); break;
    case FT_FLAG_R_T_20:
      pos.setVector( PITCH_LENGTH/2.0 + PITCH_MARGIN,  -20.0 ); break;
    case FT_FLAG_R_T_10:
      pos.setVector( PITCH_LENGTH/2.0 + PITCH_MARGIN,  -10.0 ); break;
    case FT_FLAG_G_R_T:
      pos.setVector( PITCH_LENGTH/2.0,  -dGoalWidth/2.0 );      break;
    case FT_FLAG_R_0:
      pos.setVector( PITCH_LENGTH/2.0 + PITCH_MARGIN,  0.0 );   break;
    case FT_FLAG_G_R_B:
      pos.setVector( PITCH_LENGTH/2.0,  dGoalWidth/2.0 );       break;
    case FT_FLAG_R_B_10:
      pos.setVector( PITCH_LENGTH/2.0 + PITCH_MARGIN,  10.0 );  break;
    case FT_FLAG_R_B_20:
      pos.setVector( PITCH_LENGTH/2.0 + PITCH_MARGIN,  20.0 );  break;
    case FT_FLAG_R_B_30:
      pos.setVector( PITCH_LENGTH/2.0 + PITCH_MARGIN,  30.0 );  break;
    case FT_FLAG_R_B:
      pos.setVector( PITCH_LENGTH/2.0,  PITCH_WIDTH/2.0 );      break;
    case FT_FLAG_B_R_50:
      pos.setVector(  50.0, PITCH_WIDTH/2.0 + PITCH_MARGIN );   break;
    case FT_FLAG_B_R_40:
      pos.setVector(  40.0, PITCH_WIDTH/2.0 + PITCH_MARGIN );   break;
    case FT_FLAG_B_R_30:
      pos.setVector(  30.0, PITCH_WIDTH/2.0 + PITCH_MARGIN );   break;
    case FT_FLAG_B_R_20:
      pos.setVector(  20.0, PITCH_WIDTH/2.0 + PITCH_MARGIN );   break;
    case FT_FLAG_B_R_10:
      pos.setVector(  10.0, PITCH_WIDTH/2.0 + PITCH_MARGIN );   break;
    case FT_FLAG_C_B:
      pos.setVector(   0.0, PITCH_WIDTH/2.0 );                  break;
    case FT_FLAG_B_0:
      pos.setVector(   0.0, PITCH_WIDTH/2.0 + PITCH_MARGIN );   break;
    case FT_FLAG_B_L_10:
      pos.setVector( -10.0, PITCH_WIDTH/2.0 + PITCH_MARGIN );   break;
    case FT_FLAG_B_L_20:
      pos.setVector( -20.0, PITCH_WIDTH/2.0 + PITCH_MARGIN );   break;
    case FT_FLAG_B_L_30:
      pos.setVector( -30.0, PITCH_WIDTH/2.0 + PITCH_MARGIN );   break;
    case FT_FLAG_B_L_40:
      pos.setVector( -40.0, PITCH_WIDTH/2.0 + PITCH_MARGIN );   break;
    case FT_FLAG_B_L_50:
      pos.setVector( -50.0, PITCH_WIDTH/2.0 + PITCH_MARGIN );   break;
    case FT_FLAG_L_B:
      pos.setVector( -PITCH_LENGTH/2.0,  PITCH_WIDTH/2.0 );     break;
    case FT_FLAG_L_B_30:
      pos.setVector( -PITCH_LENGTH/2.0 - PITCH_MARGIN,  30.0 ); break;
    case FT_FLAG_L_B_20:
      pos.setVector( -PITCH_LENGTH/2.0 - PITCH_MARGIN,  20.0 ); break;
    case FT_FLAG_L_B_10:
      pos.setVector( -PITCH_LENGTH/2.0 - PITCH_MARGIN,  10.0 ); break;
    case FT_FLAG_G_L_B:
      pos.setVector( -PITCH_LENGTH/2.0,  dGoalWidth/2.0 );      break;
    case FT_FLAG_L_0:
      pos.setVector( -PITCH_LENGTH/2.0 - PITCH_MARGIN,  0.0 );  break;
    case FT_FLAG_G_L_T:
      pos.setVector( -PITCH_LENGTH/2.0,  -dGoalWidth/2.0 );     break;
    case FT_FLAG_L_T_10:
      pos.setVector( -PITCH_LENGTH/2.0 - PITCH_MARGIN, -10.0 ); break;
    case FT_FLAG_L_T_20:
      pos.setVector( -PITCH_LENGTH/2.0 - PITCH_MARGIN, -20.0 ); break;
    case FT_FLAG_L_T_30:
      pos.setVector( -PITCH_LENGTH/2.0 - PITCH_MARGIN, -30.0 ); break;
    case FT_FLAG_P_L_T:
      pos.setVector( -PITCH_LENGTH/2.0 + PENALTY_AREA_LENGTH,
                                         - PENALTY_AREA_WIDTH/2.0 ); break;
    case FT_FLAG_P_L_C:
      pos.setVector( -PITCH_LENGTH/2.0 + PENALTY_AREA_LENGTH, 0.0 );break;
    case FT_FLAG_P_L_B:
      pos.setVector( -PITCH_LENGTH/2.0 + PENALTY_AREA_LENGTH,
                                           PENALTY_AREA_WIDTH/2.0 ); break;
    case FT_FLAG_P_R_T:
      pos.setVector(  PITCH_LENGTH/2.0 - PENALTY_AREA_LENGTH,
                                          -PENALTY_AREA_WIDTH/2.0 ); break;
    case FT_FLAG_P_R_C:
      pos.setVector(  PITCH_LENGTH/2.0 - PENALTY_AREA_LENGTH, 0.0 );break;
    case FT_FLAG_P_R_B:
      pos.setVector(  PITCH_LENGTH/2.0 - PENALTY_AREA_LENGTH,
                                           PENALTY_AREA_WIDTH/2.0 ); break;
    case FT_FLAG_C:
      pos.setVector(  0.0 , 0.0 );                              break;
    default:
      break;
  }

  if( s == SIDE_RIGHT )
      pos.setVector( -pos.getX(), -pos.getY() );
  return pos;
}
