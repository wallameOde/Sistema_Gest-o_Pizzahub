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
typedef struct {
    char nome[50];
    float preco;
    char ingredientes[MAX_INGREDIENTES][30];
    int num_ingredientes;
    int id;
} Pizza;

Pizza cardapio[MAX_PIZZAS];
int total_pizzas = 0;

void iniciar_cardapio() {
strcpy(cardapio[0].nome, "Margherita");
cardapio[0].preco = 30.00;
cardapio[0].id = 1;
total_pizzas++;

strcpy(cardapio[1].nome, "Pepperoni");
cardapio[1].preco = 35.00;
cardapio[1].id = 2;
total_pizzas++;

strcpy(cardapio[2].nome, "Quatro Queijos");
cardapio[2].preco = 40.00;
cardapio[2].id = 3;
total_pizzas++;
}

void mostrar_cardapio() {
    printf("\n==== Cardapio ====\n");
    int i;
    
    for ( i = 0; i < total_pizzas; i++){
       printf("%d. %s - R$ %.2f\n", cardapio[i].id, cardapio[i].nome, cardapio[i].preco);
    }
    
    

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
