#include <stdio.h>
#include <stdlib.h>

int entrada(int *sequencia) {
    int i;

    for (i = 0;; i ++) {
        scanf (" %d", &sequencia[i]);//incremento n inteiros ate que != 0

        if (sequencia[i] == 0) {//termina sequencia
            scanf (" %d", &sequencia[i + 1]);
            printf("sequencia[i + 1] = %d %d\n",sequencia[i + 1 ],(i) );
            return sequencia[i + 1];//retorna o vetor
        }
    }
}

void verifSoma(int *sequencia, int posicao, int limite) {
    int i, soma = 0;

    for (i = posicao; i < 10000; i ++) {

        if (sequencia[i] == 0) break;

        soma += sequencia[i];

        if(soma > limite) {
            posicao = i + 1;
            verifSoma(sequencia, posicao, limite);
            printf(" %d\n", sequencia[i]);
            break;
        }
    }
}

int main()
{
    int tamanho = 10000, posicao = 0, limite;
    int *sequencia;

    sequencia = malloc(tamanho * sizeof(int));

    limite = entrada(sequencia);

    verifSoma(sequencia, posicao, limite);

    return 0;
}