#include<stdio.h>
#include<string.h>
void main()
{
	char f[20],m[20],l[20],full[80];
	clrscr();

	printf("Enter first name : ");
	gets(f);
	printf("\nEnter middle name : ");
	gets(m);
	printf("\nEnter last name : ");
	gets(l);

	strcpy(full,f);
	strcat(full," ");
	strcat(full,m);
	strcat(full," ");
	strcat(full,l);

	printf("\nFull name is : %5s",full);

}