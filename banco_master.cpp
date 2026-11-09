#include <stdio.h>
 
int main(void) {
    int senha, senhaDigitada;
    int opcao;
    float saldo = 500.00f;
    float valor;
    float maiorDeposito = 0.0f;
 
   
    do {
        printf("Crie uma senha numerica de 4 digitos: ");
        if (scanf("%d", &senha) != 1) {
            while (getchar() != '\n'); 
            senha = 0;
        }
        if (senha < 1000 || senha > 9999) {
            printf("Senha invalida! Ela deve ter exatamente 4 digitos.\n");
        }
    } while (senha < 1000 || senha > 9999);
 
    printf("Senha cadastrada com sucesso!\n");
 
    do {
        printf("\n===== MENU =====\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Consultar Saldo e Estatisticas\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
 
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            opcao = 0;
        }
 
        switch (opcao) {
            case 1:
                printf("Valor do deposito: R$ ");
                if (scanf("%f", &valor) != 1) {
                    while (getchar() != '\n');
                    valor = 0;
                }
                if (valor <= 0) {
                    printf("Valor invalido!\n");
                } else {
                    saldo += valor;
                    if (valor > maiorDeposito) {
                        maiorDeposito = valor;
                    }
                    printf("Deposito realizado com sucesso!\n");
                }
                break;
 
            case 2:
                printf("Digite sua senha de 4 digitos: ");
                if (scanf("%d", &senhaDigitada) != 1) {
                    while (getchar() != '\n');
                    senhaDigitada = -1;
                }
                if (senhaDigitada != senha) {
                    printf("Senha Incorreta! Operacao cancelada.\n");
                } else {
                    printf("Valor do saque: R$ ");
                    if (scanf("%f", &valor) != 1) {
                        while (getchar() != '\n');
                        valor = 0;
                    }
                    if (valor > saldo) {
                        printf("Saldo Insuficiente!\n");
                    } else if (valor <= 0) {
                        printf("Valor invalido!\n");
                    } else {
                        saldo -= valor;
                        printf("Saque realizado com sucesso!\n");
                    }
                }
                break;
 
            case 3:
                printf("Saldo atual: R$ %.2f\n", saldo);
                printf("Maior deposito realizado: R$ %.2f\n", maiorDeposito);
                break;
 
            case 4:
                printf("Obrigado por usar nosso banco!\n");
                break;
 
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);
 
    return 0;
}
 

