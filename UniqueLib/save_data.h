#ifndef SAVE_DATA_H_INCLUDED
#define SAVE_DATA_H_INCLUDED

#include"defines.h"
#include"my_var.h"


int  sauvegarder()
{
    int i;

    if (updated)
    {
        system("cls");
        printf("Vous n'avez rien modifier! \n");
        Sleep(3000);
        return 1;
    }
    data=fopen("data.dat","w");
    if(data==NULL)
    {
        printf("impossible d'ouvrir la base de donnee...");
        return 0;
    }
    sort_bibio_par_cote();
    system("cls");
    setcolor(7);

    printf("\n\n\n\t\t\tEnregistrement en cours...\n\n");
    printf("Openning DB... Done\n");
    for(i=0; i<nb_de_livres; i++)
    {
        printf(".");
        fprintf(data,"Book ID       > %d\n",bibio[i].id);
        fprintf(data,"Book Title    > %s\n",bibio[i].titre);
        fprintf(data,"Book category > %d\n",bibio[i].catgr);
        fprintf(data,"Edition Year  > %d\n",bibio[i].annee);
        fprintf(data,"Price         > %d\n",bibio[i].prix);
        fprintf(data,"Vendu         > %d\n",bibio[i].vendre);
        fprintf(data,"-------------------------------------------------\n");
        Sleep(10);
    }
    printf("\nClosing DB... Done\n");
    printf("\n\n Nombre totales des livres :%d\n\n",nb_de_livres);
    setcolor(10);
    printf("\nLe Sauvegarde est terminer avec success.\n\n");
    Sleep(5000);
    fclose(data);
    updated=1;
    return 1;
}
/*----------------------------------------------------------------------------------------*/



#endif // SAVE_DATA_H_INCLUDED
