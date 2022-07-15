#include <stdio.h>
#include <stdlib.h>


//macros 
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

//funcoes assinadas

int separa(int *lista,int l, int r);
void quickselect(int *lista, int l, int r, int pagina);
void quicksort(int *lista,int l, int r);

//main 

int main(void){
    int quantProdutos, pagina, quantProdutosPag,i; // quantProdutos = qntd produtos / pagina = pag apresentada / quantProdutosPag = quantidade de produtos por pag

    scanf(" %d %d %d", &quantProdutos, &pagina, &quantProdutosPag);

    int inicio = quantProdutosPag*pagina; // primeiro produto da pag
    int fim = inicio+quantProdutosPag; // ultimo produto da pag -> nao incluso

    if(fim > quantProdutos){
        fim = quantProdutos;
    }

    int *lista = malloc(quantProdutos*sizeof(int));

    for(i = 0; i < quantProdutos; i++){
        scanf(" %d", &lista[i]);
    }

    quickselect(lista, 0, quantProdutos-1, inicio);
    quickselect(lista, inicio+1, quantProdutos-1, fim);

    quicksort(lista, inicio, fim-1);

    for(i = inicio; i < fim; i++){
        printf("%d\n", lista[i]);
    }

    free(lista);

    return 0;
}

//funcoes

int separa(int *lista,int l, int r){
  int auxiliar = lista[r], i, j = l;

  for(i = l; i < r; i++){
    if(less(lista[i], auxiliar)){
      exch(lista[i], lista[j]);
      j++;
    }
  }    
  
  exch(lista[j], lista[r]);

  return j;
}

void quickselect(int *lista, int l, int r, int pagina){
    int j;

    if(r <= l) return;//Caso base

    j = separa(lista, l, r);

    if(j > pagina)
        quickselect(lista, l, j-1, pagina);
    else if(j < pagina)
        quickselect(lista, j+1, r, pagina);
}

void quicksort(int *lista,int l, int r){
  if (l >= r) return; // Caso base

  //Calculo mediana
  cmpexch(lista[(l+r)/2], lista[r]);
  cmpexch(lista[l], lista[(l+r)/2]);
  cmpexch(lista[r], lista[(l+r)/2]);

  int j = separa(lista, l, r);
  quicksort(lista, l, j-1);
  quicksort(lista, j+1, r);
}