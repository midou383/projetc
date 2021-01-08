#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "equipements.h"


void
on_Ajouterequipement_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *Ajouter_un_equipement;
	GtkWidget *Gestion_des__equipement_agricole;
        Gestion_des__equipement_agricole=lookup_widget(objet,"Gestion_des__equipement_agricole");
	Ajouter_un_equipement=lookup_widget(objet,"Ajouter_un_equipement");
        gtk_widget_destroy(Gestion_des__equipement_agricole);

	Ajouter_un_equipement=create_Ajouter_un_equipement();
	gtk_widget_show(Ajouter_un_equipement);

}





void
on_supprimerequipement_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Supprimer_un_equipement;
	GtkWidget *Gestion_des__equipement_agricole;
        Gestion_des__equipement_agricole=lookup_widget(objet,"Gestion_des__equipement_agricole");
        gtk_widget_destroy(Gestion_des__equipement_agricole);

	Supprimer_un_equipement=create_Supprimer_un_equipement();
	gtk_widget_show(Supprimer_un_equipement);  
}


void
on_ajouteequipe_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
{GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8;
 GtkWidget *JOUR;
 GtkWidget *MOIS;
 GtkWidget *ANNEE;
GtkWidget *combo1_eq;
 GtkWidget*radio1; 
GtkWidget*radio2;


radio1=lookup_widget(GTK_WIDGET(objet_graphique),"enmarche");
radio2=lookup_widget(GTK_WIDGET(objet_graphique),"enpanne");
  
 equipements e;
 DATE d1;
 GtkWidget *Ajouter_un_equipement;
 FILE *f=NULL;
 
Ajouter_un_equipement=lookup_widget(objet_graphique,"Ajouter_un_equipement");
input1=lookup_widget(objet_graphique,"type");
input2=lookup_widget(objet_graphique,"marque");
input3=lookup_widget(objet_graphique,"model");
input4=lookup_widget(objet_graphique,"identifiant");
input5=lookup_widget(objet_graphique,"prix");
JOUR=lookup_widget(objet_graphique,"jour");
MOIS=lookup_widget(objet_graphique,"mois");
ANNEE=lookup_widget(objet_graphique,"annee");
input6=lookup_widget(objet_graphique,"etat");
combo1_eq=lookup_widget(objet_graphique,"combobox3");
strcpy(e.gamme,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1_eq)));
strcpy(e.type,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.marque,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.modele,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.identifiant,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(e.prix,gtk_entry_get_text(GTK_ENTRY(input5)));
e.d1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JOUR));
e.d1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MOIS));
e.d1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ANNEE));

  GSList *pList;
    const gchar *sLabel;
//GSList*gtk_radio_button_get_group(GtkRadioButton *radio1);




  /* Récupération de la liste des boutons */
    pList = gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio1));
 



    /* Parcours de la liste */
    while(pList)
    {
        /* Le bouton est-il sélectionné */
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pList->data)))
        {
            /* OUI -> on copie le label du bouton */
            sLabel = gtk_button_get_label(GTK_BUTTON(pList->data));
            /* On met la liste a NULL pour sortir de la boucle */
            pList = NULL;
        }
        else
        {
            /* NON -> on passe au bouton suivant */
            pList = g_slist_next(pList);
        }
    }
strcpy(e.etat,sLabel);
ajouter_equipe(e);

}
}


void
on_Retourgestion_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_Retourajoute_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{       GtkWidget *Gestion_des__equipement_agricole;
        GtkWidget *Ajouter_un_equipement;
	
        Ajouter_un_equipement=lookup_widget(objet,"Ajouter_un_equipement");
        gtk_widget_destroy(Ajouter_un_equipement);

	Gestion_des__equipement_agricole=create_Gestion_des__equipement_agricole();
	gtk_widget_show(Gestion_des__equipement_agricole);

}


void
on_Afficherequipe_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{        
        GtkWidget *Ajouter_un_equipement;
        GtkWidget *Afficher_un_equipement;
	
        Ajouter_un_equipement=lookup_widget(objet,"Ajouter_un_equipement");
        gtk_widget_destroy(Ajouter_un_equipement);

	Afficher_un_equipement=create_Afficher_un_equipement ();
	gtk_widget_show(Afficher_un_equipement);

}


void
on_Affichetreeview_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewequipe; 
treeviewequipe=lookup_widget(objet,"treeviewequipe");
afficher_equipement(treeviewequipe);
}


void
on_Validermodifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

}











void
on_Retoursuppr_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_un_equipement;
	GtkWidget *Gestion_des__equipement_agricole;

        Supprimer_un_equipement=lookup_widget(objet,"Supprimer_un_equipement");

        gtk_widget_destroy(Supprimer_un_equipement);

	Gestion_des__equipement_agricole=create_Gestion_des__equipement_agricole();

	gtk_widget_show(Gestion_des__equipement_agricole);
}


void
on_Modifierequipeon_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8;
 GtkWidget *JOUR;
 GtkWidget *MOIS;
 GtkWidget *ANNEE;
GtkWidget *combo1_eq;
 GtkWidget* radio1; 
GtkWidget* radio2;
GSList* gtk_radio_button_get_group(GtkRadioButton *radio_button);

radio1=lookup_widget(GTK_WIDGET(objet_graphique),"enmarchemodife");
radio2=lookup_widget(GTK_WIDGET(objet_graphique),"onpannemodife");
  
 equipements e;
 DATE d1;
 GtkWidget *Ajouter_un_equipement;
 FILE *f=NULL;
 
Ajouter_un_equipement=lookup_widget(objet_graphique,"Ajouter_un_equipement");
input1=lookup_widget(objet_graphique,"modifetype");
input2=lookup_widget(objet_graphique,"modifemarque");
input3=lookup_widget(objet_graphique,"modifmodele");
input4=lookup_widget(objet_graphique,"modifeiden");
input5=lookup_widget(objet_graphique,"modifeprix");
JOUR=lookup_widget(objet_graphique,"modifejour");
MOIS=lookup_widget(objet_graphique,"modifemois");
ANNEE=lookup_widget(objet_graphique,"modifeannee");
input6=lookup_widget(objet_graphique,"modifeetat");
combo1_eq=lookup_widget(objet_graphique,"Combomodifierequipe");
strcpy(e.gamme,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1_eq)));
strcpy(e.type,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.marque,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.modele,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.identifiant,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(e.prix,gtk_entry_get_text(GTK_ENTRY(input5)));
e.d1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JOUR));
e.d1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MOIS));
e.d1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ANNEE));

  GSList *pList;
    const gchar *sLabel;




  /* Récupération de la liste des boutons */
    pList = gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio1));
 



    /* Parcours de la liste */
    while(pList)
    {
        /* Le bouton est-il sélectionné */
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pList->data)))
        {
            /* OUI -> on copie le label du bouton */
            sLabel = gtk_button_get_label(GTK_BUTTON(pList->data));
            /* On met la liste a NULL pour sortir de la boucle */
            pList = NULL;
        }
        else
        {
            /* NON -> on passe au bouton suivant */
            pList = g_slist_next(pList);
        }
    }
strcpy(e.etat,sLabel);
modifier_equipe(e);

}
}


void
on_Retourmodifier_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

        GtkWidget *Gestion_des__equipement_agricole;
        GtkWidget *Modifier_un_equipement;
	
        Modifier_un_equipement=lookup_widget(objet,"Modifier_un_equipement");
        gtk_widget_destroy(Modifier_un_equipement);

	Gestion_des__equipement_agricole=create_Gestion_des__equipement_agricole();
	gtk_widget_show(Gestion_des__equipement_agricole);
}


void
on_Suprim_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{ 
equipements e;
GtkWidget *inputsupp;
inputsupp=lookup_widget(objet,"suppiden");
strcpy(e.identifiant,gtk_entry_get_text(GTK_ENTRY(inputsupp)));
supprimer_equipe(e); 
}


void
on_Modifierequipement_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
        
         

     GtkWidget *Modifier_un_equipement;
	GtkWidget *Gestion_des__equipement_agricole;
         Gestion_des__equipement_agricole=lookup_widget(objet,"Gestion_des__equipement_agricole");
	Modifier_un_equipement=lookup_widget(objet,"Modifier_un_equipement");
        gtk_widget_destroy(Gestion_des__equipement_agricole);

	Modifier_un_equipement=create_Modifier_un_equipement();
	gtk_widget_show(Modifier_un_equipement);








}


void
on_Afficherlesequipe_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Gestion_des__equipement_agricole;
        GtkWidget *Afficher_un_equipement;
	
         Gestion_des__equipement_agricole=lookup_widget(objet," Gestion_des__equipement_agricole");
        gtk_widget_destroy( Gestion_des__equipement_agricole);

	Afficher_un_equipement=create_Afficher_un_equipement ();
	gtk_widget_show(Afficher_un_equipement);
}


void
on_retourdesupp_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_un_equipement;
	GtkWidget *Gestion_des__equipement_agricole;

        Supprimer_un_equipement=lookup_widget(objet,"Supprimer_un_equipement");

        gtk_widget_destroy(Supprimer_un_equipement);

	Gestion_des__equipement_agricole=create_Gestion_des__equipement_agricole();

	gtk_widget_show(Gestion_des__equipement_agricole);
}


void
on_retourdeaffiche_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Afficher_un_equipement;
        GtkWidget *Gestion_des__equipement_agricole;
	
         Afficher_un_equipement=lookup_widget(objet," Afficher_un_equipement");
        gtk_widget_destroy( Afficher_un_equipement);

	Gestion_des__equipement_agricole=create_Gestion_des__equipement_agricole ();
	gtk_widget_show(Gestion_des__equipement_agricole);
}

