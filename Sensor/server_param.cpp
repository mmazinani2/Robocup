/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "server_param.h"

Server_param::Server_param ( ):UpdateServer ( false )
			      ,UpdateTime ( 0  )
{
	ServerData.deleteAllItem ();
}
bool Server_param::Update ( string strData)
{
	strData = Parser().Mid_Str(strData,1,strData.length()-1);
	string data1 = "", data2 = "", data3 = "";
	string head = Parser().Pars_Space ( strData, 1 );
	UpdateServer = true;
	UpdateTime   = atoi (Parser().Pars_Space ( strData, 2 ).c_str ());
	for ( int LoopLen = 1 ; LoopLen <= Parser().Pars_Value_Count (strData); LoopLen++ )
	{	
		data1 = Parser().Pars_Value ( strData , LoopLen);
		data2 = Parser().Pars_Space ( data1, 1 );
		data3 = Parser().Pars_Space ( data1, 2 );
		ServerData.Map_AddItem ( data2, data3);
	}
	#if 0
		show ( );
	#endif
}
string Server_param::getServerData( string strData )
{
	return ServerData.getResult ( strData );
}
bool Server_param::show ( )
{
	ServerData.show();
}
int Server_param::get_wind_random ()
{
	return atoi(getServerData( "wind_random" ).c_str ());
}
int Server_param::get_wind_rand ()
{
	return atoi(getServerData( "wind_rand" ).c_str ());
}
int Server_param::get_wind_none        ()
{
	return atoi(getServerData( "wind_none" ).c_str ());
}
int Server_param::get_wind_force       ()
{
	return atoi(getServerData( "wind_force" ).c_str ());
}
int Server_param::get_wind_dir ()
{
	return atoi(getServerData( "wind_dir" ).c_str ());
}
int Server_param::get_wind_ang ()
{
	return atoi(getServerData( "wind_ang" ).c_str ());
}
int Server_param::get_visible_distance ()
{
	return atoi(getServerData( "visible_distance" ).c_str ());
}
int Server_param::get_visible_angle    ()
{
	return atoi(getServerData( "visible_angle" ).c_str ());
}
int Server_param::get_verbose  ()
{
	return atoi(getServerData( "verbose" ).c_str ());
}
int Server_param::get_use_offside      ()
{
	return atoi(getServerData( "use_offside" ).c_str ());
}
int Server_param::get_text_logging     ()
{
	return atoi(getServerData( "text_logging" ).c_str ());
}
string Server_param::get_text_log_fixed_name      ()
{
	return getServerData( "text_log_fixed_name" );
}
int Server_param::get_text_log_fixed   ()
{
	return atoi(getServerData( "text_log_fixed" ).c_str ());
}
string  Server_param::get_text_log_dir     ()
{
	return getServerData( "text_log_dir" );
}
int Server_param::get_text_log_dated   ()
{
	return atoi(getServerData( "text_log_dated" ).c_str ());
}
int Server_param::get_text_log_compression     ()
{
	return atoi(getServerData( "text_log_compression" ).c_str ());
}
string  Server_param::get_team_r_start     ()
{
	return getServerData( "team_r_start" );
}
string  Server_param::get_team_l_start     ()
{
	return getServerData( "team_l_start" );
}
int Server_param::get_team_actuator_noise      ()
{
	return atoi(getServerData( "team_actuator_noise" ).c_str ());
}
double Server_param::get_tackle_width     ()
{
	return atof(getServerData( "tackle_width" ).c_str ());
}
double Server_param::get_tackle_power_rate        ()
{
	return atof(getServerData( "tackle_power_rate" ).c_str ());
}
int Server_param::get_tackle_exponent  ()
{
	return atoi(getServerData( "tackle_exponent" ).c_str ());
}
int Server_param::get_tackle_dist      ()
{
	return atoi(getServerData( "tackle_dist" ).c_str ());
}
int Server_param::get_tackle_cycles    ()
{
	return atoi(getServerData( "tackle_cycles" ).c_str ());
}
int Server_param::get_tackle_back_dist ()
{
	return atoi(getServerData( "tackle_back_dist" ).c_str ());
}
int Server_param::get_synch_see_offset ()
{
	return atoi(getServerData( "synch_see_offset" ).c_str ());
}
int Server_param::get_synch_offset     ()
{
	return atoi(getServerData( "synch_offset" ).c_str ());
}
int Server_param::get_synch_mode       ()
{
	return atoi(getServerData( "synch_mode" ).c_str ());
}
int Server_param::get_synch_micro_sleep        ()
{
	return atoi(getServerData( "synch_micro_sleep" ).c_str ());
}
double Server_param::get_stopped_ball_vel ()
{
	return atof(getServerData( "stopped_ball_vel" ).c_str ());
}
int Server_param::get_start_goal_r     ()
{
	return atoi(getServerData( "start_goal_r" ).c_str ());
}
int Server_param::get_start_goal_l     ()
{
	return atoi(getServerData( "start_goal_l" ).c_str ());
}
int Server_param::get_stamina_max      ()
{
	return atoi(getServerData( "stamina_max" ).c_str ());
}
int Server_param::get_stamina_inc_max  ()
{
	return atoi(getServerData( "stamina_inc_max" ).c_str ());
}
int Server_param::get_stamina_capacity ()
{
	return atoi(getServerData( "stamina_capacity" ).c_str ());
}
int Server_param::get_slowness_on_top_for_right_team   ()
{
	return atoi(getServerData( "slowness_on_top_for_right_team" ).c_str ());
}
int Server_param::get_slowness_on_top_for_left_team    ()
{
	return atoi(getServerData( "slowness_on_top_for_left_team" ).c_str ());
}
int Server_param::get_slow_down_factor ()
{
	return atoi(getServerData( "slow_down_factor" ).c_str ());
}
int Server_param::get_simulator_step   ()
{
	return atoi(getServerData( "simulator_step" ).c_str ());
}
double Server_param::get_side_dash_rate   ()
{
	return atof(getServerData( "side_dash_rate" ).c_str ());
}
int Server_param::get_sense_body_step  ()
{
	return atoi(getServerData( "sense_body_step" ).c_str ());
}
int Server_param::get_send_vi_step     ()
{
	return atoi(getServerData( "send_vi_step" ).c_str ());
}
int Server_param::get_send_step        ()
{
	return atoi(getServerData( "send_step" ).c_str ());
}
int Server_param::get_send_comms       ()
{
	return atoi(getServerData( "send_comms" ).c_str ());
}
int Server_param::get_say_msg_size     ()
{
	return atoi(getServerData( "say_msg_size" ).c_str ());
}
int Server_param::get_say_coach_msg_size       ()
{
	return atoi(getServerData( "say_coach_msg_size" ).c_str ());
}
int Server_param::get_say_coach_cnt_max        ()
{
	return atoi(getServerData( "say_coach_cnt_max" ).c_str ());
}
int Server_param::get_recv_step        ()
{
	return atoi(getServerData( "recv_step" ).c_str ());
}
double Server_param::get_recover_min      ()
{
	return atof(getServerData( "recover_min" ).c_str ());
}
int Server_param::get_recover_init     ()
{
	return atoi(getServerData( "recover_init" ).c_str ());
}
double Server_param::get_recover_dec_thr  ()
{
	return atof(getServerData( "recover_dec_thr" ).c_str ());
}
double Server_param::get_recover_dec      ()
{
	return atof(getServerData( "recover_dec" ).c_str ());
}
int Server_param::get_record_messages  ()
{
	return atoi(getServerData( "record_messages" ).c_str ());
}
double Server_param::get_quantize_step_l  ()
{
	return atof(getServerData( "quantize_step_l" ).c_str ());
}
double Server_param::get_quantize_step    ()
{
	return atof(getServerData( "quantize_step" ).c_str ());
}
int Server_param::get_proper_goal_kicks   ()
{
	return atoi(getServerData( "proper_goal_kicks" ).c_str ());
}
int Server_param::get_profile  ()
{
	return atoi(getServerData( "profile" ).c_str ());
}
int Server_param::get_prand_factor_r   ()
{
	return atoi(getServerData( "prand_factor_r" ).c_str ());
}
int Server_param::get_prand_factor_l   ()
{
	return atoi(getServerData( "prand_factor_l" ).c_str ());
}
int Server_param::get_port     ()
{
	return atoi(getServerData( "port" ).c_str ());
}
int Server_param::get_point_to_duration        ()
{
	return atoi(getServerData( "point_to_duration" ).c_str ());
}
int Server_param::get_point_to_ban     ()
{
	return atoi(getServerData( "point_to_ban" ).c_str ());
}
int Server_param::get_player_weight    ()
{
	return atoi(getServerData( "player_weight" ).c_str ());
}
double Server_param::get_player_speed_max_min     ()
{
	return atof(getServerData( "player_speed_max_min" ).c_str ());
}
double Server_param::get_player_speed_max ()
{
	return atof(getServerData( "player_speed_max" ).c_str ());
}
double Server_param::get_player_size      ()
{
	return atof(getServerData( "player_size" ).c_str ());
}
double Server_param::get_player_rand      ()
{
	return atof(getServerData( "player_rand" ).c_str ());
}
double Server_param::get_player_decay     ()
{
	return atof(getServerData( "player_decay" ).c_str ());
}
int Server_param::get_player_accel_max ()
{
	return atoi(getServerData( "player_accel_max" ).c_str ());
}
int Server_param::get_penalty_shoot_outs       ()
{
	return atoi(getServerData( "penalty_shoot_outs" ).c_str ());
}
int Server_param::get_pen_taken_wait   ()
{
	return atoi(getServerData( "pen_taken_wait" ).c_str ());
}
int Server_param::get_pen_setup_wait   ()
{
	return atoi(getServerData( "pen_setup_wait" ).c_str ());
}
int Server_param::get_pen_ready_wait   ()
{
	return atoi(getServerData( "pen_ready_wait" ).c_str ());
}
int Server_param::get_pen_random_winner        ()
{
	return atoi(getServerData( "pen_random_winner" ).c_str ());
}
int Server_param::get_pen_nr_kicks     ()
{
	return atoi(getServerData( "pen_nr_kicks" ).c_str ());
}
int Server_param::get_pen_max_goalie_dist_x    ()
{
	return atoi(getServerData( "pen_max_goalie_dist_x" ).c_str ());
}
int Server_param::get_pen_max_extra_kicks      ()
{
	return atoi(getServerData( "pen_max_extra_kicks" ).c_str ());
}
double Server_param::get_pen_dist_x       ()
{
	return atof(getServerData( "pen_dist_x" ).c_str ());
}
int Server_param::get_pen_coach_moves_players  ()
{
	return atoi(getServerData( "pen_coach_moves_players" ).c_str ());
}
int Server_param::get_pen_before_setup_wait    ()
{
	return atoi(getServerData( "pen_before_setup_wait" ).c_str ());
}
int Server_param::get_pen_allow_mult_kicks     ()
{
	return atoi(getServerData( "pen_allow_mult_kicks" ).c_str ());
}
int Server_param::get_old_coach_hear   ()
{
	return atoi(getServerData( "old_coach_hear" ).c_str ());
}
int Server_param::get_olcoach_port     ()
{
	return atoi(getServerData( "olcoach_port" ).c_str ());
}
double Server_param::get_offside_kick_margin      ()
{
	return atof(getServerData( "offside_kick_margin" ).c_str ());
}
double Server_param::get_offside_active_area_size ()
{
	return atof(getServerData( "offside_active_area_size" ).c_str ());
}
int Server_param::get_nr_normal_halfs  ()
{
	return atoi(getServerData( "nr_normal_halfs" ).c_str ());
}
int Server_param::get_nr_extra_halfs   ()
{
	return atoi(getServerData( "nr_extra_halfs" ).c_str ());
}
int Server_param::get_minpower ()
{
	return atoi(getServerData( "minpower" ).c_str ());
}
int Server_param::get_minneckmoment ()
{
	return atoi(getServerData( "minneckmoment" ).c_str ());
}
int Server_param::get_minneckang ()
{
	return atoi(getServerData( "minneckang" ).c_str ());
}
int Server_param::get_minmoment ()
{
	return atoi(getServerData( "minmoment" ).c_str ());
}
int Server_param::get_min_dash_power ()
{
	return atoi(getServerData( "min_dash_power" ).c_str ());
}
int Server_param::get_min_dash_angle ()
{
	return atoi(getServerData( "min_dash_angle" ).c_str ());
}
int Server_param::get_maxpower ()
{
	return atoi(getServerData( "maxpower" ).c_str ());
}
int Server_param::get_maxneckmoment ()
{
	return atoi(getServerData( "maxneckmoment" ).c_str ());
}
int Server_param::get_maxneckang ()
{
	return atoi(getServerData( "maxneckang" ).c_str ());
}
int Server_param::get_maxmoment ()
{
	return atoi(getServerData( "maxmoment" ).c_str ());
}
int Server_param::get_max_tackle_power ()
{
	return atoi(getServerData( "max_tackle_power" ).c_str ());
}
int Server_param::get_max_goal_kicks ()
{
	return atoi(getServerData( "max_goal_kicks" ).c_str ());
}
int Server_param::get_max_dash_power ()
{
	return atoi(getServerData( "max_dash_power" ).c_str ());
}
int Server_param::get_max_dash_angle ()
{
	return atoi(getServerData( "max_dash_angle" ).c_str ());
}
int Server_param::get_max_back_tackle_power ()
{
	return atoi(getServerData( "max_back_tackle_power" ).c_str ());
}
int Server_param::get_log_times ()
{
	return atoi(getServerData( "log_times" ).c_str ());
}
string Server_param::get_log_date_format ()
{
	return getServerData( "log_date_format" );
}
string Server_param::get_landmark_file  ()
{
	return getServerData( "landmark_file" );
}
double Server_param::get_kickable_margin ()
{
	return atof(getServerData( "kickable_margin" ).c_str ());
}
int Server_param::get_kick_rand_factor_r  ()
{
	return atoi(getServerData( "kick_rand_factor_r" ).c_str ());
}
int Server_param::get_kick_rand_factor_l  ()
{
	return atoi(getServerData( "kick_rand_factor_l" ).c_str ());
}
double Server_param::get_kick_rand  ()
{
	return atof(getServerData( "kick_rand" ).c_str ());
}
double Server_param::get_kick_power_rate ()
{
	return atof(getServerData( "kick_power_rate" ).c_str ());
}
int Server_param::get_kick_off_wait ()
{
	return atoi(getServerData( "kick_off_wait" ).c_str ());
}
int Server_param::get_keepaway_width ()
{
	return atoi(getServerData( "keepaway_width" ).c_str ());
}
int Server_param::get_keepaway_start ()
{
	return atoi(getServerData( "keepaway_start" ).c_str ());
}
int Server_param::get_keepaway_logging ()
{
	return atoi(getServerData( "keepaway_logging" ).c_str ());
}
string Server_param::get_keepaway_log_fixed_name   ()
{
	return getServerData( "keepaway_log_fixed_name" );
}
int Server_param::get_keepaway_log_fixed    ()
{
	return atoi(getServerData( "keepaway_log_fixed" ).c_str ());
}
string Server_param::get_keepaway_log_dir  ()
{
	return getServerData( "keepaway_log_dir" );
}
int Server_param::get_keepaway_log_dated    ()
{
	return atoi(getServerData( "keepaway_log_dated" ).c_str ());
}
int Server_param::get_keepaway_length   ()
{
	return atoi(getServerData( "keepaway_length" ).c_str ());
}
int Server_param::get_keepaway  ()
{
	return atoi(getServerData( "keepaway" ).c_str ());
}
int Server_param::get_inertia_moment   ()
{
	return atoi(getServerData( "inertia_moment" ).c_str ());
}
int Server_param::get_hear_max  ()
{
	return atoi(getServerData( "hear_max" ).c_str ());
}
int Server_param::get_hear_inc  ()
{
	return atoi(getServerData( "hear_inc" ).c_str ());
}
int Server_param::get_hear_decay      ()
{
	return atoi(getServerData( "hear_decay" ).c_str ());
}
int Server_param::get_half_time        ()
{
	return atoi(getServerData( "half_time" ).c_str ());
}
int Server_param::get_goalie_max_moves  ()
{
	return atoi(getServerData( "goalie_max_moves" ).c_str ());
}
double Server_param::get_goal_width       ()
{
	return atof(getServerData( "goal_width" ).c_str ());
}
int Server_param::get_game_over_wait   ()
{
	return atoi(getServerData( "game_over_wait" ).c_str ());
}
int Server_param::get_game_logging    ()
{
	return atoi(getServerData( "game_logging" ).c_str ());
}
int Server_param::get_game_log_version  ()
{
	return atoi(getServerData( "game_log_version" ).c_str ());
}
string  Server_param::get_game_log_fixed_name  ()
{
	return getServerData( "game_log_fixed_name" );
}
int Server_param::get_game_log_fixed   ()
{
	return atoi(getServerData( "game_log_fixed" ).c_str ());
}
string  Server_param::get_game_log_dir     ()
{
	return getServerData( "game_log_dir" );
}
int Server_param::get_game_log_dated   ()
{
	return atoi(getServerData( "game_log_dated" ).c_str ());
}
int Server_param::get_game_log_compression   ()
{
	return atoi(getServerData( "game_log_compression" ).c_str ());
}
int Server_param::get_fullstate_r    ()
{
	return atoi(getServerData( "fullstate_r" ).c_str ());
}
int Server_param::get_fullstate_l    ()
{
	return atoi(getServerData( "fullstate_l" ).c_str ());
}
int Server_param::get_freeform_wait_period   ()
{
	return atoi(getServerData( "freeform_wait_period" ).c_str ());
}
int Server_param::get_freeform_send_period  ()
{
	return atoi(getServerData( "freeform_send_period" ).c_str ());
}
int Server_param::get_free_kick_faults  ()
{
	return atoi(getServerData( "free_kick_faults" ).c_str ());
}
int Server_param::get_forbid_kick_off_offside   ()
{
	return atoi(getServerData( "forbid_kick_off_offside" ).c_str ());
}
int Server_param::get_extra_stamina    ()
{
	return atoi(getServerData( "extra_stamina" ).c_str ());
}
int Server_param::get_extra_half_time  ()
{
	return atoi(getServerData( "extra_half_time" ).c_str ());
}
double Server_param::get_effort_min       ()
{
	return atof(getServerData( "effort_min" ).c_str ());
}
int Server_param::get_effort_init      ()
{
	return atoi(getServerData( "effort_init" ).c_str ());
}
double Server_param::get_effort_inc_thr   ()
{
	return atof(getServerData( "effort_inc_thr" ).c_str ());
}
double Server_param::get_effort_inc       ()
{
	return atof(getServerData( "effort_inc" ).c_str ());
}
double Server_param::get_effort_dec_thr   ()
{
	return atof(getServerData( "effort_dec_thr" ).c_str ());
}
double Server_param::get_effort_dec       ()
{
	return atof(getServerData( "effort_dec" ).c_str ());
}
int Server_param::get_drop_ball_time   ()
{
	return atoi(getServerData( "drop_ball_time" ).c_str ());
}
double Server_param::get_dash_power_rate  ()
{
	return atof(getServerData( "dash_power_rate" ).c_str ());
}
int Server_param::get_dash_angle_step  ()
{
	return atoi(getServerData( "dash_angle_step" ).c_str ());
}
int Server_param::get_control_radius   ()
{
	return atoi(getServerData( "control_radius" ).c_str ());
}
int Server_param::get_connect_wait   ()
{
	return atoi(getServerData( "connect_wait" ).c_str ());
}
int Server_param::get_coach_w_referee  ()
{
	return atoi(getServerData( "coach_w_referee" ).c_str ());
}
int Server_param::get_coach_port  ()
{
	return atoi(getServerData( "coach_port" ).c_str ());
}
int Server_param::get_coach   ()
{
	return atoi(getServerData( "coach" ).c_str ());
}
int Server_param::get_clang_win_size    ()
{
	return atoi(getServerData( "clang_win_size" ).c_str ());
}
int Server_param::get_clang_rule_win    ()
{
	return atoi(getServerData( "clang_rule_win" ).c_str ());
}
int Server_param::get_clang_meta_win   ()
{
	return atoi(getServerData( "clang_meta_win" ).c_str ());
}
int Server_param::get_clang_mess_per_cycle  ()
{
	return atoi(getServerData( "clang_mess_per_cycle" ).c_str ());
}
int Server_param::get_clang_mess_delay  ()
{
	return atoi(getServerData( "clang_mess_delay" ).c_str ());
}
int Server_param::get_clang_info_win    ()
{
	return atoi(getServerData( "clang_info_win" ).c_str ());
}
int Server_param::get_clang_del_win     ()
{
	return atoi(getServerData( "clang_del_win" ).c_str ());
}
int Server_param::get_clang_define_win  ()
{
	return atoi(getServerData( "clang_define_win" ).c_str ());
}
int Server_param::get_clang_advice_win  ()
{
	return atoi(getServerData( "clang_advice_win" ).c_str ());
}
int Server_param::get_ckick_margin      ()
{
	return atoi(getServerData( "ckick_margin" ).c_str ());
}
int Server_param::get_catchable_area_w  ()
{
	return atoi(getServerData( "catchable_area_w" ).c_str ());
}
double Server_param::get_catchable_area_l  ()
{
	return atof(getServerData( "catchable_area_l" ).c_str ());
}
int Server_param::get_catch_probability   ()
{
	return atoi(getServerData( "catch_probability" ).c_str ());
}
int Server_param::get_catch_ban_cycle   ()
{
	return atoi(getServerData( "catch_ban_cycle" ).c_str ());
}
double Server_param::get_ball_weight       ()
{
	return atof(getServerData( "ball_weight" ).c_str ());
}
int Server_param::get_ball_stuck_area   ()
{
	return atoi(getServerData( "ball_stuck_area" ).c_str ());
}
int Server_param::get_ball_speed_max    ()
{
	return atoi(getServerData( "ball_speed_max" ).c_str ());
}
double Server_param::get_ball_size         ()
{
	return atof(getServerData( "ball_size" ).c_str ());
}
double Server_param::get_ball_rand         ()
{
	return atof(getServerData( "ball_rand" ).c_str ());
}
double Server_param::get_ball_decay        ()
{
	return atof(getServerData( "ball_decay" ).c_str ());
}
double Server_param::get_ball_accel_max    ()
{
	return atof(getServerData( "ball_accel_max" ).c_str ());
}
int Server_param::get_back_passes       ()
{
	return atoi(getServerData( "back_passes" ).c_str ());
}
double Server_param::get_back_dash_rate  ()
{
	return atof(getServerData( "back_dash_rate" ).c_str ());
}
int Server_param::get_auto_mode      ()
{
	return atoi(getServerData( "auto_mode" ).c_str ());
}
int Server_param::get_audio_cut_dist ()
{
	return atoi(getServerData( "audio_cut_dist" ).c_str());
}
double Server_param::get_tackle_rand_factor ()
{
        return atof (getServerData( "tackle_rand_factor" ).c_str());
}
double Server_param::get_foul_detect_probability ()
{
        return atof (getServerData( "foul_detect_probability" ).c_str());
}
double Server_param::get_foul_exponent ()
{
        return atof (getServerData( "foul_exponent" ).c_str());
}
int Server_param::get_foul_cycles ()
{
        return atoi (getServerData( "foul_cycles" ).c_str());
}
int Server_param::get_golden_goal ()
{
        return (getServerData( "golden_goal" ).c_str() == "true")?1:0;
}
#if 0

int main()
{
	Server_param sp;
	sp.setServerData();
	int i = (int)sp.getServerData("a");
	cerr<< i <<endl;
}

#endif
