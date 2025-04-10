#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionarios{
    char nome[51];
    char cargo[31];
    float salario;
}Funcionarios;

int main(){
    int N;
    printf("Informe quantos Funcionários deseja Cadastrar:\n");
    scanf("%d", &N);
    getchar();

    Funcionarios funcionarios[N];

    for(int i = 0; i < N; i++){
        printf("Informe o Nome do %dº Funcionário:\n", i+1);
        scanf("%50[^\n]", funcionarios[i].nome);
        getchar();
        printf("Informe o Cargo de %s:\n", funcionarios[i].nome);
        scanf("%50[^\n]", funcionarios[i].cargo);
        getchar();
        printf("Informe o Salário de %s:\n", funcionarios[i].nome);    
        scanf("%f", &funcionarios[i].salario);
        getchar();
    }
    printf("\n----------Info Funcionários----------\n");
    for(int i = 0; i < N; i++){
        printf("Funcionário %d :\n\n",i+1);
        printf("Nome do Funcionário: %s\n", funcionarios[i].nome);
        printf("Cargo de %s: %s\n", funcionarios[i].nome, funcionarios[i].cargo);
        printf("Salário de %s: %.2f\n", funcionarios[i].nome, funcionarios[i].salario);
        printf("\n-------//-------//--------//-------\n");
    }
    return 0;
}