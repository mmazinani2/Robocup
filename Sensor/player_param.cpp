/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "player_param.h"

Player_param::Player_param ( ):UpdatePlayer ( false )
			      ,UpdateTime ( 0  )
{
	PlayerData.deleteAllItem ();
}
bool Player_param::Update ( string strData)
{
	strData = Parser().Mid_Str(strData,1,strData.length()-1);
	string data1 = "", data2 = "", data3 = "";
	string head = Parser().Pars_Space ( strData, 1 );
	UpdatePlayer = true;
	UpdateTime   = atoi (Parser().Pars_Space ( strData, 2 ).c_str());
	for ( int LoopLen = 1 ; LoopLen <= Parser().Pars_Value_Count (strData); LoopLen++ )
	{	
		data1 = Parser().Pars_Value ( strData , LoopLen);
		data2 = Parser().Pars_Space ( data1, 1 );
		data3 = Parser().Pars_Space ( data1, 2 );
		PlayerData.Map_AddItem ( data2, data3);
	}
	#if 0
		show ( );
	#endif
}
string Player_param::getPlayerData( string strData )
{
	return PlayerData.getResult ( strData );
}
bool Player_param::show ( )
{
	PlayerData.show();
}
int Player_param::get_subs_max ()
{
	return atoi(getPlayerData( "subs_max" ).c_str());
}
int Player_param::get_stamina_inc_max_delta_factor  ()
{
	return atoi(getPlayerData( "stamina_inc_max_delta_factor" ).c_str());
}
int Player_param::get_random_seed  ()
{
	return atoi(getPlayerData( "random_seed" ).c_str());
}
int Player_param::get_pt_max  ()
{
	return atoi(getPlayerData( "pt_max" ).c_str());
}
int Player_param::get_player_types  ()
{
	return atoi(getPlayerData( "player_types" ).c_str());
}
int Player_param::get_player_speed_max_delta_min ()
{
	return atoi(getPlayerData( "player_speed_max_delta_min" ).c_str());
}
int Player_param::get_player_speed_max_delta_max ()
{
	return atoi(getPlayerData( "player_speed_max_delta_max" ).c_str());
}
int Player_param::get_player_size_delta_factor ()
{
	return atoi(getPlayerData( "player_size_delta_factor" ).c_str());
}
double Player_param::get_player_decay_delta_min ()
{
	return atof(getPlayerData( "player_decay_delta_min" ).c_str());
}
double  Player_param::get_player_decay_delta_max ()
{
	return atof(getPlayerData( "player_decay_delta_max" ).c_str());
}
int Player_param::get_new_stamina_inc_max_delta_factor ()
{
	return atoi(getPlayerData( "new_stamina_inc_max_delta_factor" ).c_str());
}
double Player_param::get_new_dash_power_rate_delta_min ()
{
	return atof(getPlayerData( "new_dash_power_rate_delta_min" ).c_str());
}
double Player_param::get_new_dash_power_rate_delta_max ()
{
	return atof(getPlayerData( "new_dash_power_rate_delta_max" ).c_str());
}
double Player_param::get_kickable_margin_delta_min ()
{
	return atof(getPlayerData( "kickable_margin_delta_min" ).c_str());
}
double Player_param::get_kickable_margin_delta_max ()
{
	return atof(getPlayerData( "kickable_margin_delta_max" ).c_str());
}
int Player_param::get_kick_rand_delta_factor ()
{
	return atoi(getPlayerData( "kick_rand_delta_factor" ).c_str());
}
int Player_param::get_inertia_moment_delta_factor ()
{
	return atoi(getPlayerData( "inertia_moment_delta_factor" ).c_str());
}
int Player_param::get_extra_stamina_delta_min ()
{
	return atoi(getPlayerData( "extra_stamina_delta_min" ).c_str());
}
int Player_param::get_extra_stamina_delta_max ()
{
	return atoi(getPlayerData( "extra_stamina_delta_max" ).c_str());
}
double Player_param::get_effort_min_delta_factor ()
{
	return atof(getPlayerData( "effort_min_delta_factor" ).c_str());
}
double Player_param::get_effort_max_delta_factor ()
{
	return atof(getPlayerData( "effort_max_delta_factor" ).c_str());
}
int Player_param::get_dash_power_rate_delta_min ()
{
	return atoi(getPlayerData( "dash_power_rate_delta_min" ).c_str());
}
int Player_param::get_dash_power_rate_delta_max ()
{
	return atoi(getPlayerData( "dash_power_rate_delta_max" ).c_str());
}
int Player_param::get_allow_mult_default_type ()
{
	return atoi(getPlayerData( "allow_mult_default_type" ).c_str());
}
double Player_param::get_kick_power_rate_delta_min ()
{
        return atof(getPlayerData( "kick_power_rate_delta_min" ).c_str());
}
double Player_param::get_kick_power_rate_delta_max ()
{
        return atof(getPlayerData( "kick_power_rate_delta_max" ).c_str());
}
double Player_param::get_foul_detect_probability_delta_factor ()
{
        return atof(getPlayerData( "foul_detect_probability_delta_factor"
).c_str());
}
double Player_param::get_catchable_area_l_stretch_min ()
{
        return atof(getPlayerData( "catchable_area_l_stretch_min" ).c_str());
}
double Player_param::get_catchable_area_l_stretch_max ()
{
        return atof(getPlayerData( "catchable_area_l_stretch_max" ).c_str());
}
