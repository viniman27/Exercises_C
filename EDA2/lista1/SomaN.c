#include <stdio.h>
#include <stdlib.h>

void somaN(int n) {
    int soma = 0, num, i;
    i=0;

    do{
        scanf(" %d", &num);
        soma += num;
        i++;
    }while(i<n);

    printf(" %d ", soma);
}

int main()
{
    int n;

    scanf("%d", &n);

    somaN(n);

    return 0;
}