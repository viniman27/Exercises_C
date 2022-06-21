#include <stdio.h>
#include <stdlib.h>



void bubble_sort(int *lista, int tamanho)
{
    int temp, i, j;
    
    for (i = 0; i < tamanho; i++)
    {
        for (j = i; j < tamanho; j++)
        {
            if (lista[i] > lista[j])
            {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

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

    bubble_sort(lista, i);

    for(j = 0; j < i - 1; j ++)
        printf("%d ", lista[j]);

    printf("%d\n", lista[j]);

    free(lista);

    return 0;
}