/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Body_sensor.h"

Body_Sensor::Body_Sensor ( ):UpdateBody ( false )
			    ,UpdateTime ( 0  )
		 	    ,CollisionType ( CLL_NONE )
			    ,ViewQuality ( VQ_ILLEGAL )
		 	    ,ViewAngle ( VA_ILLEGAL )
			    ,stamina ( 8000 )
			    ,effort ( 0 )
			    ,capacity ( 0 )
			    ,speed_magnitude ( 0 )
    			    ,speed_dir_relative ( 0 )
			    ,relative_neck ( 0.0000000000000 )
		            ,count_kick ( 0 )
		            ,count_dash ( 0 )
		            ,count_turn ( 0 )
		            ,count_say ( 0 )
		            ,count_turn_neck ( 0 )
		            ,count_catch ( 0 )
		            ,count_move ( 0 )
		            ,count_change_view ( 0 )
		            ,arm_count_movable ( 0 )
		            ,arm_count_expires ( 0 )
		            ,arm_dis ( 0 )
		            ,arm_dir ( 0 )
		            ,count_pointto ( 0 )
		            ,attentionto_side ( SIDE_ILLEGAL )
    		            ,attentionto_unum ( 0 )
    		            ,count_attentionto ( 0 )
		            ,tackle_expires ( 0 )
    		            ,count_tackle ( 0 )
                            ,charged (0)
{
}
bool Body_Sensor::Update ( string strData)
{
	UpdateBody = true;
	try {
		sscanf( strData.c_str(),
        	" (sense_body %ld (view_mode %7[^ ] %7[^)])"
        	" (stamina %i %lf %lf)"
       		" (speed %lf %lf) (head_angle %lf)"
        	" (kick %d) (dash %d) (turn %d) (say %d) (turn_neck %d)"
        	" (catch %d) (move %d) (change_view %d)"
        	" (arm (movable %d) (expires %d)"
        	" (target %lf %lf) (count %d))"
        	" (focus (target %[^)]) (count %d))"
        	" (tackle (expires %d) (count %d)) (collision %[^)])"
                " (foul (charged %d) (card  %[^)]))",
        		&UpdateTime, VQual, Vangle,
                	&stamina, &effort,&capacity,
                	&speed_magnitude, &speed_dir_relative,
                	&relative_neck,
                	&count_kick, &count_dash,
                	&count_turn, &count_say,
                	&count_turn_neck, &count_catch,
                	&count_move, &count_change_view,
                	&arm_count_movable , &arm_count_expires,
                	&arm_dis, &arm_dir,
                	&count_pointto,
                	attentionto_target , &count_attentionto,
                	&tackle_expires, &count_tackle,collision,&charged,card);
		
		setAttentionto ( attentionto_target );
		setColision    ( collision );
		setViewQuality ( VQual  );
		setViewAngle   ( Vangle );
		#if 0
			show ( );
		#endif
		return true;
	}
	catch (...)
	{
		//cerr << "(Body_sensor)::Error In Update" << endl;
		return false;
	}
	
	
}
bool Body_Sensor::setAttentionto ( char *at )
{
	 if ( at[0] == 'n' )
        {
            attentionto_side = SIDE_ILLEGAL;
            attentionto_unum = -1;
        }
        else if ( at[0] == 'l' )
        {
            attentionto_side = SIDE_LEFT;
            attentionto_unum
                = static_cast< int >( strtol( at + 2, NULL, 10 ) );
        }
        else if ( at[0] == 'r' )
        {
            attentionto_side = SIDE_RIGHT;
            attentionto_unum
                = static_cast< int >( strtol( at + 2, NULL, 10 ) );
        }
        else
        {
            attentionto_side = SIDE_ILLEGAL;
            attentionto_unum = -1;
        }
}
bool Body_Sensor::setColision    ( char *co )
{
	string strCut = Parser().Pars_Space ( co,2);
	switch (strCut[2])
	{
		case 'l' :
			CollisionType = CLL_BALL;
			return true;
		case 'a' :
			CollisionType = CLL_PLAYER;
			return true;
		case 's' :
			CollisionType = CLL_POST;
			return true;
		case 'n' :
			CollisionType = CLL_NONE;
			return true;
	}
	CollisionType = CLL_NONE;
	return false;
}
bool Body_Sensor::setViewQuality ( char *VQ  )
{
	switch (VQ[0])
	{
		case 'h' :
			ViewQuality = VQ_HIGH;
			return true;
		case 'l' :
			ViewQuality = VQ_LOW;
			return true;
	}
	ViewQuality = VQ_ILLEGAL;
	return false;
}
bool Body_Sensor::setViewAngle   ( char *Va )
{
	switch (Va[1])
	{
		case 'a' :
			ViewAngle = VA_NARROW;
			return true;
		case 'o' :
			ViewAngle = VA_NORMAL;
			return true;
		case 'i' :
			ViewAngle = VA_WIDE;
			return true;
	}
	ViewAngle = VA_ILLEGAL;
	return false;
}
int Body_Sensor::getStamina ( )
{
	return stamina;
}
double Body_Sensor::getEffort ( )
{
	return effort;
}
double Body_Sensor::getCapacity ( )
{
	return capacity;

}
double Body_Sensor::getSpeedMagnitude ( )
{
	return speed_magnitude;
}
double Body_Sensor::getSpeedDirRelative( )
{
 	return speed_dir_relative;
}
double Body_Sensor::getRelativeNeck ( )
{
	return relative_neck;
}
int Body_Sensor::getCountKick ( )
{
	return count_kick;
}
int Body_Sensor::getCountDash ( )
{
	return count_dash;
}
int Body_Sensor::getCountTurn ( )
{
	return count_turn;
}
int Body_Sensor::getCountSay ( )
{
	return count_say;
}
int Body_Sensor::getCountTurnNeck ( )
{
	return count_turn_neck;
}
int Body_Sensor::getCountCatch ( )
{
	return count_catch;
}
int Body_Sensor::getCountMove ( )
{
	return count_move;
}
int Body_Sensor::getCountChangeView ( )
{
	return count_change_view;
}
int Body_Sensor::getArmCountMovable ( )
{
	return arm_count_movable;
}
int Body_Sensor::getArmCountExpires ( )
{
	return arm_count_expires;
}
double Body_Sensor::getArmDis ( )
{
	return arm_dis;
}
double Body_Sensor::getArmDir ( )
{
	return arm_dir;
}
int Body_Sensor::getCountPointto ( )
{
	return count_pointto;
}
SideT Body_Sensor::getAttentiontoSide ( )
{
	return attentionto_side;
}
int Body_Sensor::getAttentiontoUnum ( )
{
 	return attentionto_unum;
}
int Body_Sensor::getCountAttentionto( )
{
    	return count_attentionto;
}
int Body_Sensor::getTackleExpires ( )
{
	return tackle_expires;
}
int Body_Sensor::getCountTackle ( )
{
	return count_tackle;
}
CollisionT Body_Sensor::getCollisionType ( )
{
	return CollisionType;
}
ViewQualityT Body_Sensor::getViewQuality ( )
{
	return ViewQuality;
}
ViewAngleT Body_Sensor::getViewAngle ( )
{
	return ViewAngle;
}
int Body_Sensor::getCharged ( )
{
        return charged;
}
Card Body_Sensor::getCard ( )
{
        switch (card[0])
        {
          case 'r' :
            return CARD_RED;
          case 'y' :
            return CARD_YELLOW;
          default :
            return CARD_NONE;
        }
}
bool Body_Sensor::show ( )
{
	   cerr << "\nStamina            : " << getStamina         ( )
		<< "\nEffort             : " << getEffort          ( )
		<< "\nCapacity           : " << getCapacity        ( )
		<< "\nSpeed Magnitude    : " << getSpeedMagnitude  ( )
		<< "\nSpeed Dir Relative : " << getSpeedDirRelative( )
		<< "\nRelative Neck      : " << getRelativeNeck    ( )
		<< "\nCount Kick         : " << getCountKick       ( )
		<< "\nCount Dash         : " << getCountDash       ( )
		<< "\nCount Turn         : " << getCountTurn       ( )
		<< "\nCount Say          : " << getCountSay        ( )
		<< "\nCount Turn Neck    : " << getCountTurnNeck   ( )
		<< "\nCount Catch        : " << getCountCatch      ( )
		<< "\nCount Move         : " << getCountMove       ( )
		<< "\nCount Change View  : " << getCountChangeView ( )
		<< "\nArm Count Movable  : " << getArmCountMovable ( )
		<< "\nArm Count Expires  : " << getArmCountExpires ( )
		<< "\nArm Dis            : " << getArmDis          ( )
		<< "\nArm Dir            : " << getArmDir          ( )
		<< "\nCount Pointto      : " << getCountPointto    ( )
		<< "\nAttentionto Side   : " << getAttentiontoSide ( )
		<< "\nAttentionto Unum   : " << getAttentiontoUnum ( )
		<< "\nCount Attentionto  : " << getCountAttentionto( )
		<< "\nTackle Expires     : " << getTackleExpires   ( )
		<< "\nCount Tackle       : " << getCountTackle     ( )
		<< "\nCollision Type     : " << getCollisionType   ( )
		<< "\nView Quality       : " << getViewQuality     ( )
		<< "\nView Angle         : " << getViewAngle       ( ) << endl;
}
