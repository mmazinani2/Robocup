/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "../Connection/udpsocket.h"
#include "../Commander/CommandQ.h"
#include "Coach.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
 
using namespace std;

WorldModel WM;
CommandQ  CQ;

int main( int argc, char * argv[] )
{
	char *input1;
	char *input2;
	char *input3;
	char *ipAddress;
	bool Goali = false;
	double ServerVer;
	char *teamname;
	Coach coach;
	if (argc < 5 )
	{
		cout << "Coach [[Server] [Host Name] [IsGoali] [TeamName]]" << endl;
		Goali = false;
		teamname = "Mars";
		ipAddress  = "localhost";
		ServerVer = 14.0;
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
	int  portAddress = 6002,lt;
        char *messag;
	char buf[10000];
	int len;
  	UDPsocket sock;
  	cout << "\nCoach Connect = " << sock.init_socket_fd();
  	cout << "\nCoach Connect = " << sock.init_serv_addr(ipAddress,portAddress);
	bool SetType = false;
	coach.Init (teamname,ServerVer);
	WM.Update (buf);
	CQ.runLoopCommandQ (sock);
	while (true)
	 {
		
		if (sock.recv_msg (buf,len,true))
			WM.Update (buf);
 		//cerr << buf << endl;
		coach.run (   );
		CQ.runLoopCommandQ (sock);
		
	 }
}

