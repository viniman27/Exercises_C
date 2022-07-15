#include <stdio.h>
#include <stdlib.h>


//macros
#define less(A, B) (A < B)
#define exch(A, B) {int t = B; B = A; A = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}


//funcoes assinadas
int separa(int *v, int l, int r);
void quicksort(int *v, int l, int r);


//main
int main(void){
    int j, i = 0, r;

    scanf(" %d", &r);

    int *v = malloc(r * sizeof(int));

    for(i = 0; i < r; i++){
        scanf(" %d", &v[i]);
    }

    quicksort(v, 0, i-1);

    for(j = 0; j < i - 1; j ++){
        printf("%d ", v[j]);
    }
        
    printf("%d\n", v[j]);

    free(v);
    return 0;
}


//funcoes

int separa(int *v,int l,int r)//baseada no algoritmo de sedgewick
{
  int i=l-1, j=r, V=v[r];


  for(;;)
  {
    while(less(v[++i],V));
    while(less(V,v[--j])) if(j==l) break;
    if(i>=j) break;
    exch(v[i],v[j]);
  }
  exch(v[i],v[r])
  return i;
}


void quicksort(int *v, int l, int r){
  if(l > r) return; // caso base

//escolha eficiente do pivo
  cmpexch(v[(l+r)/2],v[r]);
  cmpexch(v[l],v[(l+r)/2]);
  cmpexch(v[r],v[(l+r)/2]);
  
  int j = separa(v, l, r);
  
  quicksort(v, l, j-1);
  quicksort(v, j+1, r);
}
