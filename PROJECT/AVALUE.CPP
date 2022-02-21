#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
char da[5];
char id[14];
int a=0;
void get()
{

	struct date d;
	getdate(&d);


	sprintf(da,"%d",d.da_day);

	sprintf(id,"%d%d%d%d",d.da_day,d.da_mon,d.da_year,++a);
	printf("\nDA=%s",da);
	printf("\nID=%s",id);
	printf("\nA=%d",a);
}
void main()
{
	clrscr();
	int ch;
			char day[5];
			struct date d;
			getdate(&d);
			sprintf(day,"%d",d.da_day);
			fstream aread;
			aread.open("arec.txt",ios::in|ios::out|ios::binary);
			aread>>da;
			//aread>>a;

			int l=strcmp(da,day);
			if(l==0)
			{
				aread>>a;

			}
			else
				a=0;
	    //		cout<<endl<<"A value in file = "<<a;

			aread<<da<<endl<<a;
//			aread<<a;
			aread.close();

	while(1)
	{
	cout<<endl<<"1.ADD";
	cout<<endl<<"2.EXIT";
	cout<<endl<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			get();
			break;
		case 2:
			ofstream awrite("arec.txt");
			awrite<<da<<endl<<a;
			awrite.close();
			exit(1);
			break;
	}

	}
}
