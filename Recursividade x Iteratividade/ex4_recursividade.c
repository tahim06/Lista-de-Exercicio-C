#include <stdio.h>
#include <stdlib.h>

int produto(int a, int b);

int main(){
    int a, b;
    printf("Informe o valor(inteiro) de A: ");
    scanf("%d",&a);
    printf("Informe o valor(inteiro) de B: ");
    scanf("%d",&b);

    int x = produto(a,b);

    printf("O produto de %d e %d é igual a: %d\n\n", a, b, x);

    return 0;
}

int produto(int a, int b){
    if(b < 0){
        return -produto(a, -b);
    }

    if(b == 0){
        return 0;
    }else{
        return a + produto(a, b-1);
    }
}