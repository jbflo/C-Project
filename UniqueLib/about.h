#ifndef ABOUT_H_INCLUDED
#define ABOUT_H_INCLUDED
#include"defines.h"
void taper(const char* s, int speed)
{
    int i=0;
    while(s[i])
    {
        printf("%c",s[i]);
        Sleep(speed);
        i++;
    }
    printf("\n");
}

void about()
{
    system("cls");
    int i=20;

    setcolor(70);
    taper("\t\t\t\t\t        UNIQ                                                 \n\n\n\n\n\n\n\n\n\n",20);

    setcolor(15);
    taper("\t\t\t\t  Programme     : UNIQLIB\n",25);
    taper("\t\t\t\t  Programmeur   : Archil Mario et !\n",25);
    taper("\t\t\t\t  Date          : 18/01/2015\n",25);
    taper("\t\t\t\t  _______________________________",50);
    setcolor(70);


     for(i=MAX_W/5-10;i<MAX_W-MAX_W/5+10;i++)
    {
        gotoxy(i,MAX_H/5); printf("%c",219);
        gotoxy(i,MAX_H-MAX_H/5); printf("%c",219);
        Sleep(2);
    }

    for(i=MAX_H/5;i<=MAX_H-MAX_H/5;i++)
    {
        gotoxy(MAX_W/5-10,i); printf("%c",219);
        gotoxy(MAX_W-MAX_W/5+10,i); printf("%c",219);
        Sleep(2);
    }

     for(i=MAX_W/5-5;i<MAX_W-MAX_W/5+5;i++)
    {
        gotoxy(i,MAX_H/5-5); printf("%c",219);
        gotoxy(i,MAX_H-MAX_H/5+5); printf("%c",219);
        Sleep(2);

    }
    for(i=MAX_H/5-5;i<=MAX_H-MAX_H/5+5;i++)
    {
        gotoxy(MAX_W/5-5,i); printf("%c",219);
        gotoxy(MAX_W-MAX_W/5+5,i); printf("%c",219);
        Sleep(2);
    }

setcolor(15);
 system("pause>NULL");
}



#endif // ABOUT_H_INCLUDED
