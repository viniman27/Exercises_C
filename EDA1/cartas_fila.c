#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int dado;
	struct lista *prox;
} lista;

typedef struct fila{
	lista *i;//inicio
	lista *u;//ultima
} fila;

fila *cria_fila(){
	fila *p = (fila*)malloc(sizeof(fila));
	p -> i = NULL;
	p -> u = NULL;
	return p;
}

void *empilha(fila *p, int carta){
	lista *novo = (lista*)malloc(sizeof(lista));
	novo -> dado = carta;
	novo -> prox = NULL;
	if(p -> i == NULL){
		p -> i = novo;
  		p -> u = novo;
 	} else{
  		p -> u ->prox = novo;
  		p -> u = novo;
 	}
}

int desenfileira(fila *p){
	int carta;
	lista *l;

	l = p -> i;
 	carta = l -> dado;

	p -> i = l -> prox;
	if(p -> i == NULL) p -> u = NULL;

	free(l);

	return carta;
}

int vazio(fila *p){
	return p -> i == NULL;
}



int main(){

	int n, i, carta, cont = 0;
	fila *fila;

	fila = cria_fila();

 	scanf(" %d", &n);

  	if(n){
   		cont = n;
   		for(i=1;i<=n;i++){
    		empilha(fila, i);
    	}

		printf("Cartas descartadas:");

		while(cont != 1){  
    		printf(" %d", desenfileira(fila));
    		empilha(fila, desenfileira(fila));
    		if(cont!=2) printf(",");
    		cont--;
    	}
    	if(!vazio(fila)) printf("\nCarta restante: %d\n", desenfileira(fila));
   	}

 return 0;
}



