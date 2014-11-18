#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>


#include <iomanip>
using namespace std;

class ResTickets
{
public:


	struct Ticket
	{  public:
	bool isReserved;
	int seat;

	};
	struct Ticket t;
	void CreatingBinary()
	{

		int a;

		cout << "Enter filename: ";
		string filename;
		getline(cin,filename);
		cout<<"seats"<<endl;
		cin>>a;
		cout << endl;
		ofstream file(filename.c_str(),ios::binary|ios::out);
		if(!file)
		{ cout<<"Cannot create the file."<<endl;
		return;
		}
		for (int i=1;i<=a; i++)
		{
			t.seat=i;
			t.isReserved=false;
			file.write((char *) &t, sizeof(struct Ticket));


		}

		file.close();

	}

	void ReserveTicketBinary()

	{


		string filename;
		cout<<"Please enter again the number of the train you will travel with so you can book a place: ";
		getline(cin,filename);


		fstream myfileIn(filename.c_str(), ios::in | ios::binary);

		if(!myfileIn) 
		{
			cout << "Cannot open file.\n";
			return;
		}




		while(!myfileIn.eof())
		{
			myfileIn.read((char *) &t, sizeof(struct Ticket));
			cout<<setw(4)<<t.seat<<setw(4);
			cout<<setw(4)<<t.isReserved<<setw(4);
			cout<<endl;
		}




		myfileIn.close();



		fstream myfile(filename.c_str(), ios::in | ios::out | ios::binary);
		int myseat;
		cout<<"Choose the seat you want to book: ";
		cin>>myseat;
		myfile.seekg(myseat*(sizeof(Ticket)-1),ios::beg);
		myfile.read((char *) &t, sizeof(struct Ticket));
		if(t.isReserved==true)
			cout<<"The seat is already taken";

		else

		{
			t.isReserved=true;
			myfile.seekp(myseat+2);

			myfile.put(true);

			myfile.close();



			myfile.open(filename.c_str(), ios::in | ios::out | ios::binary);




			while(!myfile.eof()) 
			{
				myfile.read((char *) &t, sizeof(struct Ticket));
				cout<<setw(4)<<t.seat<<setw(4);
				cout<<setw(4)<<t.isReserved<<setw(4);
				cout<<endl;
			}

			myfile.write((char *) &t, sizeof(struct Ticket));
			myfile.close();

			cout<<"You have booked seat number:" <<myseat<<endl;
		}
	}

};