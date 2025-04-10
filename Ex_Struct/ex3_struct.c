#include <stdio.h>
#include <stdlib.h>

typedef struct Produto{
    char nomeProduto[31];
    int codigo;
    float preco;
}Produto;

void exibirDados(Produto produto);

int main(){
    Produto produto;
    printf("Informe o nome do produto:\n");
    scanf("%30[^\n]", produto.nomeProduto);
    getchar();
    printf("Informe o Código do Produto:\n");
    scanf("%d", &produto.codigo);
    printf("Informe o Preço do Produto (ex: 2.00):\n");
    scanf("%f",&produto.preco);

    exibirDados(produto);

    return 0;
}

void exibirDados(Produto produto){
    printf("-------Infos Produto-------\n");
    printf("Nome do Produto: %s\n", produto.nomeProduto);
    printf("Código do Produto: %d\n", produto.codigo);
    printf("Preço do produto: %.2f\n", produto.preco);
}