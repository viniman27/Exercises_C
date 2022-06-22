#include <stdio.h>

float potenciacao(int a, int b){
    // a = 0 e b ≤ 0
    if (b < 0 && a > 0) return 1/potenciacao(a, -b);
    if (b == 0) return 1;
    else return a * potenciacao(a, b-1);
}

int main () {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == 0 && b <= 0){
        printf("indefinido");
    }
    else{
        printf("%f", potenciacao(a, b));
    }
    return 0;
}
