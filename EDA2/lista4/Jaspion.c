#include <stdio.h>
#include <stdlib.h>

//struct para armazenar a palavra em "japones" e portugues

typedef struct {

    char original[81];
    char traducao[81];

} Dicionario;

//funcoes assinadas

void verificaPalavra(char auxiliar[], int tamanhoDicionario, Dicionario *dicionario, int tamanhoPalavra);
void traducao(int tamanhoMusica, int tamanhoDicionario, char musica[tamanhoMusica][81], Dicionario *dicionario);

//main

int main()
{
    int t, m, n, i = 0, j;

    scanf(" %d", &t);// o número de instâncias

    while(i < t) {

        scanf(" %d %d", &m, &n);//  o número de palavras no dicionário e número de linhas na letra da música

        Dicionario *dicionario = malloc(m * sizeof(Dicionario));

        char musica[n][81];

        for(j = 0; j < m; j ++) {
            scanf(" %[^\n]", dicionario[j].original);
            scanf(" %[^\n]", dicionario[j].traducao);
        }

        for(j = 0; j < n; j ++){
            scanf(" %[^\n]", musica[j]);
        }
        traducao(n, m, musica, dicionario);

        printf("\n");

        i ++;

        free(dicionario);
    }

    return 0;
}

//funcoes

void verificaPalavra(char auxiliar[81], int tamanhoDicionario, Dicionario *dicionario, int tamanhoPalavra) {
    int i, j;

    for(i = 0; i < tamanhoDicionario; i ++) {
        for(j = 0; j < tamanhoPalavra; j ++) {
            if(auxiliar[j] == dicionario[i].original[j] && j == (tamanhoPalavra - 1) && dicionario[i].original[j+1] == '\0') {
                printf("%s ", dicionario[i].traducao);
                return;
            }
            else if(auxiliar[j] == dicionario[i].original[j]){
                continue;
            }
            else{
                break;
            }
        }
    }
    printf("%s ", auxiliar);
}

void traducao(int tamanhoMusica, int tamanhoDicionario, char musica[tamanhoMusica][81], Dicionario *dicionario) {
    int i, j, k = 0;
    char auxiliar[81];

    for(i = 0; i < tamanhoMusica; i ++) {
        for(j = 0; musica[i][j] != '\0'; j ++) {
            if(musica[i][j] == ' ') {
                auxiliar[k++] = '\0';
                verificaPalavra(auxiliar, tamanhoDicionario, dicionario, k-1);
                k = 0;
            } else if(musica[i][j+1] == '\0') {
                auxiliar[k++] = musica[i][j];
                auxiliar[k++] = '\0';
                verificaPalavra(auxiliar, tamanhoDicionario, dicionario, k-1);
                k = 0;
            } else{
                auxiliar[k++] = musica[i][j];
        }
        printf("\n");
        }
    }
}