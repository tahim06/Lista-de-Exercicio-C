#include <stdio.h>
#include <stdlib.h>

void contagemRegressiva(int n);

int main(){
    int n;
    printf("Informe o numero de N: ");
    scanf("%d", &n);
    printf("\nContagem Regressiva(%d): ", n);
    contagemRegressiva(n);
    printf("\n\n");
    return 0;
}

void contagemRegressiva(int n){
    if(n < 0){
        return;
    }
    printf("%d ",n);
    return contagemRegressiva(n - 1);
}