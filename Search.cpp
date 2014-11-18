#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Searching
{ 
public:



	void Search ()
	{

		char nameForSearch[50];
		cout<<"Enter the cities you want to travel between. Use the following format: City A -> City B: "<<endl;
		fflush(stdin);
		cin.getline(nameForSearch,50);

		char* search = nameForSearch ; // search pattern
		int offsetForSearch;
		string lineForSearch;
		ifstream Myfile;
		Myfile.open ("schedule.txt");
		if(Myfile.is_open())
		{
			while(!Myfile.eof())
			{
				getline(Myfile,lineForSearch);
				if ((offsetForSearch = lineForSearch.find(search, 0)) != string::npos)
				{
					cout <<lineForSearch<<endl;



				}
			}
		}
		Myfile.close();
	}};








