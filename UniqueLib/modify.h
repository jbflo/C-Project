#ifndef MODIFY_H_INCLUDED
#define MODIFY_H_INCLUDED
#include<ctype.h>
#include"defines.h"

int valid_cote(int id, int nb_livre)
{
    int i,valid;
    for(i=0; i<nb_livre; i++)
    {
        valid=(id==bibio[i].id);
        if (valid) break;
    }
    return valid;
}
/************************************************************************************************/
int  get_cote_indice(int id)
{
    int i;
    for(i=0; i<nb_de_livres; i++)
    {
        if (i==id)return i;
    }
    if (i==nb_de_livres) return -1;

}
/************************************************************************************************/

void menu2()
{


    char c,s[100];
    int i,continu=1;
    while(continu)
    {
        system("cls");
        show_header("\t Menu Choisir Le Type de Modification \n");
        setcolor(70);
        printf("\n\n1:  Modification Si Un Livre Vendu Ou Non");
        printf("\n\n2:  Modifier Le Prix d'un Livre");
        printf("\n\n3 et autre:  Pour retourner au menu principale\n");
        printf("--> ");

        fflush(stdin);
        c=getchar();
        system("cls");
        if(c=='1')
        {
            setcolor(15);
             modifier();
        }
        else if(c=='2')
        {
          setcolor(15);
          modifier_prix();
        }
        else
            setcolor(15);
            break;
    }
}
///////////////////////////////////////// Fonction Modifier status du livre ////////////////////////////////////

void modifier()
{
    int i,OK=1,id;
    char s[100];
    char ch;
    while(OK)
    {
        system("cls");
        show_header("\t\t\tModification\n");
        setcolor(15);
        printf("\nEntrer le numero du livre que vous voulez le modifier: ");
        printf("--> ");
        setcolor(7);
        scanf("%d",&id);

        if (valid_cote(id,nb_de_livres))
        {
            i=get_cote_indice(id);
            if(bibio[i].vendre==1)
        {
                printf("\n\n Le livre [ %d ]", bibio[i].vendre);
                printf("\n\n Le livre [ %s ] est Vendu.\n-Voulez vous changer cette valeur?(O/N)",bibio[i].titre);
                printf("--> ");
                fflush(stdin);
                ch=getchar();
                if(toupper(ch)=='O'){
                        updated=0;
                        printf("la modification est termin%c!\n",130);
                        printf("\n\n Voulez vous sauvegarder les modifications? (o/n) ");
                        printf("--> ");
                        fflush(stdin);
                        ch=getchar();

                     if(toupper(ch)=='O'){
                           bibio[i].vendre=!bibio[i].vendre;
                           sauvegarder();
                       }
                      if(toupper(ch)=='N')
                        {
                            updated=1;
                            sauvegarder();
                            setcolor(12);
                            printf("modification non-enregistr%ce!\n",130);
                        }
                }

                if(toupper(ch)=='N') {
                    break;
                }

            }
            if(bibio[i].vendre==0)
              {
                printf("\n\n Le livre [ %d ]", bibio[i].vendre);
                printf("\n\n Le livre [ %s ] n'est pas Vendu.\n- Voulez vous Vendre cet Livre?(O/N)",bibio[i].titre);
                printf("--> ");
                fflush(stdin);
                ch=getchar();
                if(toupper(ch)=='O'){
                        updated=0;
                        printf("la modification est termin%c!\n",130);
                        printf("\n\n Voulez vous sauvegarder les modifications? (o/n) ");
                        printf("--> ");
                        fflush(stdin);
                        ch=getchar();

                     if(toupper(ch)=='O'){
                           bibio[i].vendre=!bibio[i].vendre;
                           sauvegarder();
                       }
                      if(toupper(ch)=='N')
                        {
                            updated=1;
                            sauvegarder();
                            setcolor(12);
                            printf("modification non-enregistr%ce!\n",130);
                        }
                }

                if(toupper(ch)=='N') {
                    //modifier();
                    break;
                }

            }

        }
        else
        {
            setcolor(12);
            printf("ID n'exist pas! r%cessayer a nouveau?(O/N)",130);
            printf("--> ");
            fflush(stdin);
            setcolor(15);
            ch=getchar();
            if(toupper(ch)=='N') OK=0;
        }
    }

}

//////////////////////////////////////// Modification du Prix ////////////////////////////////////////////////////
void modifier_prix()
{
    int i,OK=1,id;
    char s[100];
    int prix;
    char ch;
    while(OK)
    {
        system("cls");
        show_header("\t\t\t Modifier le prix d'un Livre\n");
        setcolor(15);
        printf("\n Entrer le numero du livre que vous voulez modifier: ");
        printf("--> ");
        setcolor(7);
        scanf("%d",&id);

        i=get_cote_indice(id);
        if (valid_cote(id,nb_de_livres))
        {
            printf("\n\nLe prix du livre  [ %s ] est : [ %d ]" "\n-Voulez vous changer cette valeur?(O/N)" ,bibio[i].titre , bibio[i].prix );
            fflush(stdin);
            ch=getchar();

            if(toupper(ch)=='O')
            printf("Entrer la nouvelle valeur pour le prix du livres [ %s ]!\n",bibio[i].titre);
            printf("--> ");
            scanf("%d",&prix);
            bibio[i].prix= prix;
            updated=0;
            printf("la modification est termin%c!\n",130);
            printf("\n\nVoulez vous sauvegarder les modifications? ");
            printf("--> ");
            fflush(stdin);
            ch=getchar();
            if(toupper(ch)=='O') sauvegarder();
            else
            {
                setcolor(12);
                printf("modification non-enregistr%ce!\n",130);
            }


            break;
        }
        else
        {
            setcolor(12);
            printf(" ID n'exist pas! r%cessayer a nouveau?(O/N)",130);
            printf("--> ");
            fflush(stdin);
            setcolor(15);
            ch=getchar();
            if(toupper(ch)=='N') OK=0;
        }
    }

}




#endif // MODIFY_H_INCLUDED
