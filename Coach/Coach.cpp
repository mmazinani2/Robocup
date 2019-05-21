/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Coach.h"

Coach::Coach ():setTypeFlag(false)
{

}
bool Coach::Init    ( char *teamname , float server )
{
	return BS.Make_Init ( teamname , server ,false);
}
bool Coach::run     (                               )
{
	if ( !IsSetType ( ) )
		setType ();
	
}
bool Coach::setType (                               )
{
	Hetero_Player HP = WM.getHeteroType ( );
	if (HP.getHeteroCount( ) == 18)
	{	
// 		cerr << "Ok" << endl;
		Hetero_Player HP = WM.getHeteroType ( );
		vector<HPlayer> PlayerTypeList = HP.getHeteroPlayer ( );
		HP.sortBySpeedReal ( );
		PlayerTypeList = HP.getHeteroPlayer ( );
		BS.Make_Change_Player_Type ( 1 ,PlayerTypeList[ 0].id);
		BS.Make_Change_Player_Type ( 2 ,PlayerTypeList[ 1].id);
		BS.Make_Change_Player_Type ( 3 ,PlayerTypeList[ 2].id);
		BS.Make_Change_Player_Type ( 4 ,PlayerTypeList[ 3].id);
		BS.Make_Change_Player_Type ( 5 ,PlayerTypeList[ 4].id);
		BS.Make_Change_Player_Type ( 6 ,PlayerTypeList[ 5].id);
		BS.Make_Change_Player_Type ( 7 ,PlayerTypeList[ 6].id);
		BS.Make_Change_Player_Type ( 8 ,PlayerTypeList[ 7].id);
		BS.Make_Change_Player_Type ( 9 ,PlayerTypeList[ 8].id);
		BS.Make_Change_Player_Type ( 10,PlayerTypeList[ 9].id);
		BS.Make_Change_Player_Type ( 11,PlayerTypeList[10].id);
		setTypeFlag = true;
	}
	else
		setTypeFlag = false;
}
bool Coach::IsSetType ( )
{
	return setTypeFlag;
}
