#include <stdio.h>
#include <stdlib.h>

//macros 

#define key(A) (A)
#define lessq(A,B) (key(A) <= key(B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

//struct para armazenar respectivos  o tamanho da sequência; o caractere da sequência, e; a posição que o caractere começou na string S original

typedef struct Item {
    int tamanho;
    char letra[1];
    int posicao;
} Item;


//funcoes assinadas 

void merge(Item dadosStr[], int e, int m, int d);
void mergeSort(Item dadosStr[], int e, int d);
void separaDados(char str[], Item dadosStr[]);

//main

int main()
{
    char str[100001];
    Item dadosStr[100001];

    scanf(" %s", str);

    separaDados(str, dadosStr);

    return 0;
}


//funcoes

void merge(Item dadosStr[100000], int e, int m, int d) {
    
    Item *listaAuxiliar = malloc((d - e + 1) * sizeof(Item));
    int i = e, j = m + 1, listaAuxiliari = 0;

    while(i <= m && j <= d) {
        if(lessq(dadosStr[i].tamanho, dadosStr[j].tamanho)) {
            listaAuxiliar[listaAuxiliari].letra[0] = dadosStr[i].letra[0];
            listaAuxiliar[listaAuxiliari].posicao = dadosStr[i].posicao;
            listaAuxiliar[listaAuxiliari++].tamanho = dadosStr[i++].tamanho;
        } else {
            listaAuxiliar[listaAuxiliari].letra[0] = dadosStr[j].letra[0];
            listaAuxiliar[listaAuxiliari].posicao = dadosStr[j].posicao;
            listaAuxiliar[listaAuxiliari++].tamanho = dadosStr[j++].tamanho;
        }
    }

    while(i <= m) {
        listaAuxiliar[listaAuxiliari].letra[0] = dadosStr[i].letra[0];
        listaAuxiliar[listaAuxiliari].posicao = dadosStr[i].posicao;
        listaAuxiliar[listaAuxiliari++].tamanho = dadosStr[i++].tamanho;
    }

    while(j <= d) {
        listaAuxiliar[listaAuxiliari].letra[0] = dadosStr[j].letra[0];
        listaAuxiliar[listaAuxiliari].posicao = dadosStr[j].posicao;
        listaAuxiliar[listaAuxiliari++].tamanho = dadosStr[j++].tamanho;
    }

    listaAuxiliari = 0;

    for(i = e; i <= d; i ++) {
        dadosStr[i].letra[0] = listaAuxiliar[listaAuxiliari].letra[0];
        dadosStr[i].posicao = listaAuxiliar[listaAuxiliari].posicao;
        dadosStr[i].tamanho = listaAuxiliar[listaAuxiliari++].tamanho;
    }

    free(listaAuxiliar);
}


void mergeSort(Item dadosStr[100000], int e, int d) {
    if(e >= d) return;//caso base

    mergeSort(dadosStr, e, (e+d)/2);
    mergeSort(dadosStr, ((e+d)/2) + 1, d);
    merge(dadosStr, e, (e+d)/2, d);
}

void separaDados(char str[100000], Item dadosStr[100000]) {
    int i, listaAuxiliari = 0, fim,j;

    dadosStr[0].letra[0] = str[0];
    dadosStr[0].tamanho = 1;
    dadosStr[0].posicao = 0;

    for(i = 1; str[i] != '\0'; i ++) {//compara e verifica caracteres iguais ininterruptos 
        if(str[i] != dadosStr[listaAuxiliari].letra[0]) {
            listaAuxiliari ++;
            dadosStr[listaAuxiliari].letra[0] = str[i];
            dadosStr[listaAuxiliari].posicao = i;
            dadosStr[listaAuxiliari].tamanho = 1;
        } else {
            dadosStr[listaAuxiliari].tamanho ++;
        }
    }

    mergeSort(dadosStr, 0, listaAuxiliari);//ordena os caracteres iguais juntos 
    
    fim = listaAuxiliari;

    for(i = listaAuxiliari; i >= 0; i --) {//comeca do final como forma mais facil de garantir caracteres iguas ininterruptos

        if(dadosStr[i].tamanho != dadosStr[i-1].tamanho) {//continua ate caracteres diferentes

            for(j = i; j <= fim; j ++){
                printf("%d %c %d\n", dadosStr[j].tamanho, dadosStr[j].letra[0], dadosStr[j].posicao);
            }

            fim = i - 1;//define novo limite para evitar erro

        } else if(i == 0){//ao chegar a 1 posicao, ir ate o limite atual , garantido na linha 122, assegura uma sequencia q n se repete

            for(j = 0; j <= fim; j ++){
                printf("%d %c %d\n", dadosStr[j].tamanho, dadosStr[j].letra[0], dadosStr[j].posicao);
            }
        }
    }
}
