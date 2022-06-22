#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;


celula *enfileira (celula *f, int x){
    
    celula *novo = malloc(sizeof(celula));
    novo->prox = f->prox;
    f->prox = novo;
    f->dado=x;
    f=novo; 

return novo;
}