#include <stdio.h>
 
void buscabinaria(long int ,long int ,long int [],long int [],long int []);
void ordenainsec(long int [], long int );
long int recMove(long int [],long int ,long int );


int main(){

    long int listaN[100000];
    long int listaM[100000];
    long int posicao[100000];
    long int n,m,i,j;


    scanf("%ld", &n);
   
    scanf("%ld", &m);
 
    for(i = 0; i < n; i++){
        scanf("%ld", &listaN[i]);
    }
 
    for(j = 0; j < m; j++){
        scanf("%ld", &listaM[j]);
    }

    ordenainsec(listaN, n);
  
    buscaBinaria(n, m, listaN, listaM, posicao);

    for(j = 0; j < m; j++){
        printf("%ld \n", posicao[j]);
    }

    return 0;
}


long int recMove(long int *v,long int i,long int elem){

   if (i<0 || v[i]<=elem) return i;
   v[i+1] = v[i];
   recMove(v,i-1,elem);
}

void ordenainsec(long int *v, long int n){

    if(n<=1) return;

    ordenainsec(v,n-1);

    long int elem= v[n-1];
    long int i = recMove(v,n-2,elem);
    v[i+1]=elem;
}

 void buscaBinaria(long int n,long int m,long int N[],long int M[],long int posicao[]){

    long int meio;
    long int e;
    long int d;
    long int i;

    for( i = 0; i <m; i++){
        e = -1;
        d = n;
    while(e != (d-1)){
        meio = (e+d)/2;
        if(M[i] > N[meio]){
            e = meio;
        }else{
            d = meio;
        }
    }
    posicao[i] = d;
    }
}