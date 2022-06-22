#include<stdio.h>
#include<string.h>

void limparBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}

int main()
{
    int N,res,i;
    char resp[100],gab[100];
    res=0;

    scanf("%d",&N);
    limparBuffer();
    scanf("%s",resp);
    limparBuffer();
    scanf("%s",gab);
    limparBuffer();

    for(i=0;i<=(N-1);i++){
        if(resp[i]==gab[i]){
            res++;
        }
    }

    printf("%d",res);
    
    return 0;
}