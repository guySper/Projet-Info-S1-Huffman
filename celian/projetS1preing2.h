#ifndef HUFFMAN
#define HUFFMAN

typedef struct arbre arbre;

struct arbre {
  int valeur;
  char lettre;
  arbre* filsdroit;
  arbre* filsgauche;
};

typedef struct teteliste teteliste;

struct teteliste {
  arbre* valeur;
  teteliste* suivant;
};

//crée une racine pointant vers un fils gauche et un fils droit
arbre* creerArbre(int val,char lettre, arbre* fd, arbre* fg);

//crée une te de liste pointant vers une autre tête de liste
teteliste* creerListe(teteliste* l,arbre* a);

//libère la mémoir allouée à un arbre
void libererArbre(arbre* a);

//libère la mémoir allouée à une liste
void libererListe(teteliste* l);

//fusionne deux arbres et renvoie un arbre ayant pour fils les arbre en entrée
arbre* fusionNoeud(arbre* a, arbre* b);

//ajout de façon triée une te de liste à une liste
teteliste* ajoutrie(teteliste* ajout,teteliste* ldep);

//assaemble les deux premiers termes d'une liste en un arbre
teteliste* construction(teteliste* liste);

void afficheAbre(arbre* a);
void afficherListe(teteliste* liste);


teteliste* creationdelaliste(teteliste* liste, FILE* fichier);

void afficherListeF(teteliste* liste, FILE *fichier);
void afficheAbreF(arbre* a, FILE* fichier);



void codage(arbre* a, char c);
void fichierCodage(teteliste *liste);

#endif
