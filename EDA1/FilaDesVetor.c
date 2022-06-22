#include <stdio.h>

typedef struct fila {
  int *dados;
  int N, p, u;
} fila;

int desenfileira(fila *f, int *y){
	if(f -> p == f -> u) return 0; // Fila  esta vazia
	*y = f -> dados[f -> p]; // Dado que estava presente no p
	f -> p = (f -> p + 1) % f -> N; // O p vai para a próxima posição
}