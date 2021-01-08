#include<gtk/gtk.h>



typedef struct
{int jour;
int mois;
int annee;
}DATE;

typedef struct{

char type[50];
char marque[50];
char modele[50];
char gamme[50];
char identifiant[50];
char prix[50];
DATE d1;
char etat[50];

}equipements;


void ajouter_equipe(equipements e);

void modifier_equipe(equipements e);

void supprimer_equipe(equipements e);

void afficher_equipement (GtkWidget *liste);
