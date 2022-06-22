#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

int remove_depois (celula *p){
	celula *lixo = p -> prox;
	if(lixo != NULL){
		int ret = lixo -> dado;
		p -> prox = lixo -> prox;
		free(lixo);
		return ret;
	}
}

void remove_elemento (celula *le, int x){
	celula *lixo = le -> prox;

	// Busca por x e vai fazendo passando "lixo" para prox
	while(lixo != NULL && lixo -> dado != x){
		le = lixo;
		lixo = lixo -> prox;
	}

	// Caso encontre o "lixo", libera ele (free)
	if(lixo != NULL){
		le -> prox = lixo -> prox;
		free(lixo);
	}

}

void remove_todos_elementos (celula *le, int x){
	// Encontrar a primeira aparição de x na lista (atualiza como "nova cabeça da lista")
    while (le && (le -> dado == x)) {
        le = le -> prox;
    }

    celula* lixo = le;
    le = le -> prox;

    // Enquanto a lista for diferente de nulo
    while (le) {
        if (le -> dado == x) { // Caso o elemento seja x, o lixo é removido e atualiza a lista
            lixo -> prox = le -> prox;
        } else { // Se não, o lixo se mantém
            lixo = le;
        }
        le = le -> prox;
    }
}