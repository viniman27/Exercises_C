#include<stdio.h>


int encaixa(int a,int b){

   if (b==0){
        if ((a%10)==0){
            return 1;
        }else{
            return 0;
        }
    }else{

        while(b!=0 && a%10==b%10)
        {
            a/=10;
            b/=10;
        }

        if(b==0){
            return 1;
        }
        else{
            return 0;
        }
    }
}

