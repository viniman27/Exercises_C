#include <stdio.h>
#include <stdlib.h>

int main() {

    int numeroAlunos, notaAlta;

    scanf(" %d", &numeroAlunos);

    int *listaNotas = malloc(1001 * sizeof(int)), i, nota;

    for(i = 0; i < 1001; i ++) {//garante os espacos preenchidos
        listaNotas[i] = 0;
    }

    for(i = 0; i < numeroAlunos; i ++) {//preenche com as notas

        scanf(" %d", &nota);

        nota = nota % 1001;
        listaNotas[nota]++;

    }

    int maior = 0;//comeca com 0 para garantir o maior sempre

    for(i = 0; i < 1001; i ++) {

        if(listaNotas[i] >= maior) {//coleta a maior nota, a titulo de desempate

            maior = listaNotas[i];
            notaAlta = i;//garante a nota de maior frequencia
            
        }
    }

    printf("%d\n", notaAlta);

    free(listaNotas);

    return 0;
}