#include <stdio.h>
#include <stdlib.h>

int maior_elemento(int vet[], int n);

int main() {
    int vet[] = {1, 6, 4, 5, 8};
    int n = sizeof(vet) / sizeof(vet[0]);  // Correto

    int maior = maior_elemento(vet, n);

    printf("O maior elemento é: %d\n", maior);  // Saída esperada: 8
    return 0;
}

int maior_elemento(int vet[], int n) {
    // Caso base: vetor com um único elemento
    if (n == 1) {
        return vet[0];
    }

    // Recursão: maior entre o último e os anteriores
    int maior_anterior = maior_elemento(vet, n - 1);

    if (vet[n - 1] > maior_anterior) {
        return vet[n - 1];
    } else {
        return maior_anterior;
    }
}
