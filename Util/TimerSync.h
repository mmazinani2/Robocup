/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef TIMER_SYNC_H_
#define TIMER_SYNC_H_
#ifdef WIN32
      #include <windows.h>
#else
      #include <sys/time.h>
#endif
class TimerSync
{
public:
 	     TimerSync();
 	     ~TimerSync();
 	     void start();
 	     void stop();
 	     double getElapsedTime();
 	     double getElapsedTimeInSec();
 	     double getElapsedTimeInMilliSec();
 	     double getElapsedTimeInMicroSec();
      private:
 	     double startTimeInMicroSec;
 	     double endTimeInMicroSec;
 	     int stopped;
 	     #ifdef WIN32
 		     LARGE_INTEGER frequency;
 		     LARGE_INTEGER startCount;
 		     LARGE_INTEGER endCount;
 	     #else
 		     timeval startCount;
 		     timeval endCount;
 	     #endif
};

#endif
