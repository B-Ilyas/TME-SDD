#include<stdio.h>
#include<stdlib.h>

typedef struct tableau{
	int* tab;
	int maxTaille;
	int position;
}Tableau;

void ajouterElement(int a,Tableau *t){
	if (t->position < t->maxTaille) {
		t->tab[t->position] = a;
		t->position++;
	} else {
		printf("Plus de place\n");
	}
}

Tableau* initTableau(int maxTaille){
	Tableau* t = (Tableau*)malloc(sizeof(Tableau));
	t->position = 0;
	t->maxTaille = maxTaille;
	t->tab = (int*)malloc(sizeof(int)*maxTaille);
	return t;
}

void affichageTableau(Tableau* t){
	printf("t->position = %d\n",t->position);
	printf("[ ");	
	for (int i = 0; i < (t->position); i++){
		printf("%d ",t->tab[i]);	
	}
	printf("]\n");
}

int main(){
	Tableau* t;
	t = initTableau(100);
	ajouterElement(5,t);
	ajouterElement(18,t);
	ajouterElement(99999,t);
	ajouterElement(-452,t);
	ajouterElement(4587,t);
	affichageTableau(t);

	free(t->tab);
	free(t);
}

// Q1.6 A la lecture du code, le programme crée et initialise un tableau de taille maximale 100, puis ajoute des valeurs a ce dernier. Ensuite il affiche le contenu du tableau puis libere le tableau.
// Il ne se passe rien. Le programme affiche bien le tableau.

// Q1.7 Les problemes de ce programme sont :
// - ajouterElement peut rajouter autant d'element qu'on veut sans prendre en compte maxTaille
// - ligne 41, il faut free le champ tab avant de free t.

// Q1.8 On constate qu'il y a 400 octets dans 1 bloc de perdu. Ces 400 octets correspondent a la taille de la memoire allouée par le champ tab de la structure Tableau.
