/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "CommandQ.h"
#include "../Util/Timer.h"

CommandQ::CommandQ ( )
{
	clearCommandQ ( );
	SeeFlag = false;
	SendFlag = false;
}
CommandQ::CommandQ ( CMD cmd)
{
	clearCommandQ ( );
	pushCommandInQ ( cmd );
}
void CommandQ::pushCommandInQ  ( CMD cmd  )
{
	CommandList.push_back (cmd);
}
void CommandQ::filterCommandQ  (       )
{
	int Prim = 0 ;
	vector <CMD> :: iterator it = CommandList.begin ();
	for (it ; it != CommandList.end (); it++)
	{
		if (it->cmd == CMD_DASH || it->cmd == CMD_TURN || it->cmd ==  CMD_CATCH 
		  ||it->cmd == CMD_KICK || it->cmd == CMD_MOVE || it->cmd ==  CMD_TACKLE )
		{
			Prim++;
			if (Prim > 1)
				CommandList.erase (it);
		}
	}
	vector <CMD> :: iterator last;
	last = unique (CommandList.begin(),CommandList.end() ,UniqCmp());
	CommandList.erase (last,CommandList.end());
}
void CommandQ::clearCommandQ   (       )
{
	CommandList.clear();
}
void CommandQ::runLoopCommandQ (   UDPsocket &sock    )
{
        //if (SendFlag)
        //{
          //  cerr << "(Command Q)::2Run" << endl;    
           // clearCommandQ   (       );
        //}
	filterCommandQ ( );
	
	while (CommandList.size ())
	{
	    sock.send_msg(CommandList.back().cmdStr);
	    CommandList.pop_back ( );
	}
	SendFlag = true;
	
}
void CommandQ::runLoopCommandQ ( bool flag , UDPsocket &sock)
{
	if (flag)
	{
		runLoopCommandQ (sock);
	}
}
int  CommandQ::commandQSize    (       )
{
	return CommandList.size();
}

