#ifndef CREATE_H_INCLUDED
#define CREATE_H_INCLUDED


#include "defines.h"
#include "my_var.h"


void menu1()
{


    char c;
    int continu=1;
    while(continu)
    {
        system("cls");
        show_header("\t Menu Ajouter Modifier \n");
        setcolor(70);
        printf("\n\n\n 1:  Pour Ajouter un livre \n",130);
        printf("\n 2:  Pour Modifier un livre ajout%c\n",130);
        printf("\n 3 et autre:  Pour retourner au menu principale\n");
        printf("\n --> ");

        fflush(stdin);
        c=getchar();
        system("cls");
        if(c=='1')
        {
            setcolor(15);
            create();
        }
        else if(c=='2')
        {
           setcolor(15);
           menu2();
        }
        else
            setcolor(15);
            break;
    }
}

/*----------------------------------------------------------------------------------------*/
void create()
{

    int livre_ajoutee=0 ;
    char c;
    int OK=1,valid,id,A;
    while(OK)
    {
        updated=0;
        system("cls");
        show_header("\tCREATION\n");
        setcolor(12);
        printf("\nLe nombre Totale de livre dans la librairie est %d\n\n",nb_de_livres);

//////////////////////////////////////////// ajouter le numero du livres ////////////////////////////////////////////
        setcolor(15);
        printf("\n\nLe nemuro du livre a ajouter: ");
        printf("--> ");
        do
        {
            scanf("%d",&id);
            valid=valid_cote(id,nb_de_livres+livre_ajoutee)&&(nb_de_livres>0);
            if(valid)
            {
                setcolor(12);
                printf("ID existe deja ! Veuillez entrer un ID different..\n");
            }
        }
        while(valid);

/////////////////////////// enumeration des categories //////////////////////////////////////////


        bibio[nb_de_livres+livre_ajoutee].id=id;
        setcolor(15);
        printf("\nLe nom du livre: ");
        setcolor(7);
        getchar();
        gets(bibio[nb_de_livres+livre_ajoutee].titre);
        setcolor(15);
        printf("\n Choisir une categorie : ");
        setcolor(7);
        printf("\n\t- 0:  Scientique ");
        printf("\n\t- 1:  Fiction  ");
        printf("\n\t- 2:  Policier ");
        printf("\n\t- 3:  Roman ");
        printf("\n\t- 4:  Culture & Arts ");
        printf("\n\t- 5:  Contes ");
        printf("\n\t- 6:  Histoire    :");
        printf("--> ");

//////////////////////////////// choisir une categories ////////////////////////////////////////////////////

        do
        {
            scanf("%d",&bibio[nb_de_livres+livre_ajoutee].catgr);
            valid=(bibio[nb_de_livres+livre_ajoutee].catgr<5&&bibio[nb_de_livres+livre_ajoutee].catgr>=0);
            if(!valid) printf("Mauvais choix!\n");
        }
        while(!valid);

/////////////////////////////// ajouter l'annee du livres //////////////////////////////////////////
        do
        {
            setcolor(15);
            printf("\nL'annee d'edition du livre: ");
            printf("--> ");
            setcolor(7);
            scanf("%d",&bibio[nb_de_livres+livre_ajoutee].annee);
            A=bibio[nb_de_livres+livre_ajoutee].annee;
            valid=(A>1799&&A<2016);
            if(!valid) printf("vous avez entrer une annee non-valide! choisissez une annee entre 1800 et 2015\n");
        }
        while(!valid);

 ////////////////////////////////////////////// ajouter le prix du livres //////////////////////////////////////
        do
        {
            setcolor(15);
            printf("\n Entrer Le Prix du Livre: ");
            printf("--> ");
            setcolor(7);
            scanf("%d",&bibio[nb_de_livres+livre_ajoutee].prix);
            A=bibio[nb_de_livres+livre_ajoutee].prix;
            valid=(A>0&&A<1001);
            if(!valid) printf("Vous avez entrer un Prix non-valide! choisissez un Prix entre 1 et 1000 \n");
        }
        while(!valid);

        setcolor(15);
        printf("\n Vendre le livre ajout%c? (O/N) : ",130);
        printf("--> ");
        fflush(stdin);
        setcolor(7);
        c=getchar();
        if(toupper(c)=='O') bibio[nb_de_livres+livre_ajoutee].vendre=1;
        else bibio[nb_de_livres+livre_ajoutee].vendre=0;

        livre_ajoutee++;
        setcolor(12);
        printf("\n\nAjouter un autre livre?(O/N)\n");
        printf("--> ");
        fflush(stdin);
        c=getchar();
        if(toupper(c)=='N') OK=0;
    }
    setcolor(12);
    printf("Sauvegarder les modifications?(O/N)\n");
    printf("--> ");
    setcolor(7);
    fflush(stdin);
    c=getchar();
    if(toupper(c)=='O')
    {
        nb_de_livres+=livre_ajoutee;
        sauvegarder();
    }
    else
    {
        OK=0;
    }


}
/*----------------------------------------------------------------------------------------*/

void show_header( const char s[100])
{
    setcolor(12);
    drw_line(MAX_W,223);
    printf("\t\t\t%s",s);
    drw_line(MAX_W,203);

}

#endif // CREATE_H_INCLUDED

