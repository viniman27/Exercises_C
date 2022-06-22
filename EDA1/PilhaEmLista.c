#include <stdio.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int empilha(celula *p, int x){
  celula *novo = malloc(sizeof(celula)); // Elemento novo a ser adicionado
  if(novo == NULL) return 0; // Não há espaço na memória, geralmente contronado pelo compilador
  novo -> dado = x; // Dado é igual a x
  novo -> prox = p -> prox; // Adiciona depois do inicio da lista
  p -> prox = novo;
  return 1;
}