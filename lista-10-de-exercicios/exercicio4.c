#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

No *criarNo(int valor);
void inserirFinal(No **head, int valor);
void imprimirLista(No *head);
void liberarLista(No **head);
int lerInteiro(const char *mensagem);
void exibirMenu();
int buscarElemento(No *head, int valor);

int main() {
    No *head = NULL;
    int valor;
    int opcao;
    int resultado;

    printf("========================================\n");
    printf("      LISTA LIGADA SIMPLES EM C      \n");
    printf("========================================\n\n");

    printf("=== INSERÇÃO DE ELEMENTOS ===\n");

    for (int i = 0; i < 5; i++) {
        char mensagem[50];
        sprintf(mensagem, "Digite o número %d: ", i + 1);
        valor = lerInteiro(mensagem);

        inserirFinal(&head, valor);
    }

    printf("\n");
    printf("=== ELEMENTOS DA LISTA ===\n");
    imprimirLista(head);
    printf("\n");

    do {
        exibirMenu();
        printf("Digite sua opção: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                printf("Digite o elemento que deseja buscar: ");
                scanf("%d", &valor);

                resultado = buscarElemento(head, valor);
                printf("\n");

                if (resultado == 1) {
                    printf("Elemento %d ENCONTRADO na lista!\n", valor);
                } else {
                    printf("Elemento %d NÃO encontrado na lista.\n", valor);
                }
                printf("\n");
                break;

            case 2:
                printf("=== ELEMENTOS DA LISTA ===\n");
                imprimirLista(head);
                printf("\n");
                break;
            case 3:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcão inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 3);

    liberarLista(&head);

    printf("Memória liberada com sucesso!\n");

    return 0;
}

No *criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        return NULL;
    }

    novo->dado = valor;
    novo->prox = NULL;

    return novo;
}

void inserirFinal(No **head, int valor) {
    No *novo = criarNo(valor);

    if (novo == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        return;
    }

    if (*head == NULL) {
        *head = novo;
        return;
    }

    No *atual = *head;
    
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    
    atual->prox = novo;
}

void imprimirLista(No *head) {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    No *atual = head;

    int posicao = 1;

    while (atual != NULL) {
        printf("Elemento %d: %d\n", posicao, atual->dado);

        atual = atual->prox;

        posicao += 1;
    }
}

void liberarLista(No **head) {
    No *atual = *head;
    No *temp;

    while (atual != NULL) {
        temp = atual->prox;

        free(atual);

        atual = temp;
    }

    *head = NULL;
}

int lerInteiro(const char *mensagem) {
    int valor;

    printf(mensagem);

    scanf("%d", &valor);

    return valor;
}

void exibirMenu() {
    printf("========================================\n");
    printf("                MENU                \n");
    printf("========================================\n");
    printf("[1] - Buscar elemento na lista\n");
    printf("[2] - Exibir lista completa\n");
    printf("[3] - Sair\n");
    printf("========================================\n");
}

int buscarElemento(No *head, int valor) {
    if (head == NULL) {
        return 0;
    }

    No *atual = head;

    while (atual != NULL) {
        if (atual->dado == valor) {
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}