#include<stdio.h>
#include<conio.h>
#include<dos.h>
#define VL 179
#define TL 218
#define TR 191
#define BL 192
#define BR 217
#define HL 196
#define DVL 186
#define DTL 201
#define DTR 187
#define DBL 200
#define DBR 188
#define DHL 205

void mybox(int x1,int y1,int x2,int y2,int c) //(x1,y1),(x2,y2),color
{
	int a;
	textcolor(c);

	gotoxy(x1,y1);
	cprintf("%c",TL);

	gotoxy(x2,y1);
	cprintf("%c",TR);
	gotoxy(x1,y2);
	cprintf("%c",BL);

	gotoxy(x2,y2);
	cprintf("%c",BR);

    //printing the horizontal line
    for(a=x1+1;a<x2;a++)
    {
	gotoxy(a,y1);
	cprintf("%c",HL);

	gotoxy(a,y2);
	cprintf("%c",HL);

	delay(20);
	sound(200*a);

    }
    //printing the vertical line
    for(a=y1+1;a<y2;a++)
    {
	gotoxy(x1,a);
	cprintf("%c",VL);

	gotoxy(x2,a);
	cprintf("%c",VL);

	delay(20);
	sound(100*a);
    }
	nosound();
}

void dmybox(int x1,int y1,int x2,int y2,int c)
{
    int a;
    textcolor(c);
    gotoxy(x1,y1);
    cprintf("%c",DTL);

    gotoxy(x2,y1);
    cprintf("%c",DTR);

    gotoxy(x1,y2);
    cprintf("%c",DBL);

    gotoxy(x2,y2);
    cprintf("%c",DBR);

    //printing the horizontal line
    for(a=x1+1;a<x2;a++)
    {
	gotoxy(a,y1);
	cprintf("%c",DHL);

	gotoxy(a,y2);
	cprintf("%c",DHL);

	delay(20);
	sound(200*a);
    }

    //printing the vertical line
    for(a=y1+1;a<y2;a++)
    {
	gotoxy(x1,a);
	cprintf("%c",DVL);

	gotoxy(x2,a);
	cprintf("%c",DVL);

	delay(20);
	sound(100*a);
    }
    nosound();

}