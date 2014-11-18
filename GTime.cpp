#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

class Time
{ 
public:

	struct tmm {
		int tm_sec;   
		int tm_min;  
		int tm_hour;  
		int tm_mday;  
		int tm_mon;   
		int tm_year;  
		int tm_wday;  
		int tm_yday;  
		int tm_isdst; 
	}	;

	void GetTime()
	{

		time_t now = time(0);
		tm *ltm = localtime(&now);


		cout <<" bought on "<<1900 + ltm->tm_year<<".";
		cout <<1 + ltm->tm_mon<<".";
		cout <<ltm->tm_mday<<" ";
		cout << "at "<<ltm->tm_hour << ":";
		cout << ltm->tm_min << ":";
		cout << ltm->tm_sec << endl;

	}};
