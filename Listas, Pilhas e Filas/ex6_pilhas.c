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
void pop(Pilha* pilha);
int isEmpty(Pilha* pilha);
int verificarParenteses(const char* expressao);
void limparPilha(Pilha* pilha);

int main() {
    const char* expressao1 = "(())()";
    const char* expressao2 = "(()";

    printf("Expressao: %s -> %s\n", expressao1, verificarParenteses(expressao1) ? "Válido" : "Inválido");
    printf("Expressao: %s -> %s\n", expressao2, verificarParenteses(expressao2) ? "Válido" : "Inválido");

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

void pop(Pilha* pilha) {
    if (!isEmpty(pilha)) {
        No* temp = pilha->top;
        pilha->top = temp->prox;
        free(temp);
    }
}

int isEmpty(Pilha* pilha) {
    return pilha->top == NULL;
}

void limparPilha(Pilha* pilha) {
    while (!isEmpty(pilha)) {
        pop(pilha);
    }
}

int verificarParenteses(const char* expressao) {
    Pilha pilha;
    inicializarPilha(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            push(&pilha, '(');
        } else if (expressao[i] == ')') {
            if (isEmpty(&pilha)) {
                return 0;
            }
            pop(&pilha);
        }
    }

    int resultado = isEmpty(&pilha);
    limparPilha(&pilha);
    return resultado;
}
