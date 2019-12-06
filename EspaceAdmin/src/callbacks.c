#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <math.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "login.h"
#include "agents.h"
#include "coordonnees.h"

GtkWidget* profil_admin;
GtkWidget* Modifier_admin;		
void
on_button_deconnecter_admin_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_profil_admin_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{


profil_admin=create_profil_admin();
gtk_widget_show(profil_admin);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"Espace_admin")));

GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;




char nom[20];
char prenom [20];
char sexe [20];
char num_tel [10];
char num_CIN [10] ;
char date[20];

FILE *f;
f=fopen("admin.txt","a+");
if (f!=NULL)
	{
	    while(fscanf(f,"%s %s %s %s %s %s %s \n",nom,prenom,sexe,num_CIN,num_tel,date)!=EOF)
		{ output1=lookup_widget(profil_admin,"label_nom_admin");
		  gtk_label_set_text(GTK_LABEL(output1),nom);
		  output2=lookup_widget(profil_admin,"label_prenom_admin");
		  gtk_label_set_text(GTK_LABEL(output2),prenom);
		  output3=lookup_widget(profil_admin,"label_sexe_admin");
		  gtk_label_set_text(GTK_LABEL(output3),sexe);
		  output4=lookup_widget(profil_admin,"label_numcin_admin");
		  gtk_label_set_text(GTK_LABEL(output4),num_CIN);
		  output5=lookup_widget(profil_admin,"label_numtel_admin");
		  gtk_label_set_text(GTK_LABEL(output5),num_tel);
		  output6=lookup_widget(profil_admin,"label_datenaiss_admin");
		  gtk_label_set_text(GTK_LABEL(output6),date);
		  }
		fclose(f);}
	
}


void
on_button_supprimer_agents_par_admin_clicked
                                        (GtkWidget       *widget,
                                        gpointer         user_data)
{
	char num_CIN [10] ;
	
	GtkWidget *current;
	GtkWidget *treeview1;
	
	GtkEntry *cin_agent;

	current=lookup_widget(widget,"Espace_admin");
	treeview1=lookup_widget(widget,"treeview_liste_agents_par_admin");

	cin_agent=lookup_widget(current,"entry4");
	


  	strcpy(num_CIN,gtk_entry_get_text(GTK_ENTRY(cin_agent)));


  	supprimer_agents(num_CIN);
  	afficher_agents (treeview1);
}


void
on_button_modifier_agents_par_admin_clicked
                                        (GtkWidget       *widget,
                                        gpointer         user_data)
{
	agents a;
	GtkWidget *current;
	GtkWidget *treeview1;

	GtkWidget* Modifier_agent;	
        
	GtkEntry *nom_agent;
	GtkEntry *prenom_agent;
	GtkEntry *sexe_agent;	
	GtkEntry *tel_agent;
	GtkEntry *cin_agent;
        GtkEntry *date_agent;

	GtkEntry *nom_agent1;
	GtkEntry *prenom_agent1;
	GtkEntry *sexe_agent1;	
	GtkEntry *tel_agent1;
	GtkEntry *cin_agent1;
        GtkEntry *date_agent1;

	current=lookup_widget(widget,"Espace_admin");
	treeview1=lookup_widget(widget,"treeview_liste_agents_par_admin");
	Modifier_agent=create_Modifier_agent();  

	nom_agent=lookup_widget(current,"entry1");
	prenom_agent=lookup_widget(current,"entry2");
	sexe_agent=lookup_widget(current,"entry3");
	cin_agent=lookup_widget(current,"entry4");
	tel_agent=lookup_widget(current,"entry5");
	date_agent=lookup_widget(current,"entry6");


	strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(nom_agent)));
  	strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_agent)));
  	strcpy(a.sexe,gtk_entry_get_text(GTK_ENTRY(sexe_agent)));
  	strcpy(a.num_tel,gtk_entry_get_text(GTK_ENTRY(tel_agent))); 	
	strcpy(a.num_CIN,gtk_entry_get_text(GTK_ENTRY(cin_agent)));
	strcpy(a.date,gtk_entry_get_text(GTK_ENTRY(date_agent)));


	nom_agent1=lookup_widget(Modifier_agent,"entry_modif_nom_agent");
	prenom_agent1=lookup_widget(Modifier_agent,"entry_modif_prenom_agent");
	sexe_agent1=lookup_widget(Modifier_agent,"entry_modif_sexe_agent");
	cin_agent1=lookup_widget(Modifier_agent,"entry_modif_numcin_agent");
	tel_agent1=lookup_widget(Modifier_agent,"entry_modif_numtel_agent");
	date_agent1=lookup_widget(Modifier_agent,"entry_modif_datenaiss_agent");


  	
	gtk_entry_set_text(GTK_ENTRY(nom_agent1),a.nom);
	gtk_entry_set_text(GTK_ENTRY(prenom_agent1),a.prenom);
	gtk_entry_set_text(GTK_ENTRY(sexe_agent1),a.sexe);
	gtk_entry_set_text(GTK_ENTRY(cin_agent1),a.num_CIN);
	gtk_entry_set_text(GTK_ENTRY(tel_agent1),a.num_tel);
	gtk_entry_set_text(GTK_ENTRY(date_agent1),a.date);




	gtk_widget_hide(current);
	gtk_widget_show(Modifier_agent);
}


void
on_button_ajouter_agents_par_admin_clicked
                                        (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget* Ajout_agent;
GtkWidget* widget_to_hide;
Ajout_agent=create_Ajout_agent();
widget_to_hide=lookup_widget(widget,"Espace_admin");  
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"Espace_admin")));
gtk_widget_show(Ajout_agent);
}


void
on_button_afficher_agents_par_admin_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_admin;
GtkWidget *treeview_liste_agents_par_admin;
Espace_admin=lookup_widget(objet_graphique,"Espace_admin");
treeview_liste_agents_par_admin=lookup_widget(Espace_admin,"treeview_liste_agents_par_admin");
afficher_agents (treeview_liste_agents_par_admin);
}


void
on_button_identifier_admin_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *input1;  
  GtkWidget *input2;
  GtkWidget *output;
  GtkWidget *loginn; 
  GtkWidget *Espace_admin;
  GtkWidget *treeview_liste_agents_par_admin;


  char login[20];
  char password[20];
  int logg;
  
  input1=lookup_widget(objet_graphique,"identifiant_entry");
  strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));

  input2=lookup_widget(objet_graphique,"password_entry"); 
  strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));

  output=lookup_widget(objet_graphique,"output_login"); 
  logg=verifier(login,password);
switch(logg)
{
case 1:Espace_admin= create_Espace_admin();
  loginn =lookup_widget(objet_graphique,"Login");
  treeview_liste_agents_par_admin=lookup_widget(Espace_admin,"treeview_liste_agents_par_admin");
  //affichage_agents (treeview_liste_agents_par_admin);
  gtk_widget_hide (loginn);  
  gtk_widget_show (Espace_admin);
  break;
default :gtk_label_set_text(GTK_LABEL(output),"Verifier vos paramètres !!");

}
}


void
on_button_ajouuut_agent_clicked        (GtkWidget       *widget,
                                        gpointer         user_data)
{
 	agents a;
	GtkWidget *current;
	GtkWidget *treeview1;

	GtkEntry *nom_agent;
	GtkEntry *prenom_agent;
	GtkEntry *sexe_agent;	
	GtkEntry *tel_agent;
	GtkEntry *cin_agent;
        GtkEntry *date_agent;

	GtkWidget *notebook;
        GtkWidget* Espace_admin;
	int retour=5;

	current=lookup_widget(widget,"Ajout_agent");

	

	nom_agent=lookup_widget(current,"entry_ajout_nom_agent");
	prenom_agent=lookup_widget(current,"entry_ajout_prenom_agent");
	sexe_agent=lookup_widget(current,"entry_ajout_sexe_agent");
	tel_agent=lookup_widget(current,"entry_ajout_tel_agent");
	cin_agent=lookup_widget(current,"entry_ajout_cin_agent");
	date_agent=lookup_widget(current,"entry_ajout_date_agent");



  	strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(nom_agent)));
  	strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_agent)));
  	strcpy(a.sexe,gtk_entry_get_text(GTK_ENTRY(sexe_agent)));
  	strcpy(a.num_tel,gtk_entry_get_text(GTK_ENTRY(tel_agent))); 	
	strcpy(a.num_CIN,gtk_entry_get_text(GTK_ENTRY(cin_agent)));
	strcpy(a.date,gtk_entry_get_text(GTK_ENTRY(date_agent)));






  	retour=ajouter_agents(a);

  	afficher_agents (treeview1);
if (retour ==0 ) {
}
else if (retour ==1){
Espace_admin=create_Espace_admin(); 
treeview1=lookup_widget(Espace_admin,"treeview_liste_agents_par_admin");
//notebook=lookup_widget(espace_agent,"notebook1");
//gtk_notebook_set_current_page(notebook,1);
gtk_widget_hide (current);
gtk_widget_show(Espace_admin);
afficher_agents(treeview1);

 

}
else{

}
}


void
on_button_retour_ajout_vers_admin_clicked
                                        (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget* Espace_admin;
GtkWidget* treeview_liste_agents_par_admin;
GtkWidget* notebook;
Espace_admin=create_Espace_admin();  
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"Ajout_agent")));
treeview_liste_agents_par_admin=lookup_widget(Espace_admin,"treeview_liste_agents_par_admin");
//affichage_Hotels(treeview1);
notebook=lookup_widget(Espace_admin,"notebook1");
gtk_notebook_set_current_page(notebook,1);
gtk_widget_show(Espace_admin);
}


void
on_button_modiffff_agent_clicked       (GtkWidget       *widget,
                                        gpointer         user_data)
{
	agents a1;
	GtkWidget *current;
	GtkWidget *treeview1;

	GtkWidget* Espace_admin;
	GtkWidget* notebook;	
        
	GtkEntry *nom_agent;
	GtkEntry *prenom_agent;
	GtkEntry *sexe_agent;	
	GtkEntry *tel_agent;
	GtkEntry *cin_agent;
        GtkEntry *date_agent;

	current=lookup_widget(widget,"Modifier_agent");
	Espace_admin=create_Espace_admin();  

	nom_agent=lookup_widget(current,"entry_modif_nom_agent");
	prenom_agent=lookup_widget(current,"entry_modif_prenom_agent");
	sexe_agent=lookup_widget(current,"entry_modif_sexe_agent");
	cin_agent=lookup_widget(current,"entry_modif_numcin_agent");
	tel_agent=lookup_widget(current,"entry_modif_numtel_agent");
	date_agent=lookup_widget(current,"entry_modif_datenaiss_agent");


	strcpy(a1.nom,gtk_entry_get_text(GTK_ENTRY(nom_agent)));
  	strcpy(a1.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_agent)));
  	strcpy(a1.sexe,gtk_entry_get_text(GTK_ENTRY(sexe_agent)));
  	strcpy(a1.num_tel,gtk_entry_get_text(GTK_ENTRY(tel_agent))); 	
	strcpy(a1.num_CIN,gtk_entry_get_text(GTK_ENTRY(cin_agent)));
	strcpy(a1.date,gtk_entry_get_text(GTK_ENTRY(date_agent)));


	//notebook=lookup_widget(Espace_admin,"notebook1");
	//gtk_notebook_set_current_page(notebook,1);
	treeview1=lookup_widget(Espace_admin,"treeview_liste_agents_par_admin");
	modifier_agents(a1);
	afficher_agents(treeview1);		
	gtk_widget_hide(current);
	gtk_widget_show(Espace_admin);
}


void
on_button_retour_modif_vers_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview_liste_agents_par_admin_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *name;
gchar *surname;
gchar *sex; 
gchar *cin;
gchar *tel;
gchar *datee;



GtkWidget *Espace_admin;
GtkWidget *current;
GtkTreeIter iter;

	GtkEntry *nom_agent;
	GtkEntry *prenom_agent;
	GtkEntry *sexe_agent;	
	GtkEntry *tel_agent;
	GtkEntry *cin_agent;
        GtkEntry *date_agent;




GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&name,1,&surname,2,&sex,3,&cin,4,&tel,5,&datee,-1);}

current=lookup_widget(treeview,"Espace_admin");

	nom_agent=lookup_widget(current,"entry1");
	prenom_agent=lookup_widget(current,"entry2");
	sexe_agent=lookup_widget(current,"entry3");
	cin_agent=lookup_widget(current,"entry4");
	tel_agent=lookup_widget(current,"entry5");
	date_agent=lookup_widget(current,"entry6");




	gtk_entry_set_text(GTK_ENTRY(nom_agent),name);
	gtk_entry_set_text(GTK_ENTRY(prenom_agent),surname);
	gtk_entry_set_text(GTK_ENTRY(sexe_agent),sex);
	gtk_entry_set_text(GTK_ENTRY(cin_agent),cin);
	gtk_entry_set_text(GTK_ENTRY(tel_agent),tel);
	gtk_entry_set_text(GTK_ENTRY(date_agent),datee);

}


void
on_button_valider_modif_admin_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
profil_admin=create_profil_admin();
gtk_widget_show(profil_admin);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet,"Modifier_admin")));

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;


char nom[20];
char prenom [20];
char sexe [20];
char num_tel [10];
char num_CIN [10] ;
char date[20];


input1=lookup_widget(objet,"entry_modif_nom_admin");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry_modif_prenom_admin");
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet,"entry_modif_sexe_admin");
strcpy(sexe,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(objet,"entry_modif_cin_admin");
strcpy(num_CIN,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(objet,"entry_modif_tel_admin");
strcpy(num_tel,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(objet,"entry_modif_date_admin");
strcpy(date,gtk_entry_get_text(GTK_ENTRY(input6)));


FILE *f;
f=fopen("admin.txt","w");
fprintf(f,"%s %s %s %s %s %s \n",nom,prenom,sexe,num_CIN,num_tel,date);
fclose(f); 

}


void
on_button_edit_profil_admin_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
Modifier_admin=create_Modifier_admin();
gtk_widget_show(Modifier_admin);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"profil_admin")));

}


void
on_button_cam_agents_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
system("vlc cam.MP4");
}


void
on_button_rechercher_agent_par_admin_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	char t[20];
        GtkWidget *treeview_coord_agents;
        GtkWidget *input1;
	input1=lookup_widget(objet_graphique,"entry_recherche_cinagent");
	treeview_coord_agents=lookup_widget(objet_graphique,"treeview_coord_agents");
	strcpy(t,gtk_entry_get_text(GTK_ENTRY(input1)));
	afficher_coord (treeview_coord_agents,t);
}

