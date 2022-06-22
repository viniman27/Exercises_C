#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void limparBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}

struct tipoData{
    int dia;
    int mes;
    int ano;
}

struct tipoPessoa{
    char nome[80];
    struct tipoData dtNascimento;
}

struct tipoPessoa separaInfo (char nome[80],int dt_nascimento){
    


}


