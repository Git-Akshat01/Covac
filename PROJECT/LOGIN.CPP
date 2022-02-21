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
//#include "BOX2.H"
//#include "front1.cpp"

//class for registration for 1st dose
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
//    void getdata();
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
reg ob1;
// input data
/*void reg ::getdata()
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
    //assigning system date to date variable
    sprintf(date,"%d%d%d",d.da_day,d.da_mon,d.da_year);
    printf("Date of First dose : %d/%d/%d",d.da_day,d.da_mon,d.da_year);


    //date of nxt dose

    //certificate id
	     ++a;
    sprintf(certiid,"%s%d",date,a);

    printf("\nCertificate Id : %s",certiid);
    //vaccine type
    int ch;
    //textcolor(YELLOW);
    gotoxy(3,15);
    printf("Which vaccine you want to take : ");
    gotoxy(3,17);
    printf("1.COVISHIELD");
    cout<<"\t";
    printf("2.COVAXIN");
    cout<<"\t";
    printf("3.SPUTNIK V");
    cout<<"\t";
    printf("4.JANSSEN");
    cout<<"\t";
    gotoxy(3,19);
    printf("\nEnter the choice of your vaccine : ");
    cin >> ch;
    while (ch<1 || ch>5)
    {
	gotoxy(3,19);
	printf("\nRe-enter the correct code from above : ");
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

} */
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
	    cout<<endl<<"NEW NAME : ";
	    fflush(stdin);
	    gets(fname);
	    cout<<endl<<"NAME MODIFIED SUCCESSFULLY!!!!!!!!";
	    break;
	case 2:
	    cout<<endl<<"AGE : ";
	    cin>>age;
	    cout<<endl<<"AGE MODIFIED SUCCESSFULLY!!!!!!!!";
	    break;
	case 3:
	    cout<<endl<<"GENDER : ";
	    fflush(stdin);
	    scanf("%c",&gen);
	    cout<<endl<<"GENDER MODIFIED SUCCESSFULLY!!!!!!!!";
	    break;
	case 4:
	    cout << endl<< "PHONE NUMBER : ";
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
void login()
{
    clrscr();
//    front();
//    page2();
    fstream akshat, tmp;
    char filename[10];
    strcpy(filename, "RECORD");

    akshat.open(filename, ios ::in | ios ::out | ios ::binary);
    //ios::in read from file
    //ios::out write from file
    int ch;
    while (1)
    {
        //textcolor(BLUE);
        clrscr();
	cout << endl<< "MAIN MENU";
//	cout << endl<< "1.ADD";
	cout << endl<< "1.LIST";
	cout << endl<< "2.COUNT";
	cout << endl<< "3.MODIFY";
//	cout << endl<< "4.DELETE";
	cout << endl<< "4.EXIT";
	cout << endl<< "ENTER YOUR CHOICE : ";
	cin >> ch;
	switch (ch)
	{
/*	case 1:
	    ob1.getdata();
	    akshat.clear();
	    akshat.seekp(0, ios::end);
	    akshat.write((char *)&ob1, sizeof(ob1));
	    break;
*/
	case 1:
	    /*	    int flag=0;
	    akshat.clear();
	    akshat.seekg(0,ios::beg);
	    while(akshat.read((char*)&ob1,sizeof(ob1)))
	    {
		ob1.putdata();
		flag=1;
	    }
	    if(flag==0)
		cout<<endl<<"NO RECORD FOUND";
	    break;     */

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


	case 2:
	    akshat.clear();
	    akshat.seekg(0, ios::end);
	    long int rec = akshat.tellg();
	    cout << endl<< "TOTAL DOSES ADMINSTERED : " << rec / sizeof(ob1);
	    // cout<<endl<<"TOTAL DOSES LEFT : "<<total-(rec/sizeof(ob1));
	    cout << endl<< "PRESS ANY KEY TO CONTINUE";
	    getch();
	    break;

	case 3:
	    akshat.clear();
	    flag = 0;
	    int z, x;
	    char n[14];
	    cout << endl<< "ENTER CERTIFICATE ID TO MODIFY : ";
	    gets(n);
	    akshat.seekg(0, ios ::beg);
	    while (akshat.read((char *)&ob1, sizeof(ob1)))
	    {
		x = strcmp(ob1.retcerti(), n);
		if (x == 0)
		{
		    cout << "\nModifying Record";
		    ob1.modidata();
		    akshat.seekg(-108L, ios::cur);
		    akshat.write((char *)&ob1, 108L);
		    flag = 1;
		    break;
		}
	    }
	    if (flag == 0)
		cout << "\nThis record does not exist.....";
	    break;

/*	case 5:
	    akshat.clear();
	    flag = 0;
	    char m[14];
	    cout << "\nENTER CERTIFICATE ID TO DELETE : ";
	    gets(m);
	    akshat.seekg(0, ios::beg);
	    tmp.open("temp.dat", ios::out | ios::binary);
	    while (akshat.read((char *)&ob1, sizeof(ob1))) //108L
	    {
		x = strcmp(ob1.retcerti(), m);
		if (x != 0)
		    tmp.write((char *)&ob1, 108L);
		else
		    flag = 1;
	    }
	    if (flag == 1)
	    {
		cout << "\nRecord has been deleted";
		akshat.close();
		tmp.close();
		remove(filename);
		rename("temp.dat", filename);
		akshat.open(filename, ios ::in | ios ::out, ios ::binary);
	    }
	    else
	    {
		tmp.close();
		remove("temp.dat");
		cout << "\nThis record does not exist";
	    }
	    printf("\nPRESS ANY KEY TO CONTINUE");
	    break;*/

	case 4:
	    akshat.close();
	    exit(1);
	}
    }
}