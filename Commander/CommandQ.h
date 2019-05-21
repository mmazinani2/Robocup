/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _CQ_
#define _CQ_

#include "../Types/SoccerTypes.h"
#include "../Connection/udpsocket.h"
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <exception>

using namespace std;
struct CMD
{
	CommandT cmd;
	string   cmdStr;
	bool operator==(const CMD &c)  const
		{return ( cmd == c.cmd && !strcmp (cmdStr.c_str(),c.cmdStr.c_str()) );}
};
class UniqCmp
	: public std::binary_function< CMD, CMD, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
                                const second_argument_type & rhs ) const
	{
		return lhs == rhs;
	}
};
class CommandQ
{
	private :
		vector <CMD> CommandList;
		bool SendFlag;
		bool SeeFlag;
	public :
		CommandQ ( );
		CommandQ ( CMD );
		void SetGameFlag     ( bool flag ){SendFlag = flag;}
                bool GetGameFlag     (  ){return SendFlag;}
		void SetSeeFlag     ( bool flag ){SeeFlag = flag;}
		void pushCommandInQ  ( CMD   );
		void filterCommandQ  (       );
		void clearCommandQ   (       );
		void runLoopCommandQ (   UDPsocket &   );
		void runLoopCommandQ ( bool ,UDPsocket &);
		int  commandQSize    (       );
};
#endif
