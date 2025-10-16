#ifndef USUARIO_H
#define USUARIO_H

typedef struct {
    int codigo;
    char nome[100];
    int idade;
} Usuario;

typedef struct NoUsuario {
    Usuario usuario;
    struct NoUsuario *prox;
} NoUsuario;

void cadastrarUsuario();
void listarUsuarios();
NoUsuario *buscarUsuarioPorCodigo(int codigo);
void inserirUsuarioNaLista(Usuario usuario);
void liberarListaUsuarios();

#endif