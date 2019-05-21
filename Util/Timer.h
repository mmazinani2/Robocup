/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _TIMER_H
#define _TIMER_H

#include <sys/time.h>
#include <cmath>
#include <iostream>

using namespace std;

timeval GetRealTime();
timeval GetRealTimeParser();
timeval GetRealTimeDecision();
timeval GetRealTimeCommandSend();

class RealTime
{
public:
	explicit RealTime(long tv_sec = 0, long tv_usec = 0) {
		mTime.tv_sec = tv_sec;
		mTime.tv_usec = tv_usec;
	}

	RealTime(const timeval &t): mTime(t) { }

	timeval GetTime() const { return mTime; }
	long GetSec() const { return mTime.tv_sec; }
	long GetUsec() const { return mTime.tv_usec; }

	const RealTime & operator = (const timeval &t) { mTime = t; return *this; }
	RealTime operator + (const RealTime &t) const;
	RealTime operator + (int msec) const;
	RealTime operator - (int msec) const;
	int operator - (const RealTime &t) const;
	long Sub( const RealTime &t);

	bool operator < (const RealTime &t) const;
	bool operator > (const RealTime &t) const;
	bool operator == (const RealTime &t) const;
	bool operator != (const RealTime &t) const;

	friend std::ostream & operator << (std::ostream &os, RealTime t);

private:
	timeval mTime;

	static timeval mStartTime;
	static const long ONE_MILLION;
};

class Time
{
public:
	explicit Time(int t = -3, int s = 0): mT(t), mS(s) {}

	int T() const { return mT; }
	int S() const { return mS; }
	void SetT(int t) { mT = t; }
	void SetS(int s) { mS = s; }

	const Time & operator=(const int a) { mT = a;  mS = 0; return *this; }
	Time operator+(const int a) const { return Time(mT + a, 0); }
	Time operator-(const int a) const;
	int operator-(const Time &a) const;

	void operator+=(const int a) { *this = *this + a; }
	void operator-=(const int a) { *this = *this - a; }
	void operator-=(const Time &a) { *this = *this - a; }
	const Time & operator++() { *this += 1; return *this; }
	const Time & operator--() { *this -= 1; return *this; }
	int operator%(const int a) const { return (mT + mS) % a; }

	bool operator==(const Time &a) const { return (mS == a.S()) && (mT == a.T()); }
	bool operator!=(const Time &a) const { return (mS != a.S()) || (mT != a.T()); }
	bool operator<(const Time &a) const { return (mT < a.T()) || (mT == a.T() && mS < a.S()); }
	bool operator<=(const Time &a) const { return (mT < a.T()) || ( mT == a.T() && mS <= a.S()); }
	bool operator>(const Time &a) const { return (mT > a.T()) || (mT == a.T() && mS > a.S()); }
	bool operator>=(const Time &a) const { return (mT > a.T()) || (mT == a.T() && mS >= a.S()); }
	bool operator!() const { return (mS == 0) && (mT == 0); }
	friend std::ostream & operator<<(std::ostream & os, const Time& t) { return os << '(' << t.T() << ':' << t.S() << ')'; }

private:
	int mT;
	int mS;
};

typedef long _Time;
class Timer 
{
	private :
		_Time newTime;
		_Time lastTime;
		_Time Synch_Time;
		timeval start;
		bool stopFlag;
	public :
		Timer             (       );
		Timer             ( _Time );
		long  getStartTime(       );
		bool  moveTime    (       );
		bool  backTime    (       );
		bool  Update      (       );
		bool  resetTime   (       );
		bool  setTime     ( _Time );
		bool  setLastTime ( _Time );
		_Time Diff_Time   (       );
		_Time getTime     (       );
		bool  isTimeUpdate(       );
		_Time getTimeCycle(       );
		bool  stopTime    (       );
		bool  startTime   (       );
};
#endif
