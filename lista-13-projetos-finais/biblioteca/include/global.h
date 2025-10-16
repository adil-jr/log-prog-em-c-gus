#ifndef GLOBAL_H
#define GLOBAL_H

#include "livro.h"
#include"usuario.h"
#include "emprestimo.h"

extern NoLivro *listaLivros;
extern NoUsuario *listaUsuarios;
extern NoEmprestimo *listaEmprestimos;

extern int proximoCodigoLivro;
extern int proximoCodigoUsuario;
extern int proximoCodigoEmprestimo;

#endif