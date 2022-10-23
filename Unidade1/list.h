#ifndef LIST_H
#define LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct nd_l {
	int vertex_index;
	struct nd_l *next;
} NodeL;


typedef struct ls{
	NodeL *start;
} List;

NodeL *allocate_node_l(){
	NodeL *n = (NodeL*) malloc(sizeof(NodeL));
	return n;
}

List *init_list(){
	List *lista = (List*) malloc(sizeof(List));
	lista->start = NULL;
	
	return lista;
}

int push(List *list, int vertex_index){
	NodeL *new_node = allocate_node_l();
	new_node->vertex_index = vertex_index;
	new_node->next = NULL;
	
	if(list->start == NULL){ list->start = new_node; return 1; }
	
	NodeL *aux_node = list->start;
	while(aux_node->next != NULL){ aux_node = aux_node->next; }
	aux_node->next = new_node;
	
	return 1;
}

int unshift(List *list){
	NodeL *node = list->start;
	if(node->next != NULL){ list->start = node->next; }
	else{ list->start = NULL; }
	free(node);
	
	return 1;
}

#endif
