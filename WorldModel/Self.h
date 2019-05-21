/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _SELF_
#define _SELF_


#include "Localization.h"
#include "PlayerObject.h"
#include "../Sensor/server_param.h"
#include "../Sensor/player_param.h"
#include "../Sensor/Hetero_player.h"
#include "../Sensor/Audio_sensor.h"
#include "../Sensor/Body_sensor.h"
#include "../Sensor/visual_sensor.h"
#include "../Util/IteratorLib.h"
#include "../Util/Timer.h"
#include "../Geometry/Geometry.h"
#include "../Util/MapLib.h"
#include <iostream>

using namespace std;


class FlagUnique: public std::binary_function< FlagInfo, FlagInfo, bool > {
	public:
		bool operator()( const FlagInfo & lhs,
				const FlagInfo & rhs ) const
		{
			return lhs == rhs;
		}
};
class _Self: public _PlayerObject
{
	private :
		
		Server_param  selfServerData;
		Player_param  selfPlayerData;
		Hetero_Player selfHeteroData;
		Visual_Sensor selfVisualSensor;
		Timer 	     selfTimer;
		Vector2D     selfGlobal_Pos;
		Vector2D     selfRelativ_Pos;
		Iterator_Lib<Vector2D> selfLast_Move_pos;
		Iterator_Lib<CommandT> selfLast_Send_Command;
		
		int     selfPos_Array;
		
		Cycle   selfClear_Last_Time;
		Cycle   selfBody_Updat;
		Cycle   selfSee_Updat;
		Cycle   selfCatch_Time;
		Cycle   selfCycle;
		ViewAngleT   selfVangle;
		ViewQualityT selfVQual;
		
		int selfStamina;
		double selfSpeed;
		double selfEffort;
		double selfCapacity;
		AngDeg selfBody;
		AngDeg selfNeck;
		
		int      selfSeeCount;
		int      selfCount_kick;
		int      selfCount_Dash;
		int      selfCount_Turn;
		int      selfCount_Say;
		int      selfCount_Turn_Neck;
		int      selfCount_Catch;
		int      selfCount_Move;
		int      selfCount_Change_View;
		int      selfArm_Count_Movable;
		int      selfArm_Count_Expires;
		Vector2D selfArm_Count_Target;
		int      selfArm_Count_Count;
		int      selfFocus_Count;
		int      selfTackle_Count_Expires;
		int      selfTackle_Count_Count;
		double selfRelativeNeck;
		bool selfNone_Collided;
    		bool selfBall_Collided;
    		bool selfPlayer_Collided;
    		bool selfPost_Collided;

		bool selfSynch;
                
	public :
		_Self ( );
		_Self ( Server_param &, Player_param &, Hetero_Player &);
		virtual bool isSelf ( )
			{return true;}
		bool setSelfCycle ( Cycle );
		bool setSelfSynch ( bool );
		bool setSelfGlobalPosition  (Vector2D);
		bool setSelfRelativPosition (Vector2D);
	        
		bool setSelfEffort (double ef)
		{
			selfEffort = ef;
		}
		bool setSelfCapacity ( double cp )
		{
			selfCapacity = cp;
		}
		double getSelfEffort ()
		{
			return selfEffort;
		}
		double getSelfCapacity ( )
		{
			return selfCapacity;
		}
		bool setSelfLastMovePosition(Vector2D);
		bool setSelfLastSendCommand (CommandT);
		
		bool setSelfPositionArray   (int     );
		
		bool setSelfClearLastTime   (long    );
		bool setSelfBodyUpdat       (Cycle   );
		bool setSelfSeeUpdat        (Cycle   );
		bool setSelfCatchTime       (Cycle   );
		bool setSelfViewAngle	       (  ViewAngleT  );
		bool setSelffViewQuality       ( ViewQualityT );
		
		bool setSelfStamina	       ( int          );
		bool setSelfSpeed	       ( double          );
		
		bool setSelfBody               (AngDeg        );
		bool setSelfNeck               (AngDeg        );
		
		bool setSelfCountkick          (int           );
		bool setSelfCountDash          (int           );
		bool setSelfCountTurn          (int           );
		bool setSelfCountSay           (int           );
		bool setSelfCountTurnNeck      (int           );
		bool setSelfCountCatch         (int           );
		bool setSelfCountMove          (int           );
		bool setSelfCountChangeView    (int           );
		bool setSelfArmCountMovable    (int           );
		bool setSelfArmCountExpires    (int           );
		bool setSelfArmCountTarget     (Vector2D      );
		bool setSelfArmCountCount      (int           );
		bool setSelfFocusCount         (int           );
		bool setSelfTackleCountExpires (int           );
		bool setSelfTackleCountCount   (int           );

		bool setSelfNone_Collided       (bool           );
    		bool setSelfBall_Collided       (bool           );
    		bool setSelfPlayer_Collided     (bool           );
    		bool setSelfPost_Collided       (bool           );


		Vector2D     getSelfGlobalPosition  (        );
		Vector2D     getSelfRelativPosition (        );
	
		Iterator_Lib<Vector2D> getSelfLastMovePosition  (        );
		Iterator_Lib<CommandT> getSelfLastSendCommand   (        );
		
		int     getSelfPositionArray    (        );
		
		Cycle   getSelfClearLastTime    (        );
		Cycle   getSelfBodyUpdat        (        );
		Cycle   getSelfSeeUpdat         (        );
		Cycle   getSelfCatchTime        (        );
		Cycle   getSelfCycle 		(        );
		ViewAngleT   getSelfVangle      (        );
		ViewQualityT getSelfVQual       (        );
		
		int getSelfStamina              (        );
		double getSelfSpeed                (        );
		
		AngDeg getSelfBody              (        );
		AngDeg getSelfNeck              (        );
		
		int      getSelfCountkick      (        );
		int      getSelfCountDash      (        );
		int      getSelfCountTurn      (        );
		int      getSelfCountSay       (        );
		int      getSelfCountTurnNeck  (        );
		int      getSelfCountCatch     (        );
		int      getSelfCountMove      (        );
		int      getSelfCountChangeView  (        );
		int      getSelfArmCountMovable  (        );
		int      getSelfArmCountExpires  (        );
		Vector2D getSelfArmCountTarget   (        );
		int      getSelfArmCountCount    (        );
		int      getSelfFocusCount           (        );
		int      getSelfTackleCountExpires   (        );
		int      getSelfTackleCountCount     (        );

		bool getSelfNone_Collided    (        );
    		bool getSelfBall_Collided    (        );
    		bool getSelfPlayer_Collided  (        );
    		bool getSelfPost_Collided    (        );
		bool setSelfRelativeNeck ( double );
		double getSelfRelativeNeck ( );
                bool setUpdateByAct          (MapLib <_MapValue> maplib);
		bool selfUpdateBySee         (  Visual_Sensor & );
		bool selfUpdateBySense       (  Body_Sensor &   );
		bool selfUpdateByHear        (  Audio_sensor &  );
		bool selfUpdateByTime        (                  );
		bool selfUpdateByType        (  Hetero_Player &hp ){selfHeteroData = hp;}
                double   calculateAngleAgentWithPos(Visual_Sensor &visualsensor
);
		int      getSelfSeeCount       (        );
		bool     setSelfSeeCount       ( int    );
		bool     selfClearCommand      (        );
		bool     selfClearMovePosition (        );
		bool 	 getSelfSynch 	       (        );
		Cycle    selfSeeUpdate         (        );
		AngDeg   selfSeeAngel          (        );
		bool     selfLocalization      (   Visual_Sensor &     );
		AngDeg   selfFaceAngelByLine   (   Visual_Sensor &     );
		AngDeg   selfFaceDirByFlag     (   Visual_Sensor &     );
		AngDeg   selfGetBodyByNeck     (      );
		bool     selfInitParse         ( string );
		bool     selfIsBallKickable    (        );
		HPlayer  getSelfType      (        );
};
#endif
