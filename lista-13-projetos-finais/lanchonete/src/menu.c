#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/produto.h"
#include "../include/cliente.h"
#include "../include/pedido.h"

void menuPrincipal() {
    int opcao;

    do {
        limparTela();
        printf("========================================\n");
        printf("   GERENCIADOR DE PEDIDOS   \n");
        printf("        LANCHONETE        \n");
        printf("========================================\n\n");
        printf("[1] - Gerenciar Produtos\n");
        printf("[2] - Gerenciar Clientes\n");
        printf("[3] - Gerenciar Pedidos\n");
        printf("[4] - Sair\n");
        printf("========================================\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuProdutos();
                break;
            case 2:
                menuClientes();
                break;
            case 3:
                menuPedidos();
                break;
            case 4:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }

    } while (opcao != 4);
}

void menuProdutos() {
    int opcao;

    do {
        limparTela();
        printf("========================================\n");
        printf("      GERENCIAMENTO DE PRODUTOS      \n");
        printf("========================================\n\n");
        printf("[1] - Cadastrar novo produto\n");
        printf("[2] - Listar todos os produtos\n");
        printf("[3] - Voltar\n");
        printf("========================================\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                break;
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }

    } while (opcao != 3);
}

void menuClientes() {
    int opcao;

    do {
        limparTela();
        printf("========================================\n");
        printf("      GERENCIAMENTO DE CLIENTES      \n");
        printf("========================================\n\n");
        printf("[1] - Cadastrar novo cliente\n");
        printf("[2] - Listar todos os clientes\n");
        printf("[3] - Voltar\n");
        printf("========================================\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                break;
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }

    } while (opcao != 3);
}

void menuPedidos() {
    int opcao;

    do {
        limparTela();
        printf("========================================\n");
        printf("      GERENCIAMENTO DE PEDIDOS      \n");
        printf("========================================\n\n");
        printf("[1] - Realizar pedido\n");
        printf("[2] - Listar todos os pedidos\n");
        printf("[3] - Voltar\n");
        printf("========================================\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                realizarPedido();
                break;
            case 2:
                listarPedidos();
                break;
            case 3:
                break;
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }

    } while (opcao != 3);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    limparBuffer();
    getchar();
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}