/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Agent.h"
#include "../GameModel/DynamicModel.h"
#include "../GameModel/SelfModel.h"
#include "../Skill/TurnBody.h"
#include <math.h>

using namespace std; 
Agent::Agent ( )
{
	//bufAng = true;
}
bool Agent::Init (char *teamname,float server,bool IsGoali)
{
	log = new Log();
	WM.setSelfIsGoali ( IsGoali );
	BS.Make_Init (teamname,server,IsGoali);
	
	return true;

}
bool Agent::run  (                  )
{
	 
        _Self s = WM.getSelf ();
	log->setPNUM(WM.getSelf().getObjectNumber());
	log->init();
        if (WM.getGameCycle () == 0 )
          GoToBeforKickOff (s);
	if (!WM.getSelf ().getSelfSynch ())
		return BS.Make_Synch_See ();
	_Self self = WM.getSelf (  );
	_Ball ball = WM.getBall (  );
	Vector2D posAgent = self.getSelfGlobalPosition();
	if (WM.getGameCycle () >= 11 )
	{
	  
	  #if 0 // GOOOOOOOOOOOOOOOOOOOOOOOODD
	   if (ball.getBallGlobalPosition ().getX() > 40.0)
	   {
	      //cerr << "get Ball Y : " << ball.getBallGlobalPosition ().getY() << endl;
	      log->write(WM.getGameCycle(),"test OK");
	   }
	  #endif
	  //if (!AS.SearchBall ())
	    if (!TurnBody().TurnBodyToPoint (Vector2D(50.0,0),self.getSelfSpeed()))
	    {
	        Vector2D BallVel = ball.getBallVel();
		Vector2D BallPos = (ball.getBallGlobalPosition ());
		
		if (self.getSelfGlobalPosition ().getDistanceTo (Vector2D(50.0,0)) >= 0.7 )//&& self.getObjectNumber() == 1)
			BS.Make_Dash(100.0);
		else //if (self.getObjectNumber() == 1)
		{
			  AS.KickToPoistion(Vector2D (52.0,0.0),100);
		}
                //cerr << "BALL POSITION : "<< ball.getBallGlobalPosition().getX() << "," << ball.getBallGlobalPosition().getY() << endl; 
	    }
	}
	
}
bool Agent::GoToBeforKickOff ( _Self & self )
{
	FileReader FR;
	vector <posStr> tmp;
	tmp.clear ( );
	FR.readStaticFile ( "Data//befor_kick_off.txt");
	tmp = FR.getCash ( );
	if ( self.getSelfGlobalPosition ().getDistanceTo (
			Vector2D (tmp[self.getObjectNumber ()-1].posX,tmp[self.getObjectNumber ()-1].posY)) >= 2)
		return BS.Make_Move (tmp[self.getObjectNumber ()-1].posX,tmp[self.getObjectNumber ()-1].posY);
	return false;
}
bool Agent::TurnBeforKickOff ( )
{
	return BS.Make_Turn (40.0);
}
