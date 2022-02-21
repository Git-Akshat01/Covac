#include<stdio.h>
//#include"box2.h"
#include<conio.h>
void front()
{
	int x1,x2,y1,y2,c;
	clrscr();
	textbackground(BLACK);
	mybox(1,1,79,25,RED);  //border
	mybox(2,2,78,24,10);  //border
	mybox(3,3,77,23,9);  //border
	mybox(15,4,70,8,YELLOW);//border of covid portal
	gotoxy(30,6);
	textcolor(BROWN);
	cprintf("COVID VACCINATION PORTAL");
	mybox(15,10,70,14,14);//border for covac
	gotoxy(30,12);
	textcolor(RED);
	cprintf("........COVAC........");
	mybox(15,15,70,20,14); //border for developed by
	gotoxy(25,17);
	textcolor(9);
	cprintf("DEVELOPED BY :-  AKSHAT TIWARI ");
       //	gotoxy(41,18);
       //	cprintf(" YASH GUPTA ");
	gotoxy(25,22);
	textcolor(LIGHTGREEN);
	cprintf("PRESS ANY KEY TO CONTINUE!!!!!!!");
	getch();
}

