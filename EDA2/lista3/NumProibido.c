#include <stdio.h>
#include <stdlib.h>

//macros 

#define less(A,B) (A < B)

//funcoes assinadas
void merge(int *listaProibidos, int l, int m, int r);
void mergesort(int *listaProibidos, int l, int r);
void buscaBinaria(int *listaProibidos, int r, int numprocurado);

//main

int main(void){
    int n, numprocurado;

    scanf(" %d", &n);

    int *listaProibidos = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf(" %d", &listaProibidos[i]);
    }

    mergesort(listaProibidos, 0, n-1);

    while (scanf(" %d", &numprocurado) != EOF){
        buscaBinaria(listaProibidos, n-1, numprocurado);
    }
}

//funcoes

void merge(int *listaProibidos, int l, int m, int r){
    int l1 = l, r1 = m, l1i = l1;
    int l2 = m+1, r2 = r, l2i = l2;

    int *listaauxiliar = malloc((r-l+1)*sizeof(int));
    int AUXi = 0;

    int rc = r-l;

    while (l1i <= r1 && l2i <= r2){
        if(less(listaProibidos[l1i], listaProibidos[l2i])){
            listaauxiliar[AUXi++] = listaProibidos[l1i++];
        } else{
            listaauxiliar[AUXi++] = listaProibidos[l2i++];
        }
    }
    
    while (l1i <= r1){
        listaauxiliar[AUXi++] = listaProibidos[l1i++];
    }
    while (l2i <= r2){
        listaauxiliar[AUXi++] = listaProibidos[l2i++];
    }
    
    l1i = l;
    for(AUXi=0; AUXi <= rc; AUXi++){
        listaProibidos[l1i++] = listaauxiliar[AUXi];
    }

    free(listaauxiliar);
}

void mergesort(int *listaProibidos, int l, int r){
    if (l >= r) return;//caso base
    int meio = (r - l)/2 + l;
    mergesort(listaProibidos, l, meio);
    mergesort(listaProibidos, meio+1, r);
    merge(listaProibidos, l, meio, r); // junta os dois vetores
}


void buscaBinaria(int *listaProibidos, int r, int numprocurado) {
    int e = -1, d = r, m;

    while (e < d - 1) {
        m = (e + d)/2;

        if (listaProibidos[m] < numprocurado){
            e = m;
        } else{
            d = m;
        } 
    }

    if(listaProibidos[d] == numprocurado){
        printf("sim\n");
    } else{
        printf("nao\n");
    }
}