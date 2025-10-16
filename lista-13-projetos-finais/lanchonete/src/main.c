#include <stdio.h>
#include <stdlib.h>
#include "../include/global.h"
#include "../include/arquivo.h"
#include "../include/menu.h"

NoProduto *listaProdutos = NULL;
NoCliente *listaClientes = NULL;
NoPedido *listaPedidos = NULL;

int proximoCodigoProduto = 1;
int proximoCodigoCliente = 1;

int main() {
    printf("========================================\n");
    printf("   GERENCIADOR DE PEDIDOS   \n");
    printf("        LANCHONETE        \n");
    printf("========================================\n\n");
    printf("Carregando dados...\n");

    carregarProdutos();
    carregarClientes();
    carregarPedidos();

    printf("Dados carregados com sucesso!\n");
    pausar();

    menuPrincipal();

    printf("\nSalvando dados...\n");

    salvarProdutos();
    salvarClientes();
    salvarPedidos();

    printf("Dados salvos com sucesso!\n");

    liberarListaProdutos();
    liberarListaClientes();
    liberarListaPedidos();

    printf("\n=== Sistema encerrado ===\n");

    return 0;
}