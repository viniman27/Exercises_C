#include <stdio.h>

void moverX(char *string, int i){
    if(string[i] != '\0'){
        if(string[i] != 'x'){
            printf("%c", string[i]);
            moverX(string, i+1); //imprime os não X na ida -> laço q pula de um em um
        }
        else{
            moverX(string, i+1);
            printf("%c", string[i]); //imprime os X nas voltas
        }
    }
}

int main(){
    char string[101];

    scanf("%s", string);
    moverX(string, 0);

    return 0;
}