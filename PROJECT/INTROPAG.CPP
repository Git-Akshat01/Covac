#include <conio.h>
//#include "BOX2.H"
#include <stdio.h>
void intropag()
{
    clrscr();
    dmybox(1,1,79,25,6);
    gotoxy(29,1);
    cprintf("COVID - 19 VACCINATION");
    gotoxy(2,2);
    textcolor(LIGHTBLUE);
    cprintf("SCIENCE BEHIND VACCINE MAKING");
    textcolor(WHITE);
    gotoxy(2,3);
    cprintf("Vaccinations against Covid-19 were developed using science that has been in");
    gotoxy(2,4);
    cprintf("the books for ages.These vaccines are not experimental.They have been through");
    gotoxy(2,5);
    cprintf("all the stages of development for any new scientific breakthrough.");
    gotoxy(2,6);
    textcolor(LIGHTRED);
    cprintf("Covid-19 vaccinations are constantly monitored by multiple health org.purely");
    gotoxy(2,7);
    cprintf("because of all the pandemonium this virus has caused across the world.");
    gotoxy(2,8);
    cprintf("Hence,it is crucial for every citizen to take part in the vaccination drives.");
    gotoxy(2,10);
    textcolor(LIGHTBLUE);
    cprintf("Here is a list of imp. details about vaccinations that makes is necessary -:");
    gotoxy(2,11);
    textcolor(WHITE);
    cprintf("1.You are contributing to mass wellness by getting vaccinated.");
    gotoxy(2,12);
    cprintf("2.A safe way to build your immune system.");
    gotoxy(2,13);
    cprintf("3.No Covid Vaccines can infect you with Covid-19 Virus.");
    gotoxy(2,15);
    textcolor(LIGHTBLUE);
    cprintf("BENEFITS of Taking Covid-19 Vaccines");
    gotoxy(2,16);
    textcolor(WHITE);
    cprintf("1.The vaccine reduces your and your family risk of get infection.");
    gotoxy(2,17);
    cprintf("2.The vaccine protects you and your family against severe illness.");
    gotoxy(2,18);
    cprintf("3.The vaccine will help you to reconnect with friends and family.");
    gotoxy(2,20);
    textcolor(LIGHTBLUE);
    cprintf("SIDE-EFFECTS of Covid-19 Vaccines");
    gotoxy(2,21);
    textcolor(WHITE);
    cprintf("The Side-effects are mild and are for short term.");
    gotoxy(2,22);
    cprintf("1.Mild Headaches");
    printf("\t");
    cprintf("2.Pain or Swelling at the injection site");
    gotoxy(2,23);
    cprintf("3.Mild Fever");
    printf("\t\t");
    cprintf("4.Irritability");
    textcolor(GREEN);
    gotoxy(25,24);
    cprintf("PRESS ANY KEY TO CONTINUE");
    getch();

}
