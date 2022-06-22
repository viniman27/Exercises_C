#include <stdio.h>

typedef struct pilha {
	int *dados;
	int N, topo;
} pilha;

int desempilha(pilha *p, int *y){
	if(p -> topo == 0) return 0; // Pilha vazia, entao retorna 0
	p -> topo--; // Diminui o tamanho do tamanho
	*y = p -> dados[p -> topo]; // Salva o elemento que estava no topo
	return 1;
}