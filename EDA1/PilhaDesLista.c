#include <stdio.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int desempilha(celula *p, int *y){
  celula *lixo = p -> prox; // O lixo será o elemento que foi removido por último
    if(lixo == NULL) {
        return 0; // Lista vazia
    }
  *y = lixo -> dado; // Y recebe o dado do lixo
  p -> prox = lixo -> prox; // Topo vai apontar para o próximo elemento
  free(lixo);
  return 1;
}