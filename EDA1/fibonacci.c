#include <stdio.h>

long int v[81];

long int fibonacci (int n){
    long int novo;
    v[1] = 1;
    v[2] = 1;
    if (v[n] != 0){
        return v[n];
    } 
    else{
        v[n] = fibonacci(n-2) + fibonacci(n-1);
        return v[n];
    } 
}