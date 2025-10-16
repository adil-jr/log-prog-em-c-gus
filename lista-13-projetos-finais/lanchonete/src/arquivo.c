#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/arquivo.h"
#include "../include/global.h"

void salvarProdutos() {
    FILE *arquivo = fopen("data/produtos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar produtos!\n");
        return;
    }

    NoProduto *atual = listaProdutos;

    while (atual != NULL) {
        fprintf(arquivo, "%d;%s;%.2f\n",
                atual->produto.codigo,
                atual->produto.nome,
                atual->produto.preco);
        
        atual = atual->prox;
    }
    
    fclose(arquivo);
}

void carregarProdutos() {
    FILE *arquivo = fopen("data/produtos.txt", "r");
    
    if (arquivo == NULL) {
        return;
    }

    Produto produto;

    while (fscanf(arquivo, "%d;%49[^;];%f\n",
                  &produto.codigo,
                  produto.nome,
                  &produto.preco) == 3) {
        
        inserirProdutoNaLista(produto);

        if (produto.codigo >= proximoCodigoProduto) {
            proximoCodigoProduto = produto.codigo + 1;
        }
    }

    fclose(arquivo);
}

void salvarClientes() {
    FILE *arquivo = fopen("data/clientes.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar clientes!\n");
        return;
    }

    NoCliente *atual = listaClientes;

    while (atual != NULL) {
        fprintf(arquivo, "%d;%s\n",
                atual->cliente.codigo,
                atual->cliente.nome);
        
        atual = atual->prox;
    }

    fclose(arquivo);
}

void carregarClientes() {
    FILE *arquivo = fopen("data/clientes.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    Cliente cliente;

    while (fscanf(arquivo, "%d;%49[^\n]\n",
                  &cliente.codigo,
                  cliente.nome) == 2) {

        inserirClienteNaLista(cliente);
    
        if (cliente.codigo >= proximoCodigoCliente) {
            proximoCodigoCliente = cliente.codigo + 1;
        }
    }

    fclose(arquivo);
}

void salvarPedidos() {
    FILE *arquivo = fopen("data/pedidos.txt", "w");
    
    if (arquivo == NULL) {
        printf("Erro ao salvar pedidos!\n");
        return;
    }

    NoPedido *atual = listaPedidos;

    while (atual != NULL) {
        fprintf(arquivo, "%d;%d;%d\n",
                atual->pedido.codigo_cliente,
                atual->pedido.codigo_produto,
                atual->pedido.quantidade);
        
        atual = atual->prox;
    }

    fclose(arquivo);
}

void carregarPedidos() {
    FILE *arquivo = fopen("data/pedidos.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    Pedido pedido;

    while (fscanf(arquivo, "%d;%d;%d\n",
                  &pedido.codigo_cliente,
                  &pedido.codigo_produto,
                  &pedido.quantidade) == 3) {
        
        inserirPedidoNaLista(pedido);
    }

    fclose(arquivo);
}