#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIZZAS 100
#define MAX_PEDIDOS 100
#define MAX_INGREDIENTES 5

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void iniciar_cardapio() {
    // Implementação da função
}

void mostrar_cardapio() {
    // Implementação da função
}

void fazer_pedido() {
    // Implementação da função
}

void mostrar_pedidos() {
    // Implementação da função
}

int main() {
    int opcao;
    iniciar_cardapio();

    do {
        printf("\n--- Pizzaria ---\n");
        printf("1. Ver cardapio\n");
        printf("2. Fazer pedido\n");
        printf("3. Relatorio de Pedidos\n");
        printf("0. Sair\n");

        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            opcao = -1;
        }

        switch(opcao) {
            case 1:
                mostrar_cardapio();
                break;
            case 2:
                fazer_pedido();
                break;
            case 3:
                mostrar_pedidos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}