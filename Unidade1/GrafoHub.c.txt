#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include"grafo.h"
#include"list.h"




int main(){
	setlocale(LC_ALL, "Portuguese");
	int i, j, size, option, exit = 0;
	int orig, dest, cost;
	
	printf("Insira a quantidade de vértices do grafo:\t");
	scanf("%d", &size);
	system("cls");
	
	Graph *adj_graph = init_graph(size);
	Graph *cost_graph = init_graph(size);
	Graph *wooden_house = init_graph(10);
	fill_wooden_house(wooden_house);
	List *graph_queue = init_list();
	
	int adj_matrix[size][size];
	int cost_matrix[size][size];
	int bfs[3][size];
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			adj_matrix[i][j] = 0;
			cost_matrix[i][j] = 0;
		}
	}
	
	system("cls");
	while(1){
		printf("-------------------X GRAFOS X-------------------\n\n");
		printf("1 - Mostrar Grafos\n");
		printf("2 - Adicionar Aresta\n");
		printf("3 - Busca em Largura\n");
		printf("4 - Caixeiro Viajante\n");
		printf("5 - Casa de Madeira\n");
		printf("6 - Caminho Crítico\n");
		printf("7 - Sair\n");
		printf("\n Escolha uma opção:\t");
		scanf("%d", &option);
		system("cls");
		
		switch(option){
			case 1:
				printf("MATRIZ ADJACENTE:\n\n");
				for(i = 0; i < size; i++){
					for(j = 0; j < size; j++){
						printf("[%d]", adj_matrix[i][j]);
					}
					printf("\n");
				}
				printf("\n\n");
				printf("MATRIZ DE CUSTOS:\n\n");
				for(i = 0; i < size; i++){
					for(j = 0; j < size; j++){
						printf("[%d]", cost_matrix[i][j]);
					}
					printf("\n");
				}
				printf("\n\n");
				printf("LISTA ADJACENTE:\n\n");
				print_graph_adjacency(adj_graph);
				printf("\n\n");
				printf("LISTA DE CUSTOS:\n\n");
				print_graph(cost_graph);
				printf("\n\n");
				break;
			case 2:
				printf("Insira a aresta de origem:\t");
				scanf("%d", &orig);
				printf("Insira a aresta de destino:\t");
				scanf("%d", &dest);
				printf("Insira o custo da aresta:\t");
				scanf("%d", &cost);
				if(orig >= size || dest >= size){
					printf("Parâmetros Inválidos!!\n\n");
				} else {
					adj_matrix[orig][dest] = 1;
					adj_matrix[dest][orig] = -1;
					cost_matrix[orig][dest] = cost;
					cost_matrix[dest][orig] = (-1 * cost);
					insert_edge(adj_graph, orig, dest, 1);
					insert_edge(adj_graph, dest, orig, -1);
					insert_edge(cost_graph, orig, dest, cost);
					insert_edge(cost_graph, dest, orig, (-1 * cost));
				}
				break;
			case 3:
				printf("Insira o vértice de origem:\t");
				scanf("%d", &orig);
				printf("\n");
				if(orig >= size){
					printf("Parâmetros Inválidos!!\n\n");
				} else {
					breadth_first_search(cost_graph, orig, bfs[1], bfs[2]);
				}
				break;
			case 4:
				printf("Insira o vértice de origem:\t");
				scanf("%d", &orig);
				printf("Insira o vértice de destino:\t");
				scanf("%d", &dest);
				printf("\n");
				if(orig >= size || dest >= size){
					printf("Parâmetros Inválidos!!\n\n");
				} else {
					traveling_salesman(cost_graph, orig, dest);
				}
				break;
			case 5:
				traveling_salesman(wooden_house, 0, 9);
				print_graph(wooden_house);
				break;
			case 6:
				profundida(cost_graph);
				break;
			case 7:
				exit = 1;
				break;
			default:
				printf("\nOpção Inválida!!\n\n");
				break;
		}
		if(exit){ system("cls"); break; }
		system("pause");
		system("cls");
	}
	return 0;
}
