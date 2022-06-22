#include<stdio.h>

void limparBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}

int main()
{
    int Ma,soma,N[10000],n,i;
    soma=0;
    Ma=0;

    scanf("%d",&n);
    limparBuffer();

        for(i=0;i<=(n-1);i++){
            scanf("%s",N[i]);
            limparBuffer();
            soma+=N[i];
        }

    Ma=soma/n;

        for(i=0;i<=(n-1);i++){
            if(N[i]>Ma){
            printf("%d ",N[i]);
            }
        }

    return 0;
}