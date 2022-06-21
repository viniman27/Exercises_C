#include <stdio.h>
#include <stdlib.h>


void swap(int *lista, int posicao, int posicao2);
void InsercaoSortSimples(int *lista, int tamanho);

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

    InsercaoSortSimples(lista, i);

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


void InsercaoSortSimples(int *lista, int tamanho){

    int i, j, temp;

    for(i = 1; i < tamanho; i ++) {

        if(lista[i] < lista[i - 1]) {

            swap(lista, i, i - 1);
            temp = i - 1;

            for(j = i - 2; j >= 0; j --) {
                if(lista[j] < lista[temp]) {
                    break;
                }
                else if(lista[j] > lista[temp]) {
                    swap(lista, j, temp);
                    temp = j;
                }
            }
        }
    }
}
