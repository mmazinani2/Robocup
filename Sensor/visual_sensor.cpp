/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "visual_sensor.h"

Visual_Sensor::Visual_Sensor ( ):Teamname (DEFAULT_TEAM_NAME)
				,isGoalie (false)
				,Quality(10)
				,UpdateTime(0)
				,LastUpdateTime(0)
				,UpdateVisual(false)
				,ViewAngle(120)
				,SeeCount(0)
{
	Set_Flag_Map ( );
}
bool TrashPlayerComp ( PlayerInfo _PInfo )
{
	return (_PInfo.Quality <= QUALITY_MIN );
}

void RefreshPlayerQuality ( PlayerInfo &_PInfo )
{
	double Q = _PInfo.Quality;
	Q -= QUALITY_STEP;
	_PInfo.Quality = max (Q,0);
	_PInfo.Visible = false;
}
void RefreshBallQuality ( BallInfo &_BInfo )
{
	double Q = _BInfo.Quality;
	Q -= QUALITY_STEP-0.5;
	_BInfo.Quality = max (Q,0);
	_BInfo.Visible = false;
}
bool TrashBallComp (BallInfo _BInfo )
{
	return (_BInfo.Quality <= QUALITY_MIN);
}
bool Visual_Sensor::Trash ( )
{
	PlayerInfo tmpTmm,tmpOpp;
	for_each (_TeammateInfo.returnVector().begin (),_TeammateInfo.returnVector().end(),RefreshPlayerQuality );
	for_each (_OpponentInfo.returnVector().begin (),_OpponentInfo.returnVector().end(),RefreshPlayerQuality );
	for_each (_BallInfo.returnVector().begin (),_BallInfo.returnVector().end(),RefreshBallQuality );
#if 0	
	cerr << "OK 1" << endl;
#endif
	vector<PlayerInfo> ::iterator last1 = _TeammateInfo.returnVector().end();
	vector<PlayerInfo> ::iterator last2 = _OpponentInfo.returnVector().end();
	vector<BallInfo> ::iterator blast;
	sort (_TeammateInfo.returnVector().begin (),_TeammateInfo.returnVector().end(),SortCmpPlayer() );
	sort (_OpponentInfo.returnVector().begin (),_OpponentInfo.returnVector().end(),SortCmpPlayer() );
	sort (_BallInfo.returnVector().begin (),_BallInfo.returnVector().end(),SortCmpBall() );
	vector<PlayerInfo>  TmpTeammate;
	vector<PlayerInfo>  TmpOpponent;
#if 0	
	cerr << "OK 2" << endl;
#endif
	for ( int ObjNum = 1; ObjNum <= 11; ObjNum++ )
	{
		TmpTeammate.clear ();
		TmpOpponent.clear ();
		tmpTmm.IDPlayer = PlayerT (    ObjNum   );
		tmpOpp.IDPlayer = PlayerT ( ObjNum + 11 );
#if 0	
	cerr << "OK 3" << endl;
#endif
		int PTCount =
			 count(_TeammateInfo.returnVector().begin (),_TeammateInfo.returnVector().end(), tmpTmm);
		int POCount = 
			 count(_OpponentInfo.returnVector().begin (),_OpponentInfo.returnVector().end(), tmpOpp);
		if (PTCount>2){
			TmpTeammate = _TeammateInfo.returnVector();
			last1 = remove_if (_TeammateInfo.returnVector().begin (),
								_TeammateInfo.returnVector().end(),TrashPlayerComp);
			_TeammateInfo.returnVector().erase ( last1 , _TeammateInfo.returnVector().end());
			PTCount =
			 count(_TeammateInfo.returnVector().begin (),_TeammateInfo.returnVector().end(), tmpTmm);
			if (PTCount < 2)
			{
				_TeammateInfo.It_clear ();
				_TeammateInfo = TmpTeammate;
			}
			
		}
 		if (POCount>2){
			TmpOpponent = _OpponentInfo.returnVector();
 			last2 = remove_if (_OpponentInfo.returnVector().begin (),
 								_OpponentInfo.returnVector().end(),TrashPlayerComp);
			_OpponentInfo.returnVector().erase ( last2 , _OpponentInfo.returnVector().end());
			POCount = 
			 count(_OpponentInfo.returnVector().begin (),_OpponentInfo.returnVector().end(), tmpOpp);
			_OpponentInfo.returnVector().erase ( last2 , _OpponentInfo.returnVector().end() );
			if (POCount < 2)
			{
				_OpponentInfo.It_clear ();
				_OpponentInfo = TmpOpponent;
			}
		}
#if 0	
	cerr << "OK 4" << endl;
#endif
	}
	_UnknownInfo.It_clear ( );
#if 0	
	cerr << "OK 5" << endl;
#endif
	BallInfo tmpBall;
	tmpBall.Quality = QUALITY_MIN;
	if (_BallInfo.It_countItem ( ) > 3)
	{
		blast = remove (_BallInfo.returnVector().begin (),_BallInfo.returnVector().end (),tmpBall);
		_BallInfo.returnVector().erase ( blast , _BallInfo.returnVector().end () );
	}
#if 0	
	cerr << "OK 6" << endl;
#endif
 
}
bool    Visual_Sensor::LineTrash ()
{
	_LineInfo.It_clear ( );
}
bool	Visual_Sensor::FlagTrash ()
{
	_FlagInfo.It_clear ( );
}
PlayerT Visual_Sensor::ConvertSToPT ( string strData)
{
     isGoalie = false;
     bool tag = false,Unknown = true;
     string data1 = "",data2 = "";
     int Playernum = 0;
     for (int LoopLen = 2; LoopLen <= Parser().Pars_Space_Count ( strData ); LoopLen++ )
     {
	data1 = Parser().Pars_Space (strData,LoopLen);
	//cerr << "Get Tag : " << data1 << endl;
        if (data1.length () > 0) {
		switch ( data1[0] )
		{
			case '"' :
				data2 = Parser().Mid_Str (data1,1,data1.length()-2);
				if (data2 == Teamname)
					tag = true;
				Unknown = false;
				break;
			case 'g' :
				isGoalie = true;
				break;
			default :
				Playernum = atoi ( data1.c_str () );
				//cerr << Playernum << endl;
		}
        }
      }
      if ( Unknown )
	return PT_UNKNOWN;
      if (tag)
      {
	      if ( Playernum != 0 )
		return PlayerT ( Playernum );
	      else
		return PT_TEAMMATES;
      }
      else
      {
 	      if ( Playernum != 0 )
		return PlayerT ( Playernum+11 );
	      else
		return PT_OPPONENTS;
      }
}
///TODO: add afunction for sync time 
bool Visual_Sensor::Update   ( string strData , Cycle seeCycle )
{
#if 0
    cerr << "Vision Massage : " << strData << endl;
#endif
	string strTime = "";
	strTime = Parser().Pars_Space (strData,1);
	strTime = Parser().Pars_Space (strData,2);
	Cycle seeTime = atoi (strTime.c_str());
	strData = Parser().Mid_Str(strData,1,strData.length()-1);
	string Block = "" , Head = "";
	if (SeeCount > 0)
		this->Trash ( );
	this->FlagTrash ();
	++SeeCount;
	bool flag = true;
	#if 0
		cerr << "Player Teamname : " << _TeammateInfo.returnVector().size() << endl;
		cerr << "Player Opponent : " << _OpponentInfo.returnVector().size() << endl;
		cerr << "Player Ball     : " << _BallInfo.returnVector().size () << endl;
	#endif
        
	for (int LoopCount = 1; LoopCount <= Parser().Pars_Value_Count (strData); LoopCount++)
	{
		Block = Parser().Pars_Value (strData,LoopCount);
		Head  = Parser().Pars_Value (Block , 1 );
	        if (Head.length () > 0) {
			switch (Head[0])
			{
				case 'b' :
				case 'B' :
					#if 0
						cerr << " Ball Data " << endl;
					#endif
					UpdateBall (Block,seeTime);
					break;
				case 'p' :
				case 'P' :
					#if 0
						cerr << " Player Data " << endl;
					#endif
					UpdatePlayer (Head,Block,seeTime);
					break;
				case 'f' :
				case 'g' :
				case 'F' :
				case 'G' :
					#if 0
						cerr << Block << endl;
					#endif
				       UpdateFlag (Head,
						Parser().Mid_Str(Block,Head.length()+1,Block.length()-1),seeTime);
					break;
				case 'l' :
				case 'L' :
					#if 0
						cerr << " Line Data " << endl;
					#endif
					if (flag) {
						LineTrash ();
						flag = false;
					}
					UpdateLine (Head,
						 Parser().Mid_Str(Block,Head.length()+1,Block.length()-1),seeTime);
					break;
				default :
					cout << "(Error In Parse see Message) : "  << Head << endl;
					break;
			}
                }
	}
}
bool Visual_Sensor::UpdatePlayer ( string strHead,string strData , Cycle seeCycle )
{
	try {
		strData = Parser().Mid_Str(strData,strHead.length()+1,strData.length()-1);
		PlayerT Pt = ConvertSToPT (strHead);
		PlayerInfo _TmpInfo;
		_TmpInfo.isTackling = false;
		_TmpInfo.isKicking  = false;
		_TmpInfo.reset ( );
		_TmpInfo.SeeTime  = seeCycle;
		_TmpInfo.Visible  = true;
		_TmpInfo.Quality  = 10;
		_TmpInfo.IDPlayer = Pt;

		if ( Pt <= 11 )
			_TmpInfo.TypePlayer = PLAYER_TEAMMATE;
		else if ( Pt > 11 && Pt <= 22 )
			_TmpInfo.TypePlayer = PLAYER_OPPONENT;
		else if ( Pt == 23 )
			_TmpInfo.TypePlayer = PLAYER_UNKNOWN_TEAMMATE;
		else if ( Pt == 24 )
			_TmpInfo.TypePlayer = PLAYER_UNKNOWN_OPPONENT;
		else 
			_TmpInfo.TypePlayer = PLAYER_UNKNOWN;
		_TmpInfo.goalie   =  isGoalie;
		_TmpInfo.Distance =  atof(Parser().Pars_Space (strData,2).c_str());
		_TmpInfo.Angle    =  atof(Parser().Pars_Space (strData,3).c_str());
		if (Parser().Pars_Space_Count( strData ) > 3)
		{
			_TmpInfo.Visible    = true;
			_TmpInfo.IsDynamic  = true;
			_TmpInfo.dist_chng  =  atof(Parser().Pars_Space (strData,4).c_str());
			_TmpInfo.dir_chng   =  atof(Parser().Pars_Space (strData,5).c_str());
			_TmpInfo.BodyAngle  =  atof(Parser().Pars_Space (strData,6).c_str());
			_TmpInfo.NeckAngle  =  atof(Parser().Pars_Space (strData,7).c_str());
			if ( Parser().Pars_Space_Count( strData ) >= 7 )
				_TmpInfo.ArmAngle = atof(Parser().Pars_Space (strData,8).c_str());
			if ( Parser().Pars_Space_Count( strData ) >= 8 )
				if (Parser().Pars_Space (strData,9) == "t")
					_TmpInfo.isTackling = true;
				else if (Parser().Pars_Space (strData,9) == "k")
					_TmpInfo.isKicking = true;
		}
		#if 0 // Player Test Ok
			cerr << "Player Data       : "  << strData << endl;
			cerr << "Player Distance   : " << _TmpInfo.Distance
			     << "\nPlayer Angle    : " << _TmpInfo.Angle  << endl;
			if (_TmpInfo.IsDynamic)
			{
				cerr << "\nPlayer Is Dynamic " 
				     << "\nPlayer Dis Chng  : " << _TmpInfo.dist_chng
				     << "\nPlayer dir Chng  : " << _TmpInfo.dir_chng  << endl;
				cerr << "Player Body   : " << _TmpInfo.BodyAngle
				     << "\nPlayer Neck : " << _TmpInfo.NeckAngle << endl;
				cerr << "Player Arm    : " << _TmpInfo.ArmAngle << endl;
				if (_TmpInfo.isTackling)
					cerr << "Player Tackle" << endl;
				else if (_TmpInfo.isKicking)
					cerr << "Player Kick" << endl;
			}
			else cerr << "Player No Dynamic " << endl;
			cerr << "-------------------------------------------" << endl;
			if (_TmpInfo.goalie)
				cerr << "Player Goalie" << endl;
			if (_TmpInfo.TypePlayer == PLAYER_TEAMMATE )
				cerr << "Player Teammate : " << _TmpInfo.IDPlayer << endl;
			else if (_TmpInfo.TypePlayer == PLAYER_OPPONENT )
				cerr << "Player Opponent : " << _TmpInfo.IDPlayer << endl;
			else cerr << "Player Unknown " << Pt << endl;
			cerr << "-------------------------------------------" << endl;
			cerr << "-------------------------------------------" << endl;
	   	#endif
		if (_TmpInfo.TypePlayer == PLAYER_TEAMMATE )
			_TeammateInfo.It_push ( _TmpInfo );
		else if (_TmpInfo.TypePlayer == PLAYER_OPPONENT )
			_OpponentInfo.It_push ( _TmpInfo );
		else 
			_UnknownInfo.It_push ( _TmpInfo );
		//cerr << "endl" << endl;
#if 0	
	cerr << "OK 1" << endl;
#endif
		return true;
	}
	catch (...)
	{
		return false;
	}
}
bool Visual_Sensor::UpdateBall ( string  strData , Cycle seeCycle )
{
	try {
		BallInfo _TmpInfo;
		_TmpInfo.reset ( );
		_TmpInfo.SeeTime = seeCycle;
		_TmpInfo.Visible = true;
		_TmpInfo.IsDynamic = false;
		_TmpInfo.Quality = 10;
		_TmpInfo.Distance =  atof(Parser().Pars_Space (strData,2).c_str());
		_TmpInfo.Angle    =  atof(Parser().Pars_Space (strData,3).c_str());
		if (Parser().Pars_Space_Count( strData ) > 3)
		{
			_TmpInfo.IsDynamic = true;
			_TmpInfo.dist_chng =  atof(Parser().Pars_Space (strData,4).c_str());
			_TmpInfo.dir_chng  =  atof(Parser().Pars_Space (strData,5).c_str());
		}
		
	   #if 0 // Ball Test Ok
		cerr << "Ball Data : "  << strData << endl;
	 	cerr << "Ball Distance : " << _TmpInfo.Distance 
		     << "\nBall Angle    : " << _TmpInfo.Angle    << endl;
		if (_TmpInfo.IsDynamic)
		{
			cerr << "\nBall Is Dynamic " 
			     << "\nBall Dis Chng : " << _TmpInfo.dist_chng
			     << "\nBall dir Chng : " << _TmpInfo.dir_chng  << endl;
		}
		else cerr << "Ball No Dynamic " << endl;
	   #endif

		_BallInfo.It_push ( _TmpInfo );
		return true;
	}
	catch (...)
	{
		cerr << "(Visual Sensor)::Ball Update exception" << endl;
		return false;
	}
}
bool Visual_Sensor::UpdateLine ( string strHead,string  strData , Cycle seeCycle )
{
	try
	{
		LineInfo _TmpInfo;
		_TmpInfo.reset ( );
		_TmpInfo.SeeTime = seeCycle;
		_TmpInfo.Visible = true;
		_TmpInfo.Quality = 10;
		_TmpInfo.TypeFlag = _Flag_Map.getResult (strHead);
		_TmpInfo.Distance =  atof(Parser().Pars_Space (strData,2).c_str());
		_TmpInfo.Angle    =  atof(Parser().Pars_Space (strData,3).c_str());
		#if 0
			cerr << "Line Data       : " << strData << endl;
			cerr << "Line Type       : " << _TmpInfo.TypeFlag << endl; 
			cerr << "Line Distance   : " << _TmpInfo.Distance 
			     << "\nLine Angle    : " << _TmpInfo.Angle    << endl;
			cerr << "-----------------------------------------------------" << endl;
		#endif
		_LineInfo.It_push ( _TmpInfo );
		return true;
	}
	catch (...)
	{
		return false;
	}
}
bool Visual_Sensor::UpdateFlag ( string strHead,string  strData , Cycle seeCycle )
{
	try
	{
		FlagInfo _TmpInfo;
		_TmpInfo.reset ( );
		_TmpInfo.SeeTime = seeCycle;
		_TmpInfo.Visible = true;
		_TmpInfo.Quality = 10;
		_TmpInfo.TypeFlag = _Flag_Map.getResult (strHead);
		_TmpInfo.Distance =  atof(Parser().Pars_Space (strData,2).c_str());
		_TmpInfo.Angle    =  atof(Parser().Pars_Space (strData,3).c_str());
		#if 0
			cerr << "Flag Type       : " << _TmpInfo.TypeFlag << endl; 
			cerr << "Flag Distance   : " << _TmpInfo.Distance 
			     << "\nFlag Angle    : " << _TmpInfo.Angle    << endl;
			cerr << "-----------------------------------------------------" << endl;
		#endif

		_FlagInfo.It_push ( _TmpInfo );
		return true;
	}
	catch (...)
	{
		return false;
	}
}
bool Visual_Sensor::Set_Flag_Map ( )
{
    	_Flag_Map.Map_AddItem ( "g l", FT_GOAL_L);
  	_Flag_Map.Map_AddItem ( "g r", FT_GOAL_R);
  	_Flag_Map.Map_AddItem ( "l l", FT_LINE_L);
  	_Flag_Map.Map_AddItem ( "l r", FT_LINE_R);
  	_Flag_Map.Map_AddItem ( "l b", FT_LINE_B);
  	_Flag_Map.Map_AddItem ( "l t", FT_LINE_T);
	_Flag_Map.Map_AddItem ( "f l t", FT_FLAG_L_T);
  	_Flag_Map.Map_AddItem ( "f l t 50", FT_FLAG_T_L_50);
  	_Flag_Map.Map_AddItem ( "f l t 40", FT_FLAG_T_L_40);
  	_Flag_Map.Map_AddItem ( "f l t 30", FT_FLAG_T_L_30);
  	_Flag_Map.Map_AddItem ( "f l t 20", FT_FLAG_T_L_20);
  	_Flag_Map.Map_AddItem ( "f l t 10", FT_FLAG_T_L_10);
  	_Flag_Map.Map_AddItem ( "f l 0", FT_FLAG_T_0);
  	_Flag_Map.Map_AddItem ( "f c t", FT_FLAG_C_T);
  	_Flag_Map.Map_AddItem ( "f t r 10", FT_FLAG_T_R_10);
  	_Flag_Map.Map_AddItem ( "f t r 20", FT_FLAG_T_R_20);
  	_Flag_Map.Map_AddItem ( "f t r 30", FT_FLAG_T_R_30);
  	_Flag_Map.Map_AddItem ( "f t r 40", FT_FLAG_T_R_40);
  	_Flag_Map.Map_AddItem ( "f t r 50", FT_FLAG_T_R_50);
  	_Flag_Map.Map_AddItem ( "f r t" , FT_FLAG_R_T);
  	_Flag_Map.Map_AddItem ( "f r t 30", FT_FLAG_R_T_30);
  	_Flag_Map.Map_AddItem ( "f r t 20", FT_FLAG_R_T_20);
  	_Flag_Map.Map_AddItem ( "f r t 10", FT_FLAG_R_T_10);
  	_Flag_Map.Map_AddItem ( "f g r t", FT_FLAG_G_R_T);
  	_Flag_Map.Map_AddItem ( "f r 0", FT_FLAG_R_0);
  	_Flag_Map.Map_AddItem ( "f g r b", FT_FLAG_G_R_B);
  	_Flag_Map.Map_AddItem ( "f r b 10", FT_FLAG_R_B_10);
  	_Flag_Map.Map_AddItem ( "f r b 20", FT_FLAG_R_B_20);
  	_Flag_Map.Map_AddItem ( "f r b 30", FT_FLAG_R_B_30);
  	_Flag_Map.Map_AddItem ( "f r b", FT_FLAG_R_B);
  	_Flag_Map.Map_AddItem ( "f b r 50", FT_FLAG_B_R_50);
  	_Flag_Map.Map_AddItem ( "f b r 40", FT_FLAG_B_R_40);
  	_Flag_Map.Map_AddItem ( "f b r 30", FT_FLAG_B_R_30);
  	_Flag_Map.Map_AddItem ( "f b r 20", FT_FLAG_B_R_20);
  	_Flag_Map.Map_AddItem ( "f b r 10", FT_FLAG_B_R_10);
  	_Flag_Map.Map_AddItem ( "f c b", FT_FLAG_C_B);
  	_Flag_Map.Map_AddItem ( "f b 0", FT_FLAG_B_0);
  	_Flag_Map.Map_AddItem ( "f b l 10", FT_FLAG_B_L_10);
  	_Flag_Map.Map_AddItem ( "f b l 20", FT_FLAG_B_L_20);
  	_Flag_Map.Map_AddItem ( "f b l 30", FT_FLAG_B_L_30);
  	_Flag_Map.Map_AddItem ( "f b l 40", FT_FLAG_B_L_40);
  	_Flag_Map.Map_AddItem ( "f b l 50", FT_FLAG_B_L_50);
  	_Flag_Map.Map_AddItem ( "f l b", FT_FLAG_L_B);
  	_Flag_Map.Map_AddItem ( "f l b 30", FT_FLAG_L_B_30);
  	_Flag_Map.Map_AddItem ( "f l b 20", FT_FLAG_L_B_20);
  	_Flag_Map.Map_AddItem ( "f l b 10", FT_FLAG_L_B_10);
  	_Flag_Map.Map_AddItem ( "f g l b", FT_FLAG_G_L_B);
  	_Flag_Map.Map_AddItem ( "f l 0", FT_FLAG_L_0);
  	_Flag_Map.Map_AddItem ( "f g l t", FT_FLAG_G_L_T);
  	_Flag_Map.Map_AddItem ( "f l t 10", FT_FLAG_L_T_10);
  	_Flag_Map.Map_AddItem ( "f l t 20", FT_FLAG_L_T_20);
  	_Flag_Map.Map_AddItem ( "f l t 30", FT_FLAG_L_T_30);
  	_Flag_Map.Map_AddItem ( "f p l t", FT_FLAG_P_L_T);
  	_Flag_Map.Map_AddItem ( "f p l c", FT_FLAG_P_L_C);
  	_Flag_Map.Map_AddItem ( "f p l b", FT_FLAG_P_L_B);
  	_Flag_Map.Map_AddItem ( "f p r t", FT_FLAG_P_R_T);
  	_Flag_Map.Map_AddItem ( "f p r c", FT_FLAG_P_R_C);
  	_Flag_Map.Map_AddItem ( "f b r b", FT_FLAG_P_R_B);
	_Flag_Map.Map_AddItem ( "f c", FT_FLAG_C);
	return true;	
}
PlayerInfo Visual_Sensor::getPlayerTeammateById ( PlayerT PID )
{
	vector<PlayerInfo>::iterator hp = _TeammateInfo.returnVector ( ).begin();
	PlayerInfo TmpData,TmpPlayer;
	TmpData.reset();
	TmpPlayer.reset ();
	int Size = _TeammateInfo.returnVector ( ).size ();
	double QualityMax = 0;
	for (_TeammateInfo.It_moveFirst () ; !_TeammateInfo.It_eof() ; _TeammateInfo.It_moveNext () )
	{
		TmpData = _TeammateInfo.It_Item ( );
		if (TmpData.IDPlayer == PID)
		{
			if (TmpData.Visible)
				return TmpData;
			else {
				if (TmpData.Quality >= QualityMax)
				{
					TmpPlayer  = TmpData;
					QualityMax = TmpData.Quality;
				}
			}
		}
	}
	return TmpPlayer;
}
PlayerInfo Visual_Sensor::getPlayerOpponentById ( PlayerT PID )
{
	vector<PlayerInfo>::iterator hp = _OpponentInfo.returnVector ( ).begin();
	PlayerInfo TmpData,TmpPlayer;
	TmpData.reset();
	TmpPlayer.reset ();
	int Size = _OpponentInfo.returnVector ( ).size ();
	double QualityMax = 0;
	for (_OpponentInfo.It_moveFirst () ; !_OpponentInfo.It_eof() ; _OpponentInfo.It_moveNext () )
	{
		TmpData = _OpponentInfo.It_Item ( );
		if (TmpData.IDPlayer == PID)
		{
			if (TmpData.Visible)
				return TmpData;
			else {
				if (TmpData.Quality >= QualityMax)
				{
					TmpPlayer  = TmpData;
					QualityMax = TmpData.Quality;
				}
			}
		}
	}
	return TmpPlayer;
}
Iterator_Lib<PlayerInfo> Visual_Sensor::getItrPlayerTeammateById ( PlayerT PID )
{
	PlayerInfo TmpData;
	Iterator_Lib<PlayerInfo> BackTmp;
	BackTmp.It_clear ();
	int Size = _TeammateInfo.returnVector ( ).size ();
	double QualityMax = 0;
	for (_TeammateInfo.It_moveFirst () ; !_TeammateInfo.It_eof() ; _TeammateInfo.It_moveNext () )
	{
		TmpData = _TeammateInfo.It_Item ( );
		if (TmpData.IDPlayer == PID)
		{
			BackTmp.It_push ( TmpData );
		}
	}
	return BackTmp;
}
Iterator_Lib<PlayerInfo> Visual_Sensor::getItrPlayerOpponentById ( PlayerT PID )
{
	PlayerInfo TmpData;
	Iterator_Lib<PlayerInfo> BackTmp;
	BackTmp.It_clear ();
	int Size = _OpponentInfo.returnVector ( ).size ();
	double QualityMax = 0;
	for (_OpponentInfo.It_moveFirst () ; !_OpponentInfo.It_eof() ; _OpponentInfo.It_moveNext () )
	{
		TmpData = _OpponentInfo.It_Item ( );
		if (TmpData.IDPlayer == PID)
		{
			BackTmp.It_push ( TmpData );
		}
	}
	return BackTmp;
}
