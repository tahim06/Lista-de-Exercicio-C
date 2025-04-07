#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* prox;
}No;

typedef struct Lista{
    No* inicio;
    No* fim;
}Lista;


int main(){



    return 0;
}

void inicializarLista(Lista* lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

void criarNo(Lista *lista ,int valor){
    No *novoNo =(No*)malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novoNo->valor = 0;
    novoNo->prox = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novoNo;
        lista->fim = novoNo;
    } else{
        lista->fim->prox = novoNo;
        lista->fim = novoNo;
    }
}

void inserirInicio(Lista* lista, int valor){
    No *novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novoNo->valor = valor;

    if(lista->inicio == NULL){
        lista->inicio = novoNo;
    }else{
        novoNo->prox = lista->inicio;
        lista->inicio = novoNo;
    } 

    if(lista->fim == NULL){
        lista->fim = novoNo;
    }
}