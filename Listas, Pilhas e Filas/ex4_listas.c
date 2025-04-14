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

int contagemElementos(Lista *lista);
void inicializarLista(Lista* lista);
No* criarNo(int valor);
void inserirInicio(Lista* lista, int valor);
void inserirFinal(Lista* lista, int valor);
void remover(Lista* lista, int valor);
void exibir(Lista* lista);
void liberarLista(Lista* lista);
void inverterLista(Lista *lista);

int main() {
    Lista lista;
    int qtdElementos;
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
    printf("\n");
    
    qtdElementos = contagemElementos(&lista);
    
    printf("A lista possui %d Elementos.\n\n", qtdElementos);
    
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

int contagemElementos(Lista *lista){
    No *atual = lista->inicio;
    int qtd = 0;

    while(atual != NULL){
        qtd++;
        atual = atual->prox;
    }
    return qtd;
}

void liberarLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
    lista->fim = NULL;
}

void inverterLista(Lista *lista){
    No* anterior = NULL;
    No* atual = lista->inicio;
    No* prox = NULL;

    lista->fim = lista->inicio;

    while(atual != NULL){
        prox = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = prox;
    }
    lista->inicio = anterior;
}