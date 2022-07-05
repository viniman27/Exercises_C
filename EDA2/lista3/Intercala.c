#include <stdio.h>
#include <stdlib.h>

//macros

#define less(A,B) (A < B)

//funcoes assinadas

void merge(int *vetor, int l, int m, int r);
void mergesort(int *vetor, int l, int r);

//main
int main(void){

    int tam, aux = 0, r = 51,j,i;
    int *v = malloc(r*sizeof(int));

    // Leitura do vetor
    for(i = 0; i < 8; i++){

        scanf(" %d", &tam);

        for (j = 0; j < tam; j++){

            if(aux == r-1){//caso ultrapasse o tamanho do vetor que esta sendo incrementado

                r = r*2;
                v = realloc(v, r*sizeof(int));

            }

            int valor;
           scanf(" %d", &v[aux++]);

        }
    }

    mergesort(v, 0, aux-1);

    for (i = 0; i < aux; i++){

        printf("%d ", v[i]);

    }

    free(v);
    
}

//funcoes

void merge(int *vetor, int l, int m, int r){

    int l1 = l, r1 = m, l1i = l1;
    int l2 = m+1, r2 = r, l2i = l2;

    int *c = malloc((r-l+1)*sizeof(int));
    int ci = 0;

    int rc = r-l;

    while (l1i <= r1 && l2i <= r2){
        if(less(vetor[l1i], vetor[l2i])){
            c[ci++] = vetor[l1i++];
        } else{
            c[ci++] = vetor[l2i++];
        }
    }
    
    while (l1i <= r1){
        c[ci++] = vetor[l1i++];
    }
    while (l2i <= r2){
        c[ci++] = vetor[l2i++];
    }
    
    l1i = l;
    for(ci=0; ci <= rc; ci++){
        vetor[l1i++] = c[ci];
    }

    free(c);
}

void mergesort(int *vetor, int l, int r){

    if (l >= r) return;//caso base

    int meio = (r - l)/2 + l;

    mergesort(vetor, l, meio);//ordena 1 metade
    mergesort(vetor, meio+1, r);//ordena 2 metade
    merge(vetor, l, meio, r); // intercala os dois vetores

}
