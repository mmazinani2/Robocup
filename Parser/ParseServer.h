/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _PARSESERVER_
#define _PARSESERVER_

#include <string>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class Parser
{
	public :
		Parser ( );
		int    Pars_Value_Count ( string );
		string Pars_Value ( string ,int );
		int    Pars_Space_Count ( string);
		string Pars_Space ( string ,int );
		string Mid_Str (string, int, int);
};

#endif
