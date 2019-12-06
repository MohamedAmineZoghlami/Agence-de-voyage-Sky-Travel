#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>


enum
{ NOM=0,
PRENOM,
SEXE,
NUMERO_CIN,
NUMERO_TELEPHONE,
DATE,
NUM_COL
};

typedef struct agents 
{
char nom[20];
char prenom [20];
char sexe [20];
char num_tel [10];
char num_CIN [10] ;
char date[20];

} agents ;

int ajouter_agents(agents a);
void supprimer_agents (char CIN[] );
void modifier_agents(agents a1);
void afficher_agents(GtkWidget *liste) ;
