#include <stdio.h>
#include <stdlib.h>

void contagemRegressiva(int n);

int main(){
    int n;
    do{
        printf("Informe um número(inteiro) maior que Zero: ");
        scanf("%d", &n);
    }while(n <= 0);

    printf("Contagem Regressiva(%d) -> ", n);
    contagemRegressiva(n);
    printf("\n\n");

    return 0;
}

void contagemRegressiva(int n){
    while(n >= 0){
        printf("%d ", n);
        n--;
    }
}
