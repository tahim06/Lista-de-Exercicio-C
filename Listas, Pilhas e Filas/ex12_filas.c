#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[50];
    struct No *prox;
} No;

typedef struct Fila {
    No *inicio;
    No *fim;
} Fila;

typedef struct Pilha {
    No *topo;
} Pilha;

void inicializarFila(Fila *fila);
void inicializarPilha(Pilha *pilha);
No* criarNo(char *nome);
int isEmptyFila(Fila *fila);
int isEmptyPilha(Pilha *pilha);
void enqueue(Fila *fila, char *nome);
void dequeue(Fila *fila);
void push(Pilha *pilha, No *no);
No* pop(Pilha *pilha);
void inverterFila(Fila *fila);
void mostrarFila(Fila *fila);

int main() {
    Fila fila;
    inicializarFila(&fila);

    enqueue(&fila, "Ana");
    enqueue(&fila, "Bruno");
    enqueue(&fila, "Carla");
    enqueue(&fila, "Daniel");

    printf("Fila original:\n");
    mostrarFila(&fila);

    inverterFila(&fila);

    printf("\nFila invertida:\n");
    mostrarFila(&fila);

    return 0;
}

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

No* criarNo(char *nome) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    return novo;
}

int isEmptyFila(Fila *fila) {
    return fila->inicio == NULL;
}

int isEmptyPilha(Pilha *pilha) {
    return pilha->topo == NULL;
}

void enqueue(Fila *fila, char *nome) {
    No *novo = criarNo(nome);
    if (isEmptyFila(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

void dequeue(Fila *fila) {
    if (!isEmptyFila(fila)) {
        No *temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        if (fila->inicio == NULL)
            fila->fim = NULL;
        free(temp);
    }
}

void push(Pilha *pilha, No *no) {
    no->prox = pilha->topo;
    pilha->topo = no;
}

No* pop(Pilha *pilha) {
    if (!isEmptyPilha(pilha)) {
        No *temp = pilha->topo;
        pilha->topo = pilha->topo->prox;
        return temp;
    }
    return NULL;
}

void inverterFila(Fila *fila) {
    Pilha pilha;
    inicializarPilha(&pilha);

    while (!isEmptyFila(fila)) {
        No *temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        push(&pilha, temp);
    }
    fila->fim = NULL;

    while (!isEmptyPilha(&pilha)) {
        No *temp = pop(&pilha);
        temp->prox = NULL;
        if (isEmptyFila(fila)) {
            fila->inicio = temp;
            fila->fim = temp;
        } else {
            fila->fim->prox = temp;
            fila->fim = temp;
        }
    }
}

void mostrarFila(Fila *fila) {
    No *atual = fila->inicio;
    int i = 1;
    while (atual != NULL) {
        printf("%d. %s\n", i++, atual->nome);
        atual = atual->prox;
    }
}
