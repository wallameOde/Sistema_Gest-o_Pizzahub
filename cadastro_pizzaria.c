#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIZZAS 100
#define MAX_PEDIDOS 100



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
        printf("Limite de pedidos atingido.\n");
        return;
    }
    mostrar_cardapio();
    int id_escolhido;
    printf("Digite o ID da pizza que deseja pedir:");
    if(scanf("%d", &id_escolhido) !=1){
        limpar_buffer();
        printf("Entrada invalida.\n");
        return;
    }
    limpar_buffer();
    int i, encontrou = 0;
    for( i = 0; i < total_pizzas; i++){
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
   if(total_pedidos == 0){
    printf("\nnenhum pedido registrado. \n");
    return;
   }
   printf("\n==== Relatorio de pedidos. ====\n");
   float valor_total = 0;
   int i;
   for(i = 0; i < total_pedidos; i++){
     printf("Pedido #%d | Pizza: %-15s | Quantidade: %d | Total: R$ %.2f \n",
     pedidos[i].id_pedido,
   pedidos[i].pizza.nome,
   pedidos[i].quantidade,
   pedidos[i].total);
   valor_total += pedidos[i].total;
   }
   printf("----------------------------- \n");
   printf("valor geral: R$ %.2f\n", valor_total);
  
}
void salvar_pedidos() {
       if (total_pedidos == 0) {
        printf("Nenhum pedido para salvar.\n");
        return;
    }

    FILE *teste = fopen("pedidos.txt", "r");
    int arquivo_novo = (teste == NULL);
    if (teste) fclose(teste);

    FILE *arquivo = fopen("pedidos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    if (arquivo_novo) {
        fprintf(arquivo, "%-10s %-20s %-12s %-18s %-10s\n",
            "ID", "Pizza", "Quantidade", "Preco Unitario", "Total");
        fprintf(arquivo, "%-10s %-20s %-12s %-18s %-10s\n",
            "----------", "--------------------", "------------", "------------------", "----------");
    }

    int i;
    float valor_total = 0;
    for (i = 0; i < total_pedidos; i++) {
        fprintf(arquivo, "%-10d %-20s %-12d R$%-16.2f R$%.2f\n",
            pedidos[i].id_pedido,
            pedidos[i].pizza.nome,
            pedidos[i].quantidade,
            pedidos[i].pizza.preco,
            pedidos[i].total);
        valor_total += pedidos[i].total;
    }

    fprintf(arquivo, "%-10s %-20s %-12s %-18s R$%.2f\n",
        "", "", "", "Total Geral:", valor_total);

    fclose(arquivo);
    printf("Pedidos salvos em 'pedidos.txt'.\n");
}
void cadastro_cliente() {
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
        printf("4. Cadastrar cliente\n");
        printf("5. Salvar pedidos \n");
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
             case 4:
                cadastro_cliente();
            case 5:
                salvar_pedidos();
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