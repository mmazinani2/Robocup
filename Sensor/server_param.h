/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _SERVER_PARAM
#define _SERVER_PARAM

#include "../Util/MapLib.h"
#include "../Parser/ParseServer.h"
#include "../Types/SoccerTypes.h"

#include <stdlib.h>
#include <string.h>
#include <string>

class Server_param
{
	private :
		MapLib<string> ServerData;
		
		bool         UpdateServer;
		int          UpdateTime;
	public :
		Server_param          (        );
		string getServerData  ( string );
		virtual bool Update   ( string );
		virtual bool isUpdate (        )
		{
			return UpdateServer;
		}
		virtual int TimeUpdate (       )
		{
			return UpdateTime;
		}
		virtual bool reset    (        )
		{
			UpdateServer = false;
		}
		virtual bool show ( );
		int 	get_wind_random ( );
		int 	get_wind_rand ( );
		int 	get_wind_none        ();
		int 	get_wind_force       ();
		int 	get_wind_dir ();
		int 	get_wind_ang ();
		int 	get_visible_distance ();
		int 	get_visible_angle    ();
		int 	get_verbose  ();
		int 	get_use_offside      ();
		int 	get_text_logging     ();
		string 	get_text_log_fixed_name      ();
		int 	get_text_log_fixed   ();
		string  get_text_log_dir     ();
		int 	get_text_log_dated   ();
		int 	get_text_log_compression     ();
		string  get_team_r_start     ();
		string  get_team_l_start     ();
		int 	get_team_actuator_noise      ();
		double  get_tackle_width     ();
		double  get_tackle_power_rate        ();
		int 	get_tackle_exponent  ();
		int 	get_tackle_dist      ();
		int 	get_tackle_cycles    ();
		int 	get_tackle_back_dist ();
		int 	get_synch_see_offset ();
		int 	get_synch_offset     ();
		int 	get_synch_mode       ();
		int 	get_synch_micro_sleep        ();
		double 	get_stopped_ball_vel ();
		int 	get_start_goal_r     ();
		int 	get_start_goal_l     ();
		int 	get_stamina_max      ();
		int 	get_stamina_inc_max  ();
		int 	get_stamina_capacity ();
		int 	get_slowness_on_top_for_right_team   ();
		int 	get_slowness_on_top_for_left_team    ();
		int 	get_slow_down_factor ();
		int 	get_simulator_step   ();
		double	get_side_dash_rate   ();
		int 	get_sense_body_step  ();
		int 	get_send_vi_step     ();
		int 	get_send_step        ();
		int 	get_send_comms       ();
		int 	get_say_msg_size     ();
		int 	get_say_coach_msg_size       ();
		int 	get_say_coach_cnt_max        ();
		int 	get_recv_step        ();
		double	get_recover_min      ();
		int 	get_recover_init     ();
		double	get_recover_dec_thr  ();
		double  get_recover_dec      ();
		int 	get_record_messages  ();
		double  get_quantize_step_l  ();
		double  get_quantize_step    ();
		int 	get_proper_goal_kicks   ();
		int 	get_profile  ();
		int 	get_prand_factor_r   ();
		int 	get_prand_factor_l   ();
		int 	get_port     ();
		int 	get_point_to_duration        ();
		int 	get_point_to_ban     ();
		int 	get_player_weight    ();
		double  get_player_speed_max_min     ();
		double  get_player_speed_max ();
		double  get_player_size      ();
		double  get_player_rand      ();
		double  get_player_decay     ();
		int 	get_player_accel_max ();
		int 	get_penalty_shoot_outs       ();
		int 	get_pen_taken_wait   ();
		int 	get_pen_setup_wait   ();
		int	get_pen_ready_wait   ();
		int 	get_pen_random_winner        ();
		int 	get_pen_nr_kicks     ();
		int 	get_pen_max_goalie_dist_x    ();
		int 	get_pen_max_extra_kicks      ();
		double  get_pen_dist_x       ();
		int 	get_pen_coach_moves_players  ();
		int 	get_pen_before_setup_wait    ();
		int 	get_pen_allow_mult_kicks     ();
		int 	get_old_coach_hear   ();
		int 	get_olcoach_port     ();
		double  get_offside_kick_margin      ();
		double  get_offside_active_area_size ();
		int 	get_nr_normal_halfs  ();
		int 	get_nr_extra_halfs   ();
		int 	get_minpower ();
		int 	get_minneckmoment ();
		int 	get_minneckang ();
		int 	get_minmoment ();
		int 	get_min_dash_power ();
		int 	get_min_dash_angle ();
		int 	get_maxpower ();
		int 	get_maxneckmoment ();
		int 	get_maxneckang ();
		int 	get_maxmoment ();
		int 	get_max_tackle_power ();
		int 	get_max_goal_kicks ();
		int 	get_max_dash_power ();
		int 	get_max_dash_angle ();
		int 	get_max_back_tackle_power ();
		int 	get_log_times ();
		string  get_log_date_format ();
		string  get_landmark_file  ();
		double  get_kickable_margin ();
		int 	get_kick_rand_factor_r  ();
		int 	get_kick_rand_factor_l  ();
		double  get_kick_rand  ();
		double  get_kick_power_rate ();
		int 	get_kick_off_wait ();
		int 	get_keepaway_width ();
		int 	get_keepaway_start ();
		int 	get_keepaway_logging ();
		string  get_keepaway_log_fixed_name   ();
		int 	get_keepaway_log_fixed    ();
		string  get_keepaway_log_dir  ();
		int 	get_keepaway_log_dated    ();
		int 	get_keepaway_length   ();
		int 	get_keepaway  ();
		int 	get_inertia_moment   ();
		int 	get_hear_max  ();
		int 	get_hear_inc  ();
		int 	get_hear_decay      ();
		int 	get_half_time        ();
		int 	get_goalie_max_moves  ();
		double  get_goal_width       ();
		int 	get_game_over_wait   ();
		int 	get_game_logging    ();
		int 	get_game_log_version  ();
		string  get_game_log_fixed_name  ();
		int 	get_game_log_fixed   ();
		string  get_game_log_dir     ();
		int 	get_game_log_dated   ();
		int 	get_game_log_compression   ();
		int 	get_fullstate_r    ();
		int 	get_fullstate_l    ();
		int 	get_freeform_wait_period   ();
		int 	get_freeform_send_period  ();
		int 	get_free_kick_faults  ();
		int 	get_forbid_kick_off_offside   ();
		int 	get_extra_stamina    ();
		int 	get_extra_half_time  ();
		double  get_effort_min       ();
		int 	get_effort_init      ();
		double  get_effort_inc_thr   ();
		double  get_effort_inc       ();
		double  get_effort_dec_thr   ();
		double  get_effort_dec       ();
		int 	get_drop_ball_time   ();
		double  get_dash_power_rate  ();
		int 	get_dash_angle_step  ();
		int 	get_control_radius   ();
		int	get_connect_wait   ();
		int 	get_coach_w_referee  ();
		int 	get_coach_port  ();
		int 	get_coach   ();
		int 	get_clang_win_size    ();
		int 	get_clang_rule_win    ();
		int 	get_clang_meta_win   ();
		int 	get_clang_mess_per_cycle  ();
		int 	get_clang_mess_delay  ();
		int 	get_clang_info_win    ();
		int 	get_clang_del_win     ();
		int 	get_clang_define_win  ();
		int 	get_clang_advice_win  ();
		int 	get_ckick_margin      ();
		int 	get_catchable_area_w  ();
		double  get_catchable_area_l  ();
		int 	get_catch_probability   ();
		int 	get_catch_ban_cycle   ();
		double  get_ball_weight       ();
		int 	get_ball_stuck_area   ();
		int 	get_ball_speed_max    ();
		double  get_ball_size         ();
		double  get_ball_rand         ();
		double  get_ball_decay        ();
		double  get_ball_accel_max    ();
		int 	get_back_passes       ();
		double  get_back_dash_rate  ();
		int 	get_auto_mode      ();
		int 	get_audio_cut_dist ();
                double  get_tackle_rand_factor ();
                double  get_foul_detect_probability ();
                double  get_foul_exponent ();
                int     get_foul_cycles ();
                int     get_golden_goal ();
};
#endif
