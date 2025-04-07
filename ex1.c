#include <stdio.h>
#include <stdio.h>

typedef struct Pessoa{
    char nome[51];
    int idade;
    float altura;
}Pessoa;

int main(){
    Pessoa pessoa; 

    printf("Informe o Nome:\n ");
    scanf("%[^\n]", pessoa.nome);
    getchar();

    printf("Informe a Idade:\n ");
    scanf("%d", &pessoa.idade);

    printf("Informe a Altura (ex: 1.75):\n ");
    scanf("%f", &pessoa.altura);

    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Altura: %.2f\n", pessoa.altura);

    return 0;
}