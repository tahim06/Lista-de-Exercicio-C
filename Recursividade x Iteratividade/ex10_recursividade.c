#include <stdio.h>
#include <stdlib.h>

int produto(int a, int b);

int main() {
    int a, b;
    printf("Informe o valor(inteiro) de A: ");
    scanf("%d", &a);
    printf("Informe o valor(inteiro) de B: ");
    scanf("%d", &b);

    int x = produto(a, b);

    printf("O produto de %d e %d é igual a: %d\n\n", a, b, x);

    return 0;
}

int produto(int a, int b) {
    int resultado = 0;
    int sinal = 1;

    if (b < 0) {
        sinal = -1;
        b = -b;
    }

    for (int i = 0; i < b; i++) {
        resultado += a;
    }

    return resultado * sinal;
}
