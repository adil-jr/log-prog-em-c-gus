#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

typedef struct NoProduto {
    Produto produto;
    struct NoProduto *prox;
} NoProduto;

void cadastrarProduto();
void listarProdutos();
NoProduto* buscarProdutoPorCodigo(int codigo);
void inserirProdutoNaLista(Produto produto);
void liberarListaProdutos();

#endif