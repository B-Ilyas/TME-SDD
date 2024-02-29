#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alloue_matrice(int **t , int n) {
	*t = (int*) malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		t[i] = (int*)malloc(n * sizeof(int));
	}
} 


// 2

void desalloue_tableau(int **t) {
	for (int i = 0; i < n; i++) {
		free(t[i]);
	}
	
	free(t);
}


// 3

void remplir_tableau(int **t, int v, int n) {
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			t[i][j] = rand()*v;
		}
	}
}


// 4

void afficher_tableau(int **t, int n) {
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			printf("%d\n", t[i][j]);
		}
	}
}
int algo1 (int** t, int n){
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			for (int k = 0 ; k < n ; k++){
				for (int l = 0 ; l < n ; l++){
					if (t[i][j] != t[k][l]){
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int main() {
	
	return 1;
}
