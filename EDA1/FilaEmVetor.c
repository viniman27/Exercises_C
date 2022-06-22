#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
  int *dados;
  int N, p, u;
} fila;

int enfileira(fila *f, int x){
  // Caso u e p sejam iguais, o vetor está cheio e deve ser redimensionado
  if((f -> u + 1) % f -> N == f -> p){
    f -> dados = realloc(f -> dados, 2*sizeof(fila)); // Aumenta tamanho da fila

        if(f -> dados == NULL) return 0; // Deu errado
            (f -> N) *= 2; // Dobra o tamanho do tamanho
  }

  f -> dados[f -> u] = x; // Adiciona x
  f -> u = (f -> u + 1) % f->N; // Vai para a próxima posição ou volta para o início
  return 1;
}