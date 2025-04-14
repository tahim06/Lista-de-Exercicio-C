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

void inicializarFila(Fila *fila);
No* criarNo(char *nome);
int isEmpty(Fila *fila);
void entrarNaFila(Fila *fila, char *nome);
void atenderCliente(Fila *fila);
void mostrarFila(Fila *fila);

int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;
    char nome[50];

    do {
        printf("=== Banco - Simulador de Atendimento ===\n");
        printf("1. Cliente chega (Entrar na fila)\n");
        printf("2. Atender próximo cliente\n");
        printf("3. Mostrar fila atual\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("Digite o nome do cliente: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                entrarNaFila(&fila, nome);
                break;
            case 2:
                atenderCliente(&fila);
                break;
            case 3:
                mostrarFila(&fila);
                break;
            case 0:
                printf("Encerrando atendimento...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

        printf("\n");

    } while (opcao != 0);

    return 0;
}

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
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

int isEmpty(Fila *fila) {
    return fila->inicio == NULL;
}

void entrarNaFila(Fila *fila, char *nome) {
    No *novo = criarNo(nome);
    if (isEmpty(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    printf("Cliente %s entrou na fila.\n", nome);
}

void atenderCliente(Fila *fila) {
    if (isEmpty(fila)) {
        printf("Nenhum cliente na fila para atendimento.\n");
        return;
    }

    No *temp = fila->inicio;
    printf("Atendendo cliente: %s\n", temp->nome);
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);
}

void mostrarFila(Fila *fila) {
    if (isEmpty(fila)) {
        printf("Fila está vazia.\n");
        return;
    }

    printf("Clientes na fila:\n");
    No *atual = fila->inicio;
    int pos = 1;
    while (atual != NULL) {
        printf("%d. %s\n", pos++, atual->nome);
        atual = atual->prox;
    }
}
