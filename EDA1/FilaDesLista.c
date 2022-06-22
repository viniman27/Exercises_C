#include <stdio.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

int desenfileira(celula *f, int *y){
	celula *lixo = f -> prox; //O lixo será o elemento que está depois do nó cabeça
	if(lixo == NULL) return 0; // fila vazia
	*y = lixo -> dado; // O dado a ser retirado é salvo em y
	f -> prox = lixo -> prox; // Passa o cabeço para o próximo
	free(lixo);
	return 1;
}