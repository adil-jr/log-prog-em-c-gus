#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cliente.h"
#include "../include/global.h"
#include "../include/menu.h"

void cadastrarCliente() {
    Cliente novoCliente;

    limparTela();
    printf("========================================\n");
    printf("        CADASTRAR NOVO CLIENTE        \n");
    printf("========================================\n\n");

    novoCliente.codigo = proximoCodigoCliente++;

    printf("Nome do cliente: ");
    limparBuffer();
    fgets(novoCliente.nome, 50, stdin);
    novoCliente.nome[strcspn(novoCliente.nome, "\n")] = '\0';

    inserirClienteNaLista(novoCliente);

    printf("\nCliente #%d cadastrado com sucesso!\n", novoCliente.codigo);
    pausar();
}

void listarClientes() {
    limparTela();
    printf("========================================\n");
    printf("          LISTA DE CLIENTES          \n");
    printf("========================================\n\n");
    
    if (listaClientes == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        pausar();
        return;
    }

    NoCliente *atual = listaClientes;

    printf("%-8s %s\n", "Código", "Nome");
    printf("----------------------------------------\n");

    while (atual != NULL) {
        printf("%-8d %s\n", 
               atual->cliente.codigo,
               atual->cliente.nome);
        
        atual = atual->prox;
    }

    pausar();
}

NoCliente* buscarClientePorCodigo(int codigo) {
    NoCliente *atual = listaClientes;

    while (atual != NULL) {
        if (atual->cliente.codigo == codigo) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

void inserirClienteNaLista(Cliente cliente) {
    NoCliente *novo = (NoCliente*) malloc(sizeof(NoCliente));

    if (novo == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        exit(1);
    }

    novo->cliente = cliente;
    novo->prox = NULL;

    if (listaClientes == NULL) {
        listaClientes = novo;
    } else {
        NoCliente *atual = listaClientes;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void liberarListaClientes() {
    NoCliente *atual = listaClientes;
    NoCliente *temp;

    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }

    listaClientes = NULL;
}