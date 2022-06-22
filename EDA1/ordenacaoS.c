#include <stdio.h>

void ordenacaoinsecFast(int *lista, int cont);

int main(){

 int t,cont,j,lista[1000];
 cont=0;

    while(scanf("%d",&t) != EOF){
        lista[cont]=t;
        cont++;
    }

   ordenacaoinsec(lista,cont);

    for(j=0;j<(cont);j++){
        printf("%d",lista[j]);
    }

}

void ordenacaoinsec(int *lista, int cont){
    int i;

    if(cont<=1) return;//caso base

    ordenacaoinsec(lista,cont-1);//reducao

//insere o elemento na posicao correta do sublista
    int elem = lista[cont-1];

    for(i= cont-2 ; i>=0 && lista[i]>elem;i--)
        lista[i+1]=lista[i];
        lista[i+1]=elem;
}
