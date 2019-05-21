/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _COACH_
#define _COACH_

#include "../Skill/BasicSkill.h"
#include "../WorldModel/WorldModel.h"

#include <string>

extern WorldModel WM;

class Coach 
{
	private :	
		BasicSkill BS;
		bool setTypeFlag;
	public :
		Coach ();
		bool Init    ( char *teamname , float server );
		bool run     (                               );
		bool setType (                               );
		bool IsSetType ( );

};
#endif
