/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Timer.h"

timeval RealTime::mStartTime = GetRealTime();
const long RealTime::ONE_MILLION = 1000000;

timeval GetRealTime()
{
    timeval time_val;
    gettimeofday(&time_val, NULL);
    return time_val;
}

Timer::Timer ( )
{
	this->stopFlag = true;
	this->newTime = 0;
	this->lastTime = 0;
	this->Synch_Time = 0;
}
Timer::Timer ( _Time tm)
{
	this->stopFlag = true;
	this->newTime = tm;
	this->lastTime = 0;
	this->Synch_Time = 0;
}
bool Timer::Update (       )
{
	if (!stopFlag) 
	{
		timeval now;
		gettimeofday(&now, NULL);
		this->setLastTime ( this->newTime );
		this->setTime ( static_cast<long>(((now.tv_usec - this->start.tv_usec) / 1000.0 + 
			(now.tv_sec - this->start.tv_sec) * 1000) + 0.5) );
		return true;
	}
	else
	{
		return false;
	}
}
long  Timer::getStartTime ( )
{
	return static_cast<long>(this->start.tv_usec);
}
_Time Timer::Diff_Time ( )
{
	return static_cast<_Time>(fabs(this->lastTime - this->newTime));
}
bool Timer::isTimeUpdate ( )
{
	return (this->Diff_Time() > 1);
}
_Time Timer::getTimeCycle( )
{
	
	return (isTimeUpdate ( ))?++this->Synch_Time:this->Synch_Time;
}
bool Timer::moveTime ( )
{
	this->Synch_Time++;
}
bool Timer::backTime ( )
{
	this->Synch_Time--;
}
bool Timer::resetTime (       )
{
	gettimeofday(&start, NULL);
}
bool Timer::setLastTime ( _Time tm )
{
	this->lastTime = tm;
}
bool Timer::setTime ( _Time tm )
{
	this->newTime = tm;
}
_Time Timer::getTime (       )
{
	return this->newTime;	
}
bool Timer::stopTime ( )
{
	this->stopFlag = true;
}
bool Timer::startTime ( )
{
	this->stopFlag = false;
	gettimeofday(&start, NULL);
}

RealTime RealTime::operator + (const RealTime &t) const
{
    if (GetUsec() + t.GetUsec() >= ONE_MILLION)
    {
        return RealTime(GetSec() + t.GetSec() + 1, GetUsec() + t.GetUsec() - ONE_MILLION);
    }
    else
    {
        return RealTime(GetSec() + t.GetSec(), GetUsec() + t.GetUsec());
    }
}


RealTime RealTime::operator + (int msec) const
{
    int usec = GetUsec() + msec * 1000;
    if (usec >= ONE_MILLION)
    {
        return RealTime(GetSec() + usec / ONE_MILLION, usec % ONE_MILLION );
    }
    else
    {
        return RealTime(GetSec(), usec);
    }
}


RealTime RealTime::operator - (int msec) const
{
    int usec = GetUsec() - msec * 1000;
    if(usec < 0)
    {
        usec = -usec;
        return RealTime(GetSec() - usec / ONE_MILLION - 1, ONE_MILLION - usec % ONE_MILLION );
    }
    else
    {
        return RealTime(GetSec(), usec);
    }
}


int RealTime::operator - (const RealTime &t) const
{
    return (GetSec() - t.GetSec()) * 1000 + int((GetUsec() - t.GetUsec()) / 1000.0);
}


long RealTime::Sub(const RealTime &t)
{
    return (GetSec() - t.GetSec()) * 1000000 + GetUsec() - t.GetUsec();
}


bool RealTime::operator < (const RealTime &t) const
{
    if (GetSec() < t.GetSec())
        return true;
    if (GetSec() == t.GetSec() && GetUsec() < t.GetUsec())
        return true;
    return false;
}


bool RealTime::operator > (const RealTime &t) const
{
    if (GetSec() > t.GetSec())
        return true;
    if (GetSec() == t.GetSec() && GetUsec() > t.GetUsec())
        return true;
    return false;
}


bool RealTime::operator == (const RealTime &t) const
{
    if(GetSec() == t.GetSec() && GetUsec() == t.GetUsec())
        return true;
    return false;
}


bool RealTime::operator != (const RealTime &t) const
{
    if(GetSec() == t.GetSec() && GetUsec() == t.GetUsec())
        return false;
    return true;
}


std::ostream & operator << (std::ostream &os, RealTime t)
{
    return os << t - RealTime::mStartTime;
}

Time Time::operator-(const int a) const
{
    int news = S() - a;
    if( news >= 0 )
    {
        return Time(T(), news);
    }
    return Time(T() + news, 0);
}


int Time::operator-(const Time &a) const
{
    if(mT == a.T())
    {
        return  mS - a.S();
    }
    else
    {
        return mT - a.T() + mS;
    }
}

#if 0
int main ( )
{
	Timer T;
	T.startTime ( );
	for (int i = 0 ; i <= 60000; i++)
		T.Update ();
	cout << T.getTime () << endl;
	return 0;
}
#endif
