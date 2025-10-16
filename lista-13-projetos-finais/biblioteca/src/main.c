#include <stdio.h>
#include <stdlib.h>
#include "../include/global.h"
#include "../include/arquivo.h"
#include "../include/menu.h"

NoLivro *listaLivros = NULL;
NoUsuario *listaUsuarios = NULL;
NoEmprestimo *listaEmprestimos = NULL;

int proximoCodigoLivro = 1;
int proximoCodigoUsuario = 1;
int proximoCodigoEmprestimo = 1;

int main() {
    printf("========================================\n");
    printf("   SISTEMA DE GERENCIAMENTO   \n");
    printf("        DE BIBLIOTECA        \n");
    printf("========================================\n\n");
    printf("Carregando dados...\n");

    carregarLivros();
    carregarUsuarios();
    carregarEmprestimos();

    printf("Dados carregados com sucesso!\n");
    pausar();

    menuPrincipal();

    printf("\nSalvando dados...\n");

    salvarLivros();
    salvarUsuarios();
    salvarEmprestimos();

    printf("Dados salvos com sucesso!\n");

    liberarListaLivros();
    liberarListaUsuarios();
    liberarListaEmprestimos();

    printf("\n=== Sistema encerrado ===\n");

    return 0;
}