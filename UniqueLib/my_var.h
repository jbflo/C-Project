#ifndef MY_VAR_H_INCLUDED
#define MY_VAR_H_INCLUDED


#include"defines.h"


enum cat {Scientique,Fiction,Policier,Roman,Culture_Arts,Conte,Histoire};
typedef enum cat cat;

struct livre
{
    int  id;
    char titre[100];
    cat  catgr;
    int  annee;
    int  prix;
    int  vendre;
};
typedef struct livre Livre[MAX];  //on définit un tableau de livres


Livre bibio;
int nb_de_livres;
FILE *data=NULL;
int updated=1;

typedef char *chaine ;
const chaine  categorie[]= {"Scientique","Fiction","Policier","Roman"," Culture_Arts","Conte","Histoire"};


#endif // MY_VAR_H_INCLUDED
