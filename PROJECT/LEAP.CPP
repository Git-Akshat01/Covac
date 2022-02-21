#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
const int month_days[]={31,28,31,30,31,30,31,31,30,31,30,31};

int isleap(int year)
{
    if((year%4==0)&&(!(year%100==0)||(year%400==0)))
	return(1);
    else
	return(0);
}
void adddays(int d,int m,int y,int add)
{
	int fg=isleap(y);
	d+=add;
	while(d>month_days[m-1])
	{
		if(fg==1 && m==2)
			d-=29;
		else
			d-=month_days[m-1];
		m++;
		if(m>12)
		{
			m%=12;
			y++;
			fg=isleap(y);
		}
	}

	cprintf("Date of Next Dose : %d/%d/%d",d,m,y);
}

/*void main()
{
	int d,m,y,add;
	clrscr();
	cout<<endl<<"Enter date to add : ";
	cin>>add;
	struct date dq;
	getdate(&dq);
	adddays(dq.da_day,dq.da_mon,dq.da_year,add);
} */