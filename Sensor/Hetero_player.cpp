/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Hetero_player.h"

Hetero_Player::Hetero_Player  ( ):UpdateHetero(false)
				 ,UpdateTime   (  0  )
{
	HeteroList.clear ( );
	setSpeedReal ( );
}
bool Hetero_Player::Update (string strData )
{
	//cerr << strData << endl;
	double Tmp[16];
	HPlayer HeteroTmp;
	strData = Parser().Mid_Str(strData,1,strData.length()-1);
	UpdateHetero = true;
	UpdateTime    = atoi (Parser().Pars_Space ( strData, 2 ).c_str());
	string Block = "", Value = "";
	for ( int LoopLen = 1 ; LoopLen <= Parser().Pars_Value_Count (strData); LoopLen++ )
	{
		Block = Parser().Pars_Value ( strData , LoopLen);
		Value = Parser().Pars_Space ( Block, 2 );
	 	Tmp [LoopLen-1] = atof ( Value.c_str () );
	}
        //cerr << "Ok" <<endl;
	HeteroTmp.id = (int)(Tmp [0]);
	HeteroTmp.player_speed_max = Tmp [1];
	HeteroTmp.stamina_inc_max = Tmp [2];
	HeteroTmp.player_decay = Tmp [3];
	HeteroTmp.inertia_moment = Tmp [4];
	HeteroTmp.dash_power_rate = Tmp [5];
	HeteroTmp.player_size = Tmp [6];
	HeteroTmp.kickable_margin = Tmp [7];
	HeteroTmp.kick_rand = Tmp [8];
	HeteroTmp.extra_stamina = Tmp [9];
	HeteroTmp.effort_max = Tmp [10];
	HeteroTmp.effort_min = Tmp [11];
	HeteroTmp.kick_power_rate = Tmp [12];
	HeteroTmp.foul_detect_probability = Tmp [13];
	HeteroTmp.catchable_area_l_stretch = Tmp [14];
	
	HeteroList.push_back (HeteroTmp);
	#if 0
	  show ();
	#endif

	return true;
}
bool Hetero_Player::sortById  ( )
{
	sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpById ( ) );
	return true;
}
bool Hetero_Player::sortByPlayerSpeedMax  ( )
{
	sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByPlayerSpeedMax ( ) );
	return true;
}
bool Hetero_Player::sortByStaminaIncMax  ( )
{
	sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByStaminaIncMax ( ) );
	return true;
}
bool Hetero_Player::sortByPlayerDecay  ( )
{
	sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByPlayerDecay ( ) );
	return true;
}
bool Hetero_Player::sortByInertiaMoment  ( )
{
	sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByInertiaMoment ( ) );
	return true;
}
bool Hetero_Player::sortByDashPowerRate  ( )
{
	sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByDashPowerRate ( ) );
	return true;
}
bool Hetero_Player::sortByPlayerSize  ( )
{
	sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByPlayerSize ( ) );
	return true;
}
bool Hetero_Player::sortByKickableMargin  ( )
{
	sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByKickableMargin ( ) );
	return true;
}
bool Hetero_Player::sortByKickRand  ( )
{
	sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByKickRand ( ) );
	return true;
}
bool Hetero_Player::sortByExtraStamina  ( )
{
	sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByExtraStamina ( ) );
	return true;
}
bool Hetero_Player::sortByEffortMax  ( )
{
      sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByEffortMax ( ) );
      return true;
}
bool Hetero_Player::sortByEffortMin  ( )
{
       sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByEffortMin ( ) );
       return true;
}
bool Hetero_Player::sortBykickpower  ( )
{
      sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpBykickpower ( ) );
      return true;
}
bool Hetero_Player::sortByfouldetect  ( )
{
      sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpByfouldetect ( ) );
      return true;
}
bool Hetero_Player::sortBycatchablearea  ( )
{
      sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpBycatchablearea ( ));
      return true;
}
vector<HPlayer> Hetero_Player::getHeteroPlayer ( )
{
	return HeteroList;
}
int  Hetero_Player::getHeteroCount   ( )
{
	return HeteroList.size ();
}
bool Hetero_Player::sortBySpeedReal ( )
{
	setSpeedReal ( );
	sort (HeteroList.begin ( ), HeteroList.end ( ), HPCmpBySpeedReal ( ) );
	return true;
}
HPlayer Hetero_Player::getTypeByID ( int ID )
{
	setSpeedReal ( );	
	sortById ();
	return HeteroList[ID];
}
bool Hetero_Player::show ()
{
	vector <HPlayer>::iterator m = HeteroList.begin();
	for (m ; m != HeteroList.end() ; m++)
	{
		
		cerr << "ID : " << m->id << "\n"
		     << "player_speed_max : " << m->player_speed_max << "\n"
		     << "stamina_inc_max : " << m->stamina_inc_max << "\n"
		     << "player_decay : " << m->player_decay << "\n"
		     << "inertia_moment : " << m->inertia_moment << "\n"
		     << "dash_power_rate : " << m->dash_power_rate << "\n"
		     << "player_size : " << m->player_size << "\n"
		     << "kickable_margin : " << m->kickable_margin << "\n"
		     << "kick_rand : " << m->kick_rand << "\n"
		     << "extra_stamina : " << m->extra_stamina << "\n"
		     << "effort_max : " << m->effort_max << "\n"
		     << "effort_min : " << m->effort_min << "\n"
		     << "kick_power_rate : " << m->kick_power_rate << "\n"
                     << "foul_detect_probability : "<<
m->foul_detect_probability
                     << "\n" << "catchable_area_l_stretch : " <<
                        m->catchable_area_l_stretch
                     <<"\n" << "----------------------------------" << "\n";
	}
}
