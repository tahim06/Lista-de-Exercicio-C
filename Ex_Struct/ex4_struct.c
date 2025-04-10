#include <stdio.h>
#include <stdlib.h>

typedef struct Carro{
    char modelo[31];
    int ano;
    float preco;
}Carro;

int main(){
    Carro *carro = (Carro*)malloc(sizeof(Carro));

    printf("Informe o Modelo do Carro: \n"); 
    scanf("%30[^\n]", carro->modelo);
    printf("Informe o Ano do Carro:\n");
    scanf("%d", &carro->ano);
    printf("Informe o Preço deste Modelo:\n");
    scanf("%f", &carro->preco);

    printf("\n----------Info Carro----------\n");
    printf("Modelo do Carro: %s\n", carro->modelo);
    printf("Ano do Carro: %d\n", carro->ano);
    printf("Preço do Carro: %.2f\n", carro->preco);

    free(carro);

    return 0;
}