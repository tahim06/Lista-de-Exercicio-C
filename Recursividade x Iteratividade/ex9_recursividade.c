#include <stdio.h>
#include <stdlib.h>

int somaDigitos(int n);

int main() {
    int n;
    printf("Informe um número inteiro: \n");
    scanf("%d", &n);
    int soma = somaDigitos(n);
    printf("Soma dos Dígitos: %d\n\n", soma);
    return 0;
}

int somaDigitos(int n) {
    int soma = 0;
    n = abs(n);

    while (n > 0) {
        soma += n % 10;
        n /= 10;
    }

    return soma;
}