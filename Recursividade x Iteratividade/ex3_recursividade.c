#include <stdio.h>
#include <stdlib.h>

int somaDigitos(int n);

int main(){

    int n;
    printf("Informe um número inteiro: \n");
    scanf("%d", &n);
    int soma = somaDigitos(n);
    printf("Soma dos Dígitos: %d\n\n", soma);
    return 0;
}

int somaDigitos(int n){
    if(n < 10){
        return n;
    } else{
        return (n % 10) + somaDigitos(n/10);
    }

}