/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _ITERATOR_LIB
#define _ITERATOR_LIB
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <exception>

using namespace std;
typedef int Index;
enum ItAction 
{
	IT_PUSH,
	IT_CLEAR,
	IT_UNIQUE,
	IT_SORT,
	IT_POP
};
template <class ItData>
class Iterator_Lib
{
	private :
		vector <ItData> ItList;
		Index  ItItem;
		
	public :
		void operator =(const vector<ItData> &data) { this->ItList = data; }
		class TargetCmp: public std::binary_function< ItData, ItData, bool > {
			public:
        			bool operator()( const ItData & lhs,
                        		        const ItData & rhs ) const
          			{
					return lhs > rhs;
          			}
		};
		class TargetUniq: public std::binary_function< ItData, ItData, bool > {
			public:
        			bool operator()( const ItData & lhs,
                        		        const ItData & rhs ) const
          			{
					return lhs == rhs;
          			}
		};
		class TargetFind: public std::binary_function< ItData, ItData, bool > {
			public:
        			ItData operator()( const ItData & lhs,
                        		        const ItData & rhs ) const
          			{
					if (lhs == rhs)
					return lhs;
          			}
		};
		class TargetErase: public std::binary_function< ItData, ItData, bool > {
			public:
        			bool operator()( const ItData & lhs,
                        		        const ItData & rhs ) const
          			{
					return lhs < rhs;
          			}
		};
		
		Iterator_Lib ( )
		{
			this->ItItem = 0;
		}
		Iterator_Lib (ItData Id, ItAction Ia )
		{
			switch (Ia)
			{
				case IT_PUSH :
					this->It_push (Id);	
					break;
				case IT_CLEAR :
					this->It_clear (Id);
					break;
				case IT_UNIQUE :
					this->It_unique (Id);
					break;
				case IT_SORT :
					this->It_sort (Id);
					break;
				case IT_POP :
					this->It_pop (Id);
					break;
			}
		}
		bool   It_push     ( ItData Id)
		{
			try {
				this->ItList.push_back(Id);
				return true;
			}
			catch (bad_alloc)
			{
				cerr << "(Iterator)::Bad Alloc Error" << endl;
				return false;
			}
			catch (...)
			{
				cerr << "(Iterator)::Add Item Failed" << endl;
				return false;
			}
		}
		bool   It_clear    (        )
		{
			try {
				this->ItList.clear ();
			}
			catch (...)
			{
				return false;
			}
		}
		bool   It_unique   (   	    )
		{
// 			try {
// 				vector <int> :: iterator last;
// 				last = unique ( this->ItList.begin(),this->ItList.end(),TargetUniq());
// 				this->ItList.erase (last , this->ItList.end() );
// 				return true;
// 			}
// 			catch (...)
// 			{
// 				return false;
// 			}
			
		}
		bool   It_sort     (        )
		{
			try {
				sort ( this->ItList.begin(),this->ItList.end(),TargetCmp());
				return true;
			}
			catch (...)
			{
				return false;
			}
		}
		bool   It_pop      (        )
		{
			if (this->ItItem > 0)
			{
				this->ItItem--;
				return true;
			}
			return false;
		}
		ItData It_Item     (        )
		{
			ItData ItNull;
			try {
				if (this->ItItem != 0)
				{
					//cerr << "this->ItItem 1 : " << this->ItItem << endl;
					return this->ItList[ItItem];
				}
				//cerr << "NULL1" << endl;
				return ItNull;
			}
			catch (...)
			{
				//cerr << "NULL2" << endl;
				return ItNull;
			}
		}
		vector<ItData>  It_find     ( ItData id)
		{
			return find(this->ItList.begin(),this->ItList.end(),id);
		}
		bool   It_eof      (        )
		{
			return (this->ItItem >= (It_countItem ()-1));
		}
		bool   It_moveIndex( Index  idx)
		{
			if (idx <= this->It_countItem () && idx >= 0)
				this->ItItem = idx;
			else
				return false;
			return true;
		}
		bool   It_moveNext (        )
		{
			if ( this->ItItem < this->It_countItem () )
				this->ItItem++;
			else
				return false;
			return true;
		}
		bool   It_moveBack (        )
		{
			if ( this->ItItem > 0 )
				this->ItItem--;
			else
				return false;
			return true;
		}
		bool   It_moveLast (        )
		{
			if ( this->ItItem != It_countItem () )
				this->ItItem = It_countItem ();
			else
				return false;
			return true;
		}
		bool   It_moveFirst(        )
		{
			if ( this->ItItem != 0 )
				this->ItItem = 0;
			else
				return false;
			return true;
		}
		bool   It_Count ( )
		{
			int CountNum;
			count_if (this->ItList.begin(),this->ItList.end(),TargetUniq(),&CountNum );
			return CountNum;
		}
		
		bool   It_erase ( ItData itComp)
		{
			for (this->It_moveFirst();!this->It_eof();this->It_moveNext)
				if ( itComp == this->It_Item ( ) )
 					ItList.erase (this->ItItem);
			return true;
		}
		int    It_countItem(        )
		{
			return ItList.size ();
		}
		vector<ItData> & returnVector ( )
		{
			return this->ItList;
		}
		bool  isEmpty(     )
		{
			return this->ItList.empty();
		}
};
#endif
