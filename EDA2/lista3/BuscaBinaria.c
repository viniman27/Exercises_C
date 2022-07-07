#include <stdio.h>
#include <stdlib.h>

//funcoes assinadas

void buscabinaria(int tamanhoN, int tamanhoM, int *N, int *M, int *posicao);

//main

int main(void){
    int n, m,i;

    scanf(" %d %d", &n, &m);//tamanho vetor de interesse e vetor de numeros a serem pedsquisados

    int *listaN = malloc(n*sizeof(int));
    int *listaM = malloc(m*sizeof(int));
    int *posicao = malloc(m*sizeof(int));

    for( i = 0; i < n; i++){
        scanf(" %d", &listaN[i]);//numeros  que compõem o conposicaounto de dados de interesse de busca
    }

    for(i = 0; i < m; i++){
        scanf(" %d", &listaM[i]);//numeros que devem ser procurados no conposicaounto de dados.
    }

    buscabinaria(n, m, listaN, listaM, posicao);

    for( i = 0; i < m; i++){
        printf("%d \n", posicao[i]);
    }

    return 0;
}

//funcoes

void buscabinaria(int tamanhoN, int tamanhoM, int *N, int *M, int *posicao){

    int m, e, d, i;

    for(i = 0; i < tamanhoM; i++){

        e = -1;
        d = tamanhoN;

        while(e != (d-1)){ // só encontrou o posicao quando e == d-1

            m = (e+d)/2;

            if(M[i] > N[m]){

                e = m; // Se tiver à esquerda de m, o esquerdo vira m 

            } else{

                d = m; // Se tiver à direita de m, o direita vira m

            } 
        }

        posicao[i] = d;
        
    }
}