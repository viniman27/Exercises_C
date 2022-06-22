#include <stdio.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

void imprime (celula *le){
    celula *p;
	for(p = le -> prox; p != NULL; p = p -> prox){ // Correr toda a lista encadeada
		printf("%d -> ", p -> dado);
	}
	printf("NULL\n");
}

void imprime_rec (celula *le){
    celula *p;
	if(le -> prox == NULL) printf("NULL\n"); // Final da lista
	else{
		p = le -> prox;
		printf("%d -> ", p -> dado);
		imprime_rec(p);
	}
}