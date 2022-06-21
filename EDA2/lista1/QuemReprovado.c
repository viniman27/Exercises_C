#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void VerifOrdem(char nome[101][21], int auxiliariliar[101], int limite);
void VerifReprovado(int numeroPessoas, char nome[101][21], int numeroProblemas[101]);


int main()
{
    int numeroPessoas;
    int numeroProblemas[101];
    char nome[101][21];
    int i = 0, j = 1;

    while(scanf(" %d", &numeroPessoas) != EOF) {
        for (i = 0; i < numeroPessoas; i ++)
            if(scanf(" %s", nome[i]) == EOF || scanf(" %d",&numeroProblemas[i]) == EOF)
                return 0;
        printf("Instancia %d\n", j);
        VerifReprovado(numeroPessoas, nome, numeroProblemas);
        printf("\n");
        j ++;
    }

    return 0;
}

void VerifOrdem(char nome[101][21], int auxiliariliar[101], int limite) {
    int i = 0, j;
    while(auxiliariliar[i] < auxiliariliar[limite]) {
        for(j = 0; nome[auxiliariliar[i]][j] != '\0'; j ++) {
            if(nome[auxiliariliar[i + 1]][j] == '\0') {
                strcpy(nome[auxiliariliar[i + 1]], nome[auxiliariliar[i]]);
                break;
            }
            else if(nome[auxiliariliar[i]][j] > nome[auxiliariliar[i + 1]][j]) {
                strcpy(nome[auxiliariliar[i + 1]], nome[auxiliariliar[i]]);
                break;
            }
            else if(nome[auxiliariliar[i]][j] == nome[auxiliariliar[i + 1]][j]) {
                continue;
            }
            else if(nome[auxiliariliar[i]][j] < nome[auxiliariliar[i + 1]][j]) {
                break;
            }
        }
        i ++;
    }

    printf("%s\n", nome[auxiliariliar[limite]]);
}

void VerifReprovado(int numeroPessoas, char nome[101][21], int numeroProblemas[101]) {
    int menor = numeroProblemas[0], j = 0, i;
    int auxiliariliar[101];
    for(i = 1; i < numeroPessoas; i ++)
        if(numeroProblemas[i] < menor) menor = numeroProblemas[i];

    for(i = 0; i < numeroPessoas; i ++)
        if(menor == numeroProblemas[i]) {
            auxiliariliar[j] = i;
            j ++;
        }

    if(j == 1)
        printf(" %s\n", nome[auxiliariliar[0]]);
    else
        VerifOrdem(nome, auxiliariliar, j - 1);
}