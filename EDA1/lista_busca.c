#include <stdio.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

celula *busca (celula *le, int x){
	celula *p;
	for(p = le -> prox; p != NULL && p -> dado != x; p = p -> prox); // Busca e para quando achar o x inserido pelo usuario
	return p; // Retorna endereço de memória ou NULL caso seja o ultimo no
}

celula *busca_rec (celula *le, int x){
	if (le -> prox == NULL) return NULL; // Tem que ter certeza que o prox não é NULL (acessar um nó que está alocado)
	if (le -> prox -> dado == x) return le -> prox;
	else{
		return busca_rec(le -> prox, x); // Avança um nó e busca de novo
	}
}