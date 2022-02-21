#include <dos.h>
#include<conio.h>
#include <stdio.h>
int i;
void main()
{

	char date[11],certiid[20];


   struct date d;

   getdate(&d);
   printf("The current year is: %d\n", d.da_year);
   printf("The current day is: %d\n", d.da_day);
   printf("The current month is: %d\n", d.da_mon);
//copying date in a
   sprintf(date,"%d%d%d",d.da_day,d.da_mon,d.da_year);
   printf("\na : %s",date);
//copying date and i in certiid
   sprintf(certiid,"%s%d",date,++i);
   printf("\nCertificate id : %s",certiid);

}
