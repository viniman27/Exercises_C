#include <stdio.h>
#include <stdlib.h>
 

#define MAX_SIZE 100 //tamanho maximo da pilha
 
// arvore
typedef struct no {
    int dado;
    struct no *esq, *dir;
}no;
 
// pilha para manipulacao do percurso
typedef struct pilha{
    int tam;
    int topo;
    struct no* *array;
} pilha;
 
// criar novo no da arvore
struct no* novono(int dado)
{
    struct no* no = (struct no*) malloc(sizeof(struct no));
    no->dado = dado;
    no->esq = no->dir = NULL;
    return no;
}
 
// criar funcao de tamanho "size"
struct pilha* criapilha(int tam)
{
    struct pilha* pilha = (struct pilha*) malloc(sizeof(pilha));
    pilha->tam = tam;
    pilha->topo = -1;
    pilha->array = (struct no*) malloc(pilha->tam * sizeof(no));
    return pilha;
}
 

int picheio(struct pilha* pilha)// pilha cheia
{ return pilha->topo - 1 == pilha->tam; }
 
int pivazio(struct pilha* pilha)//pilha vazia
{ return pilha->topo == -1; }
 
void empilha(struct pilha* pilha, struct no* no)//adiciona elemento na pilha
{
    if (picheio(pilha))
        return;
    pilha->array[++pilha->topo] = no;
}
 
struct no* desempilha(struct pilha* pilha)//remove elemento da pilha
{
    if (pivazio(pilha))
        return NULL;
    return pilha->array[pilha->topo--];
}
 
struct no* verifica(struct pilha* pilha)//retorna o topo ou null caso vazio
{
    if (pivazio(pilha))
        return NULL;
    return pilha->array[pilha->topo];
}
 

void pos_ordem (no *raiz)
{
    // Verifica se raiz esta vazia
    if (raiz == NULL)
        return;
     
    struct pilha* pilha = criapilha(MAX_SIZE);

    do
    {
        
        while (raiz) // Move para o no a esquerda
        {
            // empilha a "raiz" da direita e depois a raiz principal na pilha
            if (raiz->dir)
                empilha(pilha, raiz->dir);
            empilha(pilha, raiz);
 
            // raiz principal eh a raiz da subarvore da esquerda
            raiz = raiz->esq;
        }
 
        // desempilha e torna o elemento raiz 
        raiz = desempilha(pilha);
 
        if (raiz->dir && verifica(pilha) == raiz->dir)
        {
            desempilha(pilha); // remove o filho da direita da pilha
            empilha(pilha, raiz); // empilha de volta
            raiz = raiz->dir; // mudar raiz para direita
                                // child is processed next
        }
        else // printa a raiz principal
        {
            printf("%d ", raiz->dado);
            raiz = NULL;
        }
    } while (!pivazio(pilha));
}



