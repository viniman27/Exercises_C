#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

int separa(int *v,int e,int d)
{
    int aux = v[d], i, j = e;

    
    for(i = e; i < d; i++)
        if(less(v[i], aux))
        {
          exch(v[i], v[j]);
          j++;
        }
    exch(v[j], v[d]);
    return j;
}

void quicksort(int *v,int e, int d)
{
    if (d <= e) return;//caso base

    //calculoda mediana
    cmpexch(v[(e+d)/2], v[d]);
    cmpexch(v[e], v[(e+d)/2]);
    cmpexch(v[d], v[(e+d)/2]);

    int j = separa(v, e, d);
    quicksort(v, e, j-1);
    quicksort(v, j+1, d);
}

void maiorRepeticao(int *v, int n) {
    int i, repDef = 0, d = 0, repAux, a = 1;

    repAux = v[0];
    for(i = 1; i < n; i ++) {
        if(repAux != v[i]) {
            if(a > d) {
                repDef = repAux;
                d = a;
            }
            a = 0;
            repAux = v[i];
        }
        else if(i == n - 1 && repAux == v[i]) {
            if(a > d) {
                repDef = repAux;
                d = a;
            }
        }
        else
            a ++;
    }

    printf("%d\n", repDef);
}

int main()
{
    int s, df, de, *v = malloc(10000000 * sizeof(int)), i = 0, vv = 0, vi = 0, *vp = malloc(10000000 * sizeof(int)), *vs = malloc(10000000 * sizeof(int)), *vdf = malloc(10000000 * sizeof(int)), *vde = malloc(10000000 * sizeof(int)), j = 0, k = 0, u = 0, n = 0;

    scanf(" %d %d %d", &s, &df, &de);

    while(scanf(" %d", &v[i++]) != EOF) {
        if(v[i-1] < 0)
            vi ++;
        else
            vv ++;
    }

    printf("%d %d\n", vv, vi);

    quicksort(v, 0, vv + vi - 1);

    for(i = 0; i < vv + vi; i ++) {
        if(v[i] < 0)
            continue;
        else if(v[i] >= 0 && v[i] < 100)
            vp[j++] = v[i];
        else if(v[i] >= 100 && v[i] < 1000)
            vs[k++] = v[i];
        else if(v[i] >= 1000 && v[i] < 10000)
            vdf[u++] = v[i];
        else if(v[i] >= 10000 && v[i] < 100000)
            vde[n++] = v[i];
    }

    for(i = 0; i < j; i ++){
        printf("%d", v[i]);
    }
    
    free(v);
    return 0;
}