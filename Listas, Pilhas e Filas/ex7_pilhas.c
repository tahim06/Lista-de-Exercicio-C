#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No* prox;
} No;

typedef struct Pilha {
    No* top;
} Pilha;

void inicializarPilha(Pilha* pilha);
No* criarNo(char valor);
void push(Pilha* pilha, char valor);
char pop(Pilha* pilha);
int isEmpty(Pilha* pilha);
void limparPilha(Pilha* pilha);
void inverterString(const char* strOriginal, char* strInvertida);

int main() {
    const char* texto = "estrutura";
    char invertida[100];

    inverterString(texto, invertida);
    printf("Original: %s\n", texto);
    printf("Invertida: %s\n", invertida);

    return 0;
}

void inicializarPilha(Pilha* pilha) {
    pilha->top = NULL;
}

No* criarNo(char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void push(Pilha* pilha, char valor) {
    No* novoNo = criarNo(valor);
    novoNo->prox = pilha->top;
    pilha->top = novoNo;
}

char pop(Pilha* pilha) {
    if (isEmpty(pilha)) {
        return '\0';
    }
    No* temp = pilha->top;
    char valor = temp->valor;
    pilha->top = temp->prox;
    free(temp);
    return valor;
}

int isEmpty(Pilha* pilha) {
    return pilha->top == NULL;
}

void limparPilha(Pilha* pilha) {
    while (!isEmpty(pilha)) {
        pop(pilha);
    }
}

void inverterString(const char* strOriginal, char* strInvertida) {
    Pilha pilha;
    inicializarPilha(&pilha);

    for (int i = 0; strOriginal[i] != '\0'; i++) {
        push(&pilha, strOriginal[i]);
    }

    int i = 0;
    while (!isEmpty(&pilha)) {
        strInvertida[i++] = pop(&pilha);
    }
    strInvertida[i] = '\0';

    limparPilha(&pilha);
}
