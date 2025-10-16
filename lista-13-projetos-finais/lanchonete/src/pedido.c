#include <stdio.h>
#include <stdlib.h>
#include "../include/pedido.h"
#include "../include/global.h"
#include "../include/menu.h"

void realizarPedido() {
    Pedido novoPedido;
    int codigoProduto, codigoCliente;
    NoProduto *produto;
    NoCliente *cliente;

    limparTela();
    printf("========================================\n");
    printf("          REALIZAR PEDIDO          \n");
    printf("========================================\n\n");

    printf("Código do cliente: ");
    scanf("%d", &codigoCliente);

    printf("Código do produto: ");
    scanf("%d", &codigoProduto);

    printf("Quantidade: ");
    scanf("%d", &novoPedido.quantidade);

    if (novoPedido.quantidade <= 0) {
        printf("\nQuantidade inválida!\n");
        pausar();
        return;
    }

    cliente = buscarClientePorCodigo(codigoCliente);
    if (cliente == NULL) {
        printf("\nCliente não encontrado!\n");
        pausar();
        return;
    }

    produto = buscarProdutoPorCodigo(codigoProduto);
    if (produto == NULL) {
        printf("\nProduto não encontrado!\n");
        pausar();
        return;
    }

    novoPedido.codigo_cliente = codigoCliente;
    novoPedido.codigo_produto = codigoProduto;

    inserirPedidoNaLista(novoPedido);

    float total = produto->produto.preco * novoPedido.quantidade;

    printf("\nPedido registrado com sucesso!\n\n");
    printf("Cliente: %s\n", cliente->cliente.nome);
    printf("Produto: %s\n", produto->produto.nome);
    printf("Quantidade: %d\n", novoPedido.quantidade);
    printf("Valor unitário: R$ %.2f\n", produto->produto.preco);
    printf("Valor total: R$ %.2f\n", total);

    pausar();
}

void listarPedidos() {
    limparTela();
    printf("========================================\n");
    printf("          LISTA DE PEDIDOS          \n");
    printf("========================================\n\n");

    if (listaPedidos == NULL) {
        printf("Nenhum pedido registrado.\n");
        pausar();
        return;
    }

    NoPedido *atual = listaPedidos;
    NoProduto *produto;
    NoCliente *cliente;
    int contador = 1;
    float totalGeral = 0.0;
    
    while (atual != NULL) {
        cliente = buscarClientePorCodigo(atual->pedido.codigo_cliente);
        produto = buscarProdutoPorCodigo(atual->pedido.codigo_produto);

        printf("--- Pedido #%d ---\n", contador);

        if (cliente != NULL) {
            printf("Cliente: %s (Código: %d)\n", 
                   cliente->cliente.nome, 
                   atual->pedido.codigo_cliente);
        } else {
            printf("Cliente: Código %d (não encontrado)\n", 
                   atual->pedido.codigo_cliente);
        }

        if (produto != NULL) {
            printf("Produto: %s (Código: %d)\n", 
                   produto->produto.nome, 
                   atual->pedido.codigo_produto);
            printf("Preço unitário: R$ %.2f\n", produto->produto.preco);
            float total = produto->produto.preco * atual->pedido.quantidade;
            printf("Quantidade: %d\n", atual->pedido.quantidade);
            printf("Total: R$ %.2f\n", total);
            totalGeral += total;
        } else {
            printf("Produto: Código %d (não encontrado)\n", 
                   atual->pedido.codigo_produto);
            printf("Quantidade: %d\n", atual->pedido.quantidade);
        }

        printf("----------------------------------------\n");
        
        atual = atual->prox;
        contador++;
    }

    printf("\nTotal Geral: R$ %.2f\n", totalGeral);
    printf("Total de Pedidos: %d\n", contador - 1);

    pausar();
}

void inserirPedidoNaLista(Pedido pedido) {
    NoPedido *novo = (NoPedido*) malloc(sizeof(NoPedido));

    if (novo == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        exit(1);
    }

    novo->pedido = pedido;
    novo->prox = NULL;
    
    if (listaPedidos == NULL) {
        listaPedidos = novo;
    } else {
        NoPedido *atual = listaPedidos;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void liberarListaPedidos() {
    NoPedido *atual = listaPedidos;
    NoPedido *temp;

    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }

    listaPedidos = NULL;
}