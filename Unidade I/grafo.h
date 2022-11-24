#ifndef GRAFO_H
#define GRAFO_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"list.h"

typedef struct nd {
	int vertex_number;
	int cost;
	struct nd *next;
} Node;

typedef struct vt{
	int vertex_number;
	Node *head;
	struct vt *next;
} Vertex;

typedef struct gf{
	int vertex_qnt;
	int edges_qnt;
	Vertex *vertexes;
} Graph;

Node *allocate_node(){
	Node *n = (Node*) malloc(sizeof(Node));
	return n;
}

Vertex *init_vertex(){
	Vertex *vtx = (Vertex*) malloc(sizeof(Vertex));
	vtx->head = NULL;
	return vtx;
}

Graph *init_graph(int vertex_qnt){	
	Graph *grafo = (Graph*) malloc(sizeof(Graph));
	grafo->vertex_qnt = vertex_qnt;
	grafo->edges_qnt = 0;
	grafo->vertexes = NULL;
	
	int i = 0;
	
	for(i = 0; i < vertex_qnt; i++){
		Vertex *aux_vertex = init_vertex();
		aux_vertex->vertex_number = i;
		aux_vertex->next = NULL;
		
		if(grafo->vertexes == NULL){ grafo->vertexes = aux_vertex;}
		else{
			Vertex *temp_vertex = grafo->vertexes;
			while(temp_vertex->next != NULL){
				temp_vertex = temp_vertex->next;
			}
			temp_vertex->next = aux_vertex;
		}
	}
	
	return grafo;
}

int insert_edge(Graph *grafo, int src_vertex, int dest_vertex, int cost){
	Node *new_vertex = allocate_node();
	if(!new_vertex){ return 0; }
	new_vertex->vertex_number = dest_vertex;
	new_vertex->cost = cost;
	new_vertex->next = NULL;
	
	Vertex *aux_vertex = grafo->vertexes;
	while(aux_vertex->vertex_number != src_vertex && aux_vertex->next != NULL){ aux_vertex = aux_vertex->next; }
	if(aux_vertex->vertex_number != src_vertex){ printf("Vértice inexistente\n"); return 0; }
	
	if(aux_vertex->head == NULL){ 
		aux_vertex->head = new_vertex;
		printf("Aresta criada:  [V%d]--- %d ---> [V%d]\n", src_vertex, cost, dest_vertex);
		grafo->edges_qnt ++;
		return 1; 
	}
	
	Node *aux_node = aux_vertex->head;
	while(aux_node->next != NULL){
		if(aux_node->vertex_number == dest_vertex){
			printf("Aresta já existente!\n");
			return 0;
		}
		aux_node = aux_node->next; 
	}
	aux_node->next = new_vertex;
	printf("Aresta criada:  [V%d]--- %d ---> [V%d]\n", src_vertex, cost, dest_vertex);
	grafo->edges_qnt ++;
		
	return 1;
}

void print_graph(Graph *grafo){
	Vertex *current_vertex = grafo->vertexes;
	while(current_vertex != NULL){
		printf("[V%d]", current_vertex->vertex_number);
		Node *current_node = current_vertex->head;
		while(current_node != NULL && current_node->next != NULL){
			printf("--%d->[V%d]", current_node->cost, current_node->vertex_number);
			current_node = current_node->next;
		}
		if(current_node != NULL){
			printf("--%d->[V%d]", current_node->cost, current_node->vertex_number);
		}
		printf("\n");
		current_vertex = current_vertex->next;
	}
	printf("\n");
}

void print_graph_adjacency(Graph *grafo){
	Vertex *current_vertex = grafo->vertexes;
	while(current_vertex != NULL){
		printf("[V%d]", current_vertex->vertex_number);
		Node *current_node = current_vertex->head;
		while(current_node != NULL && current_node->next != NULL){
			printf("-->[V%d]",  current_node->vertex_number);
			current_node = current_node->next;
		}
		if(current_node != NULL){
			printf("-->[V%d]", current_node->vertex_number);
		}
		printf("\n");
		current_vertex = current_vertex->next;
	}
	printf("\n");
}

int breadth_first_search(Graph *grafo, int vertex, int distance[], int predecessor[]){
	Vertex *current_vertex;
	Node *current_node;
	List *queue;
	int i = 3, j = grafo->vertex_qnt;
	int bfs[i][j]; // [0] - Cor // [1] - distancia // [2] - predecessor
	
	for(j = 0; j < grafo->vertex_qnt; j++){
		bfs[0][j] = 0; // 0 - branco // 1 - cinza // 2 - preto
		bfs[1][j] = -1;
		bfs[2][j] = 0;
	}
	
	current_vertex = grafo->vertexes;
	while(current_vertex->vertex_number != vertex && current_vertex->next != NULL){ current_vertex = current_vertex->next; }
	if(current_vertex->head == NULL){
		bfs[1][current_vertex->vertex_number] = 0;
		for(j = 0; j < grafo->vertex_qnt; j++){
			printf("[V%d] - distância %d\n", j, bfs[1][j]);
			distance[j] = bfs[1][j];
			predecessor[j] = -1;
		}
		return -1;
	}
	
	current_node = current_vertex->head;
	bfs[0][current_vertex->vertex_number] = 1; // cinza
	bfs[1][current_vertex->vertex_number] = 0; // origem
	
	queue = init_list();
	push(queue, current_vertex->vertex_number);
	
	while(queue->start != NULL){
		if(bfs[0][current_node->vertex_number] == 0 && current_node->cost > 0){
			bfs[0][current_node->vertex_number] = 1; // cinza
			bfs[1][current_node->vertex_number] = bfs[1][current_vertex->vertex_number] + current_node->cost;
			bfs[2][current_node->vertex_number] = current_vertex->vertex_number;
			push(queue, current_node->vertex_number);
		}
		
		if(current_node->next == NULL){
			bfs[0][current_node->vertex_number] = 2; // preto
			unshift(queue);
			current_vertex = grafo->vertexes;
			
			if(queue->start == NULL){ break; }
			
			while(current_vertex->vertex_number != queue->start->vertex_index && current_vertex->next != NULL){ current_vertex = current_vertex->next; }
			if(current_vertex->head == NULL){ break; }
			current_node = current_vertex->head;
		} else{
			current_node = current_node->next;
		}
	}
	
	printf("BUSCA POR LARGURA [V%d]\n\n", vertex);
	for(j = 0; j < grafo->vertex_qnt; j++){
		printf("[V%d] - distância %d\n", j, bfs[1][j]);
		distance[j] = bfs[1][j];
		predecessor[j] = bfs[2][j];
	}
	printf("\n\n");
	
	return 0;
}

int traveling_salesman(Graph *grafo, int src_vertex, int dest_vertex){
	int size = grafo->vertex_qnt, path_size = 0;
	int bfs[3][size];
	int path[size];
	int i = 0;
	
	for(i = 0; i < size; i++){
		path[i] = 0;
	}
	
	breadth_first_search(grafo, src_vertex, bfs[1], bfs[2]);
	
	system("cls");
	printf("CAIXEIRO VIAJANTE [V%d] --> [V%d]!\n\n", src_vertex, dest_vertex);
	if(bfs[1][dest_vertex] == -1){
		printf("Não há caminhos disponíveis para [V%d] --> [V%d]!\n\n", src_vertex, dest_vertex);
		return -1;
	}
	
	int current_vertex = dest_vertex;	
	for(i = 0; i < size; i++){
		if(current_vertex != src_vertex){
			path[i] = bfs[2][current_vertex];
			current_vertex = bfs[2][current_vertex];
			path_size++;
		}
	}
	
	printf("[V%d]", src_vertex);
	for(i = path_size-2; i >= 0; i--){
		printf("-->[V%d]", path[i]);
	}
	printf("-->[V%d]", dest_vertex);
	printf("\n\n");
}

int fill_wooden_house(Graph *grafo){
	insert_edge(grafo, 0, 1, 4);
	insert_edge(grafo, 1, 2, 3);
	insert_edge(grafo, 2, 3, 7);
	insert_edge(grafo, 3, 4, 6);
	insert_edge(grafo, 3, 5, 4);
	insert_edge(grafo, 3, 7, 5);
	insert_edge(grafo, 4, 6, 6);
	insert_edge(grafo, 5, 6, 6);
	insert_edge(grafo, 6, 8, 5);
	insert_edge(grafo, 7, 9, 5);
	insert_edge(grafo, 8, 9, 5);
}


// TESTE ZONE



#define true 1
#define false 0
typedef int bool;

#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2


 void profundida (Graph *grafo)
 {
 	int u;
 	for (u=0;u<grafo->vertexes;u++){
 		int bfs[0][u]= 0;
	 }
 	for(u=0;u<grafo->vertexes; u++){
 		if (int bfs[0][u]= 0)
 		visitaP(grafo,u,cor);
	 }
 
 void visitaP(Graph *grafo, int u, int *cor){
 	
 	int bfs[0][u]= 1;
 	Node *v =  grafo->vertexes[u].cab;
 	while(v){ 
 		if(int bfs[0][v->vertexes]= 0)
 		visitaP(grafo,v->vertexes,cor);
 		v = v->next;
	 }
	
	 int bfs[0][u]= 2; // No codigo original tava vermelho mas eu botei preto
 }
 
 	
 }

#endif
