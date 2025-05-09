#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct Lista {
    No* inicio;
    No* fim;
} Lista;

void inicializarLista(Lista* lista);
No* criarNo(int valor);
void inserirInicio(Lista* lista, int valor);
void inserirFinal(Lista* lista, int valor);
void remover(Lista* lista, int valor);
void exibir(Lista* lista);
void liberarLista(Lista* lista);

int main() {
    Lista lista;
    inicializarLista(&lista);

    inserirInicio(&lista, 10);
    exibir(&lista);
    inserirInicio(&lista, 50);
    exibir(&lista);
    inserirFinal(&lista, 20);
    exibir(&lista);
    inserirFinal(&lista, 30);
    exibir(&lista);
    remover(&lista, 20);
    exibir(&lista);
    
    liberarLista(&lista);

    return 0;
}

void inicializarLista(Lista* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void inserirInicio(Lista* lista, int valor) {
    No* novoNo = criarNo(valor);

    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
    } else {
        novoNo->prox = lista->inicio;
        lista->inicio = novoNo;
    }

    printf("Valor adicionado com Sucesso!\n");
}

void inserirFinal(Lista* lista, int valor) {
    No* novoNo = criarNo(valor);

    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
    } else {
        lista->fim->prox = novoNo;
        lista->fim = novoNo;
    }

    printf("Valor adicionado com Sucesso!\n");
}

void remover(Lista* lista, int valor) {
    if (lista->inicio == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    No* atual = lista->inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor não encontrado na Lista.\n");
        return;
    }

    if (anterior == NULL) {
        lista->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    if (atual == lista->fim) {
        lista->fim = anterior;
    }

    free(atual);
    printf("Valor %d removido com Sucesso!\n", valor);
}

void exibir(Lista* lista) {
    if (lista->inicio == NULL) {
        printf("Lista está vazia!\n");
        return;
    }

    No* atual = lista->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}
