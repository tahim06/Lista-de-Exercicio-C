#include <stdio.h>
#include <stdlib.h>

typedef struct ContaBancaria {
    char nome_titular[51];
    int num_conta;
    float saldo;
} ContaBancaria;

float somarSaldo(ContaBancaria *contaBancaria, float valorDeposito);
float subtrairSaldo(ContaBancaria *contaBancaria, float valorSaque);
int depositarDinheiro(ContaBancaria *contaBancaria);
int sacarValor(ContaBancaria *contaBancaria);
void exibirSaldo(ContaBancaria *contaBancaria);
void menu(ContaBancaria *contaBancaria);

int main() {
    ContaBancaria conta = {
        "João da Silva",
        12345,
        0.0
    };

    printf("Conta criada automaticamente:\n");
    printf("Titular: %s\n", conta.nome_titular);
    printf("Número da Conta: %d\n", conta.num_conta);
    printf("Saldo Inicial: R$%.2f\n", conta.saldo);

    menu(&conta);

    return 0;
}

float somarSaldo(ContaBancaria *contaBancaria, float valorDeposito) {
    contaBancaria->saldo += valorDeposito;
    return contaBancaria->saldo;
}

float subtrairSaldo(ContaBancaria *contaBancaria, float valorSaque) {
    contaBancaria->saldo -= valorSaque;
    return contaBancaria->saldo;
}

int depositarDinheiro(ContaBancaria *contaBancaria) {
    int numConta;
    float valorDeposito;
    printf("Informe o Número da Conta que deseja Depositar: ");
    scanf("%d", &numConta);
    printf("\n");
    
    if (numConta != contaBancaria->num_conta) {
        printf("Conta não encontrada.\n");
        return 0;
    } else {
        printf("Conta Encontrada!\n");
        printf("Informe o valor que deseja depositar: ");
        scanf("%f", &valorDeposito);
        
        somarSaldo(contaBancaria, valorDeposito);
        printf("Depósito de R$%.2f realizado com sucesso.\n", valorDeposito);
        return 1;
    }
}

int sacarValor(ContaBancaria *contaBancaria) {
    int numConta;
    float saldoSaque;
    printf("Informe o Número da Conta que deseja Sacar: ");
    scanf("%d", &numConta);
    printf("\n");

    if (numConta != contaBancaria->num_conta) {
        printf("Não foi possível encontrar a conta desejada.\n");
        return 0;
    } else {
        printf("Conta Encontrada!\n");
        printf("Informe o valor que deseja sacar: ");
        scanf("%f", &saldoSaque);
        printf("\n");

        if (contaBancaria->saldo >= saldoSaque) {
            subtrairSaldo(contaBancaria, saldoSaque);
            printf("Saque de R$%.2f realizado com sucesso!\n", saldoSaque);
            return 1;
        } else {
            printf("Saldo da conta insuficiente para sacar o valor de R$%.2f.\n", saldoSaque);
            return 0;
        }
    }
}

void exibirSaldo(ContaBancaria *contaBancaria) {
    printf("\n==== SALDO DA CONTA ====\n");
    printf("Titular: %s\n", contaBancaria->nome_titular);
    printf("Número da Conta: %d\n", contaBancaria->num_conta);
    printf("Saldo Atual: R$%.2f\n", contaBancaria->saldo);
}

void menu(ContaBancaria *contaBancaria) {
    int opcao;
    do {
        printf("\n==== MENU CONTA BANCÁRIA ====\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Exibir Saldo\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                depositarDinheiro(contaBancaria);
                break;
            case 2:
                sacarValor(contaBancaria);
                break;
            case 3:
                exibirSaldo(contaBancaria);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while(opcao != 0);
}