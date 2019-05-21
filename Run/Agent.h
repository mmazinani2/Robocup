/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _AGENT_
#define _AGENT_

#include "../WorldModel/WorldModel.h"
#include "../Skill/AdvancedSkill.h"
#include "../Formation/FileReader.h"
#include <iostream>
#include <string>
#include "../Loger/Loger.h"

using namespace std;

extern WorldModel WM;
class Agent  
{
	private :
		BasicSkill BS;
		AdvancedSkill AS;
		bool bufAng;
		Log *log;
	public :
		Agent ( );
		bool Init (char *,float,bool);
		virtual bool run  (                  );
		bool GoToBeforKickOff ( _Self & );
		bool TurnBeforKickOff ( );
};
#endif
