#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
	int *dados;
	int N, topo;
} pilha;

int empilha (pilha *p, int x){
	// se a pilha está cheia
	if(p -> topo == p -> N){
		p -> dados = realloc(p -> dados, 2*sizeof(pilha));// Aumenta tamanho da pilha

		if(p -> dados == NULL) return 0;  // erro geralmente corrigido pelo compilador

        (p -> N)*=2; // Dobra o tamanho 
        
    }
	// Pilha não está cheia ou tamanho já realocado
	p -> dados[p -> topo] = x; // Adiciona o item no topo
	p -> topo++; // Topo vai para próxima posição
	return 1;
}