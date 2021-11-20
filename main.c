#include <stdlib.h>
#include <stdio.h>
#include "projetS1preing2.h"

int main(){
  teteliste* Liste=creerListe(NULL,creerArbre(4,'a',NULL,NULL));
  Liste=ajoutrie(creerListe(NULL,creerArbre(42,'b',NULL,NULL)),Liste);
  Liste=ajoutrie(creerListe(NULL,creerArbre(6,'c',NULL,NULL)),Liste);
  Liste=ajoutrie(creerListe(NULL,creerArbre(3,'d',NULL,NULL)),Liste);
  Liste=ajoutrie(creerListe(NULL,creerArbre(69,'e',NULL,NULL)),Liste);
  while(Liste->suivant!=NULL){
   Liste=construction(Liste);
  }
  afficherListe(Liste);
  printf("\n");
  return 0;
}
