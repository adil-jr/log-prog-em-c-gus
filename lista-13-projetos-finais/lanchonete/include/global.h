#ifndef GLOBAL_H
#define GLOBAL_H

#include "produto.h"
#include "cliente.h"
#include "pedido.h"

extern NoProduto *listaProdutos;
extern NoCliente *listaClientes;
extern NoPedido *listaPedidos;

extern int proximoCodigoProduto;
extern int proximoCodigoCliente;

#endif