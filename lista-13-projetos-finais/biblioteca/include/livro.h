#ifndef LIVRO_H
#define LIVRO_H

typedef struct {
    int codigo;
    char titulo[100];
    char autor[100];
    int quantidade_total;
    int quantidade_disponivel;
} Livro;

typedef struct NoLivro {
    Livro livro;
    struct NoLivro *prox;
} NoLivro;

void cadastrarLivro();
void listarLivros();
NoLivro *buscarLivroPorCodigo(int codigo);
void inserirLivroNaLista(Livro livro);
void liberarListaLivros();

#endif