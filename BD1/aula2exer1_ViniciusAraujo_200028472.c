#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structs
typedef struct{
    char modelo[30],placa[8];
    int RENAVAM;
}Carro;

typedef struct{
    char nome[30],CPF[11];//CPF como chave
    int RG, QuantCarros;
    Carro carros[30]; 
}Pessoa;

//funcoes assinadas

int Menu();//menu de opcoes
int ImpDados();//imprimir dados do arquivo
Pessoa CadastrarDono(int cont, Pessoa *dono);//registrar dados no arquivo
int AlteraMaxDonos(int cont,Pessoa *dono);//alterar o numero maximo de donos de carro(s)
int VerifCPF(char CPF[]);//verifica se o CPF e valido
int comparar(const void * a, const void * b);//funcao de comparaco entre strings



//main

int main(){

    Pessoa *dono;
    dono = (Pessoa*)malloc(100*sizeof(Pessoa));
    //Pessoa dono[100];
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
            AlteraMaxDonos(cont,dono);
            break;
        case 4:
            printf("Programa encerrado!\n");
            return 0;
        default:
            printf("\nOpcao Invalida!\n\n");
            break;
        }
    } while(opcao != 4);

    //liberando memoria
    free(dono);

    return 0;
}

//funcoes

int Menu(){
    int opcao;
    
    printf("----MENU\n\n");
    printf("1 - Cadastrar Pessoa(inicialmente 100 cadastros de pessoas disponiveis) e seus Automoveis( 30 cadastros disponiveis por dono)\n");
    printf("2 - Listar Pessoas e Automoveis cadastrados\n");
    printf("3 - Alterar numero maximo de donos de automoveis\n");
    printf("4 - Finalizar programa\n");
    printf("Escreva o numero relativo a sua opcao: \n\n");
    scanf(" %d", &opcao);

    return opcao;
}

Pessoa CadastrarDono(int cont, Pessoa *dono){

    int numAutomoveis,CPFvalido;
    char CPF[11];
    Pessoa *DonoSort,DonoRecover;
    DonoSort =(Pessoa*)malloc(100*sizeof(Pessoa));

    printf("----Registro de Pessoa\n");
    printf("Informe o nome do Pessoa: \n");
    scanf(" %[^\n]s", &dono[cont].nome);
    printf("Informe o RG da Pessoa: \n");
    scanf(" %d", &dono[cont].RG);

     do{
        printf("Informe o CPF da Pessoa: \n");
        scanf(" %s", &CPF);

        CPFvalido = VerifCPF(CPF);
        
        if(CPFvalido == 0 && strlen(CPF) == 11){
            strcpy(dono[cont].CPF, CPF);
        } else{
            printf("CPF invalido. Essas sao as possiveis razoes: caracteres nao aceitaveis, tamanho invalido ou CPF ja cadastrado!\n");
        }
     }while(CPFvalido > 0);


    printf("----Registro de Automoveis\n");
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
        printf("Veiculo cadastrado\n\n");
    }
    
    FILE *reg = fopen("arquivo", "ab");
    fwrite(&dono[cont], sizeof(Pessoa), 1, reg);
    fclose(reg);

    FILE *recover = fopen("arquivo", "rb");
    while (fread(&DonoRecover, sizeof(Pessoa), 1, recover)){
        DonoSort[cont] = DonoRecover;
        fflush(stdin);
        cont++;
    }
    qsort(DonoSort, cont, sizeof(Pessoa), comparar);
    fclose(recover);

    FILE *regChave = fopen("arquivo", "wb");
    for( i = 0; i < cont; i++){
        fwrite(&DonoSort[i], sizeof(Pessoa), 1, regChave);
    }
    fclose(regChave);
    
    printf("Pessoa e seus automoveis cadastrados\n\n");

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
        printf("NOME: %s -CPF: %s- RG:%d\n", dono.nome, dono.CPF,dono.RG);
        printf("Carros desse Pessoa: ");
        for(i = 0; i < dono.QuantCarros; i++){
            printf("MODELO: %s - PLACA: %s - RENAVAM: %d\n\n", dono.carros[i].modelo,dono.carros[i].placa, dono.carros[i].RENAVAM);
        }
        fflush(stdin);
    }
    fclose(reg);
    return 0;

}

int AlteraMaxDonos(int cont,Pessoa *dono){

    int n;

    printf("Qual a nova quantidade maxima de donos voce deseja?(Considerando o numero de donos ja registrados, caso existam)\n");
    scanf(" %d", &n);

    if(n<cont){
        do{

            printf("mudanca invalida! O novo numero maximo deve ser maior que o de registros ja existentes!");
            printf("Qual a nova quantidade maxima de donos que voce deseja?\n");
            scanf(" %d", &n);
            
        }while(n<cont);
    }

    dono = (Pessoa*)malloc(n*sizeof(Pessoa));

    return 0;
}

int VerifCPF(char CPF[11]){
    int CPFvalido = 0, CPFigual;
    Pessoa dono;

    for(int i = 0; i < 11; i++){
        if(CPF[i]<48 || CPF[i]>57){ //Inválido
            CPFvalido++;
        }
    }

    FILE *reg = fopen("arquivo", "rb");
    
    if (!reg){
        return CPFvalido;
    } else{
        while (fread(&dono, sizeof(Pessoa), 1, reg)){
            CPFigual = strcmp(dono.CPF, CPF);
            if(CPFigual == 0){
                CPFvalido++;
            }
            fflush(stdin);
        }
        fclose(reg);
    }

    return CPFvalido;
}

int comparar(const void * a, const void * b){
    const Pessoa * CPF1 = (Pessoa *) a;
    const Pessoa * CPF2 = (Pessoa *) b;

    return strcmp(CPF1 -> CPF, CPF2 -> CPF);
}
