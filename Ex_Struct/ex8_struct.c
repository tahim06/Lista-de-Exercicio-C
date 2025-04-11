#include <stdio.h>
#include <stdlib.h>

typedef struct Retangulo{
    float base;
    float altura;
}Retangulo;

float calcularArea(Retangulo retangulo);
float calcularPerimetro(Retangulo Retangulo);

int main(){
    Retangulo retangulo;
    printf("Informe a Altura do Retângulo: ");
    scanf("%f", &retangulo.altura);
    printf("\nInforme a Base do Retângulo: ");
    scanf("%f", &retangulo.base);

    float perimetro = calcularPerimetro(retangulo);
    float area = calcularArea(retangulo);

    printf("Perimetro do Retângulo: %.2f\n", perimetro);
    printf("Área do Retângulo: %.2f\n", area);
    return 0;
}

float calcularArea(Retangulo retangulo){
    float area;
    return area = retangulo.altura * retangulo.base;
}

float calcularPerimetro(Retangulo retangulo){
    float perimetro;
    return perimetro = (retangulo.altura * 2) + (retangulo.base * 2);
}