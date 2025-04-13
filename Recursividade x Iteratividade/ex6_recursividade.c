#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

int isPalindromo(char string[], int inicio, int fim);

int main(){
    char str[TAM];

    printf("Digite uma Palavra: ");
    scanf("%100[^\n]", str);
    getchar();

    int fim = strlen(str);
    int inicio = 0;

    if(isPalindromo(str, inicio, fim) == 1){
        printf("'%s' É um Palíndromo\n\n", str);
    } else{
        printf("'%s' Não é um Palíndromo\n\n", str);
    }
    
    
    return 0;
}

int isPalindromo(char string[], int inicio, int fim){
    
    if(inicio >= fim){
        return 1;
    }

    if(string[inicio] != string[fim-1]){
        return 0;
    } else{
        return isPalindromo(string, inicio + 1, fim - 1);
    }
}