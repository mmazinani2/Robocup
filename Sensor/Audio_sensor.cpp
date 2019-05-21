/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Audio_sensor.h"

int Audio_sensor::UpdateTime = 0;

Audio_sensor::Audio_sensor ( )
{
	RefereeMessageMap( );
}
bool Audio_sensor::RefereeMessageMap (    )
{
	RMessage.Map_AddItem ( "before_kick_off",REFC_BEFORE_KICK_OFF);
	RMessage.Map_AddItem ( "kick_off_l",REFC_KICK_OFF_LEFT);
	RMessage.Map_AddItem ( "kick_off_r",REFC_KICK_OFF_RIGHT);
	RMessage.Map_AddItem ( "kick_in_l",REFC_KICK_IN_LEFT);
	RMessage.Map_AddItem ( "kick_in_r",REFC_KICK_IN_RIGHT);
	RMessage.Map_AddItem ( "corner_kick_l",REFC_CORNER_KICK_LEFT);
	RMessage.Map_AddItem ( "corner_kick_r",REFC_CORNER_KICK_RIGHT);
	RMessage.Map_AddItem ( "goal_kick_l",REFC_GOAL_KICK_LEFT);
	RMessage.Map_AddItem ( "goal_kick_r",REFC_GOAL_KICK_RIGHT);
	RMessage.Map_AddItem ( "free_kick_l",REFC_FREE_KICK_LEFT);
	RMessage.Map_AddItem ( "free_kick_r",REFC_FREE_KICK_RIGHT);
	RMessage.Map_AddItem ( "indirect_free_kick_r",REFC_INDIRECT_FREE_KICK_RIGHT);
	RMessage.Map_AddItem ( "indirect_free_kick_l",REFC_INDIRECT_FREE_KICK_LEFT);
	RMessage.Map_AddItem ( "free_kick_fault_l",REFC_FREE_KICK_FAULT_LEFT);
	RMessage.Map_AddItem ( "free_kick_fault_r",REFC_FREE_KICK_FAULT_RIGHT);
	RMessage.Map_AddItem ( "back_pass_l",REFC_BACK_PASS_LEFT);
	RMessage.Map_AddItem ( "back_pass_r",REFC_BACK_PASS_RIGHT);
	RMessage.Map_AddItem ( "play_on",REFC_PLAY_ON);
	RMessage.Map_AddItem ( "time_over",REFC_TIME_OVER);
	RMessage.Map_AddItem ( "frozen",REFC_FROZEN);
	RMessage.Map_AddItem ( "quit",REFC_QUIT);
	RMessage.Map_AddItem ( "offside_l",REFC_OFFSIDE_LEFT);
	RMessage.Map_AddItem ( "offside_r",REFC_OFFSIDE_RIGHT);
	RMessage.Map_AddItem ( "half_time",REFC_HALF_TIME);
	RMessage.Map_AddItem ( "time_up",REFC_TIME_UP);
	RMessage.Map_AddItem ( "time_up_without_a_team",REFC_TIME_UP_WITHOUT_A_TEAM);
	RMessage.Map_AddItem ( "time_extended",REFC_TIME_EXTENDED);
	RMessage.Map_AddItem ( "foul_l",REFC_FOUL_LEFT);
	RMessage.Map_AddItem ( "foul_r",REFC_FOUL_RIGHT);
	RMessage.Map_AddItem ( "goal_l",REFC_GOAL_LEFT);
	RMessage.Map_AddItem ( "goal_r",REFC_GOAL_RIGHT);
	RMessage.Map_AddItem ( "drop_ball",REFC_DROP_BALL);
	RMessage.Map_AddItem ( "goalie_catch_ball_l",REFC_GOALIE_CATCH_BALL_LEFT);
	RMessage.Map_AddItem ( "goalie_catch_ball_r",REFC_GOALIE_CATCH_BALL_RIGHT);
	RMessage.Map_AddItem ( "penalty_setup_l",REFC_PENALTY_SETUP_LEFT);
	RMessage.Map_AddItem ( "penalty_setup_r",REFC_PENALTY_SETUP_RIGHT);
	RMessage.Map_AddItem ( "penalty_ready_l",REFC_PENALTY_READY_LEFT);
	RMessage.Map_AddItem ( "penalty_ready_r",REFC_PENALTY_READY_RIGHT);
	RMessage.Map_AddItem ( "penalty_taken_l",REFC_PENALTY_TAKEN_LEFT);
	RMessage.Map_AddItem ( "penalty_taken_r",REFC_PENALTY_TAKEN_RIGHT);
	RMessage.Map_AddItem ( "penalty_miss_l",REFC_PENALTY_MISS_LEFT);
	RMessage.Map_AddItem ( "penalty_miss_r",REFC_PENALTY_MISS_RIGHT);
	RMessage.Map_AddItem ( "penalty_score_l",REFC_PENALTY_SCORE_LEFT);
	RMessage.Map_AddItem ( "penalty_score_r",REFC_PENALTY_SCORE_RIGHT);
	RMessage.Map_AddItem ( "penalty_foul_l",REFC_PENALTY_FOUL_LEFT);
	RMessage.Map_AddItem ( "penalty_foul_r",REFC_PENALTY_FOUL_RIGHT);
	RMessage.Map_AddItem ( "penalty_onfield_l",REFC_PENALTY_ONFIELD_LEFT);
	RMessage.Map_AddItem ( "penalty_onfield_r",REFC_PENALTY_ONFIELD_RIGHT);
	RMessage.Map_AddItem ( "penalty_winner_l",REFC_PENALTY_WINNER_LEFT);
	RMessage.Map_AddItem ( "penalty_winner_r",REFC_PENALTY_WINNER_RIGHT);
	RMessage.Map_AddItem ( "penalty_draw",REFC_PENALTY_DRAW);
        
        /** 
          @# Update Card -- > Mohammad Mazinani
        */
        RMessage.Map_AddItem ( "yellow_card_l_1",REFC_YELLOW_CARD_L_1);
        RMessage.Map_AddItem ( "yellow_card_l_2",REFC_YELLOW_CARD_L_2);
        RMessage.Map_AddItem ( "yellow_card_l_3",REFC_YELLOW_CARD_L_3);
        RMessage.Map_AddItem ( "yellow_card_l_4",REFC_YELLOW_CARD_L_4);
        RMessage.Map_AddItem ( "yellow_card_l_5",REFC_YELLOW_CARD_L_5);
        RMessage.Map_AddItem ( "yellow_card_l_6",REFC_YELLOW_CARD_L_6);
        RMessage.Map_AddItem ( "yellow_card_l_7",REFC_YELLOW_CARD_L_7);
        RMessage.Map_AddItem ( "yellow_card_l_8",REFC_YELLOW_CARD_L_8);
        RMessage.Map_AddItem ( "yellow_card_l_9",REFC_YELLOW_CARD_L_9);
        RMessage.Map_AddItem ( "yellow_card_l_10",REFC_YELLOW_CARD_L_10);
        RMessage.Map_AddItem ( "yellow_card_l_11",REFC_YELLOW_CARD_L_11);
        
        RMessage.Map_AddItem ( "yellow_card_r_1",REFC_YELLOW_CARD_R_1);
        RMessage.Map_AddItem ( "yellow_card_r_2",REFC_YELLOW_CARD_R_2);
        RMessage.Map_AddItem ( "yellow_card_r_3",REFC_YELLOW_CARD_R_3);
        RMessage.Map_AddItem ( "yellow_card_r_4",REFC_YELLOW_CARD_R_4);
        RMessage.Map_AddItem ( "yellow_card_r_5",REFC_YELLOW_CARD_R_5);
        RMessage.Map_AddItem ( "yellow_card_r_6",REFC_YELLOW_CARD_R_6);
        RMessage.Map_AddItem ( "yellow_card_r_7",REFC_YELLOW_CARD_R_7);
        RMessage.Map_AddItem ( "yellow_card_r_8",REFC_YELLOW_CARD_R_8);
        RMessage.Map_AddItem ( "yellow_card_r_9",REFC_YELLOW_CARD_R_9);
        RMessage.Map_AddItem ( "yellow_card_r_10",REFC_YELLOW_CARD_R_10);
        RMessage.Map_AddItem ( "yellow_card_r_11",REFC_YELLOW_CARD_R_11);
        
        RMessage.Map_AddItem ( "red_card_l_1",REFC_RED_CARD_L_1);
        RMessage.Map_AddItem ( "red_card_l_2",REFC_RED_CARD_L_2);
        RMessage.Map_AddItem ( "red_card_l_3",REFC_RED_CARD_L_3);
        RMessage.Map_AddItem ( "red_card_l_4",REFC_RED_CARD_L_4);
        RMessage.Map_AddItem ( "red_card_l_5",REFC_RED_CARD_L_5);
        RMessage.Map_AddItem ( "red_card_l_6",REFC_RED_CARD_L_6);
        RMessage.Map_AddItem ( "red_card_l_7",REFC_RED_CARD_L_7);
        RMessage.Map_AddItem ( "red_card_l_8",REFC_RED_CARD_L_8);
        RMessage.Map_AddItem ( "red_card_l_9",REFC_RED_CARD_L_9);
        RMessage.Map_AddItem ( "red_card_l_10",REFC_RED_CARD_L_10);
        RMessage.Map_AddItem ( "red_card_l_11",REFC_RED_CARD_L_11);
        
        RMessage.Map_AddItem ( "red_card_r_1",REFC_RED_CARD_R_1);
        RMessage.Map_AddItem ( "red_card_r_2",REFC_RED_CARD_R_2);
        RMessage.Map_AddItem ( "red_card_r_3",REFC_RED_CARD_R_3);
        RMessage.Map_AddItem ( "red_card_r_4",REFC_RED_CARD_R_4);
        RMessage.Map_AddItem ( "red_card_r_5",REFC_RED_CARD_R_5);
        RMessage.Map_AddItem ( "red_card_r_6",REFC_RED_CARD_R_6);
        RMessage.Map_AddItem ( "red_card_r_7",REFC_RED_CARD_R_7);
        RMessage.Map_AddItem ( "red_card_r_8",REFC_RED_CARD_R_8);
        RMessage.Map_AddItem ( "red_card_r_9",REFC_RED_CARD_R_9);
        RMessage.Map_AddItem ( "red_card_r_10",REFC_RED_CARD_R_10);
        RMessage.Map_AddItem ( "red_card_r_11",REFC_RED_CARD_R_11);
        /** 
          @# Update Card -- > Mohammad Mazinani
        */
	return true;
}
bool TimeCmp  (   HearValue HVal   )
{
	return (HVal.UpTime < Audio_sensor().TimeUpdate());
}
bool Audio_sensor::Trash    (                )
{
	vector<HearValue> ::iterator last;
	vector<HearValue> vec = HValue.returnVector( );
	sort (HValue.returnVector( ).begin(),HValue.returnVector( ).end(),cmpT());

	if (! HValue.isEmpty())
	{
		last = remove_if (HValue.returnVector( ).begin (),HValue.returnVector( ).end(),TimeCmp);
	}

	HValue.returnVector( ).erase(last , HValue.returnVector( ).end());
	
	return true;
}
bool Audio_sensor::Update   ( string strData )
{
	HearValue HVal;
	strData     = Parser().Mid_Str(strData,1,strData.length()-2);
	UpdateTime  = (atoi (Parser().Pars_Space ( strData, 2 ).c_str()));
	Trash (  );
	HVal.UpTime = UpdateTime;
	HVal.Sender = Parser().Pars_Space ( strData, 3);
	if (Parser().Pars_Space_Count ( strData ) > 4)
	{
		HVal.PNum     = atoi(Parser().Pars_Space ( strData, 4).c_str());
		HVal.HearData = Parser().Pars_Space ( strData, 5);
	}
	else
	{
		HVal.HearData = Parser().Pars_Space ( strData, 4);
	}

	HValue.It_push ( HVal );

      return true;
}
RefereeMessageT Audio_sensor::getRefereeMessage ( )
{
	if (HValue.isEmpty())
		return REFC_ILLEGAL;
	else
	{
		string strValue = "";
		vector<HearValue>::iterator hv = HValue.returnVector ( ).begin();
		int Size = HValue.returnVector ( ).size ();
// 		cerr << "Size : " << Size << endl;
		for (int Rcount = 0 ; Rcount < Size ; Rcount++ )
		{
			if ( hv->Sender == "referee" )
			{
                                ;
				strValue = hv->HearData;
			}
			hv++;
		}
		return RMessage.getResult (strValue);
	}
}
int Audio_sensor::getRefereeMessageTime ( )
{
	if (HValue.isEmpty())
		return 0;
	else
	{
		int UTime = 0;
		vector<HearValue>::iterator hv = HValue.returnVector ( ).begin();
		int Size = HValue.returnVector ( ).size ();
// 		cerr << "Size : " << Size << endl;
		for (int Rcount = 0 ; Rcount < Size ; Rcount++ )
		{
			if ( hv->Sender == "referee" )
			{
				UTime = hv->UpTime;
			}
			hv++;
		}
		return UTime;
	}
}

// 	vector<HearValue>::iterator itr = HVvec.begin();
// 	cerr <<"----------vec data------------"<<endl;
// 	for (itr ; itr != HVvec.end() ; itr++)
// 	{
// 		cerr<< itr->HearData<<endl;
// 	}
