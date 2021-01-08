#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipements.h"
#include <gtk/gtk.h>

void ajouter_equipe(equipements e)
{FILE *f ;

f=fopen("equipements.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %d %d %d %s %s\n ",e.gamme,e.type,e.marque,e.modele,e.identifiant,e.d1.jour,e.d1.mois,e.d1.annee,e.prix,e.etat);
fclose(f);
}
}

void modifier_equipe(equipements e2)
{
FILE *f ;
FILE *g ;
equipements e;
f=fopen("equipements.txt","r");
g=fopen("equipements2.txt","w");
if(f!=NULL)
while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s \n ",e.gamme,e.type,e.marque,e.modele,e.identifiant,&e.d1.jour,&e.d1.mois,&e.d1.annee,e.prix,e.etat)!=EOF) {
if(strcmp(e.identifiant,e2.identifiant)==0) {
fprintf(g,"%s %s %s %s %s %d %d %d %s %s \n", e2.gamme,e2.type,e2.marque,e2.modele,e2.identifiant,e2.d1.jour,e2.d1.mois,e2.d1.annee,e2.prix,e2.etat);}
else{ fprintf(g,"%s %s %s %s %s %d %d %d %s %s \n ",e.gamme,e.type,e.marque,e.modele,e.identifiant,e.d1.jour,e.d1.mois,e.d1.annee,e.prix,e.etat);
}}
fclose(f);
fclose(g);
remove("equipements.txt");
rename("equipements2.txt","equipements.txt");
}


void supprimer_equipe(equipements e2)

{
FILE *f ;
FILE *g ;
equipements e;
f=fopen("equipements.txt","r");
g=fopen("equipements2.txt","w");
if(f!=NULL)
while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s \n ",e.gamme,e.type,e.marque,e.modele,e.identifiant,&e.d1.jour,&e.d1.mois,&e.d1.annee,e.prix,e.etat)!=EOF) {
if(strcmp(e2.identifiant,e.identifiant)!=0) {
fprintf(g,"%s %s %s %s %s %d %d %d %s %s \n", e.gamme,e.type,e.marque,e.modele,e.identifiant,e.d1.jour,e.d1.mois,e.d1.annee,e.prix,e.etat);}
}
fclose(f);
fclose(g);
remove("equipements.txt");
rename("equipements2.txt","equipements.txt");
}



enum{
	ETYPE,
	EMARQUE,
	EMODELE,
EGAMME,
	EIDENTIFIANT,
	EPRIX,
	EDATE,
EETAT,
COLUMNS
};

 
void afficher_equipement (GtkWidget *liste)


{

	GtkCellRenderer *renderer;  
	GtkTreeViewColumn *column;
	GtkTreeIter   iter;    
	GtkListStore  *store;    

        char type[50];
        char marque[50];
        char modele[50];
        char gamme[50];
        char identifiant[50];
        char prix[50];
        char date[50];
        char etat[50];
	char j[20],m[20],a[20];
	int jr,mo,an;
	 store=NULL;
	 FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
        renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("gamme",renderer,"text",EGAMME,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);  

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("modele",renderer,"text",EMODELE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

        renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",EDATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
        

        
        renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("prix",renderer,"text",EPRIX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	

        
        renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


}
	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("equipements.txt","r");
	if(f==NULL)
	{
	return;
	}
	else 
{
	f=fopen("equipements.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",gamme,type,marque,modele,identifiant,j,m,a,prix,etat)!=EOF)
{	strcpy(date,"");
	strcat(date,j);
	strcat(date,"/");
	strcat(date,m);
	strcat(date,"/");
        strcat(date,a);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,EGAMME,gamme,ETYPE,type,EMARQUE,marque,EMODELE,modele,EIDENTIFIANT,identifiant,EDATE,date,EPRIX,prix,EETAT,etat,-1);
}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	
}

}








