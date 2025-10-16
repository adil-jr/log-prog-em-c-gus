#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/livro.h"
#include "../include/usuario.h"
#include "../include/emprestimo.h"

void menuPrincipal() {
    int opcao;

    do {
        limparTela();
        printf("========================================\n");
        printf("   SISTEMA DE GERENCIAMENTO   \n");
        printf("        DE BIBLIOTECA        \n");
        printf("========================================\n\n");
        printf("[1] - Gerenciar Livros\n");
        printf("[2] - Gerenciar Usuários\n");
        printf("[3] - Gerenciar Empréstimos\n");
        printf("[4] - Sair\n");
        printf("========================================\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuLivros();
                break;
            case 2:
                menuUsuarios();
                break;
            case 3:
                menuEmprestimos();
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

void menuLivros() {
    int opcao;

    do {
        limparTela();
        printf("========================================\n");
        printf("       GERENCIAMENTO DE LIVROS       \n");
        printf("========================================\n\n");
        printf("[1] - Cadastrar novo livro\n");
        printf("[2] - Listar todos os livros\n");
        printf("[3] - Voltar\n");
        printf("========================================\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarLivro();
                break;
            case 2:
                listarLivros();
                break;
            case 3:
                break;
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }

    } while (opcao != 3);
}

void menuUsuarios() {
    int opcao;

    do {
        limparTela();
        printf("========================================\n");
        printf("      GERENCIAMENTO DE USUÁRIOS      \n");
        printf("========================================\n\n");
        printf("[1] - Cadastrar novo usuário\n");
        printf("[2] - Listar todos os usuários\n");
        printf("[3] - Voltar\n");
        printf("========================================\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                listarUsuarios();
                break;
            case 3:
                break;
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }

    } while (opcao != 3);
}

void menuEmprestimos() {
    int opcao;

    do {
        limparTela();
        printf("========================================\n");
        printf("     GERENCIAMENTO DE EMPRÉSTIMOS     \n");
        printf("========================================\n\n");
        printf("[1] - Registrar empréstimo\n");
        printf("[2] - Registrar devolução\n");
        printf("[3] - Listar empréstimos ativos\n");
        printf("[4] - Voltar\n");
        printf("========================================\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarEmprestimo();
                break;
            case 2:
                registrarDevolucao();
                break;
            case 3:
                listarEmprestimosAtivos();
                break;
            case 4:
                break;
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }

    } while (opcao != 4);
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