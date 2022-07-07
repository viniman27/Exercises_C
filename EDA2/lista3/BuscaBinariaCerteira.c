#include <stdio.h>
#include <stdlib.h>

//macros 

#define less(A,B) (A < B)

//funcoes assinadas

void merge(int *listaN, int *posicao, int e, int m, int d);
void mergesort(int *listaN, int *posicao, int l, int r);
void buscaBinaria (int *listaN, int *posicao, int r, int numBusca);


//main 

int main(void){
    int n, m, i, numBusca;

    scanf(" %d %d", &n, &m);

    int *listaN = malloc(n * sizeof(int));
    int *posicao = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf(" %d", &listaN[i]);
        posicao[i] = i;
    }

    mergesort(listaN, posicao, 0, n-1);//ordena o vetor listaN para uma busca efetiva

    for(i = 0; i < m; i++){
        scanf(" %d", &numBusca);
        buscaBinaria(listaN, posicao, n, numBusca);
    }

    free(listaN);
    free(posicao);

    return 0;
}

//funcoes

void merge(int *listaN, int *posicao, int e, int m, int d) {
    int *auxiliar = malloc((d - e + 1) * sizeof(int)), *auxP = malloc((d - e + 1) * sizeof(int));
    int i = e, j = m + 1, k = 0;

    while(i <= m && j <= d) {
        if(less(listaN[i], listaN[j])) {
            auxP[k] = posicao[i];
            auxiliar[k++] = listaN[i++];
        }
        else {
            auxP[k] = posicao[j];
            auxiliar[k++] = listaN[j++];
        }
    }

    while(i <= m) {
        auxP[k] = posicao[i];
        auxiliar[k++] = listaN[i++];
    }

    while(j <= d) {
        auxP[k] = posicao[j];
        auxiliar[k++] = listaN[j++];
    }

    k = 0;

    for(i = e; i <= d; i ++) {
        posicao[i] = auxP[k];
        listaN[i] = auxiliar[k++];
    }

    free(auxiliar);
    free(auxP);
}

void mergesort(int *listaN, int *posicao, int l, int r){
    if (l >= r) return; //caso base
    int meio = (r - l)/2 + l;
    mergesort(listaN, posicao, l, meio);
    mergesort(listaN, posicao, meio+1, r);
    merge(listaN, posicao, l, meio, r); // junta os dois listaNes
}

void buscaBinaria (int *listaN, int *posicao, int r, int numBusca) {
    int e = -1, d = r, m;

    while (e < d - 1) {
        m = (e + d)/2;

        if (listaN[m] < numBusca){
            e = m;
        } else{
            d = m;
        } 
    }

    if(listaN[d] == numBusca){
        printf("%d\n", posicao[d]);
    } else{
        printf("%d\n", -1);
    }
}









