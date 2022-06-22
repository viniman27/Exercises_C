#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

//ordenacao por insercao completa

int recMoveinsec (int *v, int i, int elem){
	if(i < 0 || v[i] <= elem) return i;
	v[i+1] = v[i];
	recMoveinsec(v, i-1, elem);
}

void ordenainsec (int *v, int n){

	//Caso Base
	if(n <= 1) return;

	//Redução
	ordenainsec (v, n-1);

	//Insere o elemento v[n-1] na posição correta no subvetor v[0...n-1]
	int elem = v[n-1];
	int i = recMoveinsec(v, n-2, elem);
	v[i+1] = elem;
}

//fim da ordenacao por insercao completa

void mescla_listas (celula *l1, celula *l2, celula *l3){
	int novacelula[1000];
	int i = 0;


    //compoe um novo vetor com os dadosda lista encabecada por l1 e l12
	for(celula *p = l1 -> prox; p != NULL; p = p -> prox){
		novacelula[i] = p -> dado;
		i++;
	}
	for(celula *q = l2 -> prox; q != NULL; q = q -> prox){
		novacelula[i] = q -> dado;
		i++;
	}

    //ordena nova lista por insercao
	ordenainsec(novacelula, i);

     int j = i-1;

	while(j >= 0){
		// Aloca espaco para nos na lista 3
		celula *novo = malloc(sizeof(celula));
		// Salva o dado
		novo -> dado = novacelula[j];
		// Pluga na lista
		novo -> prox = l3 -> prox;
		l3 -> prox = novo;
		j--;
	}
}