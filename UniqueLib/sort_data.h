#ifndef SORT_DATA_H_INCLUDED
#define SORT_DATA_H_INCLUDED

#include"defines.h"


/*----------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------*/
void sort_bibio_par_cote()
{
      Livre temp;
    int i,j,min;

    for(i=0;i<nb_de_livres;i++)
    {
        min=i;
        for(j=i;j<nb_de_livres;j++)
        if(bibio[min].id>bibio[j].id) min=j;
        temp[0]=bibio[i];
        bibio[i]=bibio[min];
        bibio[min]=temp[0];
    }

}

/*----------------------------------------------------------------------------------------*/

#endif // SORT_DATA_H_INCLUDED
