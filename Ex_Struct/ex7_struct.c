#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 30

typedef struct Agenda {
    char nome[51];
    char telefone[16];
} Agenda;

int adicionarContato(Agenda agenda[], int totalContatos);
void buscarContato(Agenda agenda[], int totalContatos);
void menu(Agenda agenda[]);

int main() {
    Agenda agenda[TAM];
    menu(agenda);
    return 0;
}

int adicionarContato(Agenda agenda[], int totalContatos) {
    if (totalContatos >= TAM) {
        printf("Agenda cheia! Não é possível adicionar mais contatos.\n");
        return totalContatos;
    }
    getchar();
    printf("Informe o nome do Contato que deseja adicionar: \n");
    scanf("%50[^\n]", agenda[totalContatos].nome);
    getchar();
    printf("Informe o telefone de %s: \n", agenda[totalContatos].nome);
    scanf("%15[^\n]", agenda[totalContatos].telefone);
    getchar();
    printf("Contato %s adicionado com sucesso!\n\n", agenda[totalContatos].nome);
    return totalContatos + 1;
}

void buscarContato(Agenda agenda[], int totalContatos) {
    char nomeBusca[51];
    getchar(); // limpar buffer
    printf("Qual o nome do Contato que deseja buscar?\n");
    scanf("%50[^\n]", nomeBusca);
    getchar();

    int encontrou = 0;
    for (int i = 0; i < totalContatos; i++) {
        if (strcmp(agenda[i].nome, nomeBusca) == 0) {
            encontrou = 1;
            printf("Contato Encontrado: \n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n\n", agenda[i].telefone);
            break;
        }
    }

    if (!encontrou) {
        printf("Contato %s Não Encontrado!\n\n", nomeBusca);
    }
}

void menu(Agenda agenda[]) {
    int opcao, totalContatos = 0;
    do {
        printf("O que deseja?\n");
        printf("1 - Adicionar Contato\n");
        printf("2 - Buscar Contato\n");
        printf("0 - Sair do Programa\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                totalContatos = adicionarContato(agenda, totalContatos);
                break;
            case 2:
                buscarContato(agenda, totalContatos);
                break;
            case 0:
                printf("Saindo do Programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
}
