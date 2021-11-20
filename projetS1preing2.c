#include <stdlib.h>
#include <stdio.h>
#include "projetS1preing2.h"

// /!\ filsdroit est filsgauche et inversement

//fontion qui crée un noeud
arbre* creerArbre(int val,char lettre, arbre* fd, arbre* fg){
  arbre* a = malloc(sizeof(arbre));
  a->valeur=val;
  a->lettre=lettre;
  a->filsdroit=fd;
  a->filsgauche=fg;
  return a;
}

//fontion qui crée une tête de liste
teteliste* creerListe(teteliste* l,arbre* a){
  teteliste* liste = malloc(sizeof(teteliste));
  liste->valeur = a;
  liste->suivant = l;
  return liste;
}

//fonction qui libère récursivement la mémoire occupée par un arbre
void libererArbre(arbre* a){
  if (a==NULL){
  }
  else{
    if ((a->filsdroit==NULL)&&(a->filsgauche==NULL)){
      free(a);
    }
    else{
      libererArbre(a->filsdroit);
      libererArbre(a->filsgauche);
    }
  }
}

//fonction qui libère récursivement la mémoire occupée par une liste
void libererListe(teteliste* l){
  if (l==NULL){
  }
  else{
    if (l->suivant==NULL){
      free(l);
    }
    else{
      libererListe(l->suivant);
    }
  }
}

//fonction qui fusione deux arbres
//le ² sert a combler le vide inutilisé dans les noeuds n'etant pas des feuilles
arbre* fusionNoeud(arbre* a, arbre* b){
  return creerArbre(a->valeur + b->valeur,'~',a,b);
}

//fontion qui ajoute de façon triée un arbre dans la liste
teteliste* ajoutrie(teteliste* ajout,teteliste* ldep){
  if (ldep==NULL){
    return ajout;
  }
  else{
    if ((ajout->valeur->valeur)<=(ldep->valeur->valeur)){
      return creerListe(ldep,ajout->valeur);
    }
    else{
      return creerListe(ajoutrie(ajout,ldep->suivant),ldep->valeur);
    }
  }
}

//fonction qui prends les deux premiers arbres de la liste les fusionent et insere l'arbre obtenu dans la liste
teteliste* construction(teteliste* liste){
  if (liste->suivant != NULL){
    return  ajoutrie(creerListe(NULL,fusionNoeud(liste->valeur,liste->suivant->valeur)),liste->suivant->suivant);
  }
  else{
    return liste;
  }
}

//fonction qui affiche les noueds d'un arbre
void afficheAbre(arbre* a){
  if (a==NULL){
  }
  else{
    afficheAbre(a->filsdroit);
    printf(" ");
    printf("%d",a->valeur );
    printf("%c",a->lettre );
    printf(" ");
    afficheAbre(a->filsgauche);
  }
}

//fonction qui affiche tous les éléments d'une liste
void afficherListe(teteliste* liste){
  if (liste!=NULL){
    afficheAbre(liste->valeur);
    printf("\n");
    afficherListe(liste->suivant);
  }
}
