/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _LOGER_
#define _LOGER_

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <map>
#include <fstream>
using namespace std;

class Log
{
	public :
		Log (  );
		void init       ( );
		void Clear	( );
		void close      ( );
		void writelog   (int,string);
		void setPNUM (int);
		
	private :
	    multimap <int,string> LogData; 
	    ofstream myfile;
	    int num;
};
#endif
