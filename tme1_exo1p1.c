#include<stdio.h>
#include<stdlib.h>

const static int len = 10;

int main(void) {
    int *tab;
    unsigned int i;

    tab = (int*)malloc(len*sizeof(int));

    for (i = len-1; i >= 0; i--) {
        tab[i] = i;
    }

    free(tab);
    return 0;
}

// Q1.2 Après l'itération i = 0, i vaut 4294967295. i devrait valoir -1 a la sortie de la boucle. On essaie d'acceder a la 4294967296eme case. L'erreur de segmentation provient de la car on essaie d'acceder a une case memoire qui n'a pas été alloué.

// Q1.3 Il faut enlever "unsigned".
