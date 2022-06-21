#include <stdio.h>

void InsercaoSortFast(int *lista, int cont);

int main()
{
    int *lista, i = 0, tamanho = 10, j;
    lista = malloc(tamanho * sizeof(int));

    while(scanf(" %d", &lista[i]) != -1) {
        if(i == tamanho - 1) {
            tamanho = tamanho * 2;
            lista = realloc(lista, tamanho * sizeof(int));
        }
        i ++;
    }

    InsercaoSortFast(lista, i);

    for(j = 0; j < i - 1; j ++)
        printf("%d ", lista[j]);

    printf("%d\n", lista[j]);

    free(lista);

    return 0;
}

void InsercaoSortFast(int *lista, int cont){
    int i;

    if(cont<=1) return 0;//caso base

    InsercaoSortFast(lista,cont-1);//reducao

//insere o elemento na posicao correta do sublista
    int elem = lista[cont-1];

    for(i= cont-2 ; i>=0 && lista[i]>elem;i--)
        lista[i+1]=lista[i];
        lista[i+1]=elem;
}
