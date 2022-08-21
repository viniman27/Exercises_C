#include <stdio.h>
#include <stdlib.h>

//macros

#define min(a, b) (a < b ? a : b)
#define max(a, b) (b < a ? a : b)
#define Item int
#define key(x) (x)
#define less(a, b) (a > b)
#define exch(a,b) {Item Operacao = a; a=b; b=Operacao;}
#define cmpexch(a,b) {if(less(b,a)) exch(a,b);}

//globais

Item NULL_ITEM = -1;

//struct para "arvore"

typedef struct
{
    Item *heap;
    size_t size, capacity;//tamanho atual e capacidade da heap
} PriorityQueue;

//funcoes assinadas

void HEAP_fixup(Item *heap, int i);
void HEAP_fixdown(Item *heap, size_t size, int i);
PriorityQueue PQ_init(size_t capacity);
void PQ_free(PriorityQueue pq);//Libera espaco
int PQ_Empty(PriorityQueue pq);
void PQ_GaranteCapacity(PriorityQueue *pq, size_t newCapacity);//Expande a heap
void PQ_insert(PriorityQueue *pq, Item x);
Item PQ_getTop(PriorityQueue pq);//printa o top
Item PQ_extractTop(PriorityQueue *pq);//tira o top e corrige a heap

//main

int main()
{
    PriorityQueue pq = PQ_init(16);
    int Operacao, entradaOp, v[100],i;

    while (scanf(" %d %d", &Operacao, &entradaOp) == 2)//selecao da operacao e entrada correspondente
    {
        if (Operacao == 1)
            PQ_insert(&pq, entradaOp);//adiciona nova placa na heap
        else//Operacao == 2
        {
            int n;//contador
            for (n = 0; n < entradaOp; n++)
            {
                int top = PQ_extractTop(&pq);//ja que a heap é crescente, quanto mais proximo do topo menor
                if (top == NULL_ITEM)
                    break;
                v[n] = top;//insere as menores placas no vetor de acordo com a entrada
            }
            for (i = 0; i < n; i++)
            {
                printf("%d%c", v[i], " \n"[i == n-1]);
                PQ_insert(&pq, v[i]);
            }
        }
    }

    PQ_free(pq);

    return 0;
}

//funcoes

void HEAP_fixup(Item *heap, int i)
{
    for (; i > 1 && less(heap[i / 2], heap[i]); i /= 2)
        exch(heap[i], heap[i / 2]);
}

void HEAP_fixdown(Item *heap, size_t size, int i)
{
    int maior;

    for (maior = i * 2; i * 2 <= size; i = maior, maior = i * 2)
    {
        if (maior < size && less(heap[maior], heap[maior + 1]))
            maior++;

        if (!less(heap[i], heap[maior]))
            break;

        exch(heap[i], heap[maior]);
    }
}

PriorityQueue PQ_init(size_t capacity)
{
    PriorityQueue pq = {.capacity = capacity, .size = 0};
    pq.heap = malloc((capacity + 1) * sizeof(Item));
    return pq;
}

void PQ_free(PriorityQueue pq)
{
    free(pq.heap);
}

int PQ_Empty(PriorityQueue pq)
{
    return pq.size == 0;
}

void PQ_GaranteCapacity(PriorityQueue *pq, size_t newCapacity)
{
    if (newCapacity <= pq->capacity)
        return;

    pq->capacity *= 4;
    pq->heap = realloc(pq->heap, (pq->capacity + 1) * sizeof(Item));
}

void PQ_insert(PriorityQueue *pq, Item x)
{
    PQ_GaranteCapacity(pq, pq->size + 1);
    pq->heap[++pq->size] = x;
    HEAP_fixup(pq->heap, pq->size);
}

Item PQ_getTop(PriorityQueue pq)
{
    return pq.heap[1];
}

Item PQ_extractTop(PriorityQueue *pq)
{
    if (PQ_Empty(*pq))
        return NULL_ITEM;

    Item top = PQ_getTop(*pq);
    pq->heap[1] = pq->heap[pq->size--];
    HEAP_fixdown(pq->heap, pq->size, 1);
    return top;
}
