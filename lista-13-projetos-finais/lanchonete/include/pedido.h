#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct {
    int codigo_cliente;
    int codigo_produto;
    int quantidade;
} Pedido;

typedef struct NoPedido {
    Pedido pedido;
    struct NoPedido *prox;
} NoPedido;

void realizarPedido();
void listarPedidos();
void inserirPedidoNaLista(Pedido pedido);
void liberarListaPedidos();

#endif