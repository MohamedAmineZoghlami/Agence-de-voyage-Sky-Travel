#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agents.h"


int ajouter_agents(agents a1) {
agents a;
FILE * f;
 int found=0;

f=fopen("agents.txt","a+") ;
if(f!=NULL) {
while (fscanf(f,"%s %s %s %s %s %s \n",a.nom,a.prenom,a.sexe,a.num_CIN,a.num_tel,a.date)!=EOF) {
if (strcmp(a1.nom ,a.nom)==0)
{
found=1;
break;
}
}}
if (found==0){
fprintf(f,"%s %s %s %s %s %s \n",a1.nom,a1.prenom,a1.sexe,a1.num_CIN,a1.num_tel,a1.date) ;
fclose(f);
return 1;
}

return 0;


}


void supprimer_agents (char num_CIN1 [] ){


agents a;
FILE *f;
FILE *f1 ;
f1 =NULL;
f=fopen("agents.txt","r") ;
f1=fopen("agents1.txt","a");
if (f!= NULL)
{

while (fscanf(f,"%s %s %s %s %s %s \n",a.nom,a.prenom,a.sexe,a.num_CIN,a.num_tel,a.date)!=EOF) {
if (strcmp(num_CIN1 ,a.num_CIN)!=0)
{


fprintf(f1,"%s %s %s %s %s %s \n",a.nom,a.prenom,a.sexe,a.num_CIN,a.num_tel,a.date);

}
}
}


fclose(f);
fclose(f1);
remove("agents.txt");
rename("agents1.txt","agents.txt");

}


void modifier_agents (agents a1)
{
agents a;
FILE *f;
FILE *f1;
f1=NULL ;
f=fopen("agents.txt","r");
f1=fopen("agents.tmp","w");
if (f!= NULL)
{
while (fscanf(f,"%s %s %s %s %s %s \n",a.nom,a.prenom,a.sexe,a.num_CIN,a.num_tel,a.date)!=EOF) {
if (strcmp(a1.num_CIN ,a.num_CIN)==0)
{
fprintf(f1,"%s %s %s %s %s %s \n",a1.nom,a1.prenom,a1.sexe,a1.num_CIN,a1.num_tel,a1.date) ;
}
else
fprintf(f1,"%s %s %s %s %s %s \n",a.nom,a.prenom,a.sexe,a.num_CIN,a.num_tel,a.date) ;
}
fclose(f);
fclose(f1);
remove("agents.txt");
rename ("agents.tmp","agents.txt");
}
}

void afficher_agents (GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;


 

char nom[20];
char prenom [20];
char sexe [20];
char num_tel [10];
char num_CIN [10] ;
char date[20];

store=NULL;

FILE *f ;

store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nom",renderer,"text",NOM,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("prenom",renderer,"text",PRENOM,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("sexe",renderer,"text",SEXE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("num_tel",renderer,"text",NUMERO_TELEPHONE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("num_CIN",renderer,"text",NUMERO_CIN,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	    
             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("date",renderer,"text",DATE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	     
}


	    store =gtk_list_store_new(NUM_COL,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING );



            f=fopen("agents.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s %s %s \n",nom,prenom,sexe,num_CIN,num_tel,date)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,NOM,nom,PRENOM,prenom,SEXE,sexe,NUMERO_TELEPHONE,num_tel,NUMERO_CIN,num_CIN,DATE,date,-1);
		}
		}
		fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);
}



