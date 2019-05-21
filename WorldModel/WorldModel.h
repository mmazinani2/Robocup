/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _WORLDMODEL_
#define _WORLDMODEL_

#include "../Geometry/Geometry.h"
#include "../Types/SoccerTypes.h"
#include "../Util/IteratorLib.h"
#include "../Util/Timer.h"
#include "../Commander/CommandQ.h"
#include "../Util/TimerSync.h"
#include "Self.h"
#include "Ball.h"

#include <string>
using namespace std;

#define MAX_PLAYER_SIZE 12

class WorldModel 
{
	private :
		Body_Sensor   BodyData;
		Server_param  ServerData;
		Player_param  PlayerData;
		Hetero_Player HeteroData;
		Audio_sensor  AudioSensor;
		Visual_Sensor VisualSensor;
		_Self         SelfObj;
		_Ball         BallObj;
		Timer         GameTimer;
		bool	      GameSync;
		Cycle         GameCycle;
		Cycle         TurnCycle;
		Cycle         KickCycle;
		_PlayerObject TeammateObject [MAX_PLAYER_SIZE];
		_PlayerObject OpponentObject [MAX_PLAYER_SIZE];
		vector  <_PlayerObject> UnknownObject;
                MapLib <_MapValue>     LastACTVal;
                
	public :
		WorldModel ( );
		Timer         BodyTimer;
		TimerSync     *SyncTimer;		
		virtual bool   Update ( string );
                bool           UpdateByAct ();
                bool           SetValByAct ( string , _MapValue );
		bool           UpdateBallBySee ( );
		bool           UpdateBallByHear( );
		bool           getSyncTime();
		bool	       setSyncTime(bool sync);
		bool           UpdateOtherPlayerBySee  ( );
		bool           UpdateOtherPlayerByHear ( );
		bool           setSelfBodyByCommand ( double );
		bool           setSelfNeckByCommand ( double );
		Cycle          getGameCycle    (       );
		bool           setGameCycle    ( Cycle );
		bool           setTurn_Cycle   ( Cycle c ) {TurnCycle = c;}
		Cycle          getTurn_Cycle   (         ) {return TurnCycle;}
		bool           setKick_Cycle   ( Cycle c ) {KickCycle = c;}
		Cycle          getKick_Cycle   (         ) {return KickCycle;}
		Timer          getGameTimer    (       );
		
		
		_Self          getSelf         ( );
		Body_Sensor    getBodySensor   ( );
		Server_param   getServerParam  ( );
		Player_param   getPlayerParam  ( );
		Hetero_Player  getHeteroType   ( );
		Audio_sensor   getAudioSensor  ( );
		Visual_Sensor  getVisualSensor ( );
		_Ball          getBall         ( );
		
		_PlayerObject  getTeammateById ( int );
		_PlayerObject  getOpponentById ( int );
		vector <_PlayerObject> getItrTeammates     ( bool , double );
		vector <_PlayerObject> getItrOpponents     ( bool , double );
		vector <_PlayerObject> getItrUnknownObject ( bool , double );
		
		bool  PredictUnknownPlayer                 (               );
		
		Vector2D       getBallPositionAfterCycle    ( Cycle , Vector2D );
		Vector2D       getPlayerPositionAfterCycle  ( _PlayerObject,Cycle , Vector2D );
		

		bool           setSelfIsGoali ( bool flag ) {SelfObj.setObjectIsGoali ( flag );}
};
extern WorldModel WM;
#endif
