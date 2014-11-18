

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;


class Train
{ public:
string Id;
string category;
int seats;
string description;
Train(string Id, string category, int seats, string description);
~Train(){};
virtual void gprice();

};


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
void Train::gprice()

{ 
	char nameIn[50];

	cout<<"Enter the cities you want to travel between. Use the following format: City A -> City B: "<<endl;
	fflush(stdin);
	cin.getline(nameIn,50);

	char* search = nameIn ; // search pattern
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
					cout<<c;

				if( category.compare("Luxury")==0 || category.compare("luxury")==0 || category.compare("LUXURY")==0)
				{c=1.2*c;
				cout<<c<<endl;}
				if( category.compare("Economy")==0 || category.compare("economy")==0 || category.compare("ECONOMY")==0)
				{c=0.7*c;
				cout<<c;}
			}
		}
	}
	MyfileIn.close();

}



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






