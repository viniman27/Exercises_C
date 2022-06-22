#include<stdio.h>
#include<stdlib.h>


void limparBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}

int encaixa(int a,int b){

   if (b==0){
        if ((a%10)==0){
            return 1;
        }else{
            return 0;
        }
    }else{

        while(b!=0 && a%10==b%10)
        {
            a/=10;
            b/=10;
        }

        if(b==0){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main()
{
   int a,b;

    scanf("%d",&a);
    scanf("%d",&b);
    if(encaixa(a,b)==1){
        printf("1");
    }else{
        printf("0");
    }

return 0;
}