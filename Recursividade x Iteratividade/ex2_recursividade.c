#include <stdio.h>
#include <stdlib.h>

int maior_elemento(int vet[], int n);

int main() {
    int vet[] = {1, 6, 4, 5, 8};
    int n = sizeof(vet) / sizeof(vet[0]);

    int maior = maior_elemento(vet, n);

    printf("O maior elemento é: %d\n", maior);
    return 0;
}

int maior_elemento(int vet[], int n) {
    if (n == 1) {
        return vet[0];
    }

    int maior_anterior = maior_elemento(vet, n - 1);

    if (vet[n - 1] > maior_anterior) {
        return vet[n - 1];
    } else {
        return maior_anterior;
    }
}
