#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/usuario.h"
#include "../include/global.h"
#include "../include/menu.h"

void cadastrarUsuario() {
    Usuario novoUsuario;

    limparTela();
    printf("========================================\n");
    printf("       CADASTRAR NOVO USUÁRIO       \n");
    printf("========================================\n\n");

    novoUsuario.codigo = proximoCodigoUsuario++;

    printf("Nome completo: ");
    limparBuffer();
    fgets(novoUsuario.nome, 100, stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &novoUsuario.idade);

    inserirUsuarioNaLista(novoUsuario);

    printf("\nUsuário #%d cadastrado com sucesso!\n", novoUsuario.codigo);
    pausar();
}

void listarUsuarios() {
    limparTela();
    printf("========================================\n");
    printf("         LISTA DE USUÁRIOS         \n");
    printf("========================================\n\n");

    if (listaUsuarios == NULL) {
        printf("Nenhum usuário cadastrado.\n");
        pausar();
        return;
    }

    NoUsuario *atual = listaUsuarios;

    while (atual != NULL) {
        printf("Código: %d\n", atual->usuario.codigo);
        printf("Nome: %s\n", atual->usuario.nome);
        printf("Idade: %d anos\n", atual->usuario.idade);
        printf("----------------------------------------\n");
        
        atual = atual->prox;
    }

    pausar();
}

NoUsuario* buscarUsuarioPorCodigo(int codigo) {
    NoUsuario *atual = listaUsuarios;

    while (atual != NULL) {
        if (atual->usuario.codigo == codigo) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

void inserirUsuarioNaLista(Usuario usuario) {
    NoUsuario *novo = (NoUsuario*) malloc(sizeof(NoUsuario));

    if (novo == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        exit(1);
    }

    novo->usuario = usuario;
    novo->prox = NULL;
    
    if (listaUsuarios == NULL) {
        listaUsuarios = novo;
    } else {
        NoUsuario *atual = listaUsuarios;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void liberarListaUsuarios() {
    NoUsuario *atual = listaUsuarios;
    NoUsuario *temp;

    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }

    listaUsuarios = NULL;
}