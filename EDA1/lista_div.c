#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2){

     celula *p;
	int par[1000], imp[1000], indPar = 0, indImp = 0;


    //verifica na lista encabecada por l se o elemento do indice atual e par ou impar
	for(p = l -> prox; p != NULL; p = p -> prox){
		if(p -> dado % 2 == 0){ // verificacao se e par ou impar
			par[indPar] = p -> dado;
			indPar++;
		} else{
			imp[indImp] = p -> dado;
			indImp++;
		}
	}

	// lista encabecada por l2 com pares
	for(int i = indPar - 1; i >= 0; i--){
		celula *novo = malloc(sizeof(celula));
		novo -> dado = par[i];
		novo -> prox = l2 -> prox;
		l2 -> prox = novo;
	}

	//  lista encabecada por l1 com impares
	for(int i = indImp - 1; i >= 0; i--){
		celula *novo = malloc(sizeof(celula));
		novo -> dado = imp[i];
		novo -> prox = l1 -> prox;
		l1 -> prox = novo;
	}

}