#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
	int i, j;
	int vertices;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o número de vértices:\t");
	scanf("%d", &vertices);
	
	int grafo[vertices][vertices];
	
	system("cls");
	for(i = 0; i < vertices; i++){
		for(j = 0; j < vertices; j++){
			printf("Insira o custo da aresta {%d, %d}:\t", i+1, j+1);
			scanf("%d", &grafo[i][j]); 
		}
	}
	
	system("cls");
	printf("MATRIZ DE ADJACÊNCIA\n\n\n");
	
	for(i = 0; i < vertices; i++){
		for(j = 0; j < vertices; j++){
			printf("[%d] ", grafo[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
