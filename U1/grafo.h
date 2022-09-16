#ifndef GRAFO_H
#define GRAFO_H

typedef struct adj {
	int vertice;
	int peso;
	struct adj *prox;
} adjacencia;

typedef struct vrtc {
	adjacencia *cab;
} vertice;

typedef struct grf{
	int vertices;
	int arestas;
	vertice *ad;
} grafo;

grafo *criar_grafo(int v){
	int i;
	
	grafo *g = (grafo *)malloc(sizeof(grafo));
	g->vertices = v;
	g->arestas = 0;
	g->ad = (vertice *)malloc(v*sizeof(vertice));
	
	for(i = 0; i < v; i++){
		g->ad[i].cab = NULL;
	}
	return g;
}

int inserir_aresta(grafo *grph, adjacencia *orig, adjacencia *dest, int peso){
	int vertice_temp = 0;
	
	if(grph->ad == null){
		vertice *v == (vertice *)malloc(sizeof(vertice));
		v->cab = orig
		grph->ad = v;
	}
	
	vertice vertice_aux = grph->ad;
	while(orig->vertice != vertice_aux->cab->vertice ){
		vertice_aux = 
	}
	
	else{
		adjacencia node_aux = grph->ad->cab;
		if(node_aux == null){
			node_aux = dest;
			return 0;
		}
		while(node_aux->prox != NULL){
			node_aux = node_aux->prox
		}
		node_aux->prox = dest;
		return 0;
	}
}

#endif
