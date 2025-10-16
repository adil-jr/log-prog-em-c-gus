#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    int codigo;
    char nome[50];
} Cliente;

typedef struct NoCliente {
    Cliente cliente;
    struct NoCliente *prox;
} NoCliente;

void cadastrarCliente();
void listarClientes();
NoCliente* buscarClientePorCodigo(int codigo);
void inserirClienteNaLista(Cliente cliente);
void liberarListaClientes();

#endif