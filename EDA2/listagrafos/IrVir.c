#include <stdio.h>
#include <stdlib.h>


//structs grafos

typedef struct graph
{
    int quantidadeVertices, quantidadeArestas;
    int **matrizAdjacencia;
    int **fechoTransitivo;

} graph;

//funcoes assinadas

int **MATRIXInit(int qtdVertices,int valorDeInicializacao);
graph *G_init(int qtdVertices);
void G_insertEdge(graph *g,int v1, int v2, int d);
void FloydWarshall(graph *g);//algoritmo que encontra o menor caminho entre todos os pares de um grafo numerado, fonte https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

//main

int main() {

  int qtdVertices, numConexoes, i, v1, v2, aresta, j, booleano = 1;

  while(1) {

    scanf(" %d%d", &qtdVertices, &numConexoes);//numero de interseccoes e numero de ruas

    if (qtdVertices == numConexoes && numConexoes == 0)
        break;

    graph *graph = G_init(qtdVertices);

    for(i = 0; i < numConexoes; i ++) {
        scanf(" %d%d%d", &v1, &v2, &aresta);//descricao das ruas
        G_insertEdge(graph, v1 - 1, v2 - 1, aresta);
    }

    FloydWarshall(graph);

    for(i = 0; i < qtdVertices; i ++) {
        for(j = 0; j < qtdVertices; j ++) {
            if(graph->fechoTransitivo[i][j] == 0) {
                booleano = 0;
                break;
            }
        }
        if(booleano == 0)
            break;
    }

    printf("%d\n", booleano);

    booleano = 1;

    free(graph);
  }

  return 0;
}

//funcoes 

int **MATRIXInit(int qtdVertices,int valorDeInicializacao)
{
    int i, j;
    int **matrix = malloc(qtdVertices*sizeof(int*));

    for(i = 0; i<qtdVertices; i++)
        matrix[i] = malloc(qtdVertices*sizeof(int));

    for(i = 0; i<qtdVertices; i++)
        for(j = 0; j<qtdVertices; j++)
            matrix[i][j] = valorDeInicializacao;

    return matrix;
}

graph *G_init(int qtdVertices)
{
    graph *g = malloc(sizeof(graph));
    g->quantidadeVertices = qtdVertices;
    g->quantidadeArestas = 0;
    g->matrizAdjacencia = MATRIXInit(qtdVertices,0);

    return g;
}

void G_insertEdge(graph *g,int v1, int v2, int d)
{
    if(g->matrizAdjacencia[v1][v2] == 0) g->quantidadeArestas++;

    g->matrizAdjacencia[v1][v2] = 1;

    if(d == 2)
      g->matrizAdjacencia[v2][v1] = 1;
}

void FloydWarshall(graph *g)
{
	int i,s,t;
	g->fechoTransitivo = MATRIXInit(g->quantidadeVertices,0);
	for(s = 0; s<g->quantidadeVertices;s++)
		for(t = 0; t< g->quantidadeVertices;t++)
			g->fechoTransitivo[s][t] = g->matrizAdjacencia[s][t];

	for(s = 0; s<g->quantidadeVertices;s++) g->fechoTransitivo[s][s] = 1;

	for(i = 0; i<g->quantidadeVertices;i++)
		for(s = 0;s<g->quantidadeVertices;s++)
			if(g->fechoTransitivo[s][i] == 1)
				for(t = 0; t< g->quantidadeVertices; t++)
					if(g->fechoTransitivo[i][t] == 1)
						g->fechoTransitivo[s][t] = 1;

}

