#include <stdio.h>

int posnaipe(char naipe){
	switch(naipe){
		case 'C': return 0;
		case 'E': return 1;
		case 'U': return 2;
		case 'P': return 3;
	}
}

int main(){
	char naipe;
	int carta, cartas[4][13], faltando[4],i,j,w;


	for( i = 0; i < 4; i++){
		faltando[i] = 13;
		for( j = 0; j < 13; j++){
			cartas[i][j] = 0;
		}
	}

	while(scanf("%d", &carta) > 0){	
		naipe = getchar();

		cartas[posnaipe(naipe)][carta-1]++;

		if(cartas[posnaipe(naipe)][carta-1] > 1){
			faltando[posnaipe(naipe)] = -1;
		} else{
			faltando[posnaipe(naipe)]--;
		}
		
	}

	for( w = 0; w < 4; w++){
		if(faltando[w]<0){
			printf("erro\n");
		}else{
			printf("%d\n", faltando[w]);
		}
	}

	return 0;
}