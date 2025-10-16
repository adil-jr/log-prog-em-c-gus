#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/arquivo.h"
#include "../include/global.h"

void salvarLivros() {
    FILE *arquivo = fopen("data/livros.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar livros!\n");
        return;
    }

    NoLivro *atual = listaLivros;

    while (atual != NULL) {
        fprintf(arquivo, "%d|%s|%s|%d|%d\n",
                atual->livro.codigo,
                atual->livro.titulo,
                atual->livro.autor,
                atual->livro.quantidade_total,
                atual->livro.quantidade_disponivel);
        
        atual = atual->prox;
    }

    fclose(arquivo);
}

void carregarLivros() {
    FILE *arquivo = fopen("data/livros.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    Livro livro;

    while (fscanf(arquivo, "%d|%99[^|]|%49[^|]|%d|%d\n",
                  &livro.codigo,
                  livro.titulo,
                  livro.autor,
                  &livro.quantidade_total,
                  &livro.quantidade_disponivel) == 5) {
        
        inserirLivroNaLista(livro);

        if (livro.codigo >= proximoCodigoLivro) {
            proximoCodigoLivro = livro.codigo + 1;
        }
    }

    fclose(arquivo);
}

void salvarUsuarios() {
    FILE *arquivo = fopen("data/usuarios.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar usuários!\n");
        return;
    }

    NoUsuario *atual = listaUsuarios;

    while (atual != NULL) {
        fprintf(arquivo, "%d|%s|%d\n",
                atual->usuario.codigo,
                atual->usuario.nome,
                atual->usuario.idade);
        
        atual = atual->prox;
    }

    fclose(arquivo);
}

void carregarUsuarios() {
    FILE *arquivo = fopen("data/usuarios.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    Usuario usuario;

    while (fscanf(arquivo, "%d|%99[^|]|%d\n",
                  &usuario.codigo,
                  usuario.nome,
                  &usuario.idade) == 3) {

        inserirUsuarioNaLista(usuario);

        if (usuario.codigo >= proximoCodigoUsuario) {
            proximoCodigoUsuario = usuario.codigo + 1;
        }
    }

    fclose(arquivo);
}

void salvarEmprestimos() {
    FILE *arquivo = fopen("data/emprestimos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar empréstimos!\n");
        return;
    }

    NoEmprestimo *atual = listaEmprestimos;

    while (atual != NULL) {
        fprintf(arquivo, "%d|%d|%d|%d\n",
                atual->emprestimo.codigo_emprestimo,
                atual->emprestimo.codigo_livro,
                atual->emprestimo.codigo_usuario,
                atual->emprestimo.ativo);
        
        atual = atual->prox;
    }

    fclose(arquivo);
}

void carregarEmprestimos() {
    FILE *arquivo = fopen("data/emprestimos.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    Emprestimo emprestimo;

    while (fscanf(arquivo, "%d|%d|%d|%d\n",
                  &emprestimo.codigo_emprestimo,
                  &emprestimo.codigo_livro,
                  &emprestimo.codigo_usuario,
                  &emprestimo.ativo) == 4) {

        inserirEmprestimoNaLista(emprestimo);

        if (emprestimo.codigo_emprestimo >= proximoCodigoEmprestimo) {
            proximoCodigoEmprestimo = emprestimo.codigo_emprestimo + 1;
        }
    }

    fclose(arquivo);
}