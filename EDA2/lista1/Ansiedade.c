#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entradaarq, i = 0, auxiliar = 0, triagem = 0,chave = 0;
    char resposta[3];

    while (scanf(" %d", &entradaarq) != EOF) {
            if (i == 10) {
                i = 0;
                auxiliar = 0;
                chave = 0;
            }

            scanf(" %s", resposta);

            if (resposta[0] == 's') auxiliar ++;//basta verificar 1 letra

            if (auxiliar >= 2 && chave == 0) {
                triagem ++;
                chave = 1;
            }

            i ++;
    }

    printf(" %d\n", triagem);

    return 0;
}