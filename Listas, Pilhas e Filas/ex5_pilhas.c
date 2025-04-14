#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* prox;
}No;

typedef struct Pilha{
    No *top;
}Pilha;

void inicializarPilha(Pilha *pilha);
No* criarNo(int valor);
void push(Pilha *pilha, int valor);
void pop(Pilha *pilha);
void exibirTop(Pilha *pilha);
int isEmpty(Pilha *pilha);
void limparPilha(Pilha *pilha);

int main(){
    Pilha pilha;
    inicializarPilha(&pilha);

    push(&pilha, 10);
    exibirTop(&pilha);
    push(&pilha, 20);
    exibirTop(&pilha);
    push(&pilha, 30);
    exibirTop(&pilha);

    pop(&pilha);
    exibirTop(&pilha);

    limparPilha(&pilha);
    exibirTop(&pilha);
}

void inicializarPilha(Pilha *pilha){
    pilha->top = NULL;
}

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Erro ao alocar Memória!\n\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;

    return novoNo;
}

void push(Pilha *pilha, int valor){
    No* novoNo = criarNo(valor);

    if(isEmpty(pilha)){
        pilha->top = novoNo;
    }else{
        novoNo->prox = pilha->top;
        pilha->top = novoNo;
    }
    printf("Valor %d adicionado ao Topo da Pilha !\n\n", valor);   
}

void pop(Pilha *pilha){
    if(isEmpty(pilha)){
        printf("Pilha está Vazia!\n\n");
        return;
    }else{
        No *temp = pilha->top;
        pilha->top = pilha->top->prox;
        printf("Valor %d Removido do Topo da Pilha!\n\n",temp->valor);
        free(temp);
    }
}

void exibirTop(Pilha *pilha){
    if(isEmpty(pilha)){
        printf("Pilha Vazia!\n");
        return;
    }else{
        printf("Topo da Pilha: %d\n\n ", pilha->top->valor);
    }    
}

int isEmpty(Pilha *pilha){
    if(pilha->top == NULL){
        return 1;        
    }else{
        return 0;
    }
}

void limparPilha(Pilha *pilha){
    while (!isEmpty(pilha)) {
        pop(pilha);
    }
}
