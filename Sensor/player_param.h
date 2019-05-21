/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _PLAYER_PARAM
#define _PLAYER_PARAM

#include "../Util/MapLib.h"
#include "../Parser/ParseServer.h"
#include "../Types/SoccerTypes.h"

#include <stdlib.h>
#include <string.h>
#include <string>

class Player_param
{
	private :
		MapLib<string> PlayerData;
		
		bool         UpdatePlayer;
		int          UpdateTime;
	public :
		Player_param          (        );
		string getPlayerData  ( string );
		virtual bool Update   ( string );
		virtual bool isUpdate (        )
		{
			return UpdatePlayer;
		}
		virtual int TimeUpdate (       )
		{
			return UpdateTime;
		}
		virtual bool reset    (        )
		{
			UpdatePlayer = false;
		}
		virtual bool show ( );
		int 	get_subs_max ();
		int 	get_stamina_inc_max_delta_factor  ();
		int 	get_random_seed  ();
		int 	get_pt_max  ();
		int 	get_player_types  ();
		int 	get_player_speed_max_delta_min ();
		int 	get_player_speed_max_delta_max ();
		int 	get_player_size_delta_factor ();
		double 	get_player_decay_delta_min ();
		double  get_player_decay_delta_max ();
		int 	get_new_stamina_inc_max_delta_factor ();
		double  get_new_dash_power_rate_delta_min ();
		double  get_new_dash_power_rate_delta_max ();
		double  get_kickable_margin_delta_min ();
		double  get_kickable_margin_delta_max ();
		int 	get_kick_rand_delta_factor ();
		int 	get_inertia_moment_delta_factor ();
		int 	get_extra_stamina_delta_min ();
		int 	get_extra_stamina_delta_max ();
		double  get_effort_min_delta_factor ();
		double  get_effort_max_delta_factor ();
		int 	get_dash_power_rate_delta_min ();
		int 	get_dash_power_rate_delta_max ();
		int 	get_allow_mult_default_type ();
                double  get_kick_power_rate_delta_min ();
                double  get_kick_power_rate_delta_max ();
                double  get_foul_detect_probability_delta_factor ();
                double  get_catchable_area_l_stretch_min ();
                double  get_catchable_area_l_stretch_max ();

};
#endif
