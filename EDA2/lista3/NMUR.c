#include <stdio.h>
#include <stdlib.h>

//macros 
#define less(A,B) (A < B)
#define lesseq(A,B) (A <= B)

//funcoes assinadas
void merge(int *vetor, int l, int m, int r);
void mergesort(int *vetor, int l, int r);
void intercala(int *v1, int r1, int *v2, int r2);
int removeRepeticao(int *v, int n);
int calculaNumMaluco(int *v, int n);


//main

int main(void){
    int n,i,j;

    scanf(" %d", &n);

    int *v = malloc(sizeof(int) * (2*n));//dobro do tamanho para eventuais adicoes

    for ( i = 0; i < n; i++){
        scanf(" %d", &v[i]);
    }

    mergesort(v, 0, n-1);

    // N é o tamanho do novo vetor
    int tam = removeRepeticao(v, n);

    if(tam % 2 != 0){ // caso tamanho vetor impar faz a adicao
        v[tam++] = 1000000000;
    }

    int novor = calculaNumMaluco(v, tam);

    // Junta o final do vetor (inseridos) com o vetor sem os repetidos
    intercala(v, tam, v + tam, novor); 

    tam = removeRepeticao(v, tam+novor);

    for( i = 0; i <= tam; i+=4){
        printf("%d\n", v[i]);
    }
    
    printf("Elementos: %d\n", tam);

    free(v);
    return 0;    
}

//funcoes

void merge(int *vetor, int l, int m, int r){
    int l1 = l, r1 = m, l1i = l1;
    int l2 = m+1, r2 = r, l2i = l2;

    int *vetAux = malloc((r-l+1)*sizeof(int));
    int vetAuxI = 0;

    int rightvetAuxI = r-l;

    while (l1i <= r1 && l2i <= r2){
        if(lesseq(vetor[l1i], vetor[l2i])){
            vetAux[vetAuxI++] = vetor[l1i++];
        } else{
            vetAux[vetAuxI++] = vetor[l2i++];
        }
    }
    
    while (l1i <= r1){
        vetAux[vetAuxI++] = vetor[l1i++];
    }
    while (l2i <= r2){
        vetAux[vetAuxI++] = vetor[l2i++];
    }
    
    l1i = l;
    for(vetAuxI=0; vetAuxI <= rightvetAuxI; vetAuxI++){
        vetor[l1i++] = vetAux[vetAuxI];
    }

    free(vetAux);
}

void mergesort(int *vetor, int l, int r){
    if (l >= r) return;//caso base

    int meio = (r - l)/2 + l;

    mergesort(vetor, l, meio);
    mergesort(vetor, meio+1, r);
    merge(vetor, l, meio, r); // junta os dois vetores
}

void intercala(int *v1, int r1, int *v2, int r2)//exatamente igual merge, com poucas alteracoes na logica(devido a recepcao de 2 vetores efetivamente, e nao so um dividido) e sintaxe 
{
    int *vetAux = malloc((r1 + r2) * sizeof(int));//tamho do vetor inteiro por seguranca
    int i = 0, j = 0, k = 0;
    for (; i < r1 && j < r2; k++)
    {
        if (v1[i] <= v2[j]){
            vetAux[k] = v1[i++];
        } else{
            vetAux[k] = v2[j++];
        }  
    }

    while (i < r1){
        vetAux[k++] = v1[i++];
    }
    while (j < r2){
        vetAux[k++] = v2[j++];
    }

    k = 0;
    for (i = 0; i < (r1 + r2); i++){
        v1[i] = vetAux[k++];
    }  

    free(vetAux);
}

int removeRepeticao(int *v, int n){
    int j = 1,i;
    
    for (i = 1; i < n; i++){
        if (v[i] != v[j - 1]){
            v[j++] = v[i];
        }
    }

    return j;
}

int calculaNumMaluco(int *v, int n){
    int j = 0,i;
    
    for(i = 0; i < n - 1; i+=2){
        v[n + j++] = v[i] + v[i+1];//calcula de 2 em 2 e adiciona ao final do vetor
    }

    return j;
}

