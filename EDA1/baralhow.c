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
	int carta, cartas[4][13], faltando[4];

	for(int i = 0; i < 4; i++){
		faltando[i] = 13;
		for(int j = 0; j < 13; j++){
			cartas[i][j];
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

	for(int i = 0; i < 4; i++){
		if(faltando[i]<0){
			printf("erro\n");
		}else{
			printf("%d\n", faltando[i]);
		}
	}

	return 0;
}