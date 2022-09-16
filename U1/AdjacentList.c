#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct adjac {
    int vertice;
    int peso;
    struct adjac *prox;
} adjacencia;

typedef struct vrtc {
    adjacencia *cab;
} vertice;

typedef struct grf { 
    int vertices;
    int arestas;
    vertice *adj;
} grafo;

grafo *criar_grafo (int v) {
	int i;
	
	grafo *g = (grafo *)malloc(sizeof(grafo));
	g->vertices = v;
	g->arestas = 0;
	g->adj = (vertice *)malloc(v*sizeof(vertice));
	for (i=0; i<v; i++){ 
		g->adj[i].cab=NULL;
	}
	return(g);
}

adjacencia *criar_adj(int v, int peso){ 
	adjacencia *temp = (adjacencia *) malloc (sizeof(adjacencia));
	temp->vertice =v;
	temp->peso = peso;
	temp->prox = NULL; 
	return(temp);
}

int criar_aresta(grafo *gr, int vi, int vf, int p) {
	if(!gr) return (0);
	if((vf<0)||(vf >= gr->vertices))return(0);
	if((vi<0)||(vf >= gr->vertices))return(0);
	
	adjacencia *novo = criar_adj(vf,p);
	novo->prox = gr->adj[vi].cab;
	gr->adj[vi].cab=novo;
	gr->arestas++;
	return (1);
}

void imprime(grafo *gr){
	
	printf("Vertices: %d. Arestas: %d. \n",gr->vertices,gr->arestas); //imprime numero de vértice e arestas
	int i;
	
	for(i=0; i<gr->vertices; i++){
		printf("v%d: ",i); //Imprimo em qual aresta estou
		adjacencia *ad = gr->adj[i].cab; //chamo a cabeça da lista de adjacencia desta aresta
			while(ad){ //enquanto as adjacencias não forem nula
				printf("v%d(%d) ",ad->vertice,ad->peso); //imprimo a adjacencia e seu peso
				ad=ad->prox; //passo para proxima adjacencia
			}
		printf("\n");	
	}
}

int main(){
	int i, j;
	int vertices;
	
	setlocale(LC_ALL, "Portuguese");
	
	
	
	grafo * gr = criar_grafo(5);
	criar_aresta(gr, 0, 1, 2);
	criar_aresta(gr, 1, 2, 4);
	criar_aresta(gr, 2, 0, 12);
	criar_aresta(gr, 2, 4, 40);
	criar_aresta(gr, 3, 1, 3);
	criar_aresta(gr, 4, 3, 8);
    
    imprime(gr);
	
	return 0;
}
