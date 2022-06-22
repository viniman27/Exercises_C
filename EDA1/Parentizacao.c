#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char caracter;
    struct no *proximo;
}No;

No* empilhar(No *pilha, char valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->caracter = valor;
        novo->proximo = pilha;
        return novo;
    }
    else  // excecao incomum
        printf("Erro ao alocar memoria");
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("Pilha vazia");
    return remover;
}

int parCorreto(char f, char d){ //verifica se abre e fecha
    switch(f){
    case ')':
        if(d == '(')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case ']':
        if(d == '[')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case '}':
        if(d == '{')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    }
}

int identificaParentizacao(char x[]){
    int i = 0;
    No *remover, *pilha = NULL;

    while(x[i] != '\0'){
        if(x[i] == '(' || x[i] == '[' || x[i] == '{'){
            pilha = empilhar(pilha, x[i]);
            
        }
        else if(x[i] == ')' || x[i] == ']' || x[i] == '}'){
            remover = desempilhar(&pilha);
            if(parCorreto(x[i], remover->caracter) == 0){
                return 1; // expressao está mal formada
            }
            free(remover);
        }
        i++;
    }
    if(pilha){
        return 1;//nao
    }
    else{
        return 0;//sim
    }
}

int main(){
    char expM[500];

    scanf(" %s", expM);// expressao

    if(identificaParentizacao(expM) == 1){
        printf("nao");
    }else{
        printf("sim");
    }


    return 0;
}