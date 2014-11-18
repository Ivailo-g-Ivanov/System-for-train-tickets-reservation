// Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "View.cpp";
#include "Add.cpp";
#include "Delete.cpp";
#include "Binaries.cpp";
#include "Search.cpp";
#include "GTime.cpp";
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;


class Train
{ 
public:
	string Id;
	string category;
	int seats;
	string description;

	~Train(){};




	Train::Train(string inId,
		string inCategory,
		int inSeats,
		string inDescription)
	{

		Id=inId;
		category=inCategory;
		seats=inSeats;
		description=inDescription;

	}
	void Price()

	{
		char nameIn[50];

		cout<<"Enter the cities you want to travel between. Use the following format: City A -> City B: "<<endl;
		fflush(stdin);
		cin.getline(nameIn,50);

		char* search = nameIn ; 
		int offsetIn;
		string lineIn;
		ifstream MyfileIn;
		MyfileIn.open ("D:/University/OOP/Project/schedule.txt");
		if(MyfileIn.is_open())
		{
			while(!MyfileIn.eof())
			{
				getline(MyfileIn,lineIn);
				if ((offsetIn = lineIn.find(search, 0)) != string::npos)
				{
					lineIn.erase(remove(lineIn.begin(),lineIn.end(),' '),lineIn.end());
					reverse (lineIn.begin(),lineIn.end());

					char lineIn2[5]={lineIn[4],lineIn[3],lineIn[2],lineIn[1],lineIn[0]};

					double c;
					c=atof(lineIn2);
					if( category.compare("Fast")==0 || category.compare("fast")==0 || category.compare("FAST")==0)
						cout<<"The price u have to pay is: "<<c<<endl;

					if( category.compare("Luxury")==0 || category.compare("luxury")==0 || category.compare("LUXURY")==0)
					{c=1.2*c;
					cout<<"The price u have to pay is: "<<c<<endl;}
					if( category.compare("Economy")==0 || category.compare("economy")==0 || category.compare("ECONOMY")==0)
					{c=0.7*c;
					cout<<"The price u have to pay is: "<<c<<endl;;}
				}
			}
		}
		MyfileIn.close();
	}









};









class LuxuryTrain : public  Train
{
public:
	LuxuryTrain::LuxuryTrain(string inId, int inSeats,string inDescription, string inCategory="Luxury"):Train (inId, inCategory, inSeats,  inDescription)

	{


	}
};





class FastTrain : public  Train
{
public:
	FastTrain::FastTrain(string inId, int inSeats,string inDescription, string inCategory="Fast"):Train (inId, inCategory, inSeats,  inDescription)

	{


	}
};


class EconomyTrain : public  Train
{
public:
	EconomyTrain::EconomyTrain(string inId, int inSeats,string inDescription, string inCategory="Economy"):Train (inId, inCategory, inSeats,  inDescription)

	{


	}
};


class CPrice
{
public:
	void CalcPrice()
	{

		LuxuryTrain LT("Id of train",100,"Description of a train");
		FastTrain FT("Id of train",100,"Description of a train");
		EconomyTrain ET("Id of train",100,"Description of a train");


		char name[50];
		cout<<"Please enter the number of the train which goes to a desired destination"<<endl;
		fflush(stdin);
		cin.getline(name,50);

		char* search = name ;
		int offset;
		string line;
		ifstream Myfile;
		Myfile.open ("D:/University/OOP/Project/trains.txt");
		if(Myfile.is_open())
		{
			while(!Myfile.eof())
			{
				getline(Myfile,line);
				if ((offset = line.find(search, 0)) != string::npos)
				{

					string myline=line;


					string srch = "luxury";
					size_t pos = myline.find(srch);
					if (pos != string::npos) //find
						LT.Price();
					else
					{
						string srch = "fast";

						if (pos != string::npos)
							FT.Price();
						else 
							ET.Price();

					}}



			}
		}
		Myfile.close();
	}};










int main()
{
	

	Time t;
	Viewing v;
	Adding a;
	Deleting d;
	CPrice cp;
	ResTickets rt;

	Searching s;
	int FirstInput;
	

	cout<<"WELCOME TO ONLINE BOOKING SYSTEM"<<endl<<endl;
	cout<<"For viewing list of a cities, trains or schedule press 1"<<endl;
	cout<<"For adding to cities, trains or schedule press 2"<<endl;
	cout<<"For deleting from cities, trains or schedule press 3"<<endl;
	cout<<"For searching a route press 4"<<endl;
	cout<<"For creating binary for a train press 5"<<endl;
	cout << "For calculating price and reserve a seat press 6" << endl;

	cout<<"Input:";
	cin>>FirstInput;
	switch (FirstInput)
	{
	default:
		cout << "Bad input!";
		break;
	case 1:
		int SecondInput;

		cout << "For viewing cities press 1" << endl;
		cout << "For viewing trains press 2" << endl;
		cout << "For viewing schedule press 3" << endl;
		cin >> SecondInput;

		switch (SecondInput)
		{
		default:
			cout << "Bad input!";
			break;

		case 1:
			v.ViewCities();
			break;
		case 2:
			v.ViewTrains();
			break;
		case 3:
			v.ViewSchedule();
			break;
		}
	case 2:
		int ThirdInput;
		cout << "For adding to cities press 1" << endl;
		cout << "For adding to trains press 2" << endl;
		cout << "For adding to schedule press 3" << endl;
		cout << "Input:";
		cin >> ThirdInput;
		switch (ThirdInput)
		{
		default:
			cout << "Bad input!";
		case 1:
			a.AddCity();
			break;
		case 2:
			a.AddTrain();
			break;
		case 3:
			a.AddSchedule();
			break;
		}
	case 3:
		int ForthInput;
		cout << "For deleting from cities press 1" << endl;
		cout << "For deleting from trains press 2" << endl;
		cout << "For deleting from schedule press 3" << endl;
		cout << "Input:";
		cin >> ForthInput;
		switch (ForthInput)
		{
		default:
			cout << "Bad input!";
			break;
		case 1:
			d.SearchBeforeDeleteC();
			break;
		case 2:
			d.SearchBeforeDeleteTr();
			break;
		case 3:
			d.DeleteSchedule();
			break;
		}

	case 4:
		int FifthInput;
		cin >> FifthInput;
		switch (FifthInput)
		{
		default:
			cout << "Bad input!";
			break;
		case 1:

			s.Search();
			break;
		}

	case 5:
		cin.ignore();
		rt.CreatingBinary();
		break;
	case 6:

		
		v.ViewSchedule();
		cp.CalcPrice();
		rt.ReserveTicketBinary();
		t.GetTime();

		break;
	};
		return 0;
	};
