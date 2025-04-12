#include <stdio.h>
#include <stdlib.h>

typedef struct Paciente
{
    char nome[51];
    int idade;
    char diagnostico[101];
}Paciente;

void exibirPacientes60(Paciente pacientes[], int quantidade);

int main(){
    Paciente pacientes[100] = {
        {"João da Silva", 65, "Hipertensão"},
        {"Maria Oliveira", 45, "Diabetes"},
        {"Carlos Souza", 72, "Artrite"},
        {"Ana Paula", 30, "Enxaqueca"}
    };

    int qtd = 4;

    exibirPacientes60(pacientes, qtd);

    return 0;
}

void exibirPacientes60(Paciente pacientes[], int quantidade) {
    printf("Pacientes com mais de 60 anos:\n");
    for (int i = 0; i < quantidade; i++) {
        if (pacientes[i].idade > 60) {
            printf("Nome: %s\n", pacientes[i].nome);
            printf("Idade: %d\n", pacientes[i].idade);
            printf("Diagnóstico: %s\n\n", pacientes[i].diagnostico);
        }
    }
}