#include <stdio.h>
#include <stdlib.h>
#include "../include/emprestimo.h"
#include "../include/global.h"
#include "../include/menu.h"

void registrarEmprestimo() {
    Emprestimo novoEmprestimo;
    int codigoLivro, codigoUsuario;
    NoLivro *livro;
    NoUsuario *usuario;
    
    limparTela();
    printf("========================================\n");
    printf("       REGISTRAR EMPRÉSTIMO       \n");
    printf("========================================\n\n");

    printf("Código do livro: ");
    scanf("%d", &codigoLivro);

    printf("Código do usuário: ");
    scanf("%d", &codigoUsuario);

    livro = buscarLivroPorCodigo(codigoLivro);
    if (livro == NULL) {
        printf("\nLivro não encontrado!\n");
        pausar();
        return;
    }

    if (livro->livro.quantidade_disponivel <= 0) {
        printf("\nLivro indisponível no momento!\n");
        printf("Título: %s\n", livro->livro.titulo);
        pausar();
        return;
    }

    usuario = buscarUsuarioPorCodigo(codigoUsuario);
    if (usuario == NULL) {
        printf("\nUsuário não encontrado!\n");
        pausar();
        return;
    }

    novoEmprestimo.codigo_emprestimo = proximoCodigoEmprestimo++;
    novoEmprestimo.codigo_livro = codigoLivro;
    novoEmprestimo.codigo_usuario = codigoUsuario;
    novoEmprestimo.ativo = 1;

    inserirEmprestimoNaLista(novoEmprestimo);

    livro->livro.quantidade_disponivel--;
    
    printf("\nEmpréstimo #%d registrado com sucesso!\n\n", 
           novoEmprestimo.codigo_emprestimo);
    printf("Livro: %s\n", livro->livro.titulo);
    printf("Usuário: %s\n", usuario->usuario.nome);

    pausar();
}

void registrarDevolucao() {
    int codigoEmprestimo;
    NoEmprestimo *empAtual;
    NoLivro *livro;
    NoUsuario *usuario;
    int encontrado = 0;

    limparTela();
    printf("========================================\n");
    printf("        REGISTRAR DEVOLUÇÃO        \n");
    printf("========================================\n\n");

    printf("Código do empréstimo: ");
    scanf("%d", &codigoEmprestimo);

    empAtual = listaEmprestimos;
    
    while (empAtual != NULL) {
        if (empAtual->emprestimo.codigo_emprestimo == codigoEmprestimo &&
            empAtual->emprestimo.ativo == 1) {

            empAtual->emprestimo.ativo = 0;

            livro = buscarLivroPorCodigo(empAtual->emprestimo.codigo_livro);
            usuario = buscarUsuarioPorCodigo(empAtual->emprestimo.codigo_usuario);

            if (livro != NULL) {
                livro->livro.quantidade_disponivel++;
            }

            printf("\nDevolução registrada com sucesso!\n\n");
            if (livro != NULL) {
                printf("Livro: %s\n", livro->livro.titulo);
            }
            if (usuario != NULL) {
                printf("Usuário: %s\n", usuario->usuario.nome);
            }

            encontrado = 1;
            break;
        }

        empAtual = empAtual->prox;
    }

    if (!encontrado) {
        printf("\nEmpréstimo não encontrado ou já devolvido!\n");
    }
    
    pausar();
}

void listarEmprestimosAtivos() {
    limparTela();
    printf("========================================\n");
    printf("      EMPRÉSTIMOS EM ANDAMENTO\n");
    printf("========================================\n\n");

    if (listaEmprestimos == NULL) {
        printf("Nenhum empréstimo registrado.\n");
        pausar();
        return;
    }

    NoEmprestimo *atual = listaEmprestimos;
    NoLivro *livro;
    NoUsuario *usuario;
    int count = 0;

    while (atual != NULL) {
        if (atual->emprestimo.ativo == 1) {
            livro = buscarLivroPorCodigo(atual->emprestimo.codigo_livro);
            usuario = buscarUsuarioPorCodigo(atual->emprestimo.codigo_usuario);
            
            printf("Empréstimo #%d\n", atual->emprestimo.codigo_emprestimo);
            
            if (livro != NULL) {
                printf("Livro: %s (Código: %d)\n", 
                       livro->livro.titulo, atual->emprestimo.codigo_livro);
            }
            
            if (usuario != NULL) {
                printf("Usuário: %s (Código: %d)\n", 
                       usuario->usuario.nome, atual->emprestimo.codigo_usuario);
            }
            
            printf("----------------------------------------\n");
            count++;
        }
    
        atual = atual->prox;
    }

    if (count == 0) {
        printf("Nenhum empréstimo ativo no momento.\n");
    } else {
        printf("\nTotal: %d empréstimo(s) ativo(s)\n", count);
    }

    pausar();
}

void inserirEmprestimoNaLista(Emprestimo emprestimo) {
    NoEmprestimo *novo = (NoEmprestimo*) malloc(sizeof(NoEmprestimo));

    if (novo == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        exit(1);
    }

    novo->emprestimo = emprestimo;
    novo->prox = NULL;
    
    if (listaEmprestimos == NULL) {
        listaEmprestimos = novo;
    } else {
        NoEmprestimo *atual = listaEmprestimos;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void liberarListaEmprestimos() {
    NoEmprestimo *atual = listaEmprestimos;
    NoEmprestimo *temp;

    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }

    listaEmprestimos = NULL;
}