/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Loger.h"
#include <fstream>
#include <time.h>
#include <exception>

Log::Log (  )
{
    init ();
}
void Log::setPNUM         (int pnum)
{
    this->num = pnum;
}
void Log::init       ( )
{
    myfile.open("GameLog.mars",ios_base::app);
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    myfile << "(Init Log " << num << " : " << asctime (timeinfo)  << " )" << endl;
}
void Log::Clear	( )
{
    LogData.clear();
}
void Log::close      ( )
{
  

    myfile << "(EOF " << num << " ) " << endl;
    
    myfile.close();
}
void Log::writelog   (int TCycle,string strData)
{
  try
    {
	myfile << "  [n l r " << num << " : " <<  TCycle << " : " <<  strData << "]" << endl;
    }
  catch (...)
    {
	myfile << "(*** Warning *** Mars Loger Error 77690)" << endl;
    }
}
