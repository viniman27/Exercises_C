#include <stdio.h>
#include <stdlib.h>

//macros

#define ull unsigned long long
#define min(a, b) (a < b ? a : b)
#define max(a, b) (b < a ? a : b)
#define key(x) (x)
#define less(a, b) (a.v == b.v ? a.k < b.k : a.v < b.v)
#define swap(a, b) { Item t = a; a = b;b = t;}
#define cmpswap(a, b) {if (less(b, a)) swap(a, b);}

//struct para tabela hash do valor e frequencia de cada caracter a ser analisado

typedef struct
{
    int k, v;

} Item;


//funcoes assinadas

int separa(Item *v, int l, int r);
void quicksortM3(Item *v, int l, int r);
void insertionsort(Item *v, int l, int r);
void quicksort(Item *v, int l, int r);

//main

int main()
{
    char listaTeste[1001],i;

    while (scanf(" %s", listaTeste) == 1)
    {
        int frequencia[130];
        Item tabelaCaracter[130];

        for (i = 0; i < 130; i++)
            frequencia[i] = 0;

        for (i = 0; listaTeste[i] != '\0'; i++)
            frequencia[listaTeste[i]]++;

        int k = 0;

        for (i = 0; i < 130; i++)
            if (frequencia[i])
                tabelaCaracter[k++] = (Item) {.k = i, .v=frequencia[i]};

        quicksort(tabelaCaracter, 0, k-1);

        for (i = 0; i < k; i++)
            printf("%d %d\n", tabelaCaracter[i].k, tabelaCaracter[i].v);

        printf("\n");//pula linha entre saidas
    }

    return 0;
}

//funcoes

int separa(Item *v, int l, int r)//com base  no algoritmo de cormem
{
    Item pivot = v[r];

    int j = l,k;

    for (k = l; k < r; k++)
        if (less(v[k], pivot))
        {
            swap(v[k], v[j]);
            j++;
        }
    swap(v[j], v[r]);

    return j;
}

void quicksortM3(Item *v, int l, int r)
{
    if (r - l <= 32) return;//caso base

    //calculo da mediana
    swap(v[(l + r) / 2], v[r - 1]);
    cmpswap(v[l], v[r - 1]);
    cmpswap(v[l], v[r]);
    cmpswap(v[r - 1], v[r]);

    int m = separa(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionsort(Item *v, int l, int r)
{

    int i,j;
    
    for (i = l + 1, j; i <= r; i++)
    {
        Item t = v[i];
        for (j = i; j > 0 && less(t, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = t;
    }
}

void quicksort(Item *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}