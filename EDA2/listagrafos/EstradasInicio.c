#include <stdio.h>
#include <stdlib.h>

//macros

#define GRAPH_WEIGHT_TYPE int
#define GRAPH_WEIGHT_SUM(a, b) (a + b)
#define GRAPH_WEIGHT_LESS(a, b) (a < b)
#define GRAPH_WEIGHT_INF 2147483647 //Teoricamente um valor qualquer de iniciacao que compoe o grafo

//structs para definicao completa do grafo

typedef struct
{
    unsigned from, to;//de onde e para onde, auxilio https://www.techiedelight.com/implement-graph-data-structure-c/. Salvo engano, prof usou 'v' e 'w' nessa representacao
    GRAPH_WEIGHT_TYPE weight;
} Edge;

typedef struct
{
    GRAPH_WEIGHT_TYPE **edges;//aresta
    unsigned vertices;
} Graph;

//funcoes assinadas

Graph G_init(unsigned vertices);//inicia grafo
void G_free(Graph g);//libera uma posicao do grafo
void G_insert(Graph *g, Edge e);//insere um elemento no grafo
void G_dfs(Graph g, int inicio, int visitados[]);//busca em profundidade-recursiva

//globais

int vi[5001];//vetor auxiliar para garantir a busca sem repeticao

//main

int main()
{
    int v,i,from, to;

    scanf(" %d", &v);//a quantidade de cidades existentes em Nlogônia

    Graph g = G_init(v);

    while(scanf(" %d %d", &from, &to) == 2)
    {
        G_insert(&g, (Edge){.from = from, .to = to});
        G_insert(&g, (Edge){.from = to, .to = from});
    }

    int resposta = 0;

    for (i = 0; i < v; i++)

        if (!vi[i])
        {
            G_dfs(g, i, vi);
            resposta++;
        }

    printf("%d\n", resposta);

    G_free(g);

    return 0;
}

//funcoes

Graph G_init(unsigned vertices)
{
    Graph g = {.vertices = vertices};
    g.edges = malloc(sizeof(GRAPH_WEIGHT_TYPE *) * g.vertices);
    for (unsigned i = 0; i < g.vertices; i++)
    {
        g.edges[i] = malloc(sizeof(GRAPH_WEIGHT_TYPE) * g.vertices);
        for (unsigned j = 0; j < g.vertices; j++)
            g.edges[i][j] = GRAPH_WEIGHT_INF;
    }
    return g;
}

void G_free(Graph g)
{
    for (unsigned i = 0; i < g.vertices; i++)
        free(g.edges[i]);
    free(g.edges);
}

void G_insert(Graph *g, Edge e)
{
    if (e.from > g->vertices || e.to > g->vertices)
        return;

    g->edges[e.from][e.to] = e.weight;
}

void G_dfs(Graph g, int inicio, int visitados[])
{
    visitados[inicio] = 1;
    for (unsigned i = 0; i < g.vertices; i++)
        if (g.edges[inicio][i] != GRAPH_WEIGHT_INF && !visitados[i])
            G_dfs(g, i, visitados);
}