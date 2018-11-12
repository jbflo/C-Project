#ifndef LOAD_DATA_H_INCLUDED
#define LOAD_DATA_H_INCLUDED

#include"defines.h"
#include"my_var.h"


/*----------------------------------------------------------------------------------------*/
int nb_de_ligne(FILE *file)
{
    int cpt=0;
    char c;

    if (file==NULL) return 0;
    while((c=fgetc(file))!=EOF)
    {
        if(c=='\n') cpt++;
    }
    return cpt;
}
/*************************************/
int get_book_nb(FILE*file)
{
    return nb_de_ligne(file)/7;
}
//*************************************
void update()
{
    data=fopen("data.dat","r");
    if (data==NULL) return 0;
    nb_de_livres=get_book_nb(data);
    fclose(data);
}
/*----------------------------------------------------------------------------------------*/
void  restauration()
{
    char ch;
    int i,cpt=0,k=0,length;
    Maximize();
    data=fopen("data.dat","r");
    if(data==NULL) {printf("Error...\n"); return;}
    printf("\n\t\tLoading... please wait\n");

     while((ch=fgetc(data))!=EOF)
     {
      if(ch=='>')
            {
                switch(cpt)
                    {
                        case 0:
                        fscanf(data,"%d",&bibio[k].id);
                        break;

                        case 1:
                        while((ch=fgetc(data))!='\n') length++;
                        fseek(data,-length-1,SEEK_CUR);
                        fgets(bibio[k].titre,length,data);
                        break;

                        case 2:
                        fscanf(data,"%d",&bibio[k].catgr);
                        break;

                        case 3:
                        fscanf(data,"%d",&bibio[k].annee);
                        break;

                        case 4:
                        fscanf(data,"%d",&bibio[k].prix);
                        break;

                        case 5:
                        fscanf(data,"%d",&bibio[k].vendre);
                        break;


                    }
                    printf(".");
                    Sleep(10);
            if(cpt==4) k++;//si on a remplit tous les champ, on avence par 1(livre suivant)
            cpt++;
            cpt=cpt%5;//pour que cpt ne prend que les valeur{0,1,2,3,4}, intéligent huh
            length=0;
            }
    }
    printf("\nData have been restored succesfuly..\n");
    Sleep(800);
    nb_de_livres=k;
fclose(data);
}



#endif // LOAD_DATA_H_INCLUDED
