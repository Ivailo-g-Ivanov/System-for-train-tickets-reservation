#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Adding
{ public:



void AddCity()
{
	ofstream myout;
	myout.open("cities.txt",ios::app);
	char add[50];
	cout<<"Enter city which you want to add:";
	fflush(stdin);
	cin.getline(add,50);
	myout<<add;
	myout.close();
	cout<<add<<" has been added to cities!"<<endl;
}


void AddTrain()
{
	ofstream myout;
	myout.open("trains.txt",ios::app);
	char add[50];
	cout<<"Enter city which you want to add:";
	fflush(stdin);
	cin.getline(add,50);
	myout<<add;
	myout.close();
	cout<<add<<" has been added to cities!"<<endl;
}


void AddSchedule()
{
	ofstream myout;
	myout.open("schedule.txt",ios::app);
	char add[50];
	cout<<"Enter city which you want to add:";
	fflush(stdin);
	cin.getline(add,50);
	myout<<add;
	myout.close();
	cout<<add<<" has been added to cities!"<<endl;
}
};