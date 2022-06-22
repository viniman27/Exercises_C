#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;


//y eh o elemento que deve ser buscado para a insercao na posicao anterior


void insere_inicio (celula *le, int x){
	// Aloca o novo no na lista
	celula *novo = malloc(sizeof(celula));
	// Salvar o x inserido pelo usuario
	novo -> dado = x;
	// Pluga na lista
	novo -> prox = le -> prox;
	le -> prox = novo;
}

void insere_antes (celula *le, int x, int y){
	// Aloca o novo no na lista
	celula *novo = malloc(sizeof(celula));
	// Salvar o x
	novo -> dado = x;

	// Cabeça da lista
	celula *q = le -> prox;

	// Busca por y e vai fazendo passando "q" para prox
	while(q != NULL && q -> dado != y){
		le = q;
		q = q -> prox;
	}

	// Pluga na lista
	novo -> prox = q;
	le -> prox = novo;
}