#include <stdio.h>
#include <stdlib.h>

void OrdenaVetor(int *IDs, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = IDs[(left + right) / 2];
     
    while(i <= j) {
        while(IDs[i] < x && i < right) {
            i++;
        }
        while(IDs[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = IDs[i];
            IDs[i] = IDs[j];
            IDs[j] = y;
            i++;
            j--;
        }
    }
    if(j > left) {
        OrdenaVetor(IDs, left, j);
    }
    if(i < right) {
        OrdenaVetor(IDs, i, right);
    }
}

int main()
{
    int numAlunos, i, auxiliar = 0;
    int *IDaluno;
    
    IDaluno = malloc(100000 * sizeof(int));

    scanf(" %d", &numAlunos);

    for(i = 0; i < numAlunos; i ++) {
        scanf(" %d", &IDaluno[i]);
    }
    
    OrdenaVetor(IDaluno, 0, numAlunos - 1);

    for (i = 0; i < numAlunos - 1; i ++) 
        if (IDaluno[i] == IDaluno[i + 1]) IDaluno[i] = -1;
        
    for (i = 0; i < numAlunos; i ++) if(IDaluno[i] != -1) auxiliar ++;

//auxiliar = auxiliar + 1 - 1 + 2 - 2;
    
    printf(" %d\n", auxiliar);

    return 0;
}