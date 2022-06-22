#include <stdio.h>

long long int conta7(long long int n){
    if (n < 1) return 0;
    if (n % 10 == 7) return 1 + conta7(n/10);
    else return conta7(n/10);
}

int main(){
    long long int numero;

    scanf("%lld", &numero);

    printf("%lld", conta7(numero));

    return 0;
}