#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct Fila {
    No* inicio;
    No* fim;
} Fila;

void inicializarFila(Fila *fila);
No* criarNo(int valor);
int isEmpty(Fila* fila);
void enqueue(Fila* fila, int valor);
void dequeue(Fila *fila);
void front(Fila *fila);

int main() {
    Fila fila;
    inicializarFila(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    front(&fila);
    dequeue(&fila);
    front(&fila);
    dequeue(&fila);
    front(&fila);
    dequeue(&fila);
    front(&fila);

    return 0;
}

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL) {
        printf("Erro ao Alocar Memória!\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

int isEmpty(Fila* fila) {
    return fila->inicio == NULL;
}

void enqueue(Fila* fila, int valor) {
    No* novoNo = criarNo(valor);
    if(isEmpty(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
    printf("Valor %d adicionado à Fila!\n\n", valor);
}

void dequeue(Fila *fila) {
    if(isEmpty(fila)) {
        printf("Fila está Vazia!\n\n");
        return;
    } else {
        No *temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        printf("Valor %d foi Removido da Fila!\n\n", temp->valor);
        free(temp);
        if (fila->inicio == NULL) {
            fila->fim = NULL;
        }
    }
}

void front(Fila *fila) {
    if(isEmpty(fila)) {
        printf("Fila está Vazia!\n\n");
    } else {
        printf("O primeiro elemento da Fila é: %d\n\n", fila->inicio->valor);
    }
}
