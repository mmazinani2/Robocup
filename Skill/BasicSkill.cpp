/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "BasicSkill.h"


BasicSkill::BasicSkill ( )
{
}
Char BasicSkill::Get_Skill ( )
{
	return Message;
}
CMD  BasicSkill::getCommandType (     )
{
	return Command;
}
bool BasicSkill::Make_Turn ( float ang)
{
	stst.str("");
	if( WM.getServerParam().get_minmoment () <= ang 
			&& ang <= WM.getServerParam().get_maxmoment () )
    				stst << "(turn " << ang << ")\n";
  	else 
 	{
    		ang = 0.0;
    		stst << "(turn 0)\n";
  	}
  	Command.cmd = CMD_TURN;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
        _MapValue val;
        val.PAR1 = ang;
        WM.SetValByAct("BODY",val);
	return true;
}
bool BasicSkill::Make_Turn_Neck ( float ang)
{
	stst.str("");
	if( WM.getServerParam().get_minneckmoment () <= ang 
			&& ang  <= WM.getServerParam().get_maxneckmoment () )
   		 		stst << "(turn_neck " << ang << ")\n";
  	else
  	{
    		ang = 0.0;
    		stst << "(turn_neck 0)\n";
  	}
	Command.cmd = CMD_TURNNECK;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
        _MapValue val;
        val.PAR1 = ang;
        WM.SetValByAct("NECK",val);
	return true;
}
bool BasicSkill::Make_Dash      ( float po,float Ang)
{
	stst.str("");
	if( WM.getServerParam().get_min_dash_power() <= po 
			&& po <= WM.getServerParam().get_max_dash_power() )
 		   		stst << "(dash " << po << " " << Ang << ")\n";
 	else
  	{
    		po = 0.0;
    		stst << "(dash 0)\n";
  	}
  	Command.cmd = CMD_DASH;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
        _MapValue val;
        val.PAR1 = po;
        val.PAR2 = Ang;
        WM.SetValByAct("DASH",val);
	return true;
}
bool BasicSkill::Make_SideDash   ( float po , AngDeg Ang )
{
	stst.str("");
	if( WM.getServerParam().get_min_dash_power() <= po 
			&& po <= WM.getServerParam().get_max_dash_power() )
 		   		stst << "(dash " << po << " " << Ang << ")\n";
 	else
  	{
    		po = 0.0;
    		stst << "(dash 0)\n";
  	}
  	Command.cmd = CMD_DASH_SIDE;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
         _MapValue val;
        val.PAR1 = po;
        val.PAR2 = Ang;
        WM.SetValByAct("DASH",val);
	return true;
}
bool BasicSkill::Make_Kick      ( float po, float dir)
{
	stst.str("");
    	stst << "(kick " << po <<" " << dir <<")\n";
  	Command.cmd = CMD_KICK;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
        _MapValue val;
        val.PAR1 = po;
        val.PAR2 = dir;
        WM.SetValByAct("KICK",val);
	return true;
}
bool BasicSkill::Make_Move      ( float X, float Y)
{	
	stst.str("");
   	stst << "(move " << X << " " << Y << ")\n";
  	Command.cmd = CMD_MOVE;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
        _MapValue val;
        val.PAR1 = X;
        val.PAR2 = Y;
        WM.SetValByAct("MOVE",val);
	return true;
}
bool BasicSkill::Make_Catch     ( float po)
{
	stst.str("");
	if( WM.getServerParam().get_minmoment ( ) <= po 
			&& po <= WM.getServerParam().get_maxmoment () )
    				stst << "(catch " << po << ")\n";
 	else
  	{
		po = max (po,WM.getServerParam().get_minmoment ( ));
		po = min (po,WM.getServerParam().get_maxmoment ( ));
   		stst << "(catch " << po << ")\n";
  	}
 	Command.cmd = CMD_CATCH;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
        _MapValue val;
        val.PAR1 = po;
        WM.SetValByAct("CATCH",val);
	return true;
}
bool BasicSkill::Make_Say       ( Char  msg)
{
	stst.str("");
	if( msg != NULL && msg[0] != '\0' )
   		 stst << "(say \""<< msg <<"\")\n";
 	else
 	{
  		  stst << "(say \"\")\n";
  	}
 	Command.cmd = CMD_SAY;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
	return true;
}
bool BasicSkill::Make_Change_View   ( ViewAngleT vat, ViewQualityT vqt)
{
	stst.str("");
	Char  va = "";
	Char  vq = "";
	switch( vat )
  	{
   		 case VA_NARROW: 
			 va = "narrow";
			 break;
   		 case VA_NORMAL:
			 va = "normal";
    		 	 break;	 
		 case VA_WIDE:
			 va = "wide";
			 break;
   		 case VA_ILLEGAL:
			 va = "normal";	
			 break; 
    		 default: 
			  va = "normal";
	                  break;
  	}
	switch( vqt )
 	{
    		case VQ_HIGH:   
			 vq = "high";
    			 break;
		case VQ_LOW:
			 vq = "low";
			 break;
    		case VQ_ILLEGAL:
			 vq = "high";
			 break;	
    		default:       
			 vq = "high";
			 break;
  	}
	if( vat != VA_ILLEGAL && vqt != VQ_ILLEGAL )
    		stst << "(change_view " << va << " " << vq <<")\n";
  	Command.cmd = CMD_CHANGEVIEW;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
	return true;
}
bool BasicSkill::Make_Pointto       ( float X, float Y)
{
	stst.str("");
	if( X < 0 )
  	{
    		stst << "(pointto off)\n";
  	}

  	if( Y >= WM.getServerParam().get_minmoment ()
			&& Y <= WM.getServerParam().get_maxmoment()  )
   		 		stst << "(pointto " << X << " " << Y << ")\n";
  	else
  	{
		Y = max (Y , WM.getServerParam().get_minmoment ());
		Y = min (Y , WM.getServerParam().get_maxmoment ());
    		stst << "(pointto " << X << " " << Y << ")\n";
  	}
  	Command.cmd = CMD_POINTTO;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
	return true;
}
bool BasicSkill::Make_Tackl         ( float po)
{
	stst.str("");
	if( 0 <= po && po <= WM.getServerParam().get_max_tackle_power () )
    		stst << "(tackle " << po << ")\n";
  	
  	Command.cmd = CMD_TACKLE;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
        _MapValue val;
        val.PAR1 = po;
        WM.SetValByAct("TACKL",val);
	return true;
}
bool BasicSkill::Make_Attentionto   ( Char teamn,int Unum)
{
	stst.str("");
  	if( Unum <= 0 )
  	{
    		stst << "(attentionto off)\n";
  	}

  	if( Unum > 0  && Unum <= MAX_TEAMMATES )
    		stst << "(attentionto " << teamn << " " << Unum << ")\n";
  	Command.cmd = CMD_ATTENTIONTO;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
	return true;
}
bool BasicSkill::Make_Change_Player_Type ( int X,int Y)
{
	stst.str("");
 	if( (int)X > 0  && (int)X <= MAX_TEAMMATES &&
     		 (int)Y >= 0 && (int)Y < MAX_HETERO_PLAYERS  )
    		stst << "(change_player_type " << X << " " << Y << ")\n";
	//cerr << "------------- " << stst.str() << endl;
  	Command.cmd = CMD_CHANGEPLAYER;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
	return true;
}
bool BasicSkill::Make_Sense_Body    (             )
{
	stst.str("");
	stst << "(sense_body)\n";
  	Command.cmd = CMD_SENSEBODY;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
	return true;
}
bool BasicSkill::Make_Init ( Char Teamn, float Ver,bool Goli)
{
	stst.str("");
	if (Goli)
		stst << "(init " << Teamn << " (version "<< Ver << ") (goalie))\n";
	else 
		stst << "(init " << Teamn << " (version " << Ver <<"))\n" ;
  	Command.cmd = CMD_INIT;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
	return true;
}
bool BasicSkill::Make_Reconnect	( Char Tname, int unum)
{
	stst.str("");
	stst << "(reconnect " << Tname << " " << unum <<")\n";
  	Command.cmd = CMD_RECONNECT;
	Command.cmdStr = stst.str();
	CQ.pushCommandInQ  ( Command   );
	return true;
}
bool BasicSkill::Make_Synch_See ()
{
	Command.cmd = CMD_SYNCH_SEE;
	Command.cmdStr = "(synch_see)\n";
	CQ.pushCommandInQ  ( Command   );
	return true;
}
bool BasicSkill::Make_Bye ()
{
	Command.cmd = CMD_BYE;
	Command.cmdStr = "(bye)\n";
	CQ.pushCommandInQ  ( Command   );
	return true;
}
