#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
namespace {
	char name6[50];
}
class Deleting
{ public:

void DeleteCities()
{


	string line;
	string deleteline;
	ifstream file;
	file.open("cities.txt");
	ofstream temp;
	temp.open("temp.txt");
	while (getline(file,line))
	{
		if (line.compare(name6) !=0)
		{
			temp << line << endl;
		}
	}
	temp.close();
	file.close();
	remove("cities.txt");
	rename("temp.txt","cities.txt");
	cout<<name6<<"has been deleted from the file!"<<endl;
}
void SearchBeforeDeleteC()
{
	fflush(stdin);
	cout<<"Enter name of the city which you want to delete: ";
	cin.getline(name6,50);

	char* search = name6 ; // search pattern
	int offset;
	string line;
	ifstream Myfile;
	Myfile.open ("schedule.txt");
	if(Myfile.is_open())
	{
		while(!Myfile.eof())
		{
			getline(Myfile,line);
			if ((offset = line.find(search, 0)) != string::npos) //ako e namereno
			{
				cout <<"File cannot be deleted"<<endl;
			}
			else DeleteCities();
			break;
		}
		Myfile.close();

	}}


void DeleteTrains()
{int offset;
string line;
string line2;
ifstream file;
file.open("trains.txt");
ofstream temp;
temp.open("temp.txt");


while (getline(file,line))
{

	if ((offset = line.find(name6, 0)) == string::npos)
	{
		temp << line << endl;
	}

}
temp.close();
file.close();
remove("trains.txt");
rename("temp.txt","trains.txt");
cout<<name6<<"has been deleted from the file!"<<endl;
}


void SearchBeforeDeleteTr()
{
	fflush(stdin);
	cout<<"Enter the ID of the train which you want to delete: ";
	cin.getline(name6,100);

	char* search = name6 ; // search pattern
	int offset;
	string line;
	ifstream Myfile;
	Myfile.open ("schedule.txt");
	if(Myfile.is_open())
	{
		while(!Myfile.eof())
		{
			getline(Myfile,line);
			if ((offset = line.find(search, 0)) != string::npos) //ako e namereno
			{
				cout <<"File cannot be deleted"<<endl;
			}
			else DeleteTrains();
			break;
		}
		Myfile.close();

	}}
void DeleteSchedule()
{
	int offset;
	string line;
	string deleteline;
	ifstream file;
	file.open("schedule.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "Enter schedule which you want to delete. Use the following format: City A -> City B: ";
	cin >> deleteline;
	while (getline(file,line))
	{
		if ((offset = line.find(deleteline, 0)) == string::npos)
		{
			temp << line << endl;
		}
	}
	temp.close();
	file.close();
	remove("schedule.txt");
	rename("temp.txt","schedule.txt");
	cout<<deleteline<<"has been deleted from the file!"<<endl;
}
};