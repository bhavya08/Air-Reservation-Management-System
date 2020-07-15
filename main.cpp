#include <iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<string.h>
#include<stdio.h>
using namespace std;
void gotoxy(short x,short y);
struct airway{
	char fname[20],lname[20],sex,from[20],rstatus[20],nat[10];
	int passno,age,des;
};
//class to control all function
class air{
	private:
		airway r;
		void getdata(int);
		void add();
		void list();
		void pinfo();
		void cancel();
		void mod();
		char select();
	public:
		void nik1();
		void nik();
};
//opens the main menu and call other related functions
void air::nik1()
{
	do
	{
		system("CLS");
		char choice;
		gotoxy(30,2);
		cout<<"M A I N -- M E N U ";
		gotoxy(26,3);
		cout<<"---------------------------";
		gotoxy(30,7);
		cout<<"1- New Reservation";
		gotoxy(30,9);
		cout<<"2- Passenger Information";
		gotoxy(30,11);
		cout<<"3- Modify Record";
		gotoxy(30,13);
		cout<<"4- Display Information of Passengers";
		gotoxy(30,15);
		cout<<"5- Cancellation";
		gotoxy(30,17);
		cout<<"0- Quit To System";
		gotoxy(34,22);
		cout<<"ENTER CHOICE : ";
		cin>>choice;
		switch(choice)
		{
			case '1':
				add();
				break;
			case '2':
				pinfo();
				break;
			case '3':
				mod();
				break;
			case '4':
				list();
				break;
			case '5':
				cancel();
				break;
			case '0':
				exit(1);
			case 27:
				exit(1);
			default:
				cout<<"\a";
		}
	}
	while(1);
}

//this function opens a sub-menu for user to select an air craft from the list
char air::select()
{
	char choice;
	do
	{
		system("CLS");
		gotoxy(25,5);
		cout<<"SELECT A FLIGHT";
		gotoxy(27,9);
		cout<<"1- Air India\n";
		gotoxy(27,10);
		cout<<"2- British Airways\n";
		gotoxy(27,11);
		cout<<"3- Gulf Airways\n";
		gotoxy(27,12);
		cout<<"4- United Airlines\n";
		gotoxy(27,13);
		cout<<"5- Luthansa\n";
		gotoxy(27,15);
		cout<<"R- Return to Main Menu\n";
		gotoxy(27,16);
		cout<<"Q- Quit to System\n";
		gotoxy(30,20);
		cout<<"Enter Choice: ";
		cin>>choice;
		choice=toupper(choice);
		switch(choice)
		{
			case '1':
				return(choice);
			case '2':
				return(choice);
			case '3':
				return(choice);
			case '4':
				return(choice);
			case '5':
				return(choice);
			case 'R':
				nik1();
			case 'Q':
				exit(1);
			case 27:
				nik1();
				break;
			default:
				cout<<"\a";
				select();	
		}
	}
	while(1);	
}

//function to get data of the passenger
void air::getdata(int p)
{
	char ch;
	cout<<"\n\n\tTHE ROUTES ARE\n";
	cout<<"1. DELHI - LONDON - DELHI\n";
	cout<<"2. DELHI - NEW YORK - DELHI\n";
	cout<<"3. DELHI - PARIS - DELHI\n";
	cout<<"4. DELHI - SWITZERLAND - DELHI\n";
	cout<<"\n     Please Select Your Route: ";
	cin>>r.des;
	system("CLS");
	r.passno=p;
	gotoxy(20,7);
	cout<<"Passenger Number: "<<r.passno;
	gotoxy(20,9);
	cout<<"Enter FIRST NAME of the Passenger: ";
	cin>>r.fname;
	gotoxy(20,10);
	cout<<"Enter LAST NAME of the Passenger: ";
	cin>>r.lname;
	gotoxy(20,11);
	cout<<"Enter SEX of Passenger(M/F): ";
	cin>>r.sex;
	while(1)
	{
		gotoxy(34,12);
		cout<<"          ";
		if(r.sex=='m'||r.sex=='M'||r.sex=='f'||r.sex=='F')
		{
			break;
		}
		gotoxy(34,12);
		cout<<"ENTER M OR F"<<endl;
		getch();
		gotoxy(34,12);
		cout<<"               ";
		gotoxy(20,11);
		cout<<"                              ";
		gotoxy(20,11);
		cout<<"Enter SEX of Passenger: ";
		cin>>r.sex;	
	}
	gotoxy(20,12);
	cout<<"Enter AGE of Passenger: ";
	cin>>r.age;
	while(1)
	{
		gotoxy(25,13);
		cout<<"               ";
		if(r.age>=4 && r.age<=100)
			break;
		gotoxy(25,13);
		cout<<"Enter correct AGE";
		getch();
		gotoxy(25,13);
		cout<<"                         ";
		gotoxy(20,12);
		cout<<"                                ";
		gotoxy(20,12);
		cout<<"Enter AGE of the Passenger: ";
		cin>>r.age;
	}
	gotoxy(20,13);
	cout<<"Enter the NATIONALITY: ";
	cin>>r.nat;
	gotoxy(20,14);
	cout<<"STARTING POINT: ";
	cout<<"DELHI\n";
	gotoxy(20,15);
	cout<<"DESTINATION: ";
	switch(r.des)
	{
		case 1:
			cout<<"LONDON\n";
			break;
		case 2:
			cout<<"NEW YORK\n";
			break;
		case 3:
			cout<<"PARIS\n";
			break;
		case 4:
			cout<<"SWITZERLAND\n";
			break;		
	}
	gotoxy(20,19);
	cout<<"TICKET NUMBER: "<<r.passno;		
}

//function to add data provided from getdata function into a file
void air::add()
{
	air temp;
	int t;
	fstream airs;
	char c,filename[8],choice1,choice2;
	do
	{
		t=0;
		c=select();
		switch(c)
		{
			case '1':
				strcpy(filename,"Ind.Dat");
				break;
			case '2':
				strcpy(filename,"Brit.Dat");
				break;
			case '3':
				strcpy(filename,"Gulf.Dat");
				break;
			case '4':
				strcpy(filename,"Unit.Dat");
				break;
			case '5':
				strcpy(filename,"Luf.Dat");
				break;
		}
		airs.open(filename,ios::in|ios::binary|ios::app);
		while(airs.read((char *)&temp, sizeof(airway)))
		{
			t++;
		}
		airs.close();
		do
		{
			if(t<5)
				strcpy(r.rstatus,"C");
			else
				strcpy(r.rstatus,"W");
			if(t<8)
			{
				t++;
				system("CLS");
				gotoxy(25,3);
				cout<<"ADDITION OF NEW PASSENGER";
				gotoxy(21,4);
				cout<<"---------------------------------";
				gotoxy(20,6);
				cout<<"Flight Name :";
				switch(c)
				{
					case '1':
						cout<<"Air India";
						break;
					case '2':
						cout<<"British Airways";
						break;
					case '3':
						cout<<"Gulf Airways";
						break;
					case '4':
						cout<<"United Airways";
						break;
					case '5':
						cout<<"Lufthansa";
						break;
				}
				getdata(t);
				gotoxy(1,17);
				cout<<"---------------------------------------------------------------";
				gotoxy(1,20);
				cout<<"---------------------------------------------------------------";
				gotoxy(20,18);
				cout<<"STATUS: ";
				if(t<5)
					cout<<"\aCONFIRMED";
				else
					cout<<"\aWAITING LIST";
				getch();
				airs.open(filename,ios::out|ios::binary|ios::app);
				airs.write((char *)&r,sizeof(airway));
				airs.close();
			}
			else
			{
				system("CLS");
				gotoxy(22,20);
				cout<<"NO MORE TICKETS AVAILABLE FOR THIS FLIGHT\a";
				getch();
			}
			gotoxy(12,25);
			cout<<"\aDo you wish to make any more reservation on this Flight(Y/N)";
			do
			{
				choice1=getch();
				choice1=toupper(choice1);
			}
			while((choice1!='Y')&&(choice1!='N'));
		}
		while(choice1=='Y');
		gotoxy(1,25);
		system("CLS");
		gotoxy(12,25);
		cout<<"Do you wish to make any more reservation on any Flight(Y/N)";
		do
		{
			choice2=getch();
			choice2=toupper(choice2);
		}
		while((choice2!='Y')&&(choice2!='N'));
	}
	while(choice2=='Y');
}

//function to get full details of a particular passenger
void air::pinfo()
{
	fstream airs;
	int p,k=0;
	char c,filename[20];
	c=select();
	switch(c)
	{
		case '1':
			strcpy(filename,"Ind.Dat");
			break;
		case '2':
			strcpy(filename,"Brit.Dat");
			break;
		case '3':
			strcpy(filename,"Gulf.Dat");
			break;
		case '4':
			strcpy(filename,"Unit.Dat");
			break;
		case '5':
			strcpy(filename,"Luf.Dat");
			break;
	}
	system("CLS");
	gotoxy(10,3);
	cout<<"Enter Passenger Number: ";
	cin>>p;
	airs.open(filename,ios::in|ios::binary|ios::app);
	while(airs.read((char *)&r,sizeof(airway)))
	{
		k++;
	}
	airs.close();
	if(p>k)
	{
		system("CLS");
		gotoxy(25,25);
		cout<<"Record Not Found....\a";
		getch();
	}
	else
	{
		airs.open(filename,ios::in|ios::binary|ios::app);
		while(airs.read((char *)&r,sizeof(airway)))
		{
			if(r.passno==p)
			{
				system("CLS");
				gotoxy(27,3);
				cout<<"PASSENGER INFORMATION";
				gotoxy(23,6);
				cout<<"Flight Name: ";
				switch(c)
				{
					case '1':
						cout<<"Air India";
						break;
					case '2':
						cout<<"British Airways";
						break;
					case '3':
						cout<<"Gulf Airways";
						break;
					case '4':
						cout<<"United Airways";
						break;
					case '5':
						cout<<"Lufthansa";
						break;
				}
				gotoxy(23,7);
				cout<<"Passenger Number: "<<r.passno;
				gotoxy(23,9);
				cout<<"Name of Passenger: "<<r.fname<<" "<<r.lname;
				gotoxy(23,10);
				cout<<"Sex of Passenger: "<<r.sex;
				gotoxy(23,11);
				cout<<"Age of Passenger: "<<r.age;
				gotoxy(23,12);
				cout<<"Nationality: "<<r.nat;
				gotoxy(23,13);
				cout<<"Starting Point: "<<"DELHI";
				gotoxy(23,14);
				cout<<"Destination: ";
				switch(r.des)
				{
					case 1:
						cout<<"LONDON";
						break;
					case 2:
						cout<<"NEW YORK";
						break;
					case 3:
						cout<<"PARIS";
						break;
					case 4:
						cout<<"SWITZERLAND";
						break;
				}
				gotoxy(23,16);
				cout<<"TICKET NUMBER: "<<r.passno;
				gotoxy(23,17);
				cout<<"STATUS   :";
				if(strcmp(r.rstatus,"W")==0)
					cout<<"WAITING LIST";
				else
					cout<<"CONFIRMED";
				gotoxy(5,25);
				cout<<"Press Any Key To Continue.....";
				getch();
			}
		}
		airs.close();
	}	
}

//funcion to show passenger list flight wise
void air::list()
{
	fstream airs;
	char c;
	char filename[20];
	c=select();
	switch(c)
	{
		case '1':
			strcpy(filename,"Ind.Dat");
			break;
		case '2':
			strcpy(filename,"Brit.Dat");
			break;
		case '3':
			strcpy(filename,"Gulf.Dat");
			break;
		case '4':
			strcpy(filename,"Unit.Dat");
			break;
		case '5':
			strcpy(filename,"Luf.Dat");
			break;		
	}
	system("CLS");
	gotoxy(29,3);
	cout<<"PASSENGER LIST";
	gotoxy(25,4);
	cout<<"----------------------";
	gotoxy(30,5);
	switch(c)
	{
		case '1':
			cout<<"Air India";
			break;
		case '2':
			cout<<"British Airways";
			break;
		case '3':
			cout<<"Gulf Airways";
			break;
		case '4':
			cout<<"United Airways";
			break;
		case '5':
			cout<<"Lufthansa";
			break;		
	}
	gotoxy(3,7);
	cout<<"Passenger Number";
	gotoxy(27,7);
	cout<<"PASSENGER - NAME";
	gotoxy(62,7);
	cout<<"Reservation Status";
	int i=9;
	airs.open(filename,ios::in|ios::binary);
	while(airs.read((char *)&r,sizeof(airway)))
	{
		gotoxy(10,i);
		cout<<r.passno;
		gotoxy(30,i);
		cout<<r.fname<<" "<<r.lname;
		gotoxy(66,i);
		if(strcmp(r.rstatus,"C")==0)
			cout<<"CONFIRMED";
		else
			cout<<"WAITING LIST";
		i++;
	}
	gotoxy(25,25);
	cout<<"\aPress Any Key To Continue......";
	getch();
	airs.close();
}

//function to modify ticket details
void air::mod()
{
	fstream airs,airs1;
	airway t;
	int p,flag;
	char c,filename[20];
	c=select();
	switch(c)
	{
		case '1':
			strcpy(filename,"Ind.Dat");
			break;
		case '2':
			strcpy(filename,"Brit.Dat");
			break;
		case '3':
			strcpy(filename,"Gulf.Dat");
			break;
		case '4':
			strcpy(filename,"Unit.Dat");
			break;
		case '5':
			strcpy(filename,"Luf.Dat");
			break;				
	}
	system("CLS");
	int k=0;
	gotoxy(10,3);
	cout<<"Enter Passenger Number: ";
	cin>>p;
	airs.open(filename,ios::in|ios::binary|ios::app);
	while(airs.read((char *)&r,sizeof(airway)))
	{
		k++;
	}
	airs.close();
	if(p>k)
	{
		system("CLS");
		gotoxy(25,24);
		cout<<"\aPASSENGER NUMBER DOES NOT EXIST....";
		getch();
		return;
	}
	system("CLS");
	gotoxy(25,3);
	cout<<"MODIFICATION OF PASSENGER";
	gotoxy(21,4);
	cout<<"---------------------------------";
	getdata(p);
	airs.open(filename,ios::in|ios::binary);
	airs1.open("Temp.Dat",ios::out|ios::binary);
	airs.seekg(0);
	while(airs.read((char *)&t,sizeof(airway)))
	{
		if(t.passno!=r.passno)
			airs1.write((char *)&t,sizeof(airway));
		else
			airs1.write((char *)&r,sizeof(airway));
	}
	airs.close();
	airs1.close();
	remove(filename);
	rename("Temp.Dat",filename);
	system("CLS");
	gotoxy(20,25);
	cout<<"\aTicket Details Successfully Modified......";
	getch();
}

//function to cancel a ticket
void air::cancel()
{
	fstream airs,airs1;
	int p,k=0;
	char c,filename[20];
	c=select();
	switch(c)
	{
		case '1':
			strcpy(filename,"Ind.Dat");
			break;
		case '2':
			strcpy(filename,"Brit.Dat");
			break;
		case '3':
			strcpy(filename,"Gulf.Dat");
			break;
		case '4':
			strcpy(filename,"Unit.Dat");
			break;
		case '5':
			strcpy(filename,"Luf.Dat");
			break;		
	}
	system("CLS");
	gotoxy(10,3);
	cout<<"Enter Passenger Number: ";
	cin>>p;
	airs.open(filename,ios::in|ios::binary|ios::app);
	while(airs.read((char *)&r,sizeof(airway)))
	{
		k++;
	}
	airs.close();
	if(p>k)
	{
		system("CLS");
		gotoxy(25,24);
		cout<<"\aPASSENGER NUMBER NOT EXIST";
		getch();
		return;
	}
	system("CLS");
	gotoxy(25,3);
	cout<<"CANCELLATION OF TICKET";
	airs.open(filename,ios::in|ios::binary);
	airs1.open("Temp.Dat",ios::out|ios::binary);
	while(airs.read((char *)&r,sizeof(airway)))
	{
		if(r.passno>p)
		{
			r.passno--;
			airs1.write((char *)&r,sizeof(airway));
		}
		else if(r.passno<p)
		{
			airs1.write((char *)&r,sizeof(airway));
		}	
	}
	airs.close();
	airs1.close();
	remove(filename);
	rename("Temp.Dat",filename);
	airs.open(filename,ios::in|ios::binary);
	airs1.open("Temp.Dat",ios::out|ios::binary);
	while(airs.read((char *)&r,sizeof(airway)))
	{
		if(r.passno<=5)
			strcpy(r.rstatus,"C");
		else
			strcpy(r.rstatus,"W");
		airs1.write((char *)&r,sizeof(airway));
	}
	airs.close();
	airs1.close();
	remove(filename);
	rename("Temp.Dat",filename);
	system("CLS");
	gotoxy(25,24);
	cout<<"\aTicket Successfully Cancelled.....";
	getch();
}

//whenever main() functions calls, this function will execute first
void air::nik()
{
	system("CLS");
	cout<<"\n\n\n                                          --              - -";
	Sleep(125);
	cout<<"\n                                        -  -             -  -";
	Sleep(125);
	cout<<"\n				      -    -            - B -       ";
	Sleep(125);
	cout<<"\n		               	    -      -           -  S -       ";
	Sleep(25);
	cout<<"\n		    - - - - - - - - - - - - - - - - - -     -      ";
	Sleep(125);
	cout<<"\n		 -                                        A -      ";
	Sleep(125);
	cout<<"\n              -                                           I -      ";
	Sleep(125);
	cout<<"\n		 -                                        R -      ";
	Sleep(125);
	cout<<"\n		    - - - - - - - - - - - - - - - - - - - - -      ";
	Sleep(125);
	cout<<"\n				    -      -                       ";
	Sleep(125);
	cout<<"\n				      -    -                       ";
	Sleep(125);
	cout<<"\n					-  -                       ";
	Sleep(125);
	cout<<"\n                                          --";
	Sleep(425);
	gotoxy(32,17);
	cout<<"			BY	         ";
	gotoxy(32,18);
	cout<<"	  	  BHAVYA SHARMA     ";
	Sleep(425);
	Sleep(425);
	Sleep(425);
}

//main function
int main(){
	air obj;
	obj.nik();
	obj.nik1();
	return 0;	
}

//definition of gotoxy function
void gotoxy(short x,short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

