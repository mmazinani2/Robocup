/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _BODY_SENSOR
#define _BODY_SENSOR

#include "../Util/MapLib.h"
#include "../Parser/ParseServer.h"
#include "../Types/SoccerTypes.h"


#include <stdlib.h>
#include <string.h>
#include <string>

class Body_Sensor
{
	private :

		bool         UpdateBody;
		int          UpdateTime;
		double       Quality;

		char   Vangle[8];
		char   VQual[8];
		CollisionT  	CollisionType;
		ViewQualityT    ViewQuality;
		ViewAngleT      ViewAngle;
		int    stamina;
		double effort;
		double capacity;
		double speed_magnitude;
    		double speed_dir_relative;
		double relative_neck;
		int count_kick;
		int count_dash;
		int count_turn;
		int count_say;
		int count_turn_neck;
		int count_catch;
		int count_move;
		int count_change_view;
		int arm_count_movable;
		int arm_count_expires;
		double  arm_dis;
		double  arm_dir;
		int     count_pointto;
		char  attentionto_target[15];
		SideT attentionto_side;
    		int attentionto_unum;
    		int count_attentionto;
		int tackle_expires;
    		int count_tackle;
                int charged;
                char card[18];
		char collision[18];
		
	public  :
		Body_Sensor ( );
		
		bool setAttentionto ( char *);
		bool setColision    ( char *);
		bool setViewQuality ( char *);
		bool setViewAngle   ( char *);

		int 		getStamina         ( );
		double 		getEffort          ( );
		double 		getCapacity        ( );
		double 		getSpeedMagnitude  ( );
    		double 		getSpeedDirRelative( );
		double 		getRelativeNeck    ( );
		int 		getCountKick       ( );
		int 		getCountDash       ( );
		int 		getCountTurn       ( );
		int 		getCountSay        ( );
		int 		getCountTurnNeck   ( );
		int 		getCountCatch      ( );
		int 		getCountMove       ( );
		int 		getCountChangeView ( );
		int 		getArmCountMovable ( );
		int 		getArmCountExpires ( );
		double  	getArmDis          ( );
		double  	getArmDir          ( );
		int     	getCountPointto    ( );
		SideT 		getAttentiontoSide ( );
    		int 		getAttentiontoUnum ( );
    		int 		getCountAttentionto( );
		int 		getTackleExpires   ( );
    		int 		getCountTackle     ( );
		CollisionT  	getCollisionType   ( );
		ViewQualityT    getViewQuality     ( );
		ViewAngleT      getViewAngle       ( );
                int             getCharged ( );
                Card            getCard ( );
		virtual bool Update   ( string );
		virtual bool isUpdate (        )
		{
			return UpdateBody;
		}
		virtual int TimeUpdate (       )
		{
			return UpdateTime;
		}
		virtual bool reset    (        )
		{
			UpdateBody = false;
		}
		virtual bool setQuality ( double Q)
		{
			Quality = Q;
		}
		virtual double getQuality (    )
		{
			return Quality;
		}
		virtual bool show ( );

};
#endif
