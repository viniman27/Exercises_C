#include <stdio.h>
#include <stdlib.h>

//macros

#define key(A)(A.key)
#define less(A,B) (key(A) < key(B))
#define exch(A, B) {instrucao t = B; B = A; A = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}

//estruturas

typedef struct instrucao
{
    int key;
    char inst[16];
} instrucao;


//assinatura funcoes
void insertionsortfast(instrucao *vetor, int l, int r);
void BinarySearch(instrucao *vetor, int l, int r, int codigo);


//main
int main(void){
    int n, codigo,i;

    scanf(" %d", &n);

    instrucao *instrucoes = malloc(n*sizeof(instrucao));

    for ( i = 0; i < n; i++){
        scanf(" %d %s", &instrucoes[i].key, &instrucoes[i].inst);
    }
    
    insertionsortfast(instrucoes, 0, n-1);

    while(scanf(" %d", &codigo) != EOF){
        BinarySearch(instrucoes, 0, n-1, codigo);
    }

    free(instrucoes);

    return 0;
}


//funcoes 

void insertionsortfast(instrucao *vetor, int l, int r){
    int i;

    for( i = r; i > l; i--){
        if(less(vetor[i], vetor[i-1])){
            exch(vetor[i], vetor[i-1])
        }
    }
    for( i = l+1; i <= r; i++){

        int j = i - 1;
        instrucao tmp = vetor[j + 1]; 

        while(less(tmp, vetor[j])){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = tmp;
    }
}

void BinarySearch(instrucao *vetor, int l, int r, int codigo){
    while (l <= r)
    {
        int meio = (l + r) / 2;

        if (key(vetor[meio]) == codigo){
            printf("%s\n", vetor[meio].inst);
            return;
        }   

        if (key(vetor[meio]) > codigo){
            r = meio - 1;
        }else{
            l = meio + 1;
        }
    }

    printf("undefined\n"); // Instrução não registrada
    return;
}