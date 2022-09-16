#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
	int i, j;
	int vertices, arestas = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o número de vértices:\t");
	scanf("%d", &vertices);
	printf("Insira o número de arestas:\t");
	scanf("%d", &arestas);
	
	int mat_inc[vertices][arestas];
	
	for(i = 0; i < vertices; i++){
		for(j = 0; j < arestas; j++){
			mat_inc[i][j] = 0;
		}
	}
	
	system("cls");
	for(j = 0; j < arestas; j++){
		int orig, dest;
		printf("Insira os vértices da aresta %d:\t", j+1);
		scanf("%d %d", &orig, &dest);
		mat_inc[orig-1][j] = 1;
		mat_inc[dest-1][j] = -1;
	}
	
	system("cls");
	printf("MATRIZ DE INCIDÊNCIA\n\n\n");
	
	for(i = 0; i < vertices; i++){
		for(j = 0; j < arestas; j++){
			printf("[%d] ", mat_inc[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
