#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct Fila {
    int dados[TAM];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializarFila(Fila* fila);
int isEmpty(Fila* fila);
int isFull(Fila* fila);
void enqueue(Fila* fila, int valor);
void dequeue(Fila* fila);
void front(Fila* fila);

int main() {
    Fila fila;
    inicializarFila(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    front(&fila);

    dequeue(&fila);
    front(&fila);

    enqueue(&fila, 40);
    front(&fila);

    dequeue(&fila);
    front(&fila);

    enqueue(&fila, 50);
    enqueue(&fila, 60);
    front(&fila);

    return 0;
}

void inicializarFila(Fila* fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
}

int isEmpty(Fila* fila) {
    return fila->tamanho == 0;
}

int isFull(Fila* fila) {
    return fila->tamanho == TAM;
}

void enqueue(Fila* fila, int valor) {
    if (isFull(fila)) {
        printf("Fila Cheia! Não é possível adicionar %d\n\n", valor);
        return;
    }

    fila->dados[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % TAM;
    fila->tamanho++;
    printf("Valor %d adicionado à Fila!\n\n", valor);
}

void dequeue(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Fila está Vazia!\n\n");
        return;
    }

    printf("Valor %d foi Removido da Fila!\n\n", fila->dados[fila->inicio]);
    fila->inicio = (fila->inicio + 1) % TAM;
    fila->tamanho--;
}

void front(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Fila está Vazia!\n\n");
    } else {
        printf("O primeiro elemento da Fila é: %d\n\n", fila->dados[fila->inicio]);
    }
}
