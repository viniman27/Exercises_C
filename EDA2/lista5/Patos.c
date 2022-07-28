#include <stdio.h>
#include <stdlib.h>

//macros

#define key(A) (A)
#define lessq(A,B) (key(A) <= key(B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}


//funcoes assinadas

void merge(int *listaCodCor, int e, int m, int d);
void mergeSort(int *listaCodCor, int e, int d);
void CorMajoritaria(int *listaCodCor, int numeroPatos);

//main

int main()
{
    int numeroPatos, i;

    scanf(" %d", &numeroPatos);//numero de patos observados

    while(numeroPatos != 0) {
        int *listaCodCor = malloc(numeroPatos * sizeof(int));

        for(i = 0; i < numeroPatos; i ++) {

            scanf(" %d", &listaCodCor[i]);//armazena ccodigos das cores

        }

        mergeSort(listaCodCor, 0, numeroPatos - 1);

        CorMajoritaria(listaCodCor, numeroPatos);

        free(listaCodCor);

        scanf(" %d", &numeroPatos);//proxima linha
    }

    return 0;
}

//funcoes

void merge(int *listaCodCor, int e, int m, int d) {
    int *auxiliar = malloc((d - e + 1) * sizeof(int));
    int i = e, j = m + 1, k = 0;

    while(i <= m && j <= d) {
        if(lessq(listaCodCor[i], listaCodCor[j]))
            auxiliar[k++] = listaCodCor[i++];
        else
            auxiliar[k++] = listaCodCor[j++];
    }

    while(i <= m)
        auxiliar[k++] = listaCodCor[i++];

    while(j <= d)
        auxiliar[k++] = listaCodCor[j++];

    k = 0;

    for(i = e; i <= d; i ++)
        listaCodCor[i] = auxiliar[k++];

    free(auxiliar);
}


void mergeSort(int *listaCodCor, int e, int d) {
    if(e >= d) return;//caso base

    mergeSort(listaCodCor, e, (e+d)/2);
    mergeSort(listaCodCor, ((e+d)/2) + 1, d);
    merge(listaCodCor, e, (e+d)/2, d);
}

void CorMajoritaria(int *listaCodCor, int numeroPatos) {
    int i, rep = 0, auxiliar = 0;

    for(i = 0; i < numeroPatos; i ++) {
        if(auxiliar == 0) {
            rep = listaCodCor[i];
            auxiliar ++;
        }
        else if(rep == listaCodCor[i]) {
            auxiliar ++;
        } else
            auxiliar --;
    }

    printf("%d\n", rep);
}