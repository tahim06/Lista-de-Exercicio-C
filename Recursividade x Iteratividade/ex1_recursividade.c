#include <stdio.h>
#include <stdlib.h>

int contar_digitos(int n);

int main(){
    int n, qtd_digitos;

    printf("Informe o número que deseja contar os Dígitos: ");
    scanf("%d", &n);
    
    qtd_digitos = contar_digitos(n);

    printf("O número %d possui %d dígitos.\n", n, qtd_digitos);


    return 0;
}

int contar_digitos(int n){
    n = abs(n);

    if(n < 10){
        return 1;
    } else{
        return 1 + contar_digitos(n/10); 
    }

}