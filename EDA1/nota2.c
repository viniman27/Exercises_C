#include<stdio.h>


void limparBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}

int main()
{
    int B,T,At,Ar;
    Ar= 11200;

    printf("B:");
    scanf("%d",&B);
    limparBuffer();

    if(B>160 || B<0 ){
        do{
            printf("entrada incorreta,tente novamente\n");
            scanf("%d",&B);
            limparBuffer();
        }while(B>160 || B<0);
    }

    printf("T:");
    scanf("%d",&T);
    limparBuffer();

    if(T>160 || T<0 ){
        do{
            printf("entrada incorreta,tente novamente\n");
            scanf("%d",&T);
            limparBuffer();
        }while(T>160 || T<0);
    }

    At=((B+T)*70)/2;

    if(At==Ar/2){
        printf("0");
    }

    if(At>Ar/2){
        printf("1");
    }

     if(At<Ar/2){
        printf("2");
    }
    

    return 0;
}