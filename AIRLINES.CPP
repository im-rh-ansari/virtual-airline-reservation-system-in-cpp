/*THIS PROGRAM FOR AIRLINE RESERVATION HAS BEEN MADE BY RAZAUL HASAN ANSARI,
VEDANSH AGARWAL & PIYUSH GUPTA.
IT CONSISTS OF BOOKING,VIEWING,DELETING&PRINTING TICKETS FOR USERS
IT ALSO CONSISTS OF FUNCTIONS TO REGISTER,VIEW,UPDATE & DELETE A FLIGHT INFO
IT IS PASSWORD PROTECTED AND WE HOPE YOU LIKE IT
*/
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
/******************************DECLARING FUNCTIONS*****************************
******************************************************************************/
void login();       //FUNCTION TO GET & CHECK PASSWORD FOR PROGRAM
void border();      //FUNCTION TO ADD BORDER
void heading(int);  //FUNCTION FOR PRINTING THE NAME OF AIRLINES
void loading();     //FUNCTION WHICH RUNS THE MAIN LOADING ON FRONT PAGE
void madeby();      //FUNCTION TO DISPLAY NAMES OF PROGRAMMERS
void mgetflight();  //FUNCTION TO INSERT FLIGHT INFO
void mviewflight(); //FUNCTION TO VIEW FLIGHT INFO
void mchaflight();  //FUNCTION TO CHANGE THE FLIGHT INFO
void cbookticket(); //FUNCTION TO BOOK TICKET
void ccheckticket();//FUNCTION TO DISPLAY TICKET INFO
void loading1();    //FUNCTION FOR LOADING OF FIRST WINDOW LOADING
void loading2();    //FUNCTION FOR LOADING OF SECOND WINDOW LOADING
void loading3();    //FUNCTION FOR LOADING OF THIRD WINDOW LOADING
void loading4();    //FUNCTION FOR LOADING OF FOURTH WINDOW LOADING
void loading5();    //FUNCTION FOR LOADING OF FIFTH WINDOW LOADING
void loading6();    //FUNCTION FOR LOADING OF SIXTH WINDOW LOADING
void gate();        //FUNCTION TO ENTER IN USER OR MANAGER GATE
void cwindow();     //FUNCTION FOR DISPLAYING AND ENTERING IN DIFFERENT
		    //USER FUNCTIONS
void mwindow();     //FUNCTION FOR DISPLAYING AND ENTERING IN DIFFERENT
		    //MANAGER FUNCTIONS
void format();      //FUNCTION TO DISPLAY INPUT PRECAUTIONS
/*****************************DECLARING CLASS**********************************
*******************************************************************************/
class flight        //CLASS FOR FLIGHT INFO
{
	char flightname[20];         //NAME OF FLIGHT
	char startplace[20];         //START PLACE
	char destination[20];        //DESTINATION OF FLIGHT
	char takeoff[10];            //TAKE OFF TIME
	char land[10];               //LANDING TIME
	int capacity;                //CAPACITY OF FLIGHT
	int maxspeed;                //MAXIMUM SPEED OF FLIGHT
public:
	int flightno;                //FLIGHT CODE
	int generalcost;             //COST OF GENERAL CLASS
	int executivecost;           //COST OF EXECUTIVE CLASS
	void getinfo();              //FUNCTION TO GET FLIGHT DETAILS
	void addflight();            //FUNCTION TO WRITE DETAILS IN DATA FILE
	void delflight();            //FUNCTION TO DELETE FLIGHT DETAILS
	void displayinfo();          //FUNCTION TO DISPLAY DETAILS OF FLIGHTS
	void flightrecord();         //FUNCTION TO DISPLAY LISTS OF FLIGHTS
	void availflight();          //FUNCTION TO GET FLIGHT DETAILS FROM FILE
	void modify(int);            //FUNCTION TO DISPLAY MODIFICATION SCREEN
	void tmodify();              //FUNCTION TO MODIFY IN DATA FILE
}obj;
class ticket                         //CLASS FOR TICKET INFO
{ 	int tckno;                   //TICKET NUMBER SYSTEM CREATED
	char uname[20];              //NAME OF TICKET BEARER
	char age[10];                //AGE OF TICKET BEARER
	char adress[50];             //ADDRESS OF TICKET BEARER
	char gender[10];             //GENDER OF TICKET BEARER
	char phno[20];               //PHONE NUMBER OF TICKET BEARER
	char costy[20];              //COST OF TICKET
public:
	int uflightno;               //USER GIVEN FLIGHT NUMBER
	void ugetinfo();             //FUNCTION TO GET USER INFO
	void addticket();            //FUNCTION TO INPUT IN FILE
	void delticket();            //FUNCTION TO DELETE TICKET
	void displayticket();        //FUNCTION TO DISPLAY TICKET
	void availticket();          //FUNCTION TO GET TICKET FROM FILE
	void npflight();             //FUNCTION TO DISPLAY LIST OF BOOKED TICKETS
	void printticket();          //FUNCTION TO PRINT TICKET OUTLINES
	void getprint();             //FUNCTION TO PRINT USER INFO ON TICKET
}ob;
void flight::getinfo()
{
	textcolor(WHITE);
	gotoxy(35,5);
	cin>>flightno;
	gotoxy(35,7);
	gets(flightname);
	gotoxy(35,9);
	gets(startplace);
	gotoxy(35,11);
	gets(destination);
	gotoxy(35,13);
	gets(takeoff);
	gotoxy(35,15);
	gets(land);
	gotoxy(35,17);
	cin>>capacity;
	gotoxy(35,19);
	cin>>generalcost;
	gotoxy(35,21);
	cin>>executivecost;
	gotoxy(35,23);
	cin>>maxspeed;
}
void flight::displayinfo()
{
	gotoxy(35,5);
	cout<<flightno;
	gotoxy(35,7);
	cout<<flightname;
	gotoxy(35,9);
	cout<<startplace;
	gotoxy(35,11);
	cout<<destination;
	gotoxy(35,13);
	cout<<takeoff;
	gotoxy(35,15);
	cout<<land;
	gotoxy(35,17);
	cout<<capacity;
	gotoxy(35,19);
	cout<<generalcost;
	gotoxy(35,21);
	cout<<executivecost;
	gotoxy(35,23);
	cout<<maxspeed;
}
void flight::addflight()
{
	char choice;
	fstream fin;
	fin.open("check_1.txt",ios::app);
	A:
	mgetflight();
	obj.getinfo();
	fin.write((char *)&obj,sizeof(obj));
	gotoxy(2,2);
	cprintf("MORE ENTRIES PRESS Y ELSE PRESS ANY KEY");
	choice=getch();
	if(choice=='y'||choice=='Y')
	goto A;
	else
	fin.close();
}
void flight::delflight()
{
	clrscr();
	int i;
	int fno;                    //USER CHOICE
	char choice;                //USER CHOICE
	fstream f;
	fstream k;
	fstream g;
	C:
	clrscr();
	g.open("check_1.txt",ios::in);
	i=1;
	while(g.read((char *)&obj,sizeof(obj)))
	{
		textcolor(YELLOW);
		gotoxy(2,1);
		cprintf("S.NO.");
		gotoxy(10,1);
		cprintf("FLIGHT NO.");
		gotoxy(25,1);
		cprintf("START PLACE");
		gotoxy(50,1);
		cprintf("DESTINATION");
		gotoxy(2,i+1);
		cout<<i;
		gotoxy(10,i+1);
		cout<<flightno;
		gotoxy(25,i+1);
		cout<<startplace;
		gotoxy(50,i+1);
		cout<<destination;
		i++;
	}
	g.close();
	cout<<endl;
	f.open("check_1.txt",ios::in);
	k.open("replace2.txt",ios::out|ios::trunc);
	gotoxy(55,23);
	cout<<"TYPE 911 TO GO BACK";
	gotoxy(2,21);
	cout<<"ENTER FLIGHT NUMBER TO BE DELETED - ";
	cin>>fno;
	if(fno==911)
	mwindow();
	while(f.read((char*)&obj,sizeof(obj)))
	{
		if(flightno==fno)
		{
			gotoxy(2,22);
			cout<<"FLIGHT RECORD DELETING";
			delay(900);
			gotoxy(2,23);
			cout<<"RECORD WAS SUCCESSFULLY DELETED";
			gotoxy(2,24);
			cout<<"TO DELETE MORE RECORDS PRESS Y ELSE PRESS ANY KEY";
		}
		else
		{
			k.write((char*)&obj,sizeof(obj));
			gotoxy(2,23);
			cout<<"WRONG INPUT";
			gotoxy(2,24);
			cout<<"TO TRY AGAIN PRESS Y ELSE PRESS ANY KEY";
		}
	 }
	 remove("check_1.txt");
	 f.close();
	 k.close();
	 f.open("replace2.txt",ios::in);
	 k.open("check_1.txt",ios::out|ios::trunc);
	 while(f.read((char*)&obj,sizeof(obj)))
	 {
		k.write((char*)&obj,sizeof(obj));
	 }
	 remove("replace2.txt");
	 f.close();
	 k.close();
	 choice=getch();
	 if(choice=='y'||choice=='Y')
	 goto C;
}
void flight::availflight()
{
	int i=1;
	int k=0;
	int choice;
	int more;
	char cho;                   //USER CHOICE
	fstream g;
	A:
	clrscr();
	i=1;
	clrscr();
	g.open("check_1.txt",ios::in);
	while(g.read((char *)&obj,sizeof(obj)))
	{
		textcolor(YELLOW);
		gotoxy(2,1);
		cprintf("S.NO.");
		gotoxy(10,1);
		cprintf("FLIGHT NO.");
		gotoxy(25,1);
		cprintf("START PLACE");
		gotoxy(50,1);
		cprintf("DESTINATION");
		gotoxy(2,i+1);
		cout<<i;
		gotoxy(10,i+1);
		cout<<flightno;
		gotoxy(25,i+1);
		cout<<startplace;
		gotoxy(50,i+1);
		cout<<destination;
		i++;
	}
	g.close();
	{
		gotoxy(55,23);
		cout<<"TYPE 911 TO GO BACK";
		gotoxy(2,23);
		cout<<"ENTER FLIGHT NUMBER TO SEE INFO - ";
		cin>>choice;
		if(choice==911)
		mwindow();
		g.open("check_1.txt",ios::in);
		g.seekg(0);
		while(g.read((char *)&obj,sizeof(obj)))
		{
			if(flightno==choice)
			{
				mviewflight();
				obj.displayinfo();
				k=1;
			}
		}
		g.close();
		if(k==0)
		{
			gotoxy(30,12);
			cout<<"WRONG INPUT ENTER AGAIN";
			delay(900);
			goto A;
		}
		gotoxy(2,2);
		cout<<"TO SEE MORE RECORDS PRESS Y ELSE PRESS ANY KEY";
		cho=getch();
		if(cho=='y'||cho=='Y')
		goto A;
	}

}
void flight::flightrecord()
{
	int i;
	i=1;
	ifstream g;
	g.open("check_1.txt",ios::in);
	while(g.read((char *)&obj,sizeof(obj)))
		{
			textcolor(YELLOW);
			gotoxy(2,1);
			cprintf("S.NO.");
			gotoxy(10,1);
			cprintf("FLIGHT NO.");
			gotoxy(25,1);
			cprintf("START PLACE");
			gotoxy(50,1);
			cprintf("DESTINATION");
			gotoxy(2,i+1);
			cout<<i;
			gotoxy(10,i+1);
			cout<<flightno;
			gotoxy(25,i+1);
			cout<<startplace;
			gotoxy(50,i+1);
			cout<<destination;
			i++;
		}
		g.close();
	}
void flight::modify(int k)
{
	char mchange[20];
	int p;
	A:
	gotoxy(2,2);
	cout<<"WHAT DO YOU WANT TO CHANGE -                   ";
	gotoxy(31,2);
	gets(mchange);                                         //USER CHOICE
	if(strcmpi(mchange,"FLIGHT NUMBER")==0)
	{
		Z:
		gotoxy(35,5);
		cout<<"                          ";
		gotoxy(35,5);
		cin>>p;
		ifstream z;
		z.open("check_1.txt",ios::in);
		while(z.read((char *)&obj,sizeof(obj)))
		{
			if(flightno==p)             //CHECKING FLIGHT NUMBER
			{
				gotoxy(2,2);
				cout<<"FLIGHT NUMBER ALRESDY EXISTS !!              ";
				delay(900);
				gotoxy(2,2);
				cout<<"                                             ";
				z.close();
				goto Z;
			}
		}
		flightno=p;
	}
	else   if(strcmpi(mchange,"FLIGHT NAME")==0)
	{
		gotoxy(35,7);
		cout<<"                          ";
		gotoxy(35,7);
		gets(flightname);
	}
	else   if(strcmpi(mchange,"START PLACE")==0)
	{
		 gotoxy(35,9);
		 cout<<"                          ";
		 gotoxy(35,9);
		 gets(startplace);
	}
	else   if(strcmpi(mchange,"DESTINATION")==0)
	{
		gotoxy(35,11);
		cout<<"                          ";
		gotoxy(35,11);
		gets(destination);
	}
	else   if(strcmpi(mchange,"TAKEOFF TIME")==0)
	{
		gotoxy(35,13);
		cout<<"                          ";
		gotoxy(35,13);
		gets(takeoff);
	}
	else   if(strcmpi(mchange,"LANDING TIME")==0)
	{
		gotoxy(35,15);
		cout<<"                          ";
		gotoxy(35,15);
		gets(land);
	}
	else   if(strcmpi(mchange,"CAPACITY")==0)
	{
		gotoxy(35,17);
		cout<<"                          ";
		gotoxy(35,17);
		cin>>capacity;
	}
	else   if(strcmpi(mchange,"GENERAL CLASS")==0)
	{
		gotoxy(35,19);
		cout<<"                          ";
		gotoxy(35,19);
		cin>>generalcost;
	}
	else    if(strcmpi(mchange,"EXECUTIVE CLASS")==0)
	{
		gotoxy(35,21);
		cout<<"                          ";
		gotoxy(35,21);
		cin>>executivecost;
	}
	else    if(strcmpi(mchange,"MAX SPEED")==0)
	{
		gotoxy(35,23);
		cout<<"                          ";
		gotoxy(35,23);
		cin>>maxspeed;
	}
	else
	{
		gotoxy(55,2);
		cout<<"WRONG INPUT ENTER AGAIN";
		delay(900);
		gotoxy(55,2);
		cout<<"                       ";
		goto A;
	}
}
void flight::tmodify()
{
	char chola;                        //USER CHOICE
	int r;
	fstream up("check_1.txt",ios::in|ios::out);
	int fno;
	long pos;
	Y:
	clrscr();
	flightrecord();
	gotoxy(55,23);
	cout<<"TYPE 911 TO GO BACK";
	gotoxy(2,24);
	cout<<"ENTER FLIGHT NUMBER TO BE CHANGED - ";
	cin>>fno;
	X:
	r=0;
	up.seekg(0);
	while(!up.eof())
	{
		pos=up.tellg();
		up.read((char*)&obj,sizeof(obj));
		if(flightno==fno)
		{
			mchaflight();
			obj.displayinfo();
			obj.modify(fno);
			up.seekg(pos);
			up.write((char*)&obj,sizeof(obj));
			break;
			r=1;
		}
	}
	if(r==1)
	{
		gotoxy(2,2);
		cout<<"TO UPDATE SAME RECORD PRESS U,FOR ANOTHER PRESS A ELSE PRESS ANY KEY";
		chola=getch();
		if(chola=='u'||chola=='U')
		goto X;
		else if(chola=='a'||chola=='A')
		goto Y;
		else
		up.close();
	}
}
void ticket::ugetinfo()
{
	int x=10000,y,ext;
	randomize();
	ticket ob2;
	fstream ck;
	ck.open("user_2.txt",ios::in);
	A:
	ck.seekg(0);
	y=random(x);
	while(!ck.eof())
	{
		ck.read((char*)&ob2,sizeof(ob2));
		if(tckno==y||tckno==911)            //GENERATING TICKET NO.
		goto A;
	}
	tckno=y;
	ck.seekg(0);
	ck.close();
	int pu=0;
	fstream ni;
	N:
	ni.open("check_1.txt",ios::in);
	ni.seekg(0);
	gotoxy(35,5);
	cout<<"    ";
	gotoxy(35,5);
	cin>>ext;
	while(ni.read((char *)&obj,sizeof(obj)))
	{
		if(ext==obj.flightno)
		pu=1;
	}
	if(pu==1)
	{
		uflightno=ext;
		ni.close();
		goto L;
	}
	else if(pu==0)
	{
		ni.close();
		goto N;
	}
	L:
	gotoxy(35,7);
	gets(uname);
	gotoxy(35,9);
	gets(age);
	gotoxy(35,11);
	gets(adress);
	gotoxy(35,13);
	gets(gender);
	gotoxy(35,15);
	gets(phno);
	gotoxy(35,17);
	gets(costy);
	gotoxy(2,20);
	cprintf("YOUR TICKET NUMBER IS:     ");
	cout<<tckno;
}
void ticket::addticket()
{
	char choi;                               //USER CHOICE
	fstream fon;
	fon.open("user_2.txt",ios::app);
	MO:
	cbookticket();
	ob.ugetinfo();
	fon.write((char *)&ob,sizeof(ob));
	gotoxy(2,2);
	cout<<"TO BOOK MORE TICKETS PRESS Y ELSE PRESS ANY KEY";
	choi=getche();
	if(choi=='Y'||choi=='y')
	goto MO;
	else
	fon.close();
}
void ticket::displayticket()
{
	gotoxy(35,5);
	cout<<tckno;
	gotoxy(35,7);
	cout<<uflightno;
	gotoxy(35,9);
	cout<<uname;
	gotoxy(35,11);
	cout<<age;
	gotoxy(35,13);
	cout<<adress;
	gotoxy(35,15);
	cout<<gender;
	gotoxy(35,17);
	cout<<phno;
	gotoxy(35,19);
	cout<<costy;
}
void ticket::availticket()
{
	int i=1;
	int k=0;
	int choice;
	int more;
	char cho;
	fstream m;
	A:
	k=0;
	clrscr();
	gotoxy(55,2);
	cprintf("TYPE 911 TO GO BACK");
	gotoxy(2,22);
	cout<<"ENTER TICKET NUMBER:      ";
	cin>>choice;
	if(choice==911)
	cwindow();
	m.open("user_2.txt",ios::in);
	m.seekg(0);
	while(m.read((char *)&ob,sizeof(ob)))
	{
		if(tckno==choice)
		{
			ccheckticket();
			ob.displayticket();
			k=1;
		}
	}
	m.close();
	if(k==0)
	{
		gotoxy(55,24);
		cout<<"WRONG INPUT ENTER AGAIN";
		delay(900);
		gotoxy(65,24);
		cout<<"                       ";
		goto A;
	}
	gotoxy(2,2);
	cout<<"TO VIEW MORE TICKETS PRESS Y ELSE PRESS ANY KEY";
	cho=getch();
	if(cho=='y'||cho=='Y')
	goto A;
}
void ticket::getprint()
{
	int i=1;
	int k=0;
	int choice;
	int more;
	char cho;
	fstream m;
	A:
	k=0;
	clrscr();
	gotoxy(55,2);
	cprintf("TYPE 911 TO GO BACK");
	gotoxy(2,22);
	cout<<"ENTER TICKET NUMBER:      ";
	cin>>choice;
	if(choice==911)
	cwindow();
	m.open("user_2.txt",ios::in);
	m.seekg(0);
	while(m.read((char *)&ob,sizeof(ob)))
	{
		if(tckno==choice)
		{
			ob.printticket();
			k=1;
		}
	}
	m.close();
	if(k==0)
	{
		gotoxy(55,24);
		cout<<"WRONG INPUT ENTER AGAIN";
		delay(900);
		gotoxy(65,24);
		cout<<"                       ";
		goto A;
	}
	gotoxy(2,2);
	cout<<"TO VIEW MORE TICKETS PRESS Y ELSE PRESS ANY KEY";
	cho=getch();
	if(cho=='y'||cho=='Y')
	goto A;
}

void ticket::delticket()
{
	clrscr();
	int i;
	int fno;
	char choice;                            //USER CHOICE
	fstream f;
	fstream k;
	fstream g;
	g.open("user_2.txt",ios::in);
	C:
	clrscr();
	f.open("user_2.txt",ios::in);
	k.open("replace3.txt",ios::out|ios::trunc);
	gotoxy(55,2);
	cout<<"TYPE 911 TO GO BACK";
	gotoxy(15,10);
	cout<<"ENTER TICKET NUMBER TO BE DELETED:  ";
	cin>>fno;
	if(fno==911)
	cwindow();
	while(f.read((char*)&ob,sizeof(ob)))
	{
		if(tckno==fno)
		{
			gotoxy(15,11);
			cout<<"TICKET DELETING";
			delay(1800);
		}
		else
		{
			k.write((char*)&ob,sizeof(ob));
		}
	}
	remove("user_2.txt");
	f.close();
	k.close();
	f.open("replace3.txt",ios::in);
	k.open("user_2.txt",ios::out|ios::trunc);
	while(f.read((char*)&ob,sizeof(ob)))
	{
		k.write((char*)&ob,sizeof(ob));
	}
	gotoxy(15,13);
	cout<<"YOUR TICKET WAS SUCCESSFULLY DELETED";
	remove("replace3.txt");
	f.close();
	k.close();
	gotoxy(15,14);
	cout<<"TO DELETE MORE RECORDS PRESS Y ELSE PRESS ANY KEY";
	choice=getch();
	if(choice=='y'||choice=='Y')
	goto C;
}
void ticket::npflight()
{
	clrscr();
	fstream d;
	d.open("user_2.txt",ios::in);
	int i=1;
	while(d.read((char*)&ob,sizeof(ob)))
	{
		textcolor(YELLOW);
		gotoxy(2,1);
		cprintf("S.NO.");
		gotoxy(10,1);
		cprintf("TICKET NUMBER");
		gotoxy(25,1);
		cprintf("FLIGHT NUMBER");
		gotoxy(50,1);
		cprintf("NAME");
		gotoxy(2,i+1);
		cout<<i;
		gotoxy(10,i+1);
		cout<<tckno;
		gotoxy(25,i+1);
		cout<<uflightno;
		gotoxy(50,i+1);
		cout<<uname;
		i++;
	}
	d.close();
	getch();
}
void ticket::printticket()
{
	_setcursortype(_NOCURSOR);
	clrscr();
	for(int i=10;i<=70;i++)
	{
		delay(10);
		textcolor(1291);
		gotoxy(i,5);
		cprintf("³");
		gotoxy(i,20);
		cprintf("³");
	}
	for(int j=6;j<20;j++)
	{
		delay(10);
		gotoxy(10,j);
		cprintf("³");
		gotoxy(70,j);
		cprintf("³");
	}
	for(i=50;i<=65;i++)
	{
		int x=random(100);
		if(x%2==0)
		for(j=15;j<=18;j++)
		{
			textcolor(WHITE);
			gotoxy(i,j);
			cprintf("³");
		}
		else
		for(j=15;j<=18;j++)
		{
			textcolor(WHITE);
			gotoxy(i,j);
			cprintf("Þ");
		}
	}
	gotoxy(45,19);
	cprintf("SCAN WITH YOUR SMARTPHONE");
	textcolor(1113);
	gotoxy(13,10);
	cprintf("NAME         :");
	gotoxy(27,10);
	cout<<uname;
	gotoxy(13,8);
	cprintf("TICKET NUMBER:");
	gotoxy(27,8);
	cout<<tckno;
	gotoxy(40,8);
	cprintf("FLIGHT NUMBER:");
	gotoxy(54,8);
	cout<<uflightno;
	gotoxy(13,12);
	cprintf("PHONE NUMBER :");
	gotoxy(27,12);
	cout<<phno;
	gotoxy(13,14);
	cprintf("GENDER       :");
	gotoxy(27,14);
	cout<<gender;
	gotoxy(13,16);
	cprintf("CLASS        :");
	gotoxy(27,16);
	cout<<costy;
	gotoxy(13,18);
	cprintf("TICKET COST  :$");
	gotoxy(28,18);
	ifstream momo;
	int lolo,mcosty;
	momo.open("user_2.txt",ios::in);
	momo.seekg(0);
	while(momo.read((char *)&ob,sizeof(ob)))
	{
		if(strcmpi(costy,"EXECUTIVE CLASS")==0)
		lolo=1;
		else if(strcmpi(costy,"GENERAL CLASS")==0)
		lolo=2;
	}
	momo.close();
	ifstream tata;
	tata.open("check_1.txt",ios::in);
	tata.seekg(0);
	while(tata.read((char *)&obj,sizeof(obj)))
	{
		if(uflightno==obj.flightno)
		{
			if(lolo==1)
			mcosty=obj.executivecost;
			else if(lolo==2)
			mcosty=obj.generalcost;
		}
	}
	tata.close();
	cout<<mcosty;      //    COST CALCULATED DISPLAY HERE
	textcolor(1091);
	gotoxy(11,19);
	cprintf("ASYLUM AIRLINES");
	getch();
}
void loading()
{       textcolor(1292);
	for(int a=11;a<40;a++)
	{
		delay(15);
		gotoxy(a,10);
		cprintf(" _");
		gotoxy(a-2,11);
		cprintf(" __");
		gotoxy(a-4,12);
		cprintf(" ___");
		gotoxy(a-6,13);
		cprintf(" ____");
	}
	for(a=75;a>=40;a--)
	{
		delay(15);
		gotoxy(a,17);
		cprintf("_ ");
		gotoxy(a-2,16);
		cprintf("__ ");
		gotoxy(a-4,15);
		cprintf("___ ");
		gotoxy(a-6,14);
		cprintf("____ ");
	}
	int b=37,c=0,x=0,y=0,w=0;
	for(int i=0;i<4;i++)
	{
		delay(200);
		gotoxy(b+w,11);
		cprintf(" __");
		gotoxy((b-3)+x,12);
		cprintf("  ___");
		gotoxy((b-6)+y,13);
		cprintf("   ____");
		gotoxy((b-6)+y,14);
		cprintf("   ____");
		gotoxy((b-3)+x,15);
		cprintf("  ___");
		gotoxy(b+w,16);
		cprintf(" __");
		w++;
		x+=2;
		y+=3;
	}
	for(int k=40;k<=75;k++)
	{
		delay(15);
		int p=k-1,q=k+1,r=k+2;
		int  s=k;
		if(p<76)
		{
			gotoxy(p,10);
			cprintf(" _");
			gotoxy(p,17);
			cprintf(" _");
		}
		if(s<74)
		{
			gotoxy(s,11);
			cprintf(" __");
			gotoxy(s,16);
			cprintf(" __");
		}
		if(q<73)
		{
			gotoxy(q,12);
			cprintf(" ___");
			gotoxy(q,15);
			cprintf(" ___");
		}
		if(r<72)
		{
			gotoxy(r,13);
			cprintf(" ____");
			gotoxy(r,14);
			cprintf(" ____");
		}
		gotoxy(40,10);
		cprintf("_");
		gotoxy(40,11);
		cprintf(" __");
		gotoxy(40,12);
		cprintf("  ___");
		gotoxy(40,13);
		cprintf("   ____");
		gotoxy(40,14);
		cprintf("   ____");
		gotoxy(40,15);
		cprintf("  ___");
		gotoxy(40,16);
		cprintf(" __");
		gotoxy(40,17);
		cprintf("_");
		gotoxy(32,13);
		cprintf("FLYING....");
		gotoxy(32,14);
		cprintf("MADNESS...");
		for(int f=10;f<=17;f++)
		for(int g=72;g<=75;g++)
		{
			gotoxy(g,f);
			cprintf(" ");
		}
	   }
}
void border()
{
	clrscr();
	textcolor(823);
	for(int i=40;i>=1;i--)
	{
		gotoxy(i,2);
		cprintf("Û");
		gotoxy(80-i,2);
		cprintf("Û");
		delay(20);
	}
	for(int j=2;j<=24;j++)
	{
		gotoxy(1,j);
		cprintf("Û");
		gotoxy(80,j);
		cprintf("Û");
		delay(30);
	}
	for(i=1;i<=40;i++)
	{
		gotoxy(i,24);
		cprintf("Û");
		gotoxy(81-i,24);
		cprintf("Û");
		delay(20);
	}
	textcolor(824);
	for(i=40;i>=2;i--)
	{
		gotoxy(i,23);
		cprintf("Û");
		gotoxy(80-i,23);
		cprintf("Û");
		delay(20);
	}
	for(j=23;j>=3;j--)
	{
		gotoxy(2,j);
		cprintf("Û");
		gotoxy(79,j);
		cprintf("Û");
		delay(30);
	}
	for(i=3;i<=40;i++)
	{
		gotoxy(i,3);
		cprintf("Û");
		gotoxy(81-i,3);
		cprintf("Û");
		delay(20);
	}
	textcolor(WHITE);
}
void heading(int a)
{
	gotoxy(5,4+a);
	cprintf("ÛÛÛÛ ÛÛÛÛ Û  Û Û    Û  Û ÛÛÛÛÛ   ÛÛÛÛ ÛÛÛÛ ÛÛÛÛ Û    ÛÛÛÛ ÛÝ  Û ÛÛÛÛ ÛÛÛÛ ");
	gotoxy(5,5+a);
	cprintf("Û  Û Û    Û  Û Û    Û  Û Û Û Û   Û  Û  ÛÛ  Û  Û Û     ÛÛ  ÛÞ  Û Û    Û    ");
	gotoxy(5,6+a);
	cprintf("ÛÛÛÛ ÛÛÛÛ ÛÛÛÛ Û    Û  Û Û   Û   ÛÛÛÛ  ÛÛ  ÛÛÛÛ Û     ÛÛ  Û Ý Û ÛÛÛ  ÛÛÛÛ");
	gotoxy(5,7+a);
	cprintf("Û  Û    Û  ÛÛ  Û    Û  Û Û   Û   Û  Û  ÛÛ  ÛÞÝ  Û     ÛÛ  Û  ÝÛ Û       Û");
	gotoxy(5,8+a);
	cprintf("Û  Û ÛÛÛÛ  ÛÛ  ÛÛÛÛ ÛÛÛÛ Û   Û   Û  Û ÛÛÛÛ Û ÞÝ ÛÛÛÛ ÛÛÛÛ Û  ÞÛ ÛÛÛÛ ÛÛÛÛ");
	textcolor(WHITE);
}
void madeby()
{
		char ch[28]="PRESS ANY KEY TO CONTINUE";
		textcolor(CYAN);
			gotoxy(5,19);
			cprintf("MADE BY: ");
		for(int i=55;i>4;i--)
		{
			delay(10);
			gotoxy(i,20);
			textcolor(591);
			cprintf("RAZAUL HASAN ANSARI ");
		}
		for(i=55;i>4;i--)
		{
			delay(10);
			gotoxy(i,21);
			cprintf("VEDANSH AGARWAL ");
		}
		for(i=55;i>4;i--)
		{
			delay(10);
			gotoxy(i,22);
			cprintf("PIYUSH GUPTA ");
		}
		textcolor(CYAN);
		gotoxy(59,20);
		cprintf("GUIDED BY");
		gotoxy(51,21);
		cprintf("MR. SHAKTIRISH K.AGARWAL");
		textcolor(WHITE);
		for(i=50;i<78;i++)
		for(int j=12;j<=18
		;j++)
		{
			delay(15);
			gotoxy(i,j-1);
			cprintf("  ");
			gotoxy(i,j);
			cout<<ch[i-50];
		}
		textcolor(WHITE+BLINK);
		gotoxy(50,18);
		cprintf("PRESS ANY KEY TO CONTINUE");
		getch();
}
void gate()
{
	clrscr();
	textcolor(WHITE);
	for(int i=0;i<=80;i++)
	for(int j=0;j<=25;j++)
	{
		textcolor(WHITE);
		gotoxy(i,j);
		if((i==15&&j==12)||(i==45&&j==12))
		cprintf("É");
		if((i==35&&j==12)||(i==65&&j==12))
		cprintf("»");
		if((j>12)&&(i==15||i==35||i==45||i==65))
		cprintf("º");
		if(((i>15&&i<35)||(i>45&&i<65))&&j==12)
		cprintf("Í");
		if((j>16&&j<22)&&(i==25||i==55))
		cprintf("³");
		if((j>17&&j<21)&&(i==24||i==54))
		cprintf("³");
		if((i==26||i==56)&&j==19)
		cprintf("");
		if((j>=12)&&(i==14||i==36||i==44||i==66||i==16||i==34||i==46||i==64))
		cprintf(" ");
		cprintf("°");
	}
	gotoxy(19,9);
	cprintf("CUSTOMER GATE");
	gotoxy(50,9);
	cprintf("MANAGER GATE");
	gotoxy(18,24);
	cprintf("TYPE 1 TO ENTER");
	gotoxy(48,24);
	cprintf("TYPE 2 TO ENTER");
	gotoxy(33,25);
	cprintf("TYPE E TO EXIT");
	char m;
	a:
	m=getch();
	if(m=='1')
	cwindow();
	if(m=='2')
	mwindow();
	if(m=='e'||m=='E')
	exit(0);
	else
	goto a;
}
void cwindow()
{
	q:
	_setcursortype(_NOCURSOR);
	clrscr();
	textcolor(WHITE);
	heading(0);
	for(int i=0;i<=80;i++)
	for(int j=0;j<=25;j++)
	{
		gotoxy(i,j);
		if((i==10||i==30||i==50)&&(j==9||j==17))
		cprintf("É");
		if((i==29||i==49||i==69)&&(j==9||j==17))
		cprintf("»");
		if((i==10||i==30||i==50)&&(j==16||j==25))
		cprintf("È");
		if((i==29||i==49||i==69)&&(j==16||j==25))
		cprintf("¼");
		if(((i>10&&i<29)||(i>30&&i<49)||(i>50&&i<69))&&(j==9||j==17||j==16||j==25))
		cprintf("Í");
		if(((j>9&&j<16)||(j>17&&j<25))&&(i==10||i==29||i==30||i==49||i==50||i==69))
		cprintf("º");
	}
	int x=20,y=15;
	gotoxy(50,1);
	cprintf("USE A & D FOR CONTROLS");
	gotoxy(50,2);
	cprintf("PRESS B TO RETURN & E TO EXIT");
	gotoxy(14,10);
	cprintf("BOOK TICKET");
	gotoxy(34,10);
	cprintf("CHECK TICKET");
	gotoxy(53,10);
	cprintf("CANCEL BOOKING");
	gotoxy(53,18);
	cprintf("MANAGER WINDOW");
	gotoxy(13,18);
	cprintf("CHECK  FLIGHTS");
	gotoxy(34,18);
	cprintf("PRINT TICKET");
	gotoxy(x,y);
	cprintf("ð");
	p:
	int k=(x/20)*y;
	char z=getch();
	if(x>=20&&x<60&&(z=='d'||z=='D'))
	{
		gotoxy(x,y);
		cprintf(" ");
		gotoxy(x+=20,y);
		cprintf("ð");
	}
	else if(x==60&&y==15&&(z=='d'||z=='D'))
	{
		gotoxy(x,y);
		cprintf(" ");
		x=20;
		y=24;
		gotoxy(x,y);
		cprintf("ð");
	}
	if(x>20&&x<=60&&(z=='a'||z=='A'))
	{
		gotoxy(x,y);
		cprintf(" ");
		gotoxy(x-=20,y);
		cprintf("ð");
	}
	else if(x==20&&y==24&&(z=='a'||z=='A'))
	{
		gotoxy(x,y);
		cprintf(" ");
		x=60;
		y=15;
		gotoxy(x,y);
		cprintf("ð");
	}
	if(z=='b'||z=='B')
	gate();
	if(z==13&&k==15)
	{
		loading1();
		_setcursortype(_NORMALCURSOR);
		ob.addticket();
		_setcursortype(_NOCURSOR);
		goto q;
	}
	if(z==13&&k==30)
	{
		loading2();
		_setcursortype(_NORMALCURSOR);
		ob.availticket();
		_setcursortype(_NOCURSOR);
		goto q;
	}
	if(z==13&&k==45)
	{
		loading3();
		_setcursortype(_NORMALCURSOR);
		ob.delticket();
		_setcursortype(_NOCURSOR);
		goto q;
	}
	if(z==13&&k==24)
	{
		loading4();
		_setcursortype(_NORMALCURSOR);
		obj.availflight();
		_setcursortype(_NOCURSOR);
		goto q;
	}
	if(z==13&&k==48)
	{
		loading5();
		_setcursortype(_NORMALCURSOR);
		ob.getprint();
		_setcursortype(_NOCURSOR);
		goto q;
	}

	if(z==13&&k==72)
	{
		loading6();
		_setcursortype(_NORMALCURSOR);
		mwindow();
		_setcursortype(_NOCURSOR);
		goto q;
	}
	if(z=='e'||z=='E')
	exit(0);
	goto p;
}
void mwindow()
{
	q:
	_setcursortype(_NOCURSOR);
	clrscr();
	textcolor(WHITE);
	heading(0);
	for(int i=0;i<=80;i++)
	for(int j=0;j<=25;j++)
	{
		gotoxy(i,j);
		if((i==10||i==30||i==50)&&(j==9||j==17))
		cprintf("É");
		if((i==29||i==49||i==69)&&(j==9||j==17))
		cprintf("»");
		if((i==10||i==30||i==50)&&(j==16||j==25))
		cprintf("È");
		if((i==29||i==49||i==69)&&(j==16||j==25))
		cprintf("¼");
		if(((i>10&&i<29)||(i>30&&i<49)||(i>50&&i<69))&&(j==9||j==17||j==16||j==25))
		cprintf("Í");
		if(((j>9&&j<16)||(j>17&&j<25))&&(i==10||i==29||i==30||i==49||i==50||i==69))
		cprintf("º");
	}
	int x=20,y=15;
	gotoxy(50,1);
	cprintf("USE A & D FOR CONTROLS");
	gotoxy(50,2);
	cprintf("PRESS B TO RETURN & E TO EXIT");
	gotoxy(12,10);
	cprintf("REGISTER  FLIGHT");
	gotoxy(35,10);
	cprintf("VIEW FLIGHT");
	gotoxy(54,10);
	cprintf("UPDATE FLIGHT");
	gotoxy(13,18);
	cprintf("DELETE FLIGHT");
	gotoxy(52,18);
	cprintf("CUSTOMER  WINDOW");
	gotoxy(33,18);
	cprintf("PASSANGER LIST");
	gotoxy(x,y);
	cprintf("ð");
	p:
	int k=(x/20)*y;
	char z=getch();
	if(x>=20&&x<60&&(z=='d'||z=='D'))
	{
		gotoxy(x,y);
		cprintf(" ");
		x=x+20;
		gotoxy(x,y);
		cprintf("ð");
	}
	else if(x==60&&y==15&&(z=='d'||z=='D'))
	{
		gotoxy(x,y);
		cprintf(" ");
		x=20;
		y=24;
		gotoxy(x,y);
		cprintf("ð");
	}
	if(x>20&&x<=60&&(z=='a'||z=='A'))
	{
		gotoxy(x,y);
		cprintf(" ");
		x=x-20;
		gotoxy(x,y);
		cprintf("ð");
	}
	else if(x==20&&y==24&&(z=='a'||z=='A'))
	{
		gotoxy(x,y);
		cprintf(" ");
		x=60;
		y=15;
		gotoxy(x,y);
		cprintf("ð");
	}
	if(z=='b'||z=='B')
	gate();
	if(z==13&&k==30)
	{
		loading2();
		_setcursortype(_NORMALCURSOR);
		obj.availflight();
		_setcursortype(_NOCURSOR);
		goto q;
	}
		if(z==13&&k==15)
	{
		loading1();
		_setcursortype(_NORMALCURSOR);
		mgetflight();
		obj.addflight();
		_setcursortype(_NOCURSOR);
		goto q;
	}
		if(z==13&&k==45)
	{
		loading3();
		_setcursortype(_NORMALCURSOR);
		obj.tmodify();
		_setcursortype(_NOCURSOR);
		goto q;
	}
		if(z==13&&k==24)
	{
		loading4();
		_setcursortype(_NORMALCURSOR);
		obj.delflight();
		_setcursortype(_NOCURSOR);
		goto q;
	}
		if(z==13&&k==48)
	{
		loading5();
		_setcursortype(_NORMALCURSOR);
		ob.npflight();
		_setcursortype(_NOCURSOR);
		goto q;
	}
		if(z==13&&k==72)
	{
		loading6();
		cwindow();
		goto q;
	}
	if(z=='e'||z=='E')
	exit(0);
	goto p;

}
void mgetflight()
{
	clrscr();
	for(int i=0;i<=80;i++)
	for(int j=0;j<=25;j++)
	{
		textcolor(1086);
		gotoxy(i,j);
		if((i==1&&j==2))
		cprintf("É");
		if((i==80&&j==2))
		cprintf("»");
		if((i==1&&j==25))
		cprintf("È");
		if((i==80&&j==25))
		cprintf("¼");
		if((i>1&&i<80&&(j==2||j==25)))
		cprintf("Í");
		if((j>2&&j<25&&(i==1||i==80)))
		cprintf("º");
	}
	gotoxy(33,3);
	cprintf("REGISTER FLIGHT");
	gotoxy(33,4);
	cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
	gotoxy(3,5);
	cprintf("FLIGHT NUMBER    :");
	gotoxy(3,7);
	cprintf("FLIGHT NAME      :");
	gotoxy(3,9);
	cprintf("START PLACE      :");
	gotoxy(3,11);
	cprintf("DESTINATION      :");
	gotoxy(3,13);
	cprintf("TAKEOFF TIME     :");
	gotoxy(3,15);
	cprintf("LANDING TIME     :");
	gotoxy(3,17);
	cprintf("CAPACITY         :");
	gotoxy(3,19);
	cprintf("GENERAL CLASS    :");
	gotoxy(3,21);
	cprintf("EXECUTIVE CLASS  :");
	gotoxy(3,23);
	cprintf("MAX SPEED        :");
	format();
}
void mviewflight()
{
	clrscr();
	for(int i=0;i<=80;i++)
	for(int j=0;j<=25;j++)
	{
		textcolor(1086);
		gotoxy(i,j);
		if((i==1&&j==2))
		cprintf("É");
		if((i==80&&j==2))
		cprintf("»");
		if((i==1&&j==25))
		cprintf("È");
		if((i==80&&j==25))
		cprintf("¼");
		if((i>1&&i<80&&(j==2||j==25)))
		cprintf("Í");
		if((j>2&&j<25&&(i==1||i==80)))
		cprintf("º");
	}
	gotoxy(31,3);
	cprintf("VIEW FLIGHT DETAILS");
	gotoxy(31,4);
	cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
	gotoxy(3,5);
	cprintf("FLIGHT NUMBER    :");
	gotoxy(3,7);
	cprintf("FLIGHT NAME      :");
	gotoxy(3,9);
	cprintf("START PLACE      :");
	gotoxy(3,11);
	cprintf("DESTINATION      :");
	gotoxy(3,13);
	cprintf("TAKEOFF TIME     :");
	gotoxy(3,15);
	cprintf("LANDING TIME     :");
	gotoxy(3,17);
	cprintf("CAPACITY         :");
	gotoxy(3,19);
	cprintf("GENERAL CLASS    :             $");
	gotoxy(3,21);
	cprintf("EXECUTIVE CLASS  :             $");
	gotoxy(3,23);
	cprintf("MAX SPEED        :");
}
void mchaflight()
{
	clrscr();
	for(int i=0;i<=80;i++)
	for(int j=0;j<=25;j++)
	{
		textcolor(1086);
		gotoxy(i,j);
		if((i==1&&j==2))
		cprintf("É");
		if((i==80&&j==2))
		cprintf("»");
		if((i==1&&j==25))
		cprintf("È");
		if((i==80&&j==25))
		cprintf("¼");
		if((i>1&&i<80&&(j==2||j==25)))
		cprintf("Í");
		if((j>2&&j<25&&(i==1||i==80)))
		cprintf("º");
	}
	gotoxy(30,3);
	cprintf("CHANGE FLIGHT DETAILS");
	gotoxy(30,4);
	cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
	gotoxy(3,5);
	cprintf("FLIGHT NUMBER    :");
	gotoxy(3,7);
	cprintf("FLIGHT NAME      :");
	gotoxy(3,9);
	cprintf("START PLACE      :");
	gotoxy(3,11);
	cprintf("DESTINATION      :");
	gotoxy(3,13);
	cprintf("TAKEOFF TIME     :");
	gotoxy(3,15);
	cprintf("LANDING TIME     :");
	gotoxy(3,17);
	cprintf("CAPACITY         :");
	gotoxy(3,19);
	cprintf("GENERAL CLASS    :             $");
	gotoxy(3,21);
	cprintf("EXECUTIVE CLASS  :             $");
	gotoxy(3,23);
	cprintf("MAX SPEED        :");
}
void cbookticket()
{
	clrscr();
	for(int i=0;i<=80;i++)
	for(int j=0;j<=25;j++)
	{
		textcolor(1086);
		gotoxy(i,j);
		if((i==1&&j==2))
		cprintf("É");
		if((i==80&&j==2))
		cprintf("»");
		if((i==1&&j==25))
		cprintf("È");
		if((i==80&&j==25))
		cprintf("¼");
		if((i>1&&i<80&&(j==2||j==25)))
		cprintf("Í");
		if((j>2&&j<25&&(i==1||i==80)))
		cprintf("º");
	}
	gotoxy(35,3);
	cprintf("TICKET BOOKING");
	gotoxy(35,4);
	cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
	gotoxy(3,5);
	cprintf("FLIGHT NUMBER    :");
	gotoxy(3,7);
	cprintf("NAME             :");
	gotoxy(3,9);
	cprintf("AGE              :");
	gotoxy(3,11);
	cprintf("ADDRESS          :");
	gotoxy(3,13);
	cprintf("GENDER           :");
	gotoxy(3,15);
	cprintf("CONTACT NUMBER   :");
	gotoxy(3,17);
	cprintf("CLASS            :");
	gotoxy(3,19);
	cprintf("WRITE EXECUTIVE CLASS OR GENERAL CLASS");
}
void ccheckticket()
{
	clrscr();
	for(int i=0;i<=80;i++)
	for(int j=0;j<=25;j++)
	{
		textcolor(1086);
		gotoxy(i,j);
		if((i==1&&j==2))
		cprintf("É");
		if((i==80&&j==2))
		cprintf("»");
		if((i==1&&j==25))
		cprintf("È");
		if((i==80&&j==25))
		cprintf("¼");
		if((i>1&&i<80&&(j==2||j==25)))
		cprintf("Í");
		if((j>2&&j<25&&(i==1||i==80)))
		cprintf("º");
	}
	gotoxy(35,3);
	cprintf("TICKET CHECKING");
	gotoxy(35,4);
	cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
	gotoxy(3,5);
	cprintf("TICKET NUMBER    :");
	gotoxy(3,7);
	cprintf("FLIGHT NUMBER    :");
	gotoxy(3,9);
	cprintf("NAME             :");
	gotoxy(3,11);
	cprintf("AGE              :");
	gotoxy(3,13);
	cprintf("ADDRESS          :");
	gotoxy(3,15);
	cprintf("GENDER           :");
	gotoxy(3,17);
	cprintf("CONTACT NUMBER   :");
	gotoxy(3,19);
	cprintf("CLASS            :");
}
void loading1()
{
	gotoxy(17,14);
	cprintf("LOADING");
	for(int i=3;i>0;i--)
	for(int j=11;j<=17+i;j++)
	{
		delay(50);
		gotoxy(j,13);
		cprintf(" .");
	}
	for(i=1;i<=3;i++)
	for(j=22-i;j<=27;j++)
	{
		delay(50) ;
		gotoxy(j,13);
		cprintf(" .");
		gotoxy(27,13);
		cprintf("  ");
	}
}

void loading2()
{
	gotoxy(37,14);
	cprintf("LOADING");
	for(int i=3;i>0;i--)
	for(int j=31;j<=37+i;j++)
	{
		delay(50);
		gotoxy(j,13);
		cprintf(" .");
	}
	for(i=1;i<=3;i++)
	for(j=42-i;j<=47;j++)
	{
		delay(50);
		gotoxy(j,13);
		cprintf(" .");
		gotoxy(47,13);
		cprintf("  ");
	}
}
void loading3()
{
	gotoxy(57,14);
	cprintf("LOADING");
	for(int i=3;i>0;i--)
	for(int j=51;j<=57+i;j++)
	{
		delay(50);
		gotoxy(j,13);
		cprintf(" .");
	}
	for(i=1;i<=3;i++)
	for(j=62-i;j<=67;j++)
	{
		delay(50);
		gotoxy(j,13);
		cprintf(" .");
		gotoxy(67,13);
		cprintf("  ");
	}
}
void loading4()
{
	gotoxy(17,23);
	cprintf("LOADING");
	for(int i=3;i>0;i--)
	for(int j=11;j<=17+i;j++)
	{
		delay(50);
		gotoxy(j,22);
		cprintf(" .");
	}
	for(i=1;i<=3;i++)
	for(j=22-i;j<=27;j++)
	{
		delay(50) ;
		gotoxy(j,22);
		cprintf(" .");
		gotoxy(27,22);
		cprintf("  ");
	}
}
void loading5()
{
	gotoxy(37,23);
	cprintf("LOADING");
	for(int i=3;i>0;i--)
	for(int j=31;j<=37+i;j++)
	{
		delay(50);
		gotoxy(j,22);
		cprintf(" .");
	}
	for(i=1;i<=3;i++)
	for(j=42-i;j<=47;j++)
	{
		delay(50);
		gotoxy(j,22);
		cprintf(" .");
		gotoxy(47,22);
		cprintf("  ");
	}
}
void loading6()
{
	gotoxy(57,23);
	cprintf("LOADING");
	for(int i=3;i>0;i--)
	for(int j=51;j<=57+i;j++)
	{
		delay(50);
		gotoxy(j,22);
		cprintf(" .");
	}
	for(i=1;i<=3;i++)
	for(j=62-i;j<=67;j++)
	{
		delay(50);
		gotoxy(j,22);
		cprintf(" .");
		gotoxy(67,22);
		cprintf("  ");
	}
}
void format()
{
	textcolor(WHITE);
	gotoxy(34,19);
	cprintf("$");
	gotoxy(34,21);
	cprintf("$");
	textcolor(1064);
	gotoxy(62,5);
	cprintf("('ONLY INTEGER')");
	gotoxy(62,7);
	cprintf("('ONLY CHARACTER')");
	gotoxy(62,9);
	cprintf("('ONLY CHARACTER')");
	gotoxy(62,11);
	cprintf("('ONLY CHARACTER')");
	gotoxy(62,13);
	cprintf("('ONLY CHARACTER')");
	gotoxy(62,15);
	cprintf("('ONLY CHARACTER')");
	gotoxy(62,17);
	cprintf("('ONLY INTEGER')");
	gotoxy(62,19);
	cprintf("('ONLY INTEGER')");
	gotoxy(62,21);
	cprintf("('ONLY INTEGER')");
	gotoxy(62,23);
	cprintf("('ONLY INTEGER')");
	textcolor(WHITE);
}
void login()
{
	char pass[100];
	char pass2[]={"pass"};
	char pass3[]={"911"};
	a:
	textcolor(1287);
	gotoxy(55,22);
	cprintf("TYPE 911 TO EXIT");
	gotoxy(29,11);
	cprintf("PASSWORD : ");
	textcolor(WHITE);
	gotoxy(40,11);
	for(int i=0,x=40;i<10;i++,x++)
	{
		b:
		pass[i]=getch();
		if(pass[i]==13)
			break;
		else if(pass[i]==8&&x>40)
		{
			x--;
			i--;;
			gotoxy(x,11);
			cprintf("                              ");
			gotoxy(40+i,11);
			goto b;

		}
		else if(pass[i]!=8)
			cprintf("*");
	}
	int valid=0,valid1=0;
	for(i=0;pass[i]!='\0';i++)
		if(pass[i]==pass2[i])
			valid++;
	if(valid==strlen(pass2))
	{
		gotoxy(30,15);
		cprintf("ACCESS GRANTED");
		delay(1000);
		gotoxy(30,17);
		cprintf("LOADING SYSTEM");
		gotoxy(37,18);
		delay(1000);
		_setcursortype(_NOCURSOR);
		return;
	}
	for(i=0;pass[i]!='\0';i++)
		if(pass[i]==pass3[i])
			valid1++;
	if(valid1==strlen(pass3))
	exit(0);
	else
	{
		gotoxy(30,15);
		cprintf("ACCESS DENIED");
		delay(900);
		gotoxy(40,11);
		cprintf("                                            ");
		gotoxy(30,15);
		cprintf("             ");
		goto a;
	}
}

void main()
{
	clrscr();
	login();
	border();
	textcolor(267);
	heading(1);
	delay(300);
	loading();
	delay(300);
	madeby();
	gate();
	getch();
}




