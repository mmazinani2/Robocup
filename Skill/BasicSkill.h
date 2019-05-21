/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _BASICSKILL_H
#define _BASICSKILL_H

#include <vector>
#include <string>
#include <sstream>
#include "../Commander/CommandQ.h"
#include "../WorldModel/WorldModel.h"
#include "../Types/SoccerTypes.h"
 
using namespace std;


typedef char * Char;
extern WorldModel WM;
extern CommandQ   CQ;

class BasicSkill 
{
	private :
		stringstream stst;
		char Message[MAX_SAY_MSG];
		CMD   Command;
	public :
		BasicSkill ( );
		Char Get_Skill ( );
		bool Make_Turn       	     ( float );
		bool Make_Turn_Neck 	     ( float );
		bool Make_Dash      	     ( float po,float Ang = 0);
		bool Make_SideDash         ( float , AngDeg  );
		bool Make_Kick       	     ( float , float );
		bool Make_Move       	     ( float , float );
		bool Make_Catch       	     ( float );
		bool Make_Say         	     ( Char  );
		bool Make_Change_View 	     ( ViewAngleT, ViewQualityT);
		bool Make_Pointto     	     ( float , float );
		bool Make_Tackl       	     ( float );
		bool Make_Attentionto        ( Char ,int  );
		bool Make_Change_Player_Type ( int ,int );
		bool Make_Sense_Body	     (             );
		bool Make_Init               ( Char , float ,bool );
		bool Make_Reconnect	     ( Char , int         );
		bool Make_Synch_See         ();
		bool Make_Bye 	      ();
		bool Make_Done              ();      /// (done)
		bool Make_Compression       ( int ); /// (compression <level>)
		bool Make_Score             (     ); /// (score)
		bool Make_ear               (     );
		CMD  getCommandType         (     );
			///<- (ear (<onoff> <side> <mode>))
  			///<- (ear (<onoff> <mode>))
  			///<- (ear (<onoff> <side>))
  			///<- (ear (<onoff>))
  			///<onoff> :- on | off
  			///<side> :- our | opp | left | l | right | r | TEAMNAME
  			///<mode> :- partial | p | complete | c
};


#endif
