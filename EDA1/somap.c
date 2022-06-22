#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void limparBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}

int main()
{
    int N,Sp,Si;
    N=0;
    Sp=0;
    Si=0;

    do{
        scanf("%d",&N);
        limparBuffer();

        if(N%2==0){
            Sp += N;
        }else{
            Si += N;
        }

    }while(N!=0);

    printf("%d %d",Sp,Si);

    return 0;
}