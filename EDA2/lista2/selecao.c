#include <stdio.h>
#include <stdlib.h>

void swap(int *lista, int posicao, int posicao2);
void SelectionSort(int *lista, int tamanho);


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

    SelectionSort(lista, i);

    for(j = 0; j < i - 1; j ++)
        printf("%d ", lista[j]);

    printf("%d\n", lista[j]);

    free(lista);

    return 0;
}

void swap(int *lista, int posicao, int posicao2) {
    int temp;
    temp = lista[posicao];
    lista[posicao] = lista[posicao2];
    lista[posicao2] = temp;
}

void SelectionSort(int *lista, int tamanho){

    int i, menor, j;

    for(i = 0; i < tamanho - 1; i ++) {
        
        menor = i;

        for(j = i + 1; j < tamanho; j ++)
            if(lista[j] < lista[menor]) {
                menor = j;
            }
        if(i != menor)
            swap(lista, i, menor);
    }

}