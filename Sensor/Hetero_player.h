/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _HETERO_PLAYER
#define _HETERO_PLAYER

#include "../Util/IteratorLib.h"
#include "../Parser/ParseServer.h"
#include "../Types/SoccerTypes.h"

#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

typedef struct _HeteroPlayers
{
	int    id;
	double player_speed_max;
	double stamina_inc_max;
	double player_decay;
	double inertia_moment;
	double dash_power_rate;
	double player_size;
	double kickable_margin;
	double kick_rand;
	double extra_stamina;
	double effort_max;
	double effort_min;
	double speed_real;
	double kick_power_rate;
	double foul_detect_probability;
	double catchable_area_l_stretch;
}HPlayer;
class HPCmpBykickpower
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.foul_detect_probability <
                                      rhs.foul_detect_probability;
	}
};
class HPCmpByfouldetect
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.foul_detect_probability <
                                                    rhs.foul_detect_probability;
	}
};
class HPCmpBycatchablearea
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.catchable_area_l_stretch <
                                              rhs.catchable_area_l_stretch;
	}
};
class HPCmpById
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.id < rhs.id;
	}
};

class HPCmpByPlayerSpeedMax
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.player_speed_max < rhs.player_speed_max;
	}
};

class HPCmpByStaminaIncMax
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.stamina_inc_max < rhs.stamina_inc_max;
	}
};

class HPCmpByPlayerDecay
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.player_decay < rhs.player_decay;
	}
};

class HPCmpByInertiaMoment
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.inertia_moment < rhs.inertia_moment;
	}
};

class HPCmpByDashPowerRate
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.dash_power_rate < rhs.dash_power_rate;
	}
};

class HPCmpByPlayerSize
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.player_size < rhs.player_size;
	}
};

class HPCmpByKickableMargin
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.kickable_margin < rhs.kickable_margin;
	}
};

class HPCmpByKickRand
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.kick_rand < rhs.kick_rand;
	}
};


class HPCmpByExtraStamina
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.extra_stamina < rhs.extra_stamina;
	}
};

class HPCmpByEffortMax
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.effort_max < rhs.effort_max;
	}
};

class HPCmpByEffortMin
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.effort_min < rhs.effort_min;
	}
};
class HPCmpBySpeedReal
	: public std::binary_function< HPlayer, HPlayer, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.speed_real > rhs.speed_real;
	}
};
class Hetero_Player
{
	private :
		vector<HPlayer> HeteroList;
		
		bool     UpdateHetero;
		int      UpdateTime;
		
	public  :
		Hetero_Player  ( );
		virtual bool Update ( string );
		virtual bool isUpdate ( )
		{
			return UpdateHetero;
		}
		virtual int TimeUpdate (       )
		{
			return UpdateTime;
		}
		virtual bool reset    (        )
		{
			UpdateHetero = false;
		}
		double ComputeSpeedReal ( double maxPower, double dashPowerRate, double effortMax, double PlayerDecay )
		{
			return (maxPower*dashPowerRate*effortMax)/(1-PlayerDecay);
		}
		bool setSpeedReal ( )
		{
			int it = HeteroList.size ( );
			for (int Loop = 0 ; Loop < it; Loop++)
				HeteroList[Loop].speed_real = ComputeSpeedReal(100.00,
									       HeteroList[Loop].dash_power_rate,
									       HeteroList[Loop].effort_max,
									       HeteroList[Loop].player_decay);
		}
		bool sortBySpeedReal ( );
		bool sortById  ( );
		bool sortByPlayerSpeedMax  ( );
		bool sortByStaminaIncMax  ( );
		bool sortByPlayerDecay  ( );
		bool sortByInertiaMoment  ( );
		bool sortByDashPowerRate  ( );
		bool sortByPlayerSize  ( );
		bool sortByKickableMargin  ( );
		bool sortByKickRand  ( );
		bool sortByExtraStamina  ( );
		bool sortByEffortMax  ( );
		bool sortByEffortMin  ( );
                bool sortBykickpower  ( );
                bool sortByfouldetect  ( );
                bool sortBycatchablearea  ( );
                vector<HPlayer>  getHeteroPlayer ( );
		HPlayer getTypeByID ( int );
		virtual bool show ();
		int  getHeteroCount   ( );
};
#endif
