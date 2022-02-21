#include <iostream.h>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <process.h>
#include <fstream.h>
#include <iomanip.h>
#include <string.h>
#include <stdlib.h>
#include "BOX2.H"
#include "front1.cpp"
#include "leap.cpp"
#include "logregis.cpp"
//class for registration for 1st dose
class reg
{
private:
    char fname[30];
    int age;
    char phonenum[11];
    char gen;
    char aadhar[13];
    char date[11];
    char nxtdate[11];
    char vaccine[15];
protected:
    char certiid[14];
public:
    void getdata();
    void putdata();
    void modidata();
    void title();
    char* retcerti()
    {
	return(certiid);
    }
    char * retphone()
    {
	return(phonenum);
    }
} ;
int a=0;
char da[5];
reg ob1;
// input data
void reg ::getdata()
{
    int i, cnt, x, y;
    ag://label when age is below 18
    clrscr();

    mybox(1, 1, 79, 25, 14);
    gotoxy(20, 1);
    printf("Enter the following details in the form ");
    textcolor(BROWN);

    //age
    gotoxy(3, 3);
    cprintf("Age : ");
    cin >> age;
    if(age<18)
    {
	gotoxy(3,3);
	cprintf("Registration is not available for age below 18");
	cprintf("PRESS ANY KEY TO CONTINUE");
	getch();
	goto ag;
    }

    //first name
    gotoxy(3, 5);
    cprintf("NAME : ");
    fflush(stdin);
    gets(fname);

    // gender
    gotoxy(3, 7);
    cprintf("Gender [M/F/T] : ");
    gend:
    // fflush(stdin);
    cin >> gen;
    //check is alphabet
    if(isalpha(gen))
    {
	gen=toupper(gen);
    }
    else
    {
	gotoxy(3,7);
	cprintf("Re-Enter Correct Gender [M/F/T] : ");
	goto gend;
    }

    // phone number
    gadha: //label"Phone Number : ";
    gotoxy(3, 9);
    cprintf("Phone Number : ");
    cnt = 0;
    fflush(stdin);
    scanf("%s",phonenum);
    cnt=strlen(phonenum);
    if (cnt != 10)
	goto gadha;
    // aadhar number
    aadha: //label"Aadhar Number : ";
    gotoxy(3, 11);
    cprintf("Aadhar Number : ");
    fflush(stdin);
    cnt = 0;
    scanf("%s",aadhar);
    cnt=strlen(aadhar);
    if (cnt != 12)
	goto aadha;
    //date
    struct date d;
    getdate(&d);
    sprintf(da,"%d",d.da_day);
    //assigning system date to date variable
    sprintf(date,"%d%d%d",d.da_day,d.da_mon,d.da_year);
    gotoxy(3,13);
    cprintf("Date of First dose : %d/%d/%d",d.da_day,d.da_mon,d.da_year);

    //date of nxt dose
    gotoxy(3,15);
    adddays(d.da_day,d.da_mon,d.da_year,84);

    //certificate id
    textcolor(RED);
    sprintf(certiid,"%s%d",date,++a);
    gotoxy(3,15);
    cprintf("Certificate Id : %s (PLEASE NOTE THE CERTIFICATE ID FOR FUTURE USE)",certiid);
    //vaccine type
    int ch;
    textcolor(YELLOW);
    gotoxy(3,17);
    cprintf("Which vaccine you want to take : ");
    gotoxy(3,18);
    cprintf("1.COVISHIELD");
    cout<<"\t";
    cprintf("2.COVAXIN");
    cout<<"\t";
    cprintf("3.SPUTNIK V");
    cout<<"\t";
    cprintf("4.JANSSEN");
    cout<<"\t";
    gotoxy(3,20);
    cprintf("Enter the choice of your vaccine : ");
    cin >> ch;
    while (ch<=0 || ch>=5)
    {
	gotoxy(3,20);
	cprintf("Re-enter the correct code from above : ");
	cin >> ch;
    }
    if (ch == 1)
    {
	strcpy(vaccine, "COVISHIELD");
    }
    if (ch == 2)
    {
	strcpy(vaccine, "COVAXIN");
    }
    if (ch == 3)
    {
	strcpy(vaccine, "SPUTNIK V");
    }
    if (ch == 4)
    {
	strcpy(vaccine, "JANSSEN");
    }
    gotoxy(25,22);
    textcolor(LIGHTGREEN);
    cprintf("REGISTERED SUCCESSFULLY");
    gotoxy(25,23);
    textcolor(LIGHTGREEN);
    cprintf("PRESS ANY KEY TO CONTINUE......");
    getch();
}
/*class reg
{
private:
    char fname[30];
    int age;
    char phonenum[11];
    char gen;
    char aadhar[13];
    char date[11];
    char nxtdate[11];
    char vaccine[15];
protected:
    char certiid[14];

public:
    void getdata();
    void putdata();
    void modidata();
    void title();
    char* retcerti()
    {
	return(certiid);
    }
    char* retphone()
    {
	return(phonenum);
    }
} ;
int a=0;
char da[5];
reg ob1;
// input data
void reg ::getdata()
{
    int i, cnt, x, y;

    clrscr();
    //textcolor(RED);
    mybox(1, 1, 79, 25, 14);
    gotoxy(20, 1);
    printf("Enter the following details in the form ");

    //first name
    gotoxy(3, 3);
    printf("NAME : ");
    fflush(stdin);
    gets(fname);
    //cin.getline(fname, 30);

    //age
    gotoxy(3, 5);
    printf("Age : ");
    cin >> age;

    // gender
    gotoxy(3, 7);
    printf("Gender [M/F/T] : ");
    // fflush(stdin);
    cin >> gen;
    gen=toupper(gen);

    // phone number
    gadha: //label"Phone Number : ";
    gotoxy(3, 9);
    printf("Phone Number : ");
    cnt = 0;
    fflush(stdin);
    scanf("%s",phonenum);
    cnt=strlen(phonenum);
    if (cnt != 10)
	goto gadha;

    // aadhar number
    aadha: //label"Aadhar Number : ";
    gotoxy(3, 11);
    printf("Aadhar Number : ");
    fflush(stdin);
    cnt = 0;
    scanf("%s",aadhar);
    cnt=strlen(aadhar);
    if (cnt != 12)
	goto aadha;

    //date
    struct date d;
    getdate(&d);
    sprintf(da,"%d",d.da_day);
    //assigning system date to date variable
    sprintf(date,"%d%d%d",d.da_day,d.da_mon,d.da_year);
    gotoxy(3,13);
    printf("Date of First dose : %d/%d/%d",d.da_day,d.da_mon,d.da_year);


    //date of nxt dose

    //certificate id
    textcolor(RED);
    sprintf(certiid,"%s%d",date,++a);
    gotoxy(3,15);
    printf("Certificate Id : %s (PLEASE NOTE THE CERTIFICATE ID FOR FUTURE USE)",certiid);
    //vaccine type
    int ch;
    //textcolor(YELLOW);
    gotoxy(3,17);
    printf("Which vaccine you want to take : ");
    gotoxy(3,18);
    printf("1.COVISHIELD");
    cout<<"\t";
    printf("2.COVAXIN");
    cout<<"\t";
    printf("3.SPUTNIK V");
    cout<<"\t";
    printf("4.JANSSEN");
    cout<<"\t";
    gotoxy(3,20);
    printf("Enter the choice of your vaccine : ");
    cin >> ch;
    while (ch<1 || ch>5)
    {
	gotoxy(3,21);
	printf("Re-enter the correct code from above : ");
	cin >> ch;
    }

    if (ch == 1)
    {
	strcpy(vaccine, "COVISHIELD");
    }
    if (ch == 2)
    {
	strcpy(vaccine, "COVAXIN");
    }
    if (ch == 3)
    {
	strcpy(vaccine, "SPUTNIK V");
    }
    if (ch == 4)
    {
	strcpy(vaccine, "JANSSEN");
    }

    cout<<endl<<"REGISTERED SUCCESSFULLY";
    cout<<endl<<"PRESS ANY KEY TO CONTINUE......";
    getch();

}*/
void reg :: title()
{
	int i=0;
	if(strlen(fname)!=0)
	{

		fname[i]=toupper(fname[i]);
		for(i=1;fname[i]!='\0';i++)
		{
			if(isspace(fname[i]))
			{
				i++;
				fname[i]=toupper(fname[i]);
			}
			else
				fname[i]=tolower(fname[i]);
		}
	}
}

//print data
void reg :: putdata()
{
	int c;
	clrscr();
	cout<<"\n";
    printf("BENEFICIARY DETAILS : ");
   // cout << "\nName : "<<title(fname);
   title();
    cout<<"\n";
    printf("Name : %s",fname);
    cout<<"\n";
    printf("Age : %d",age);
    cout<<"\n";
    printf("Gender : %c ",gen);
    cout<<"\n";
    printf("Phone Number : %s",phonenum);
    cout<<"\n";
    printf("Aadhar Number : %s",aadhar);
    cout<<"\n";
    printf("Vaccine details");
    cout<<"\n";
    printf("Vaccine Name : %s ",vaccine);
    cout<<"\n";
    printf("Date of First dose : %s",date);
    cout<<"\n";
    printf("Certificate ID : %s",certiid);
    cout<<"\n";
    printf("Press any key to continue..... ");
    getch();
/*    struct date d;
    getdate(&d);
    printf("Date of First dose : %d/%d/%d", d.da_day,d.da_mon,d.da_year);*/

    clrscr();
}

// modify data
void reg :: modidata()
{
    int ch=0,cnt=0,f=0;
    while(1)
    {
	//textcolor(BROWN);
	cout<<endl<<"MODIFYING CERTIFICATE ID : "<<certiid;
	cout<<endl<<"MODIFY MENU ";
	cout<<endl<<"1.NAME ";
	cout<<endl<<"2.AGE ";
	cout<<endl<<"3.GENDER";
	cout<<endl<<"4.PHONE NUMBER";
	cout<<endl<<"5.EXIT";
	cout<<endl<<"ENTER CHOICE 1 - 5 : ";
	cin>>ch;
	switch(ch)
	{
	case 1:
	    printf("\nCURRENT NAME : %s",fname);
	    cout<<endl<<"NEW NAME : ";
	    fflush(stdin);
	    gets(fname);
	    cout<<endl<<"NAME MODIFIED SUCCESSFULLY!!!!!!!!";
	    break;
	case 2:
	    printf("\nCURRENT AGE : %d",age);
	    cout<<endl<<"NEW AGE : ";
	    cin>>age;
	    cout<<endl<<"AGE MODIFIED SUCCESSFULLY!!!!!!!!";
	    break;
	case 3:
	    cout<<endl;
	    printf("CURRENT GENDER : %c",gen);
	    cout<<endl<<"NEW GENDER [M/F/T] : ";
	    lab:
	    fflush(stdin);
	    scanf("%c",&gen);
	    if(isalpha(gen))
		gen=toupper(gen);
	    else
	    {
		cout<<endl;
		printf("Re-Enter Correct GENDER [M/F/T] :");
		goto lab;
	    }
	    cout<<endl;
	    printf("GENDER MODIFIED SUCCESSFULLY!!!!!!!!");
	    break;
	case 4:
	    printf("\nCURRENT PHONE NUMBER : %s",phonenum);
	    cout << endl<< "NEW PHONE NUMBER : ";
	    fflush(stdin);
	    gadha: //label"Phone Number : ";
	    // gotoxy(3, 8);
	    printf("Phone Number : ");
	     cnt = 0;
	    // fflush(stdin);
	    scanf("%s", phonenum);
	    cnt = strlen(phonenum);
	    if (cnt != 10)
		goto gadha;
	    cout<<endl<<"PHONE NUMBER MODIFIED SUCCESSFULLY!!!!!!!!";
	    break;

	case 5:
	    f=1;
	    break;
	}
	if(f==1)
	    break;

    }
}
void main()
{
    clrscr();
    front();
    page2();
//    logregis();

    char day[5];
    struct date d;
    getdate(&d);
    sprintf(day,"%d",d.da_day);
    fstream aread;
    aread.open("arecord.txt",ios::in|ios::out|ios::binary);
    aread>>da;
    int l=strcmp(da,day);
    if(l==0)
	aread>>a;
    else
	a=0;
    aread<<da<<endl<<a;
    aread.close();


    fstream akshat,tmp;
    char filename[10];
    strcpy(filename,"record.txt");

    akshat.open(filename,ios :: in| ios :: out| ios :: binary);
    //ios::in read from file
    //ios::out write from file

    int ch;
    while(1)
    {
	//textcolor(BLUE);
	clrscr();
	cout<<endl<<"MAIN MENU";
	cout<<endl<<"1.ADD";
	cout<<endl<<"2.LIST";
	cout<<endl<<"3.COUNT";
	cout<<endl<<"4.MODIFY";
	cout<<endl<<"5.DELETE";
	cout<<endl<<"6.EXIT";
	cout<<endl<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	switch(ch)
	{
	    case 1:
	    ob1.getdata();
	    akshat.clear();
	    akshat.seekp(0,ios::end);
	    akshat.write((char *)&ob1,sizeof(ob1));
	    break;

	   /* case 2:
	    int flag=0;
	    akshat.clear();
	    akshat.seekg(0,ios::beg);
	    while(akshat.read((char*)&ob1,sizeof(ob1)))
	    {
		ob1.putdata();
		flag=1;
	    }
	    if(flag==0)
		cout<<endl<<"NO RECORD FOUND";
	    break;   */

	case 2:
	    int flag = 0;
	    int lch;
	    cout << endl<< "1.ALL LISITNG";
	    cout << endl<< "2.SPECIFIC LISTING";
	    cout << endl<< "ENTER YOUR CHOICE : ";
	    cin >> lch;
	    switch (lch)
	    {
	    case 1:
		akshat.clear();
		akshat.seekg(0,ios::beg);
		while (akshat.read((char *)&ob1, sizeof(ob1)))
		{
		    ob1.putdata();
		    flag = 1;
		}
		/*if (flag == 0)
		    cout << endl<< "NO RECORD FOUND";*/
		break;
	    case 2:
		cout << endl<< "1.SEARCH BY PHONE NUMBER";
		cout << endl<<"2.SEARCH BY CERTIFICATE ID";
		cout << endl<< "ENTER YOUR CHOICE : ";
		int sch;
		cin >> sch;
		switch (sch)
		{
		case 1:
		    char p[11];
		    int k;
		    cout << endl<< "ENTER PHONE NUMBER : ";
		    gets(p);
		    akshat.clear();
		    akshat.seekg(0, ios::beg);
		    while (akshat.read((char *)&ob1, sizeof(ob1)))
		    {
			k = strcmp(ob1.retphone(), p);
			if (k == 0)
			{
			    ob1.putdata();
			    flag = 1;
			}
		    }
		    /*if (flag == 0)
			cout << endl<< "NO RECORD FOUND";*/
		    break;
		case 2:
		    char po[14];
		    int ko;
		    cout << endl<< "ENTER CERTIFICATE ID : ";
		    gets(po);
		    akshat.clear();
		    akshat.seekg(0, ios::beg);
		    while (akshat.read((char *)&ob1, sizeof(ob1)))
		    {
			ko = strcmp(ob1.retcerti(), po);
			if (ko == 0)
			{
			    ob1.putdata();
			    flag = 1;
			}
		    }
		    /*	if(flag==0)
						cout<<endl<<"NO RECORD FOUND";*/
		    break;
		}
	    break;
	    }

		if (flag == 0)
		    cout << endl<< "NO RECORD FOUND";
		break;
	    case 3:
	    akshat.clear();
	    akshat.seekg(0,ios::end);
	    long int rec=akshat.tellg();
	    cout<<endl<<"TOTAL DOSES ADMINSTERED : "<<rec/sizeof(ob1);
	    // cout<<endl<<"TOTAL DOSES LEFT : "<<total-(rec/sizeof(ob1));
	    cout<<endl<<"PRESS ANY KEY TO CONTINUE";
	    getch();
	    break;

	    case 4:
	    akshat.clear();
	    flag=0;
	    int z,x;
	    char n[14];
	    cout<<endl<<"ENTER CERTIFICATE ID TO MODIFY : ";
	    gets(n);
	    akshat.seekg(0, ios :: beg);
	    while(akshat.read((char*)&ob1,sizeof(ob1)))
	    {
		x=strcmp(ob1.retcerti(),n);
		if(x==0)
		{
			cout<<"\nModifying Record";
			ob1.modidata();
			akshat.seekg(-108L,ios::cur);
			akshat.write((char*)&ob1,108L);
			flag=1;
			break;
		}
	    }
	    if(flag==0)
		cout<<"\nThis record does not exist.....";
	    break;

	    case 5:
		akshat.clear();
		flag=0;
		char m[14];
		cout<<"\nENTER CERTIFICATE ID TO DELETE : ";
		gets(m);
		akshat.seekg(0,ios::beg);
		tmp.open("temp.dat",ios::out|ios::binary);
		while(akshat.read((char *)&ob1,sizeof(ob1)))//108L
		{
			x=strcmp(ob1.retcerti(),m);
			if(x!=0)
				tmp.write((char *)&ob1,108L);
			else
				flag=1;
		}
		if(flag==1)
		{
			cout<<"\nRecord has been deleted";
			akshat.close();
			tmp.close();
			remove(filename);
			rename("temp.dat",filename);
			akshat.open(filename,ios :: in|ios :: out,ios :: binary);
		}
		else
		{
			tmp.close();
			remove("temp.dat");
			cout<<"\nThis record does not exist";
		}
		printf("\nPRESS ANY KEY TO CONTINUE");
		break;

	    case 6:
	    ofstream awrite("arecord.txt");
	    awrite<<da<<endl<<a;
	    awrite.close();
	    akshat.close();
	    exit(1);
	}
    }
}
