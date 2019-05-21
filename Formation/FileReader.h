/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _FILEREADER_
#define _FILEREADER_

#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

struct posStr
{
	int uniNum;
	double posX;
	double posY;

	posStr ():uniNum(0)
		  ,posX(0.0000)
		  ,posY(0.0000)
	{ };
};
class FileReader
{
	private :
		vector <posStr> cash_Data;
		string filePath;
	public :
		FileReader ( );
		bool readStaticFile ( string strPath );
		bool clearCash      (                );
		vector <posStr> getCash (            );
};
#endif
