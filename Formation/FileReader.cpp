/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "FileReader.h"

FileReader::FileReader ( )
{
	cash_Data.clear ( );
}
bool FileReader::readStaticFile ( string strPath )
{
	ifstream iFile( strPath.c_str() , ios::in );
	posStr m_str;
	string data;

	while (! iFile.eof())
	{
		iFile >> data;
		m_str.uniNum = atoi(data.c_str());
		iFile >> data;
		m_str.posX = atof(data.c_str());
		iFile >> data;
		m_str.posY = atof(data.c_str());
		
		cash_Data.push_back(m_str);
	}
	return true;
}
bool FileReader::clearCash (                )
{
	cash_Data.clear ( );
}
vector <posStr> FileReader::getCash (            )
{
	return cash_Data;
}
