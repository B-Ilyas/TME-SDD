#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct adresse {
    int numero;
    char* rue;
    int code_postal;
} Adresse;

Adresse* creer_adresse(int n, char* r, int c) {
    Adresse* new = (Adresse*) malloc(sizeof(Adresse));

    new->numero = n;
    strcpy(new->rue, r);
    new->code_postal = c;

    return new;
}

int main(void) {
    Adresse* maison = creer_adresse (12, "manoeuvre", 15670);
    
    printf("Adresse courante : %d rue %s %d France\n", maison->numero, maison->rue, maison->code_postal);
    
    return 0;
}

// Q1.4 La fonction creer_adresse permet de creer une structure. Dans le main, on teste la fonction et on l'affiche.

// Q2.5
// On voit l'adresse 0x0. 
// On constate que l'erreur est due à l'utilisation de la fonction strcpy.
// La cause de l'erreur est qu'on a utilisé strcpy sur une chaine de caractères qui n'a pas été alloué précedemment. On propose de corriger en utilisant strdup a la place de strcpy.
