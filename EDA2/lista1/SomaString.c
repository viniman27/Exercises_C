#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, cont, soma = 0;
    char string[100];

    scanf(" %d", &N);

    for(i = 0; i < N; i ++) {

        scanf(" %s", string);

        for(cont = 0; cont < 100; cont ++) {
            if(string[cont] == '\0') break;

            if(string[cont] > 48 && string[cont] < 58) soma += (string[cont] - '0');

        }
        printf (" %d\n", soma);
        soma = 0;
    }

    return 0;
}