/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "../Connection/udpsocket.h"
#include "../Commander/CommandQ.h"
#include "../Parser/ParseServer.h"
#include "../WorldModel/WorldModel.h"
#include "../WorldModel/Localization.h"
#include "../WorldModel/Self.h"
#include "../Skill/BasicSkill.h"
#include "../Util/Timer.h"

#include "Agent.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;
int LOG;
WorldModel WM;
CommandQ   CQ;


int main( int argc, char * argv[] )
{
        LOG = 1;
	char *input1;
	char *input2;
	char *input3;
	char *ipAddress;
	bool Goali = false;
	double ServerVer;
	char *teamname;
	Agent agent;
	BasicSkill BS;
	if (argc < 5 )
	{
		cout << "Agent [[Server] [Host Name] [IsGoali] [TeamName]]" << endl;
		Goali = false;
		teamname = "Mars";
		ipAddress  = "localhost";
		ServerVer = 14.1;
	}
	else 
	{
		ServerVer = atof (argv [1]);
		input1 = argv [2];
		input2 = argv [3];
		input3 = argv [4];
		if (input2[0] == 'o') {
			Goali = true;
		}
		teamname = input3;
		ipAddress  = input1;
	}
		
	int  portAddress = 6000,lt;
        char *messag;
	char buf[10000];
	int len;
  	UDPsocket sock;
	
  	cout << "\nSystem Connect = " << sock.init_socket_fd();
  	cout << "\nServer Connect = " << sock.init_serv_addr(ipAddress,portAddress);
	

 	agent.Init (teamname,ServerVer,Goali);
#if 0
	ofstream s("saeed.log",ios::out);
#endif
        CQ.SetGameFlag(false);
	CQ.runLoopCommandQ ( sock );	

	while (true)
	{
	      	
	      if (sock.recv_msg (buf,len,true))
	      {
		  WM.Update (buf);
                  if (!CQ.GetGameFlag())
                        agent.run ();
	      }
	      CQ.runLoopCommandQ (  sock );
	 }
}

