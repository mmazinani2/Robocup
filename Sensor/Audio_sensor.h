/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _AUDIO_SENSOR
#define _AUDIO_SENSOR

#include "../Util/MapLib.h"
#include "../Types/SoccerTypes.h"
#include "../Parser/ParseServer.h"
#include "../Util/IteratorLib.h"

#include <algorithm>

typedef string Message;
struct HearValue
{
	string Sender;
	int    PNum;
	string HearData;
	int    UpTime;
	double Quality;
	bool operator==( HearValue HV)  const
	{return ( HV.Sender == Sender );}


};

class cmpT
	: public std::binary_function< HearValue, HearValue, bool > {
public:
	result_type operator()( const first_argument_type & lhs,
			const second_argument_type & rhs ) const
	{
		return lhs.UpTime < rhs.UpTime;
	}
};

class Audio_sensor
{

	private :
		vector<HearValue> HVvec;
		map<string,RefereeMessageT,greater<string> > _mapVal;
		MapLib <RefereeMessageT> RMessage;
		Iterator_Lib <HearValue> HValue;
		RefereeMessageT RFT;
		bool         UpdateAudio;
		static int   UpdateTime;
		bool         Trash ( );
	public  :
		Audio_sensor ( );
		RefereeMessageT getRefereeMessage ( );
		int             getRefereeMessageTime ( );
		bool    	RefereeMessageMap (    );
		bool            setRefereeMessage ( RefereeMessageT );

		virtual bool Update   ( string );
		virtual bool isUpdate (        )
		{
			return UpdateAudio;
		}
		virtual int TimeUpdate (       )
		{
			return UpdateTime;
		}
		virtual bool reset    (        )
		{
			UpdateAudio = false;
		}
};
#endif
