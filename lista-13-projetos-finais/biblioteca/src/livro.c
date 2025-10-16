#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/livro.h"
#include "../include/global.h"
#include "../include/menu.h"

void cadastrarLivro() {
    Livro novoLivro;

    limparTela();
    printf("========================================\n");
    printf("        CADASTRAR NOVO LIVRO        \n");
    printf("========================================\n\n");

    novoLivro.codigo = proximoCodigoLivro++;

    printf("Título: ");
    limparBuffer();
    fgets(novoLivro.titulo, 100, stdin);
    novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = '\0';

    printf("Autor: ");
    fgets(novoLivro.autor, 50, stdin);
    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = '\0';

    printf("Quantidade total: ");
    scanf("%d", &novoLivro.quantidade_total);

    novoLivro.quantidade_disponivel = novoLivro.quantidade_total;

    inserirLivroNaLista(novoLivro);

    printf("\nLivro #%d cadastrado com sucesso!\n", novoLivro.codigo);
    pausar();
}

void listarLivros() {
    limparTela();
    printf("========================================\n");
    printf("          LISTA DE LIVROS          \n");
    printf("========================================\n\n");

    if (listaLivros == NULL) {
        printf("Nenhum livro cadastrado.\n");
        pausar();
        return;
    }

    NoLivro *atual = listaLivros;

    while (atual != NULL) {
        printf("Código: %d\n", atual->livro.codigo);
        printf("Título: %s\n", atual->livro.titulo);
        printf("Autor: %s\n", atual->livro.autor);
        printf("Total: %d | Disponível: %d\n", 
               atual->livro.quantidade_total,
               atual->livro.quantidade_disponivel);
        printf("----------------------------------------\n");
        
        atual = atual->prox;
    }

    pausar();
}

NoLivro* buscarLivroPorCodigo(int codigo) {
    NoLivro *atual = listaLivros;

    while (atual != NULL) {
        if (atual->livro.codigo == codigo) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

void inserirLivroNaLista(Livro livro) {
    NoLivro *novo = (NoLivro*) malloc(sizeof(NoLivro));

    if (novo == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        exit(1);
    }

    novo->livro = livro;
    novo->prox = NULL;
    
    if (listaLivros == NULL) {
        listaLivros = novo;
    } else {
        NoLivro *atual = listaLivros;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void liberarListaLivros() {
    NoLivro *atual = listaLivros;
    NoLivro *temp;
    
    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }

    listaLivros = NULL;
}