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

int main() {
    No *head = NULL;
    int valor;

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