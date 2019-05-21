/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _MAP_LIB
#define _MAP_LIB
#include <map>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <exception>
#include "../Types/SoccerTypes.h"


using namespace std;

typedef string KEY;

template <class MapData>
class MapLib 
{
	private :
		
		map<KEY,MapData,greater<string> > _mapVal;
		long  MapItem;
	public :
		MapLib ( ):MapItem(0)
		{

		}
		MapLib ( KEY keyVal, MapData mData):MapItem(0)
		{
			Map_AddItem ( keyVal, mData );
		}
		bool Map_AddItem ( KEY keyVal, MapData mData )
		{
			try {
				_mapVal [string (keyVal)] = mData;
				++MapItem;
			}
			catch (bad_alloc)
			{
				//cerr << "(Iterator)::Bad Alloc Error" << endl;
				return false;
			}
			catch (...)
			{
				//cerr << "(Iterator)::Add Item Failed" << endl;
				return false;
			}
		}
		void show(  )
		{
			MapData m1;
  			map <KEY,string,greater<string> >::iterator m = _mapVal.begin();
			for (m ; m != _mapVal.end() ; m++)
			{
				cout << "Head : " << m->first  << "\tValue : " << m->second  <<endl;
			}
		}
		bool deleteItem ( KEY keymap )
		{
			_mapVal.erase ( keymap );
		}
		bool deleteAllItem (  )
		{
			_mapVal.clear (  );
		}
		MapData getResult ( KEY keyVal )
		{
			return _mapVal [string (keyVal)];
		}


};
#endif

