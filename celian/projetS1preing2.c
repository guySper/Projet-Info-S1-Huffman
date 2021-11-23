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
    printf("freq :%d ||",a->valeur );
    printf("charactere :%c",a->lettre );
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

teteliste* creationdelaliste(teteliste* liste, FILE* fichier){
  fichier = fopen("test.txt", "r");
  char tmp;
  char c = ' ';
  int acc;
  while(c < '~'){
    tmp = fseek(fichier, SEEK_SET, 0);
    acc = 0;
    while (tmp != EOF)
    {
      tmp = fgetc(fichier);
      if (tmp == c)
      {
        acc++;
      }

    }
    // printf("%c:%d\n", c, acc );
    // insertionListe(liste, cree_arbre(acc, c, NULL, NULL));
    liste = ajoutrie(creerListe(NULL,creerArbre(acc, c, NULL, NULL)),liste);
    c++;


  }
  return liste;
}

void afficherListeF(teteliste* liste, FILE* fichier){
  if (liste != NULL)
  {
    afficheAbreF(liste->valeur, fichier);
    fputs(" ", fichier);
    afficherListeF(liste->suivant, fichier);
  }
  
}

void afficheAbreF(arbre* a, FILE* fichier){
  
  if(a != NULL){
    afficheAbre(a->filsdroit);
    fputs(" ", fichier);
    fprintf(fichier, "freq :%d ||",a->valeur);
    fprintf(fichier, "charactere :%c",a->lettre);
    fputs(" \n", fichier);
    afficheAbre(a->filsgauche);
  }
}



void codage(arbre* a, char c){
  
  
  

  
  
  
}

void fichierCodage(teteliste *Liste){
  FILE* fichiercodage = NULL;
  fichiercodage = fopen("fichiercodage.txt", "w");
  if (fichiercodage != NULL)
  {
    fputs("caractere  code\n", fichiercodage);


    afficherListeF(Liste, fichiercodage);
    
    fclose(fichiercodage);
  }
  
}
