#ifndef SHOW_DATA_H_INCLUDED
#define SHOW_DATA_H_INCLUDED

#include"defines.h"

void menu3()
{


    char c;
    int continu=1;
    while(continu)
    {
        system("cls");
        show_header("\t CONSUTATION DES OUVRAGES \n");
        setcolor(70);
        printf("\n\n 1:Lister les cat%Cgories d%cOuvrage \n",130 ,96);
        printf("\n 2:  Lister les ouvrages par Cat%cgorie  \n",130);
        printf("\n 3:  Lister les ouvrages ann%Ce d'edition \n",130);
        printf("\n 4:  Lister les ouvrages par Prix \n");
        printf("\n 5:  Lister les ouvrages Vendu et non Vendu \n");
        printf("\n 6:  Lister les ouvrages par ordre Alphab%ctique \n",130);
        printf("\n 7 et autre:  Pour retourner au menu Principale\n");
        printf("\n --> ");

        fflush(stdin);
        c=getchar();
        system("cls");
        if(c=='1')
        {
           setcolor(15);
           affi_categ();
        }
        else if(c=='2')
        {
           setcolor(15);
           affichage_categorie();
        }
        else if(c=='3')
        {
           setcolor(15);
           afficher_annee();
        }
        else if(c=='4')
        {
           setcolor(15);
           afficher_prix();
        }
        else if(c=='5')
        {
           setcolor(15);
           affichage();
        }
        else
            setcolor(15);
            break;
    }
}


int npos(long a)
{
    int cpt=0;
    do
    {
        a/=10;
        cpt++;
    }
    while(a>0);
    return cpt;

}

/*----------------------------------------------------------------------------------------*/
void affi_categ(){
    char c;
            system("cls");
            show_header("\t Affichage des Categories Disponible \n");
            setcolor(70);
            printf("\n 0:  Scientique \n");
            printf("\n 1:  Fiction  \n");
            printf("\n 2:  Policier \n");
            printf("\n 3:  Roman \n");
            printf("\n 4:  Culture & Arts \n");
            printf("\n 5:  Contes \n");
            printf("\n 6:  Histoire \n");
            printf("\n --> presser une touche pour continuer :  ");
            fflush(stdin);
            c=getchar();
            system("cls");
            setcolor(15);


}
///////////////////////////////////vendu non vendu ///////////////.........................................
affichage()
{
    int k;
    char c,s[100];
    int i,continu=1,reponce;
    update();
    while(continu)
    {
        system("cls");
        show_header("\t AFFICHAGE DES LIVRES VENDU ET NON VENDU \n");
        setcolor(70);
        printf("\n\t1:  Pour Afficher les livres Vendu\n");
        printf("\n\t2:  Pour Afficher les livres non Vendu\n");
        printf("\n\t3 et autre:  Pour retourner au menu principale\n");
        printf("\n --> ");
        fflush(stdin);
        c=getchar();
        system("cls");
        if(c=='1')
        {
            sprintf(s,"\t\tLES LIVRES EMPRUNTES\n");
            show_header(s);
            reponce=1;
        }
        else if(c=='2')
        {
            sprintf(s,"\t\tLES LIVRES NON_EMPRUNTES\n");
            show_header(s);
            reponce=0;
        }
        else break;

        printf("\n");
        setcolor(7);
        drw_line(MAX_W,22);

        printf("|cote  | Nom du livre");
        for(k=0; k<62; k++) printf(" ");
        printf("|Categorie|Annee|");
        drw_line(MAX_W,22);

        for(i=0; i<nb_de_livres; i++)
        {
            if(bibio[i].vendre==reponce)
            {
                setcolor(14);
                printf("|");
                setcolor(10);
                printf(" %d",bibio[i].id);
                for(k=npos(bibio[i].id); k<5; k++) printf(" ");
                setcolor(14);
                printf("|");
                setcolor(15);
                printf("  %s ",bibio[i].titre);
                for(k=strlen(bibio[i].titre); k<72; k++)printf(" ");
                setcolor(14);
                printf("|");
                setcolor(7);
                printf("%s",categorie[bibio[i].catgr]);
                for(k=strlen(categorie[bibio[i].catgr]); k<10; k++) printf(" ");
                {
                    setcolor(14);
                    printf("|");
                    setcolor(7);
                    printf("%d",bibio[i].annee);
                    setcolor(14);
                    printf("|");
                }
                drw_line(MAX_W,22);
            }
            Sleep(10);

        }
        setcolor(7);
        system("pause");

    }
}

////>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> affichage par annee >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

afficher_annee(){
    char c,s[100];
    int i,j,continu=1,k,annee;
    setcolor(15);
            system("cls");
            setcolor(15);
            show_header("\tAFFICHAGE DES LIVRES PAR ANNEE\n");
            setcolor(2);

            printf("/n Quel ann%ce?   ",130);
            printf("--> ");
            do
            {
                scanf("%d",&annee);
                if(annee>2016||annee<1800)
                {
                  setcolor(12);printf("annee non-valide!");setcolor(15);
                }
            }while(annee>2016||annee<1800);
            sprintf(s,"\tAnn%ce : %d\n",130,annee);
            show_header(s);
            printf("\n");
            setcolor(7);
            drw_line(MAX_W,22);
            printf("|ID    | Nom du livre");
            for(k=0; k<58; k++) printf(" ");
            printf("|Categorie  |Emprnte|");
            drw_line(MAX_W,22);
            for(i=0; i<nb_de_livres; i++)
            {
                if(bibio[i].annee==annee)
                {

                    setcolor(14);
                    printf("|");
                    setcolor(10);
                    printf(" %d",bibio[i].id);
                    for(k=npos(bibio[i].id); k<5; k++) printf(" ");
                    setcolor(14);
                    printf("|");
                    setcolor(15);
                    printf("  %s ",bibio[i].titre);
                    for(k=strlen(bibio[i].titre); k<MAX_W-32; k++)printf(" ");
                    setcolor(14);
                    printf("|");
                    setcolor(7);
                    printf(" %s",categorie[bibio[i].catgr]);
                    for(k=strlen(categorie[bibio[i].catgr]); k<10; k++) printf(" ");
                    if(bibio[i].id)
                    {
                        setcolor(14);
                        printf("|");
                        setcolor(10);
                        printf(" Oui   ");
                        setcolor(14);
                        printf("|");
                    }
                    else
                    {
                        setcolor(14);
                        printf("|");
                        setcolor(12);
                        printf(" Non   ");
                        setcolor(14);
                        printf("|");
                    }

                    drw_line(MAX_W,22);
                }
            }
            setcolor(7);
            system("pause");


}

/////////////////////////////////////affichage pa prix ///////////////////////////////////////////////////////////

afficher_prix(){
    char c,s[100];
    int i,j,continu=1,k,prix;
    setcolor(15);
            system("cls");
            setcolor(15);
            show_header("\t AFFICHAGE DES LIVRES PAR PRIX \n");
            setcolor(2);

            printf("/n entrer le prix ?   ");
            printf("--> ");
            do
            {
                scanf("%d",&prix);
                if(prix>1000||prix<1)
                {
                  setcolor(12);printf("prix non-valide!");setcolor(15);
                }

            }while(prix>1000||prix<1);
            sprintf(s,"\t Prix: %d\n",prix);
            show_header(s);
            printf("\n");
            setcolor(7);
            drw_line(MAX_W,22);
            printf("|ID    | Nom du livre");
            for(k=0; k<58; k++) printf(" ");
            printf("|Categorie  |Vendu|");
            drw_line(MAX_W,22);
            for(i=0; i<nb_de_livres; i++)
            {
                if(bibio[i].prix==prix)
                {

                    setcolor(14);
                    printf("|");
                    setcolor(10);
                    printf(" %d",bibio[i].id);
                    for(k=npos(bibio[i].id); k<5; k++) printf(" ");
                    setcolor(14);
                    printf("|");
                    setcolor(15);
                    printf("  %s ",bibio[i].titre);
                    for(k=strlen(bibio[i].titre); k<MAX_W-32; k++)printf(" ");
                    setcolor(14);
                    printf("|");
                    setcolor(7);
                    printf(" %s",categorie[bibio[i].catgr]);
                    for(k=strlen(categorie[bibio[i].catgr]); k<10; k++) printf(" ");
                    if(bibio[i].id)
                    {
                        setcolor(14);
                        printf("|");
                        setcolor(10);
                        printf(" Oui   ");
                        setcolor(14);
                        printf("|");
                    }
                    else
                    {
                        setcolor(14);
                        printf("|");
                        setcolor(12);
                        printf(" Non   ");
                        setcolor(14);
                        printf("|");
                    }

                    drw_line(MAX_W,22);
                }
            }
            setcolor(7);
            system("pause");


}

/*----------------------------------------------------------------------------------------*/
void affichage_categorie()
{
    char c,s[100];
    int i,j,continu=1,k,annee;
    while(continu)
    {
        system("cls");
        show_header("\t AFFICHAGE DES LIVRES PAR CATEGORIE  \n");
        setcolor(70);
        printf("\n\n 1:  Pour Afficher les livres par categorie\n");
        printf("\n 2 et autre:  Pour retourner au menu principale\n");
        printf("\n --> ");
        fflush(stdin);
        c=getchar();
        switch(c)
        {
        case '1':
            setcolor(15);
            system("cls");
            setcolor(15);

            setcolor(2);
            printf("\n\t\tQuelle qategorie?\n\t\t- 0: Scientique\n\t\t- 1: Fiction\n\t\t- 2: PoLicier\n\t\t- 3:  Roman\n\t\t- 4: Conte\n\t\t- 1:  Histoire\n");
            printf("\t\t Choisir une categorie :--> ");
            scanf("%d",&j);
            sprintf(s,"- CATEGORIE %d: %s\n",j,categorie[j]);
            show_header(s);

            printf("\n");
            setcolor(7);
            drw_line(MAX_W,22);
            printf("| ID | Nom du livre ");
            for(k=0; k<64; k++) printf(" ");
            printf("| Annee | Vendu |");
            drw_line(MAX_W,22);


            setcolor(14);
            drw_line(MAX_W,22);
            for(i=0; i<nb_de_livres; i++)
            {

                {
                    if(bibio[i].catgr==j)
                    {
                        setcolor(14);
                        printf("|");
                        setcolor(10);
                        printf(" %d",bibio[i].id);
                        for(k=npos(bibio[i].id); k<5; k++) printf(" ");
                        setcolor(14);
                        printf("|");
                        setcolor(15);
                        printf("  %s ",bibio[i].titre);
                        for(k=strlen(bibio[i].titre); k<MAX_W-26; k++)printf(" ");
                        setcolor(14);
                        printf("|");
                        setcolor(7);
                        printf(" %d ",bibio[i].annee);
                        if(bibio[i].vendre)
                        {
                            setcolor(14);
                            printf("|");
                            setcolor(10);
                            printf(" Oui ");
                            setcolor(14);
                            printf(" |");
                        }
                        else
                        {
                            setcolor(14);
                            printf("|");
                            setcolor(12);
                            printf(" Non ");
                            setcolor(14);
                            printf(" |");
                        }

                        drw_line(MAX_W,22);

                    }
                    Sleep(10);
                }
            }
            printf("\n\n");
            setcolor(7);
            system("pause");
            break;
        case '2':
            setcolor(15);
            continu=0;
            break;
        default:
            setcolor(15);
            taper("\t\t\t\t Mauvais choix!\n",25);
            //printf("Mauvais choix!\n");
            break;
        }
    }

}
/*----------------------------------------------------------------------------------------*/


#endif // SHOW_DATA_H_INCLUDED
