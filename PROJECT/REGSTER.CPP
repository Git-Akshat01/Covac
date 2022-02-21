#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <process.h>
#include<dos.h>
#include"box2.h"
//#include "front.cpp"

struct regster
{
    char fname[20];
    char mname[20];
    char lname[20];
    char phonenum[15];
    int age;
    char gen[8];
    char aadhar[15];
    char date[15];
    char nxtdate[10];
    struct regster *next;
};

typedef struct regster reg;

struct vaccine
{
    char vacchoice[15];
    regster *h;
    regster *t;
    struct vaccine *nptr;
};

typedef vaccine vac;
vac *head, *tail; //vaccine type head and tail pointer

//getdata
void getdata(reg *p)
{
    int i, cnt,x,y;

    textcolor(RED);
    clrscr();
    mybox(1,1,79,25,14);
    gotoxy(20,1);
    cprintf("Enter the following details in the form ");

    //first name
    gotoxy(3,3);
    cprintf("Name : ");
    fflush(stdin);
    gets(p->fname);

    //age
    gotoxy(3,5);
    cprintf("Age : ");
    cin >> (p->age);

    // gender
    gotoxy(3,7);
    cprintf("Gender [M/F/T] : ");
   // fflush(stdin);
    cin>>(p->gen);

    // phone number
    gadha:       //label"Phone Number : ";
    gotoxy(3,9);
    cprintf("Phone Number : ");
    cnt=0;
   // fflush(stdin);
    scanf("%s",(p->phonenum));
	cnt=strlen(p->phonenum);

    if(cnt!=10)
       goto gadha;

    // aadhar number
    aadha:               //label"Aadhar Number : ";
    gotoxy(3,11);
    cprintf("Aadhar Number : ");
    fflush(stdin);
    cnt=0;
    scanf("%s",(p->aadhar));
    cnt=strlen(p->aadhar);
    if(cnt!=12)
	goto aadha;

    // date
    dat:                       //label
    gotoxy(3,13);
    cprintf("Date (DD/MM/YYYY) : ");
    cnt=0;
    fflush(stdin);
    scanf("%s",(p->date));
    cnt=strlen(p->date);
    if(cnt!=10)
	goto dat;



    p->next = NULL;
}
void myadd()
{
    reg *t;
    t = new reg;
    getdata(t);

    int ch;
    char j[15];
    textcolor(YELLOW);
    gotoxy(3,15);
    cprintf("Which vaccine you want to take : ");
    gotoxy(3,17);
    cprintf("101.COVISHIELD");
    cout<<"\t";
    cprintf("102.COVAXIN");
    cout<<"\t";
    cprintf("103.SPUTNIK V");
    cout<<"\t";
    cprintf("104.JANSSEN");
    cout<<"\t";
    gotoxy(3,19);
    cprintf("\nEnter the choice of your vaccine : ");
    cin >> ch;
    while (ch<100 || ch>105)
    {
	gotoxy(3,19);
	cprintf("\nRe-enter the correct code from above : ");
	cin >> ch;
    }
//    clrscr();
    if (ch == 101)
    {
	strcpy(j, "COVISHIELD");
    }
    if (ch == 102)
    {
	strcpy(j, "COVAXIN");
    }
    if (ch == 103)
    {
	strcpy(j, "SPUTNIK V");
    }
    if (ch == 104)
    {
	strcpy(j, "JANSSEN");
    }

    //head will be null only when first company is created.
    if (head == NULL)
    {
	vac *tmp;
	tmp = new vac;
	strcpy(tmp->vacchoice, j);
	tmp->h = t;
	tmp->t = t;
	tmp->nptr = NULL;
	head = tmp;
	tail = tmp;
	/*	if (ch == 101)
	{
	    strcpy(tmp->vacchoice,"COVISHIELD");
	    tmp->h = t;
	    tmp->t = t;
	    tmp->nptr = NULL;
	    head = tmp;
	    tail = tmp;
	}
	if (ch == 102)
	{
	    strcpy(tmp->vacchoice, "COVAXIN");
	    tmp->h = t;
	    tmp->t = t;
	    tmp->nptr = NULL;
	    head = tmp;
	    tail = tmp;
	}
	if (ch == 103)
	{
	    strcpy(tmp->vacchoice, "SPUTNIK V");
	    tmp->h = t;
	    tmp->t = t;
	    tmp->nptr = NULL;
	    head = tmp;
	    tail = tmp;
	}
	if (ch == 104)
	{
	    strcpy(tmp->vacchoice, "JANSSEN");
	    tmp->h = t;
	    tmp->t = t;
	    tmp->nptr = NULL;
	    head = tmp;
	    tail = tmp;
	} */
	return;
    }
    int x = 0;
    vac *p;
    //if(same vaccine)
    for (p = head; p != NULL; p = p->nptr)
    {
	x = strcmp(p->vacchoice, j);
	if (x == 0)
	{
	    p->t->next = t;
	    p->t = t;
	    return;
	}
    }
    if (p == NULL)
    {
	vac *tmp;
	tmp = new vac;
	if (ch == 101)
	{
	    strcpy(tmp->vacchoice, "COVISHIELD");
	    tmp->h = t;
	    tmp->t = t;
	    tmp->nptr = NULL;
	    tail->nptr = tmp;
	    tail = tmp;
	}
	if (ch == 102)
	{
	    strcpy(tmp->vacchoice, "COVAXIN");
	    tmp->h = t;
	    tmp->t = t;
	    tmp->nptr = NULL;
	    tail->nptr = tmp;
	    tail = tmp;
	}
	if (ch == 103)
	{
	    strcpy(tmp->vacchoice, "SPUTNIK V");
	    tmp->h = t;
	    tmp->t = t;
	    tmp->nptr = NULL;
	    tail->nptr = tmp;
	    tail = tmp;
	}
	if (ch == 104)
	{
	    strcpy(tmp->vacchoice, "JANSSEN");
	    tmp->h = t;
	    tmp->t = t;
	    tmp->nptr = NULL;
	    tail->nptr = tmp;
	    tail = tmp;
	}
    }
}


//listing
void title(char *p)
{
if(strlen(p)!=0)
{

	*(p)=toupper(*p);
	for(int i=1;*(p+i)!='\0';i++)
	{
		if(isspace(*(p+i))                     )
		{
			i++;
			*(p+i)=toupper(*(p+i));
		}
		else
			*(p+i)=tolower(*(p+i));
	}
}
}
void print(reg *i, vac *j,int c)
{
	//int i;
	textcolor(c);
	cout<<"\n";
    cprintf("DETAILS OF REGISTRATION FORMS : ");
   // cout << "\nName : "<<title(i->fname);
   title(i->fname);
   title(i->mname);
   title(i->lname);
   cout<<"\n";
    cprintf("Name : %s %s %s",i->fname,i->mname,i->lname);
    cout<<"\n";
    cprintf("Age : %d",i->age);
    cout<<"\n";
    cprintf("Gender : ",i->gen);
    cout<<"\n";
    cprintf("Phone Number : ",i->phonenum);
    cout<<"\n";
    cprintf("Aadhar Number : ",i->aadhar);
    cout<<"\n";
    cprintf("Vaccine details : ");
    cout<<"\n";
    cprintf("Vaccine Name : ",j->vacchoice);
    cout<<"\n";
    cprintf("Date of First dose : ",i->date);
    cout<<"\n";
    cprintf("Press any key to continue..... ");
    getch();
}
void mylist()
{
	clrscr();
    //two types of listing
    //1.all list 2. specific list(specific list for each vaccine)
    if (head == NULL)
    {
	cout << "\nNo Records found";
	return;
    }
    int n;
    reg *p;
    cout << "\n1.All Listing";
    cout << "\n2.Specific listing";
    cout<<"\nEnter your choice : ";
    cin >> n;
    //all listing
    if (n == 1)
    {
	vac *t;
	for (t = head; t != NULL; t = t->nptr)
	{
	    cout << "\nVaccine name : " << t->vacchoice;
	    for (p = t->h; p != NULL; p = p->next)
		print(p,t,YELLOW);
	}
	return;
    }
    //specific listing
    vac *t;
    int x;
    char j[15];
    clrscr();
    for (t = head; t != NULL; t = t->nptr)
	cout << "\nVaccines name : " << t->vacchoice;
    cout << "\nEnter any one vaccine name mentioned above : ";
    cin >> j;
    strupr(j);
    for (t = head; t != NULL; t = t->nptr)
    {
	x = strcmp(t->vacchoice, j);
	if (x == 0)
	{
	    for (p = t->h; p != NULL; p = p->next)
		print(p,t,YELLOW);
	    return;
	}
    }
    if (t == NULL)
	cout << "\nVaccine name not found." << endl
	     << "please try again";
}
void main()
{
    int choi;
    //front.cpp page
    clrscr();
    while (1)
    {
	clrscr();
	textcolor(BROWN);

	cout << "\n1.REGISTER ";
	cout << "\n2.LIST";
	cout << "\n3.EXIT" ;
	cout << "\nEnter your choice : ";
	cin >> choi;
	switch (choi)
	{
	case 1:
	    myadd();
	    break;
	case 2:
	    mylist();
	    break;
	case 3:
	    exit(1);
	    break;
	default:
		cout<<endl<<"Enter the correct option : ";
		break;
	}
    }
}





