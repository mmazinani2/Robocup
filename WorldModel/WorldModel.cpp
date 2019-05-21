/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "WorldModel.h"
extern CommandQ CQ;
WorldModel::WorldModel ( )
{
	GameTimer.startTime ();
	BodyTimer.startTime ();
	SyncTimer = new TimerSync();
	this->GameSync = false;
        this->LastACTVal.deleteAllItem();
}
Cycle WorldModel::getGameCycle    (       )
{
	return  GameCycle;
}
bool  WorldModel::getSyncTime()
{
  return this->GameSync;
}
bool  WorldModel::setSyncTime(bool sync)
{
  this->GameSync = sync;
}
bool  WorldModel::setGameCycle    ( Cycle cycle)
{
	GameCycle = cycle;
}
Timer WorldModel::getGameTimer    (       )
{
	return GameTimer;
}
_Self WorldModel::getSelf         ( )
{
	return SelfObj;
}
Body_Sensor WorldModel::getBodySensor   ( )
{
	return BodyData;
}
Server_param WorldModel::getServerParam  ( )
{
	return ServerData;
}
Player_param WorldModel::getPlayerParam  ( )
{
	return PlayerData;
}
Hetero_Player WorldModel::getHeteroType   ( )
{
	return HeteroData;
}
Audio_sensor WorldModel::getAudioSensor  ( )
{
	return AudioSensor;
}
Visual_Sensor WorldModel::getVisualSensor ( )
{
	return VisualSensor;
}
bool WorldModel::Update (string str)
{
    bool SeenFlag = false;
    if(getGameCycle() == 0)
        CQ.SetGameFlag(false);
	switch (str[3])
	{
		case 'i':
                        
 			SelfObj.selfInitParse ( str );
 			break;
		case 'r':
 			ServerData.Update ( str );	
 			//setGameCycle ( ServerData.TimeUpdate( ) );
			break;
		case 'a':
 			switch (str[2])
 			{
				case 'l' :
					switch (str[8])
					{
						case 't' :
							HeteroData.Update ( str );
			//				setGameCycle (HeteroData.TimeUpdate( ) );
							SelfObj.selfUpdateByType ( HeteroData );
							break;
						case 'p' :
							PlayerData.Update ( str );
							setGameCycle ( PlayerData.TimeUpdate( ) );
							break;
					}
					break;
				case 'e' :
					AudioSensor.Update ( str );
					SelfObj.selfUpdateByHear ( AudioSensor);

					//BallObj.ballUpdateByHear (SelfObj);
					UpdateBallByHear( );
					//setGameCycle ( AudioSensor.TimeUpdate( ));
					break;
				default :
				      #if 0	
					cerr << "ID : " <<
atoi(Parser().Pars_Space ( str, 2 ).c_str())
					     << "\tType : " <<
atoi(Parser().Pars_Space ( str, 3 ).c_str()) << endl;
				      #endif
					if (atoi(Parser().Pars_Space ( str, 2
).c_str()) == SelfObj.getObjectNumber() )
						SelfObj.setObjectType
(atoi(Parser().Pars_Space ( str, 3 ).c_str()));
					
					TeammateObject[atoi(Parser().Pars_Space
( str, 2 ).c_str())].setObjectType
								
(atoi(Parser().Pars_Space ( str, 3 ).c_str()));
					break;
 			}
			break;
		case 'e':
                        SeenFlag = true;
			//if ((RealTime(GetRealTime()).GetUsec()*0.0001) > 60 ) break;
			if (SyncTimer->getElapsedTimeInMilliSec() > 60)
			{
				//cerr << "lost update" << endl;
				setSyncTime(false);
				break;  			
			}
			setSyncTime(true);
			CQ.SetSeeFlag(false);
			VisualSensor.Update ( str , getGameCycle ( ));
			SelfObj.selfUpdateBySee (VisualSensor);
			//setGameCycle ( VisualSensor.TimeUpdate( ) );
			UpdateBallBySee ( );
			UpdateOtherPlayerBySee  ( ); 
			
			break;
		case 'n':
			//SyncTimer->stop();			
			SyncTimer->start();
			CQ.SetGameFlag(false);
			setSyncTime(false);
			//cerr << "Cycle : " << getGameCycle() << "  Time : " << BodyTimer.getTime() << endl; 
			BodyData.Update ( str );
			BodyTimer.resetTime ( );
			SelfObj.selfUpdateBySense ( BodyData );
			setGameCycle ( BodyData.TimeUpdate( ) );
			
			break;
		case ' ':
			if (str[4] == 's')
			{
				SelfObj.setSelfSynch ( true );
			}
			break;
		default :
			//cerr << "(WorldModel Update):: error int Parse --> " << str << endl;
			break;
	}
	if (getGameCycle ( ))
		GameTimer.Update ();
        if (!SeenFlag)
        {
            UpdateByAct();
        }
        _MapValue val;
        val.PAR1 = -1000;
        val.PAR2 = -1000;
        this->LastACTVal.Map_AddItem("DASH",val);
        this->LastACTVal.Map_AddItem("NECK",val);
        this->LastACTVal.Map_AddItem("BODY",val);
        this->LastACTVal.Map_AddItem("TACKLE",val);
        this->LastACTVal.Map_AddItem("MOVE",val);
        this->LastACTVal.Map_AddItem("KICK",val);
       
}
bool WorldModel::UpdateBallBySee ( )
{
	Iterator_Lib<BallInfo>  _ballInfo = VisualSensor.getIteratorBallInfo ( );
	BallInfo _tmpBall;
	BallInfo _BestBall;
	int Quality = 0;
        if ( _ballInfo.returnVector().size () > 0 )
        {
          _BestBall = _ballInfo.returnVector().back();
        }
	Vector2D vel;
	if (_BestBall.IsDynamic)
		vel  = vel.getVector2DFromPolar ( _BestBall.dist_chng, _BestBall.dir_chng );
	else	vel = BallObj.getBallVel (  );
	BallObj.setBallVel ( vel );
	BallObj.setBallSpeed ( vel.getMagnitude () );
	BallObj.setBallCountUpdate (BallObj.getBallCountUpdate() + 1);
	BallObj.setBallSeeUpdate ( getGameCycle ( ));
	BallObj.setBallRelativPosition ( Vector2D (_BestBall.Distance,_BestBall.Angle) );
	
	// cerr << "Quality : " << _BestBall.Quality << endl;
	if (_BestBall.Visible)
	{
		BallObj.setBallVisible(true);
		Vector2D vec = vec.getVector2DFromPolar ( _BestBall.Distance , _BestBall.Angle + SelfObj.getSelfNeck() );
		vec += SelfObj.getSelfGlobalPosition();
		BallObj.setBallGlobalPosition (vec);
		#if 0
			cerr << "Real Ball X : " << vec.getX() << "\tReal Ball Y : " << vec.getY() << endl;
		#endif
	}
	else 
	{
		BallObj.setBallVisible(false);
		Vector2D vec  = getBallPositionAfterCycle (( getGameCycle() - _BestBall.SeeTime),vel);
		BallObj.setBallGlobalPosition (vec);
		#if 0
			cerr << "Per Ball X : " << vec.getX() << "\tPer Ball Y : " << vec.getY() << endl;
		#endif
	}
}
bool WorldModel::UpdateBallByHear( )
{

}
Vector2D WorldModel::getBallPositionAfterCycle    ( Cycle cycle, Vector2D vel)
{
	Vector2D BallPos = BallObj.getBallGlobalPosition ();
	Vector2D BallVel = vel;
	const double p_x = (PITCH_LENGTH/2) + 5.0;
	const double p_y = (PITCH_WIDTH/2) + 5.0;
	for (int CycleCount = 1 ; CycleCount <= cycle; CycleCount++)
	{
		//cerr << "Ball Vel ===============>  " << BallVel.getMagnitude () << endl;
		BallPos += BallVel;
		BallVel *= ServerData.get_ball_decay();
		if (fabs (BallPos.getX()) > p_x ||
				fabs (BallPos.getX()) > p_y)
		{
			return BallPos;
		}
		if (CycleCount >= 5 && BallVel.getMagnitude() < 0.01*0.01)
		{
			return BallPos + BallVel;
		}
	}
	return BallPos;
}
bool WorldModel::setSelfBodyByCommand ( double ang)
{
      SelfObj.setSelfBody (ang);
}
bool WorldModel::setSelfNeckByCommand ( double ang)
{
      SelfObj.setSelfNeck (ang);
}
_Ball WorldModel::getBall ( )
{
	return BallObj;
}
_PlayerObject WorldModel::getTeammateById ( int Index)
{
	Index = min (Index,11);
	return TeammateObject [Index];
}
_PlayerObject WorldModel::getOpponentById ( int Index)
{
	Index = min (Index,11);
	return OpponentObject [Index];
}
vector <_PlayerObject> WorldModel::getItrTeammates  ( bool visi, double quality)
{
	vector <_PlayerObject> tmpList;
	tmpList.clear();
	for (int ObjectCounter = 0; ObjectCounter <= MAX_PLAYER_SIZE; ObjectCounter++)
	{
	    if (visi == getTeammateById (ObjectCounter).getObjectVisible ( ) && quality <= getTeammateById (ObjectCounter).getObjectQuality ())
	    {
	      tmpList.push_back(getTeammateById (ObjectCounter));
	    }
	}
	return tmpList;
}
vector <_PlayerObject> WorldModel::getItrOpponents     ( bool visi, double quality)
{
	vector <_PlayerObject> tmpList;
	tmpList.clear();
	for (int ObjectCounter = 0; ObjectCounter <= MAX_PLAYER_SIZE; ObjectCounter++)
	{
	    if (visi == getOpponentById (ObjectCounter).getObjectVisible ( ) && quality <= getOpponentById (ObjectCounter).getObjectQuality ())
	    {
	      tmpList.push_back(getOpponentById (ObjectCounter));
	    }
	}
	return tmpList;
}
vector <_PlayerObject> WorldModel::getItrUnknownObject ( bool visi, double quality)
{

}
bool WorldModel::PredictUnknownPlayer (   )
{

}
bool WorldModel::UpdateOtherPlayerBySee  ( )
{
	//cerr << "OK 1" << endl;
	Iterator_Lib<PlayerInfo> unknowninfo = VisualSensor.getIteratorUnknownInfo   ( );
	//cerr << "OK 2" << endl;
	for (int AgentC = 1 ; AgentC <= 11; AgentC++)
	{
		OpponentObject[AgentC].setObjectVisible    ( false );
		TeammateObject[AgentC].setObjectVisible    ( false );
	}	
	//cerr << "OK 3" << endl;
	for (int AgentCount = 1 ; AgentCount <= 11; AgentCount++)
	{
		PlayerInfo _BestOpp = VisualSensor.getPlayerOpponentById ( PlayerT (AgentCount+11) );
		PlayerInfo _BestTmm = VisualSensor.getPlayerTeammateById ( PlayerT (  AgentCount ) );
		if ( _BestOpp.IDPlayer != PT_UNKNOWN )
		{
			if ( SelfObj.getObjectSide () == SIDE_LEFT )
				OpponentObject[AgentCount].setObjectSide( SIDE_RIGHT );
			else OpponentObject[AgentCount].setObjectSide( SIDE_LEFT );
			
			OpponentObject[AgentCount].setObjectNumber  (   AgentCount    );
			OpponentObject[AgentCount].setObjectIsGoali ( _BestOpp.goalie );
			OpponentObject[AgentCount].setObjectPlayerID ( _BestOpp.IDPlayer );
			OpponentObject[AgentCount].setObjectQuality    ( _BestOpp.Quality  );
			OpponentObject[AgentCount].setObjectVisible    ( true );
			OpponentObject[AgentCount].setObjectSeeTime  ( getGameCycle () );
			Vector2D vel;
			if (_BestOpp.IsDynamic)
				vel  = vel.getVector2DFromPolar ( _BestOpp.dist_chng, _BestOpp.dir_chng );
			else	vel = OpponentObject[AgentCount].getObjectVel (  );
			
			OpponentObject[AgentCount].setObjectVel  ( vel );
			OpponentObject[AgentCount].setObjectVelDistance    ( vel.getMagnitude () );
			OpponentObject[AgentCount].setObjectBodyAngle      ( _BestOpp.BodyAngle );
			OpponentObject[AgentCount].setObjectNeckAngle	   ( _BestOpp.NeckAngle  );
			
			if (_BestOpp.Quality > 8)
			{
				float mx,mn;
				Localization().quantizeRange((float)_BestOpp.Distance ,mn,mx);
				float mid = (mn - mx )/2;
				Vector2D vec = vec.getVector2DFromPolar (  (mn+mx)/2,
						 _BestOpp.Angle + SelfObj.getSelfNeck() );
				vec += SelfObj.getSelfGlobalPosition();
				OpponentObject[AgentCount].setObjectSeePosition (Vector2D(vec.getX()-mid,vec.getY()-mid));
				//cerr <<AgentCount <<endl;
			}
			else
			{
				Vector2D vec = 
				   getPlayerPositionAfterCycle ( OpponentObject[AgentCount],
						( getGameCycle() - _BestOpp.SeeTime),vel );
				OpponentObject[AgentCount].setObjectSeePosition (vec);
			}
			OpponentObject[AgentCount].setObjectGlobalPosition 
						( OpponentObject[AgentCount].getObjectSeePosition () );
			OpponentObject[AgentCount].setObjectBallDistance   
					( BallObj.getBallGlobalPosition ().getDistanceTo
						 (OpponentObject[AgentCount].getObjectSeePosition ())  );
		}
		if ( _BestTmm.IDPlayer != PT_UNKNOWN )
		{
			//cerr << "OKK Parser" << AgentCount << endl;
			TeammateObject[AgentCount].setObjectSide( SelfObj.getObjectSide () );
			TeammateObject[AgentCount].setObjectNumber   (     AgentCount    );
			TeammateObject[AgentCount].setObjectIsGoali  (  _BestTmm.goalie  );
			TeammateObject[AgentCount].setObjectPlayerID ( _BestTmm.IDPlayer );
			TeammateObject[AgentCount].setObjectSeeTime  ( getGameCycle () );
			Vector2D vel;
			Vector2D vec;
			if (_BestTmm.IsDynamic)
				vel  = vel.getVector2DFromPolar ( _BestTmm.dist_chng, _BestTmm.dir_chng );
			else	vel = TeammateObject[AgentCount].getObjectVel (  );
			TeammateObject[AgentCount].setObjectQuality    ( _BestTmm.Quality  );
			TeammateObject[AgentCount].setObjectVisible    ( true );
			TeammateObject[AgentCount].setObjectVel  ( vel );
			TeammateObject[AgentCount].setObjectVelDistance    ( vel.getMagnitude () );
			TeammateObject[AgentCount].setObjectBodyAngle      ( _BestOpp.BodyAngle );
			TeammateObject[AgentCount].setObjectNeckAngle	   ( _BestOpp.NeckAngle  );
			
			if (_BestTmm.Quality > 8)
			{
				float mx,mn;
				Localization().quantizeRange((float)_BestTmm.Distance ,mn,mx);
				float mid = (mn - mx )/2;
				vec = vec.getVector2DFromPolar (  (mn+mx)/2,
						 _BestTmm.Angle + SelfObj.getSelfNeck() );
				vec += SelfObj.getSelfGlobalPosition();
			
TeammateObject[AgentCount].setObjectSeePosition(Vector2D(vec.getX()-mid,vec.getY
()-mid));
			
			}
			else
			{
				vec = 
				   getPlayerPositionAfterCycle ( TeammateObject[AgentCount],
						( getGameCycle() - _BestTmm.SeeTime),vel );
				TeammateObject[AgentCount].setObjectSeePosition (vec);
				TeammateObject[AgentCount].setObjectSeePosition (vec);
			}
			TeammateObject[AgentCount].setObjectGlobalPosition 
						( TeammateObject[AgentCount].getObjectSeePosition () );
			TeammateObject[AgentCount].setObjectBallDistance
					( BallObj.getBallGlobalPosition ().getDistanceTo
						 (TeammateObject[AgentCount].getObjectSeePosition ())  );
		}
	}
	//cerr << "OK 4" << endl;
	UnknownObject.clear ();
	_PlayerObject tmpUnknown;
	vector <PlayerInfo> :: iterator it = unknowninfo.returnVector().begin ();
	for (it;it!=unknowninfo.returnVector().end (); it++)
	{
		Vector2D vec = vec.getVector2DFromPolar ( it->Distance ,
						 it->Angle + SelfObj.getSelfNeck() );
		vec += SelfObj.getSelfGlobalPosition();
		tmpUnknown.setObjectSeePosition (vec);
		UnknownObject.push_back(tmpUnknown);
	}
	//cerr << "OK 5" << endl;
}
bool WorldModel::UpdateOtherPlayerByHear ( )
{

}
Vector2D WorldModel::getPlayerPositionAfterCycle    ( _PlayerObject Pt,Cycle cycle, Vector2D vel)
{
	Vector2D ObjPos = Pt.getObjectSeePosition ();
	Vector2D ObjVel = vel;
	const double p_x = (PITCH_LENGTH/2) + 5.0;
	const double p_y = (PITCH_WIDTH/2) + 5.0;
	for (int CycleCount = 1 ; CycleCount <= cycle; CycleCount++)
	{
		//cerr << "Ball Vel ===============>  " << BallVel.getMagnitude () << endl;
		ObjPos += ObjVel;
		ObjVel *= ServerData.get_player_decay();
		if (fabs (ObjPos.getX()) > p_x ||
				fabs (ObjPos.getX()) > p_y)
		{
			return ObjPos;
		}
		if (CycleCount >= 5 && ObjVel.getMagnitude() < 0.01*0.01)
		{
			return ObjPos + ObjVel;
		}
	}
	return ObjPos;
}
bool  WorldModel::UpdateByAct ()
{
    SelfObj.setUpdateByAct(this->LastACTVal);
}
bool  WorldModel::SetValByAct ( string key, _MapValue val)
{
    this->LastACTVal.Map_AddItem(key,val);
}
