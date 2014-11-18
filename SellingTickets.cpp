#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "GTime.cpp";
#include "GetPrice.cpp";

using namespace std;


namespace {Time te;};



struct Ticket
{ 
	bool isReserved;
	int seat;
	
};



class SellTickets
{ public:


void CreatingBinary()
{
	int k;
	struct Ticket t;
	cout << "Enter filename: ";
	string filename;
	getline(cin,filename);
	cout<<"seats"<<endl;
	cin>>k;
	cout << endl;
	ofstream file(filename.c_str(),ios::binary|ios::out);
	if(!file)
	{ cout<<"Cannot open the file."<<endl;
	return;
	}
	for (int i=1;i<=k; i++)
	{
		t.seat=i;
		t.isReserved=false;
		file.write((char *) &t, sizeof(struct Ticket));


	}

	file.close();
}

void ReadingBin1()
{
	int i;
	FILE *f;
	struct Ticket t;
	f=fopen("train01","r");
	for (i=0;i<=25; i++)
	{
		fread(&t,sizeof(struct Ticket),1,f);
		cout<<t.seat<<setw(4);
		cout<<t.isReserved<<setw(4);
		
		cout<<endl;
	}
	fclose(f);
	f=fopen("train01","r+");
	int myseat;
	cout<<"Choose the seat you want to book: ";
	cin>>myseat;
	fseek(f,sizeof(struct Ticket)*myseat,SEEK_SET);
	fread(&t,sizeof(struct Ticket),1,f);
	if(t.isReserved==true)
		cout<<"The seat is already takenr";

	else
	{t.isReserved=true;
	fseek(f,sizeof(struct Ticket)*myseat,SEEK_SET);
	fwrite(&t,sizeof(struct Ticket),1,f);
	fclose(f);
	f=fopen("train01","r");
	for (i=0;i<=25; i++)
	{
		fread(&t,sizeof(struct Ticket),1,f);
		cout<<t.seat<<setw(4);
		cout<<t.isReserved<<setw(4);
		cout<<t.price<<setw(4);
		cout<<endl;
	}
	fwrite(&t,sizeof(struct Ticket),1,f);
	fclose(f);
	cout<<"You just booked ticket for seat: "<<myseat<<"  "<<"which cost: ";
	gp.GetPrice1();
	te.GetTime();
	}}

void ReadingBin2()
{
	int i;
	FILE *f;
	struct Ticket t;
	f=fopen("train02","r");
	for (i=0;i<=25; i++)
	{
		fread(&t,sizeof(struct Ticket),1,f);
		cout<<t.seat<<setw(4);
		cout<<t.isReserved<<setw(4);
		cout<<t.price<<setw(4);
		cout<<endl;
	}
	fclose(f);
	f=fopen("train02","r+");
	int myseat;
	cout<<"Choose the seat you want to book: ";
	cin>>myseat;
	fseek(f,sizeof(struct Ticket)*myseat,SEEK_SET);
	fread(&t,sizeof(struct Ticket),1,f);
	if(t.isReserved==true)
		cout<<"The seat is already takenr";

	else {t.isReserved=true;
	fseek(f,sizeof(struct Ticket)*myseat,SEEK_SET);
	fwrite(&t,sizeof(struct Ticket),1,f);
	fclose(f);
	f=fopen("train02","r");
	for (i=0;i<=25; i++)
	{

		fread(&t,sizeof(struct Ticket),1,f);
		cout<<t.seat<<setw(4);
		cout<<t.isReserved<<setw(4);
		cout<<t.price<<setw(4);
		cout<<endl;
	}
	fwrite(&t,sizeof(struct Ticket),1,f);
	fclose(f);
	cout<<"You just booked ticket for seat: "<<myseat<<"  "<<"which cost: ";
	gp.GetPrice2();
	te.GetTime();
	}}

void ReadingBin3()
{
	int i;
	FILE *f;
	struct Ticket t;
	f=fopen("train03","r");
	for (i=0;i<=25; i++)
	{
		fread(&t,sizeof(struct Ticket),1,f);
		cout<<t.seat<<setw(4);
		cout<<t.isReserved<<setw(4);
		cout<<t.price<<setw(4);
		cout<<endl;
	}
	fclose(f);
	f=fopen("train03","r+");
	int myseat;
	cout<<"Choose the seat you want to book: ";
	cin>>myseat;
	fseek(f,sizeof(struct Ticket)*myseat,SEEK_SET);
	fread(&t,sizeof(struct Ticket),1,f);
	if(t.isReserved==true)
		cout<<"The seat is already takenr";

	else 
	{t.isReserved=true;
	fseek(f,sizeof(struct Ticket)*myseat,SEEK_SET);
	fwrite(&t,sizeof(struct Ticket),1,f);
	fclose(f);
	f=fopen("train03","r");
	for (i=0;i<=25; i++)
	{
		fread(&t,sizeof(struct Ticket),1,f);
		cout<<t.seat<<setw(4);
		cout<<t.isReserved<<setw(4);
		cout<<t.price<<setw(4);
		cout<<endl;
	}
	fwrite(&t,sizeof(struct Ticket),1,f);
	fclose(f);
	cout<<"You just booked ticket for seat: "<<myseat<<"  "<<"which cost: ";
	gp.GetPrice3();
	te.GetTime();
	}}


void ReadingBin4()
{
	int i;
	FILE *f;
	struct Ticket t;
	f=fopen("train04","r");
	for (i=0;i<=25; i++)
	{
		fread(&t,sizeof(struct Ticket),1,f);
		cout<<t.seat<<setw(4);
		cout<<t.isReserved<<setw(4);
		cout<<t.price<<setw(4);
		cout<<endl;
	}
	fclose(f);
	f=fopen("train04","r+");
	int myseat;
	cout<<"Choose the seat you want to book: ";
	cin>>myseat;
	fseek(f,sizeof(struct Ticket)*myseat,SEEK_SET);
	fread(&t,sizeof(struct Ticket),1,f);
	if(t.isReserved==true)
		cout<<"The seat is already takenr";

	else {t.isReserved=true;
	fseek(f,sizeof(struct Ticket)*myseat,SEEK_SET);
	fwrite(&t,sizeof(struct Ticket),1,f);
	fclose(f);
	f=fopen("train04","r");
	for (i=0;i<=25; i++)
	{
		fread(&t,sizeof(struct Ticket),1,f);
		cout<<t.seat<<setw(4);
		cout<<t.isReserved<<setw(4);
		cout<<t.price<<setw(4);
		cout<<endl;
	}
	fwrite(&t,sizeof(struct Ticket),1,f);
	fclose(f);
	cout<<"You just booked ticket for seat: "<<myseat<<"  "<<"which cost: ";
	gp.GetPrice4();
	te.GetTime();
	}}




};

