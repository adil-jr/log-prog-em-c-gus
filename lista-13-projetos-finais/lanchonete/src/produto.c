#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/produto.h"
#include "../include/global.h"
#include "../include/menu.h"

void cadastrarProduto() {
    Produto novoProduto;

    limparTela();
    printf("========================================\n");
    printf("        CADASTRAR NOVO PRODUTO\n");
    printf("========================================\n\n");

    novoProduto.codigo = proximoCodigoProduto++;

    printf("Nome do produto: ");
    limparBuffer();
    fgets(novoProduto.nome, 50, stdin);
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = '\0';

    printf("Preço: R$ ");
    scanf("%f", &novoProduto.preco);

    inserirProdutoNaLista(novoProduto);

    printf("\nProduto #%d cadastrado com sucesso!\n", novoProduto.codigo);
    pausar();
}

void listarProdutos() {
    limparTela();
    printf("========================================\n");
    printf("          LISTA DE PRODUTOS          \n");
    printf("========================================\n\n");

    if (listaProdutos == NULL) {
        printf("Nenhum produto cadastrado.\n");
        pausar();
        return;
    }

    NoProduto *atual = listaProdutos;
    
    printf("%-8s %-25s %s\n", "Código", "Nome", "Preço");
    printf("--------------------------------------------------------\n");

    while (atual != NULL) {
        printf("%-8d %-25s R$ %.2f\n", 
               atual->produto.codigo,
               atual->produto.nome,
               atual->produto.preco);
        
        atual = atual->prox;
    }

    pausar();
}

NoProduto* buscarProdutoPorCodigo(int codigo) {
    NoProduto *atual = listaProdutos;

    while (atual != NULL) {
        if (atual->produto.codigo == codigo) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

void inserirProdutoNaLista(Produto produto) {
    NoProduto *novo = (NoProduto*) malloc(sizeof(NoProduto));

    if (novo == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        exit(1);
    }
    
    novo->produto = produto;
    novo->prox = NULL;

    if (listaProdutos == NULL) {
        listaProdutos = novo;
    } else {
        NoProduto *atual = listaProdutos;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void liberarListaProdutos() {
    NoProduto *atual = listaProdutos;
    NoProduto *temp;

    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }

    listaProdutos = NULL;
}