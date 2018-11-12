#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include"defines.h"
#include"consolemgmt.h"





char menu() // on renvoie un char pour éviter les ereurs !
{
    int i;
    system("cls");
    setcolor(70);
    for(i=MAX_W/5-10;i<MAX_W-MAX_W/5+10;i++)
    {
        gotoxy(i,MAX_H/5); printf("%c",219);
        gotoxy(i,MAX_H-MAX_H/5); printf("%c",219);

    }
    for(i=MAX_H/5;i<=MAX_H-MAX_H/5;i++)
    {
        gotoxy(MAX_W/5-10,i); printf("%c",219);
        gotoxy(MAX_W-MAX_W/5+10,i); printf("%c",219);
        Sleep(2);
    }
    char c;
    setcolor(70);
    gotoxy(20,3);
    printf("                                                             \n");
    gotoxy(20,4);
    taper("                        MENU UNIQLIB                         \n",20);
    gotoxy(20,5);
    printf("                                                             \n");

    setcolor(70);
    gotoxy(25,10);
    printf("1: Consultation des Produits \n");
    gotoxy(25,12);
    printf("2: Les Entr%ces \n",130);
    gotoxy(25,14);
    printf("3: Les Sorties \n");
    gotoxy(25,16);
    printf("4: Apropos \n");
    gotoxy(25,18);
    printf("5: Quiter l'appliction \n");
    gotoxy(25,20);
    printf("--> ");

    setcolor(7);
    fflush(stdin);// on vide le BUFFER
    c=getchar();
    return c;

}
/**------------------------------------------------------------------------------------*/




#endif // MENU_H_INCLUDED
