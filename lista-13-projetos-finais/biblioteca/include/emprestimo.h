#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

typedef struct {
    int codigo_emprestimo;
    int codigo_livro;
    int codigo_usuario;
    int ativo;
} Emprestimo;

typedef struct NoEmprestimo {
    Emprestimo emprestimo;
    struct NoEmprestimo *prox;
} NoEmprestimo;

void registrarEmprestimo();
void registrarDevolucao();
void listarEmprestimosAtivos();
void inserirEmprestimoNaLista(Emprestimo emprestimo);
void liberarListaEmprestimos();

#endif