//dessa vez , novamente :), tentativa de grafo por matriz de adjacencia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//globais

int componentesVisitados[5001];
int hash[5001];
char criaturas[5001][32];

// Structs do grafo
typedef struct graph{
    int V;
    int E;
    int **adj;
} graph;

typedef struct Edge{
    int u;
    int w;
} Edge;

//funcoes assinadas

Edge EDGE(int u, int w);
int **MATRIXinit(int V, int init);
graph *G_Init(int V);
void G_insert(graph *G, Edge e);
void G_DFS(graph *G, int start);
void initVetores(int c);

//main

int main(){

    int c, r,i;//numero de criaturas e relacoes

    while(scanf(" %d %d", &c, &r)==2)
    {

    if (c == 0 && r == 0){
        break;
    }

    initVetores(c);

    for (i = 0; i < c; i++){
        scanf(" %s", criaturas[i]);//compoe criaturas
    }
        
    graph *G = G_Init(c);

    for (i = 0; i < r; i++){

        char criatura1[32], criatura2[32];

        scanf(" %s %s", criatura1, criatura2);//compoe relacoes
        
        int ai = -1, bi = -1, j = 0;//verificam se eh "predador" a partir da ideia de componentes visitados

        while(j < c && (ai == -1 || bi == -1)){
            
            if (ai == -1 && strcmp(criaturas[j], criatura1) == 0){
                ai = j;
            } else if (bi == -1 && strcmp(criaturas[j], criatura2) == 0){
                bi = j;
            }

            j++;
        }

        Edge E = EDGE(bi, ai);

        G_insert(G, E);
    }

    for (i = 0; i < c; i++){
        G_DFS(G, i);
    }
        
    for (i = 0; i < G->V; i++)
        free(G->adj[i]);
    free(G->adj);

    int resposta = 0;

    for (i = 0; i < c; i++){
        if (++hash[componentesVisitados[i]] > resposta){
            resposta = hash[componentesVisitados[i]];
        }
    }    

    printf("%d\n", resposta);

    }

    return 0;
}

//funcoes

Edge EDGE(int u, int w){
    return (Edge){u, w};
}


int **MATRIXinit(int V, int init){
    int **matrix = malloc(V*sizeof(int*));
    int i,j;

    for(i = 0; i < V; i++){
        matrix[i] = malloc(V*sizeof(int));
    }

    for(i = 0; i < V; i++){
        for(j = 0; j < V; j++){
            matrix[i][j] = init;
        }
    }

    return matrix;
}


graph *G_Init(int V){

    graph *g = malloc(sizeof(graph));
    
    g->V = V;
    g->E = 0;
    g->adj = MATRIXinit(V, 0);

    return g;
}


void G_insert(graph *G, Edge e){
    int u = e.u, w = e.w;

    if(G->adj[u][w] == 0){
        G->E++;
    }

    G->adj[u][w] = 1;
    G->adj[w][u] = 1;

    return;
}

void G_DFS(graph *G, int start){

    if (componentesVisitados[start] < 0)
        componentesVisitados[start] = start;
    for (unsigned i = 0; i < G->V; i++)
        if (G->adj[start][i] != 0 && componentesVisitados[i] < 0)
        {
            int mn = ((int)i < componentesVisitados[start] ? (int)i : componentesVisitados[start]);
            componentesVisitados[start] = mn;
            componentesVisitados[i] = mn;
            G_DFS(G, i);
        }
        
    return;
}

void initVetores(int c){
    
    int i;

    for( i = 0; i < c; i++){
        componentesVisitados[i] = -1;
    }

    for( i = 0; i < c; i++){
        hash[i] = 0;
    }

    return;
}

