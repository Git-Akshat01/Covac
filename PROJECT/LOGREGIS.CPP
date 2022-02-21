#include<stdio.h>
//#include"box2.h"
#include<conio.h>
void page2()
{
	int x1,x2,y1,y2,c,choi;
	clrscr();
	textbackground(BLACK);
	dmybox(1,1,79,25,4);  //border
	dmybox(2,2,78,24,10);  //border
	dmybox(3,3,77,23,9);  //border
	/*mybox(15,4,70,8,YELLOW);//border of covid portal
	gotoxy(30,6);
	textcolor(BROWN);
	cprintf("COVID VACCINATION PORTAL");*/
	mybox(15,5,70,9,14);//border for covac
	gotoxy(30,7);
	textcolor(RED);
	cprintf("........COVAC........");
	gotoxy(35,22);

	//for last line
	textcolor(RED);
	cprintf("A </> BY %2c%2c%2c",2,3,2);

	mybox(15,11,70,15,14); //border for login and register
	gotoxy(35,12);
	textcolor(9);
	cprintf("1.REGISTER");
	gotoxy(35,14);
	cprintf("2.LOGIN");
	gotoxy(35,18);
	cprintf("ENTER YOUR CHOICE : ");
	scanf("%d",choi);
	switch(choi)
	{
		case 1:

			break;
		case 2:
			break;
	}
}
