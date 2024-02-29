#include<stdio.h>
#include<stdlib.h>
#include <time.h>

clock_t temps_initial;
clock_t temps_final;
double temps_cpu1;
double temps_cpu2;


// Q2.1

// 1

int* alloue_tableau(int n) {
	int *t = (int*) malloc(n * sizeof(int));
	return t;
}

void alloue_tableau2(int **t , int n) {
	*t = (int*)malloc(n*sizeof(int));
} 


// 2

void desalloue_tableau(int *t) {
	free(t);
}


// 3

void remplir_tableau(int *t, int v, int n) {
	for (int i = 0 ; i < n ; i++) {
		t[i] = rand()*v;
	}
}


// 4

void afficher_tableau(int *t, int n) {
	for (int i = 0 ; i < n ; i++) {
		printf("%d\n", t[i]);
	}
}



// Q2.1

// 1

int algo1(int *t, int n) {
	int s = 0;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			s+= (t[i] - t[j])*(t[i] - t[j]);
		}
	}
	return s;
}


int algo2(int *t, int n) {
	int s1 = 0;
	int s2 = 0; 
	
	for (int i = 0 ; i < n ; i++) {
		s1 += t[i]*t[i];
		s2 += t[i];
	}

	return 2*n*s1 - 2*s2*s2 ;
}




int main() {
	int *t = (int *)malloc(100*sizeof(int));
	
	for (int i = 0; i < 100; i++) {
		t[i] = i;
	}
	
	// afficher_tableau(t, 100);
	
	printf("somme d'algo1 : %d\nsomme d'algo2 : %d\n", algo1(t, 100), algo2(t, 100)); 
	
	int nb_it = 0;
	
	printf("Ecriture du fichier en cours\n");
    FILE *f = fopen("sortie_vitesse.txt", "w");
    
    if (f == NULL) {
        printf("Erreur a l'ouverture de sortie_vitesse.txt\n");
        return 1;
    }
    
    fprintf(f, "%d %f %f\n", nb_it, temps_cpu1, temps_cpu2);
    while (nb_it < 100) {
        
        temps_initial = clock();
		algo1(t, nb_it);
		temps_final = clock();
		
		temps_cpu1 = ((double)(temps_final - temps_initial))/ CLOCKS_PER_SEC;
		
		temps_initial = clock();
		algo2(t, nb_it);
		temps_final = clock();

		temps_cpu2 = ((double)(temps_final - temps_initial))/ CLOCKS_PER_SEC;
		
        fprintf(f, "%d %f %f\n", nb_it, temps_cpu1, temps_cpu2);
        
        nb_it++;
    }
    
    fclose(f);
    
    printf("Ecriture du fichier termine !\n");
    
	desalloue_tableau(t);
	
	return 0;
}

