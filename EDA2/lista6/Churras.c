#include <stdio.h>
#include <stdlib.h>

//macros

#define min(a, b) (a < b ? a : b)
#define max(a, b) (b < a ? a : b)
#define key(x) (x->value)
#define less(a, b) (key(a) > key(b))
#define exch(a,b) {Item t = a; a=b; b=t;}
#define cmpexch(a,b) {if(less(b,a)) exch(a,b);}

//struct para item

struct Item
{
    int heap_idx, value;
};

//globais

typedef struct Item *Item;
Item NULL_ITEM = NULL;

//struct heap

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
Item PQ_remove(PriorityQueue *pq, int i);//remove um elemento da posicao i e corrige
void resolve();

//main

int main()
{
    resolve();//troca de um while por uma funcao recursiva, quem sabe da certo
    return 0;
}

//funcoes

void HEAP_fixup(Item *heap, int i)
{
    for (; i > 1 && less(heap[i / 2], heap[i]); i /= 2)
    {
        exch(heap[i], heap[i / 2]);
        heap[i]->heap_idx = i;
        heap[i / 2]->heap_idx = i / 2;
    }
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
        heap[i]->heap_idx = i;
        heap[maior]->heap_idx = maior;
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
    x->heap_idx = pq->size;
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

Item PQ_remove(PriorityQueue *pq, int i)
{
    if (i < 1 || i > pq->size)
        return NULL_ITEM;

    Item removed = pq->heap[i];
    pq->heap[i] = pq->heap[pq->size--];
    HEAP_fixdown(pq->heap, pq->size, i);
    return removed;
}

void resolve()
{
    int n, k, i;//numero de churrascarias e numero de pessoas

    scanf(" %d %d\n", &n, &k);

    if (n == 0 && k == 0)
        return;

    Item v = malloc(n * sizeof(struct Item));

    for (i = 0; i < n; i++)
        scanf(" %d", &v[i].value);

    PriorityQueue pq = PQ_init(k);

    for (i = 0; i < k - 1; i++)
        PQ_insert(&pq, &v[i]);

    for (i = k - 1; i < n; i++)
    {
        PQ_insert(&pq, &v[i]);
        printf("%d%c", PQ_getTop(pq)->value, " \n"[i == n-1]);
        PQ_remove(&pq, v[i - k + 1].heap_idx);
    }

    PQ_free(pq);
    resolve();
}
