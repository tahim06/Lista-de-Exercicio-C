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
    int maior = vet[0];

    for (int i = 1; i < n; i++) {
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }

    return maior;
}
