#include<stdio.h>

typedef struct tipoData{
    int dia;
    int mes;
    int ano;
}tipoData;

typedef struct tipoPessoa{
    char nome[80];
    struct tipoData dtNascimento;
}tipoPessoa;

struct tipoPessoa separaInfo (char nome[80],int dt_nascimento){
    
    struct tipoPessoa retorno;
	int i;

	for(i = 0; i < 80; i++){
		retorno.nome[i] = nome[i];
	}

	retorno.dtNascimento.dia = dt_nascimento%100;
	dt_nascimento = dt_nascimento/100;

	retorno.dtNascimento.mes = dt_nascimento%100;
	dt_nascimento = dt_nascimento/100;

	retorno.dtNascimento.ano = dt_nascimento;

	return retorno;

}


