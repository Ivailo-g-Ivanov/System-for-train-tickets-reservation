#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Viewing
{ public:

void ViewCities()
{
	ifstream myfile;
	myfile.open("cities.txt");
	cout<<endl;
	if (myfile)
	{
		string line;
		while (getline(myfile, line))
			cout << line <<endl;
	}
	myfile.close();
}



void ViewTrains()
{
	ifstream myfile;
	myfile.open("trains.txt");
	cout<<endl;
	if (myfile)
	{
		string line;
		while (getline(myfile, line))
			cout << line <<endl;
	}
	myfile.close();
}



void ViewSchedule()
{
	ifstream myfile;
	myfile.open("schedule.txt");
	cout<<endl;
	if (myfile)
	{
		string line;
		while (getline(myfile, line))
			cout << line <<endl;
	}
	myfile.close();
}
};
