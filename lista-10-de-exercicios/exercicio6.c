#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    char nome[50];
} Cliente;

typedef struct No {
    Cliente cliente;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

Fila *criarFila();
void enqueue(Fila *fila, Cliente cliente);
Cliente *dequeue(Fila *fila);
int isEmpty(Fila *fila);
void mostrarFila(Fila *fila);
void liberarFila(Fila *fila);

void exibirMenu();
void lerNomeCliente(char *nome, int tamanho);

int contadorClientes = 0;

int main() {
    Fila *fila = criarFila();
    int opcao;
    Cliente cliente;
    Cliente *atendido;

    printf("========================================\n");
    printf("   SIMULAÇÃO DE ATENDIMENTO BANCÁRIO   \n");
    printf("========================================\n");

    do {
        exibirMenu();
        printf("Digite sua opção: ");
        
        char buffer[16];
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            opcao = 4;
        } else {
            if (sscanf(buffer, "%d", &opcao) != 1) {
                opcao = -1;
            }
        }
        
        printf("\n");

        switch (opcao) {
            case 1:
                contadorClientes += 1;
                cliente.numero = contadorClientes;

                printf("Nome do cliente: ");
                lerNomeCliente(cliente.nome, 50);

                enqueue(fila, cliente);

                printf("\nCliente #%d (%s) adicionado à fila!\n", cliente.numero, cliente.nome);
                break;
            case 2:
                atendido = dequeue(fila);

                if (atendido != NULL) {
                    printf(">>> Atendendo cliente #%d (%s)\n", atendido->numero, atendido->nome);
                    free(atendido);
                } else {
                    printf("Fila vazia! Nenhum cliente para atender.\n");
                }
                break;
            case 3:
                printf("=== FILA ATUAL ===\n");
                mostrarFila(fila);
                printf("\n");
                break;
            case 4:
                printf("Encerrando sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 4);

    liberarFila(fila);
    printf("Memória liberada. Sistema encerrado.\n");

    return 0;
}

Fila *criarFila() {
    Fila *fila = (Fila*) malloc(sizeof(Fila));

    if (fila == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        exit(1);
    }

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

void enqueue(Fila *fila, Cliente cliente) {
    No *novo = (No*) malloc(sizeof(No));
    
    if (novo == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        return;
    }
    
    novo->cliente = cliente;
    novo->prox = NULL;
    
    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

Cliente *dequeue(Fila *fila) {
    if (fila->inicio == NULL) {
        return NULL;
    }
    
    No *temp = fila->inicio;
    
    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));
    
    if (cliente == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        return NULL;
    }
    
    *cliente = temp->cliente;
    
    fila->inicio = temp->prox;
    
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    
    free(temp);
    
    return cliente;
}

int isEmpty(Fila *fila) {
    return (fila->inicio == NULL) ? 1 : 0;
}

void mostrarFila(Fila *fila) {
    if (isEmpty(fila) == 1) {
        printf("Fila vazia! Nenhum cliente aguardando.\n");
        return;
    }
    
    No *atual = fila->inicio;
    
    int posicao = 1;
    
    printf("Clientes aguardando atendimento:\n");
    printf("\n");
    
    while (atual != NULL) {
        printf("%d. Cliente #%d", posicao, atual->cliente.numero);
        printf(" - %s", atual->cliente.nome);
        printf("\n");
        
        atual = atual->prox;
        posicao = posicao + 1;
    }
    
    printf("\n");
    printf("Total: %d cliente(s) na fila\n", posicao - 1);
}

void liberarFila(Fila *fila) {
    No *atual = fila->inicio;
    No *temp;
    
    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }
    
    free(fila);
}

void exibirMenu() {
    printf("========================================\n");
    printf("                MENU\n");
    printf("========================================\n");
    printf("[1] - Inserir cliente na fila\n");
    printf("[2] - Atender próximo cliente\n");
    printf("[3] - Mostrar fila atual\n");
    printf("[4] - Sair\n");
    printf("========================================\n");
}

void lerNomeCliente(char *nome, int tamanho) {
    fgets(nome, tamanho, stdin);
    nome[strcspn(nome, "\n")] = '\0';
}