#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//globais

char ht[109][20];
int tamanho = 0;

//funcoes assinadas

int hash(char *k);//calcula o hash da posicao, seja para pesquisa, adicao ou remocao
int pesquisa(char *s);
void ADD(char *s);
void DEL(char *s);

//main

int main()
{
    int numeroCasos,i;
    scanf(" %d", &numeroCasos);//

    while (numeroCasos--)
    {
        for (i = 0; i < 101; i++)
            *ht[i] = '\0';

        tamanho = 0;

        int numeroOperacoes;

        scanf(" %d", &numeroOperacoes);

        char operacao[4], s[16];

        while (numeroOperacoes--)
        {
            scanf(" %s:%s", operacao, s);
            if (operacao[0] == 'A')
                ADD(s);
            else
                DEL(s);
        }

        printf("%d\n", tamanho);

        for (i = 0; i < 101; i++)
            if (*ht[i] != '\0')
                printf("%d:%s\n", i, ht[i]);
    }

    return 0;
}

//funcoes

int hash(char *k)
{
    int h = 0,i;

    for (i = 0; k[i] != '\0'; i++)
        h += k[i] * (i+1LL);
    return (h * 19) % 101;
}

int pesquisa(char *s)
{
    int h = hash(s),j;

    for (j = 0; j < 20; j++)
    {
        int i = (h + j*j + 23LL*j) % 101;//LL OU long long
        if (strcmp(ht[i], s) == 0)
            return 1;
    }
    return 0;
}

void ADD(char *s)
{
    if (pesquisa(s))//garante, pelo menos idealmente, que nao havera repeticao
        return;

    int h = hash(s),j;

    for (j = 0; j < 20; j++)
    {
        int i = (h + j*j + 23LL*j) % 101;
        if (*ht[i] == '\0')
        {
            strcpy(ht[i], s);
            tamanho++;
            break;
        }
    }
}

void DEL(char *s)
{
    int h = hash(s),j;

    for (j = 0; j < 20; j++)
    {
        int i = (h + j*j + 23LL*j) % 101;

        if (strcmp(ht[i], s) == 0)
        {
            *ht[i] = '\0';
            tamanho--;
        }
    }
}