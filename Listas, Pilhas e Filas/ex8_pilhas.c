#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int bit;
    struct No* prox;
} No;

typedef struct Pilha {
    No* top;
} Pilha;

void inicializarPilha(Pilha* pilha);
No* criarNo(int bit);
void push(Pilha* pilha, int bit);
int pop(Pilha* pilha);
int isEmpty(Pilha* pilha);
void limparPilha(Pilha* pilha);
void converterDecimalParaBinario(int numero);

int main() {
    int numero;

    printf("Digite um número decimal: ");
    scanf("%d", &numero);

    printf("Binário: ");
    converterDecimalParaBinario(numero);
    printf("\n");

    return 0;
}

void inicializarPilha(Pilha* pilha) {
    pilha->top = NULL;
}

No* criarNo(int bit) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        exit(1);
    }
    novoNo->bit = bit;
    novoNo->prox = NULL;
    return novoNo;
}

void push(Pilha* pilha, int bit) {
    No* novoNo = criarNo(bit);
    novoNo->prox = pilha->top;
    pilha->top = novoNo;
}

int pop(Pilha* pilha) {
    if (isEmpty(pilha)) {
        return -1;
    }
    No* temp = pilha->top;
    int bit = temp->bit;
    pilha->top = temp->prox;
    free(temp);
    return bit;
}

int isEmpty(Pilha* pilha) {
    return pilha->top == NULL;
}

void limparPilha(Pilha* pilha) {
    while (!isEmpty(pilha)) {
        pop(pilha);
    }
}

void converterDecimalParaBinario(int numero) {
    Pilha pilha;
    inicializarPilha(&pilha);

    if (numero == 0) {
        printf("0");
        return;
    }

    while (numero > 0) {
        push(&pilha, numero % 2);
        numero /= 2;
    }

    while (!isEmpty(&pilha)) {
        printf("%d", pop(&pilha));
    }

    limparPilha(&pilha);
}
