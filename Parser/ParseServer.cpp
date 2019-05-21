/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "ParseServer.h"

Parser::Parser ()
{

}
string Parser::Pars_Value ( string strData,int Item)
{
		int len = strData.length ();
		int Brc1 = 0 , Brc2 = 0;
		bool tag = false;
		string stTmp = "";
		for (int LpCount = 0 ; LpCount < len; LpCount++)
		{	
			if ( strData [ LpCount ] == '(' )
			{
				tag = true;
 				if (Brc1 >= 1)
 					stTmp += strData [ LpCount ];
				Brc1++;
			}
			else if ( strData [ LpCount ] == ')' )
			{
 				if (tag && Brc1 > 1)
 					stTmp += strData [ LpCount ];
				Brc1--;
			}
			else 
			{
				if (tag)
					stTmp += strData [ LpCount ];
			}
			if ( tag && Brc1 <= 0 )
			{
				Brc2++;
				tag = false;
				if (Brc2 >= Item)
					return stTmp;
				else
					stTmp = "";
			}
			
		} 
		return stTmp;
}
int Parser::Pars_Value_Count ( string strData)
{
	if (strData == "" ) return '\0';
	int len = strData.length ();
	int Brc1 = 0 , Brc2 = 0;
	bool tag = false;
	string stTmp = "";
	for (int LpCount = 0 ; LpCount < len; LpCount++)
	{	
		if ( strData [ LpCount ] == ')' )
		{
			tag = true;
			Brc1++;
		}
		else if ( strData [ LpCount ] == '(' )
		{
			Brc1--;
		}
		if ( tag && Brc1 == 0 )
		{
			tag = false;
			Brc2++;
		}
	}
	return Brc2;
}
string Parser::Mid_Str (string strData, int startPoint, int endPoint )
{
	string strLT = "";
	int len = strData.length();
	if (len == 0 || startPoint > len || endPoint > len ) return "";
	else 
	{
		for ( int i = startPoint; i <= endPoint; i++)
			strLT += strData [i];
	}
	return strLT;
}
int Parser::Pars_Space_Count ( string strData)
{
	if (strData == "") 
		return 0;
	int count1 = 1 ;
	int len = strData.length();
	for (int co = 0; co < len; co++)
	{
		if ( strData[co] == ' ')
		{
			count1++;
		}
	}
	return count1;
}
string Parser::Pars_Space ( string strData,int Item)
{
	if ( Item > Pars_Space_Count (strData) || strData == "")
		return "";
	
	int count1 = 0;
	int len = strData.length();
	string strTmp = "";
	for (int co = 0; co < len; co++)
	{
		if ( strData[co] == ' ')
		{
			count1++;
			if (count1 == Item)
				break;
			else strTmp = "";
		}
		else 
		{
			strTmp += strData [co];
		}
	}
	return strTmp;
}
