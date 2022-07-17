#include <stdio.h>
#include <stdlib.h>

//macros

#define key(A) (A.cargo)
#define less(A, B) (A.voto == B.voto ? key(A) > key(B) : A.voto > B.voto) // comparar se a quantidade de voto for igual, pelo cargo em si
#define exch(A, B)  {politico t = B; B = A; A = t;}
#define cmpexch(A, B) {if (less(B, A)) exch(A, B)}


//struct dados politicos

typedef struct politico{
    int cargo;
    int voto;
} politico;

//globais

politico pres[91], sen[901], fed[9001], est[90001];
int quantPres = 0, quantSen = 0, quantDepFed = 0, quantDepEst = 0;

//funcoes assinadas

int separa(politico *lista, int l, int r);
void quicksort(politico *lista, int l, int r);

//main

int main()
{
    long long senadores, depFederais, depEstaduais,i;
    scanf(" %lld %lld %lld", &senadores, &depFederais, &depEstaduais);

    int valido = 0, invalidoo = 0, totalVotos = 0, votoLido, l;

    while (scanf(" %d%n", &votoLido, &l) != EOF){ //le numero do candidato depEstaduais captura o quantidade de numeros digitados para diferenciar o tipo de voto(%n)

        if (votoLido < 0){
            invalidoo++;
            continue;
        }

        switch (l){ // Quantidade de caracteres lidos(%n) salva nos vetores o voto do político como indice

        case 3: // Presidente
            pres[votoLido - 10].cargo = votoLido;
            pres[votoLido - 10].voto++;
            totalVotos++;
            break;
        case 4: //Senador
            sen[votoLido - 100].cargo = votoLido;
            sen[votoLido - 100].voto++;
            break;
        case 5: //Deputado Federal
            fed[votoLido - 1000].cargo = votoLido;
            fed[votoLido - 1000].voto++;
            break;
        default: //Deputado Estadual
            est[votoLido - 10000].cargo = votoLido;
            est[votoLido - 10000].voto++;
        }
        valido++;
    }

    // Correcao para os índices corretos

    for (i = 0; i < 91; i++){
        if (pres[i].voto){
            pres[quantPres++] = pres[i];
        }   
    }
        
    for (i = 0; i < 901; i++){
        if (sen[i].voto){
            sen[quantSen++] = sen[i];
        }     
    }
        
    for (i = 0; i < 9001; i++){
        if (fed[i].voto){
            fed[quantDepFed++] = fed[i];
        }  
    }
        
    for (i = 0; i < 90001; i++){
        if (est[i].voto){
            est[quantDepEst++] = est[i];
        }
    }

    printf("%d %d\n", valido, invalidoo);

    quicksort(pres, 0, quantPres - 1);
    quicksort(sen, 0, quantSen - 1);
    quicksort(fed, 0, quantDepFed - 1);
    quicksort(est, 0, quantDepEst - 1);

    if ((double)pres[0].voto/totalVotos >= 0.51){//mais que 51% de votos totais
        printf("%d\n", pres[0].cargo);
    } else{
        printf("Segundo turno\n");
    }   

    for (i = 0; i < senadores; i++){
        printf("%d%c", sen[i].cargo, " \n"[i == senadores - 1]);
    }
        
    for (i = 0; i < depFederais; i++){
        printf("%d%c", fed[i].cargo, " \n"[i == depFederais - 1]);
    }
        
    for (i = 0; i < depEstaduais; i++){
        printf("%d%c", est[i].cargo, " \n"[i == depEstaduais - 1]);
    }

    return 0;
}

//funcoes

int separa(politico *lista, int l, int r)
{
    politico aux = lista[r];
    int j = l,k;

    for (k = l; k < r; k++){
        if (less(lista[k], aux)){
            exch(lista[k], lista[j]);
            j++;
        }
    }
    exch(lista[j], lista[r]);
    
    return j;
}

void quicksort(politico *lista, int l, int r){
    
    if (l >= r) return;//caso base

    //calculo mediana
    cmpexch(lista[(l + r) / 2], lista[r]);
    cmpexch(lista[l], lista[(l + r) / 2]);
    cmpexch(lista[r], lista[(l + r) / 2]);

    int j = separa(lista, l, r);
    quicksort(lista, l, j - 1);
    quicksort(lista, j + 1, r);
}
