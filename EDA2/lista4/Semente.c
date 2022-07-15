#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//macros

#define ull unsigned long long
#define less(a, b) (a.notaSemente == b.notaSemente ? a.codSemente < b.codSemente : a.notaSemente < b.notaSemente)
#define less2(a, b) (a.codSemente == b.codSemente ? a.notaSemente < b.notaSemente : a.codSemente < b.codSemente)
#define exch(a, b) { Item t = a;a = b;b = t;}
#define cmpexch(a, b) {if (less(b, a)) exch(a, b);}
#define cmpexch2(a, b) {if (less2(b, a)) exch(a, b);}

//struct para sementes

typedef struct
{
    long long codSemente;
    int notaSemente;
} Item;

//funcoes assinadas

void quicksort2(Item *sementeCompleto, int l, int r);
void quicksortM3(Item *sementeCompleto, int l, int r);
int separa(Item *sementeCompleto, int l, int r);
void quickselect(Item *sementeCompleto, int l, int r, int i);
void insertionsort(Item *sementeCompleto, int l, int r);

//variaveis globais

Item sementeCompleto[10000001];

//main

int main()
{
    int k,n,i;

    scanf(" %d", &k);//numero de sementes selecionadas

    for (n = 0; scanf(" %lld %d", &sementeCompleto[n].codSemente, &sementeCompleto[n].notaSemente) == 2; n++);

    quickselect(sementeCompleto, 0, n - 1, k - 1);
    quicksort2(sementeCompleto, 0, k - 1);

    for (i = 0; i < k; i++)
        printf("%lld %d\n", sementeCompleto[i].codSemente, sementeCompleto[i].notaSemente);

    return 0;
}

//funcoes


void quicksortM3(Item *sementeCompleto, int l, int r)
{
    if (r<=l )return;//caso base

    //Calculo da mediana
    exch(sementeCompleto[(l + r) / 2], sementeCompleto[r - 1]);
    cmpexch2(sementeCompleto[l], sementeCompleto[r - 1]);
    cmpexch2(sementeCompleto[l], sementeCompleto[r]);
    cmpexch2(sementeCompleto[r - 1], sementeCompleto[r]);

    int m = separa(sementeCompleto, l, r);
    quicksortM3(sementeCompleto, l, m - 1);
    quicksortM3(sementeCompleto, m + 1, r);

}

void insertionsort(Item *sementeCompleto, int l, int r)
{
    int i,j;
    for (i = l + 1, j; i <= r; i++)
    {
        Item t = sementeCompleto[i];
        for (j = i; j > 0 && less2(t, sementeCompleto[j - 1]); j--)
            sementeCompleto[j] = sementeCompleto[j - 1];
        sementeCompleto[j] = t;
    }
}

int separa(Item *sementeCompleto, int l, int r)
{
    Item pivot = sementeCompleto[r];

    int j = l,k;
    
    for (k = l; k < r; k++)
        if (less(sementeCompleto[k], pivot))
        {
            exch(sementeCompleto[k], sementeCompleto[j]);
            j++;
        }
    exch(sementeCompleto[j], sementeCompleto[r]);
    return j;
}

void quicksort2(Item *sementeCompleto, int l, int r)
{
    quicksortM3(sementeCompleto, l, r);
    insertionsort(sementeCompleto, l, r);
}

void quickselect(Item *sementeCompleto, int l, int r, int i)
{
    cmpexch(sementeCompleto[(l + r) / 2], sementeCompleto[r]);
    cmpexch(sementeCompleto[l], sementeCompleto[(l + r) / 2]);
    cmpexch(sementeCompleto[r], sementeCompleto[(l + r) / 2]);

    int m = separa(sementeCompleto, l, r);
    if (m > i)
        quickselect(sementeCompleto, l, m - 1, i);
    else if (m < i)
        quickselect(sementeCompleto, m + 1, r, i);
}