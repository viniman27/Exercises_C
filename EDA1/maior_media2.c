#include<stdio.h>

void limparBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}

int main()
{
    int Ma,soma,N[10000],n,i,existe;
    soma=0;
    Ma=0;
    existe=0;

    scanf("%d",&n);
    limparBuffer();

    if(quantidade >= 10 && quantidade <= 10000){
         for(i=0;i<=(n-1);i++){
            scanf("%d",N[i]);
            limparBuffer();
            soma+=N[i];
      }
    }

    Ma=soma/n;

    for(i=0;i<=(n-1);i++){
        if(N[i]>Ma){
        printf("%d ",N[i]);
        existe++;
        }
    }

    if(existe==0){
        printf("0");
    }

    return 0;
}