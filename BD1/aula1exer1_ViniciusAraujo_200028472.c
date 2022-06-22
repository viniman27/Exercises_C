#include <stdio.h>
#include <stdlib.h>




typedef struct{
    char modelo[30],placa[8];
    int RENAVAM;
}Carro;


typedef struct{
    char nome[30];
    int CPF,RG, QuantCarros;
    Carro carros[30]; 
}Pessoa;

int Menu();
int ImpDados();
Pessoa CadastrarDono(int cont, Pessoa *dono);

int main(){

    Pessoa dono[100];
    int opcao, cont = 0; 

    do{
        opcao = Menu();
        switch (opcao)
        {
        case 1:
            CadastrarDono(cont, dono);
            cont ++;
            break;
        case 2:
            ImpDados();
            break;
        case 3:
            printf("Programa encerrado!\n");
            return 0;
        default:
            printf("\nOpcao Invalida!\n\n");
            break;
        }
    } while(opcao != 3);

    return 0;
}


int Menu(){
    int opcao;
    
    printf("MENU\n\n");
    printf("1 - Cadastrar Pessoa e seus Automoveis\n");
    printf("2 - Listar Pessoas e Automoveis cadastrados\n");
    printf("3 - Finalizar programa\n");
    printf("Escreva o numero relativo a sua opcao: \n");
    scanf(" %d", &opcao);

    return opcao;
}

Pessoa CadastrarDono(int cont, Pessoa *dono){

    int numAutomoveis;

    printf("Registro de Pessoa\n");
    printf("Informe o nome do Pessoa: \n");
    scanf(" %[^\n]s", &dono[cont].nome);
    printf("Informe o CPF da Pessoa: \n");
    scanf(" %d", &dono[cont].CPF);
    printf("Informe o RG da Pessoa: \n");
    scanf(" %d", &dono[cont].RG);

    printf("Registro de Automoveis\n");
    printf("Quantos automoveis esse Pessoa tem? \n");
    scanf(" %d", &numAutomoveis);

    dono[cont].QuantCarros = numAutomoveis;
    int i;
    for(i = 0; i < numAutomoveis; i++){
        printf("Cadastro do automovel %d da Pessoa\n", (i+1));
        printf("Informe o modelo do automovel: \n");
        scanf(" %[^\n]s", &dono[cont].carros[i].modelo);
        printf("Informe a placa do automovel: \n");
        scanf(" %[^\n]s", &dono[cont].carros[i].placa);
        printf("Informe o RENAVAM do automovel: \n");
        scanf(" %d", &dono[cont].carros[i].RENAVAM);
        printf("Veiculo cadastrado!\n\n");
    }
    
    FILE *reg = fopen("arquivo", "ab");
    fwrite(&dono[cont], sizeof(Pessoa), 1, reg);
    fclose(reg);

}

int ImpDados(){
   Pessoa dono;
   int i;

    printf("Pessoas e Automoveis cadastrados\n");
    FILE *reg = fopen("arquivo", "rb");

    if (!reg){
        printf(" :/ Erro\n");
        printf("--------------------------------------\n");
        exit(1);
    }
    while (fread(&dono, sizeof(Pessoa), 1, reg)){
        printf("NOME: %s -CPF: %d- RG:%d\n", dono.nome, dono.CPF,dono.RG);
        printf("Carros desse Proprietario: ");
        for(i = 0; i < dono.QuantCarros; i++){
            printf("MODELO: %s - PLACA: %s - RENAVAM: %d\n", dono.carros[i].modelo,dono.carros[i].placa, dono.carros[i].RENAVAM);
        }
        fflush(stdin);
    }
    fclose(reg);
    return 0;

}


