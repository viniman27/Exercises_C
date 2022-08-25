#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, m, j;

    scanf(" %d %d %d", &n, &m, &j);//o número de locais do bairro, o número de locais em que Juliano já esteve e o número de locais que deseja-se saber se Juliano estará.

    int matriz[n][n], i, u;

    for(i = 0; i < n; i ++)//locais numerados de 0 a n
        for(u = 0; u < n; u ++)
            matriz[i][u] = 0;//compoe inicialmente a matriz com 0

    int vizinho;

    for(i = 0; i < n; i ++) {

        scanf(" %d", &vizinho);

        int local;

        for(u = 0; u < vizinho; u ++) {

            scanf(" %d", &local);
            matriz[i][local] = 1;

        }
    }

    int l;//mais uma variavel para controle dos locais na matriz

    for(i = 0; i < m; i ++) {

        scanf(" %d", &l);

        matriz[l][l] = 2;//indicacao que o juliano esteve no local

        for(u = 0; u < n; u ++) {

            if(matriz[l][u] == 1) {
                matriz[u][u] = 2;
            }
        }
    }

    for(i = 0; i < j; i ++) {

        scanf(" %d", &l);

            if(matriz[l][l] == 2) {
                printf("Eu vou estar la\n");
            }
            else
                printf("Nao vou estar la\n");
    }

    return 0;
}