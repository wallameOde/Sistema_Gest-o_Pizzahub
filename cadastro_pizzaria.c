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
    int id;
} Pizza;

Pizza cardapio[MAX_PIZZAS];
int total_pizzas = 0;

typedef struct{
    int id_pedido;
    Pizza pizza;
    int quantidade;
    float total;
}Pedido;
Pedido pedidos[MAX_PEDIDOS];
int total_pedidos = 0;

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
    if(total_pedidos >= MAX_PEDIDOS){
        printf("Limite de pedidos atingido./n");
        return;
    }
    mostrar_cardapio();
    int id_escolhido;
    printf("Digite o ID da pizza que deseja pedir:");
    if(scanf("%d", &id_escolhido) !=1){
        limpar_buffer();
        printf("Entrada invalida./n");
        return;
    }
    limpar_buffer();
    int i, encontrou = 0;
    for( i = 0; 1 < total_pizzas; i++){
        if(cardapio[i].id == id_escolhido){
            encontrou = 1;
            break;
        }
    }
if(!encontrou){
    printf("Pizza nao encontrada./n");
    return;
}
int quantidade;
printf("Digite a quantidade:");
if(scanf("%d", &quantidade) !=1 || quantidade <= 0){
    limpar_buffer();
    printf("Quantidade invalida./n");
    return;
}
limpar_buffer();
pedidos[total_pedidos].id_pedido = total_pedidos + 1;
pedidos[total_pedidos].pizza = cardapio[i];
pedidos[total_pedidos].quantidade = quantidade;
pedidos[total_pedidos].total = cardapio[i].preco * quantidade;
total_pedidos++;
printf("Pedido feito com sucesso! Total: R$ %.2f\n", pedidos[total_pedidos - 1].total);
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
