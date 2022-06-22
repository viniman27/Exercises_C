#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void limparBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}

int main()
{
    int N;
    char stringA['A','B','C','D','E'],stringB['A','B','C','D','E'];

    printf("quantas  questoes tem a prova?\n");
    scanf("%d",&N);
    limparBuffer();
    printf("quais as respostas das questoes da prova?\n");
    gets(stringA);
    limparBuffer();
    printf("quais foram as respostas do aluno nas questoes da prova?\n");
    gets(stringB);
    limparBuffer();

    return 0;
}