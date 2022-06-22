#include<stdio.h>


void limparBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}

int main()
{
   int n,m,l;

    scanf("%d",&n);
    limparBuffer();

   
    for(m=1;m<=n;m++){
        for(l=1;l<=m;l++){
            printf("%02d ",m);
       }
        printf("\n");
    }

    printf("\n");
      
        for(m=1;m<=n;m++){
            for(l=1;l<=m;l++){
                printf("%02d ",l);
            }
            printf("\n");
        }

    return 0;
}