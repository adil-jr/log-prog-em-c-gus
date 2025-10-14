#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *proximo;
};

int main() {
    int tamanhoLista;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanhoLista);

    if (tamanhoLista <= 0) {
        printf("Valor inválido!\n");
        return 1;
    }

    struct No *primeiro = NULL;
    struct No *ultimo = NULL;

    for (int i = 0; i < tamanhoLista; i++) {
        struct No *novo = (struct No*) malloc(sizeof(struct No));

        printf("Digite o valor do NÓ %d: ", i);
        scanf("%d", &novo->valor);
        novo->proximo = NULL;

        if (primeiro == NULL) {
            primeiro = novo;
            ultimo = novo;
        } else {
            ultimo->proximo = novo;
            ultimo = novo;
        }
    }

    printf("Valores da lista: ");

    struct No *temp = primeiro;

    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }

    printf("\n");

    // limpar memória
    temp = primeiro;

    while (temp != NULL) {
        struct No *proximo = temp->proximo;
        free(temp);
        temp = proximo;
    }

    return 0;
}