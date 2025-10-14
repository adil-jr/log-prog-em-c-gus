#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No *prox;
} No;

void push(No **topo, char caractere);
char pop(No **topo);
int isEmpty(No *topo);
void liberarPilha(No **topo);

int verificarBalanceamento(const char *expressao);
void lerExpressao(char *expressao, int tamanho);

int main() {
    char expressao[100];

    printf("========================================\n");
    printf("   VERIFICADOR DE PARÊNTESES   \n");
    printf("========================================\n");

    lerExpressao(expressao, 100);

    if (verificarBalanceamento(expressao) == 1) {
        printf("\nResultado: BALANCEADO\n");
    } else {
        printf("\nResultado: NÃO BALANCEADO\n");
    }

    printf("\n");

    return 0;
}

void push(No **topo, char caractere) {
    No *novo;
    novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        exit(1);
    }

    novo->dado = caractere;
    novo->prox = *topo;

    *topo = novo;
}

char pop(No **topo) {
    if (*topo == NULL) {
        return '\0';
    }

    No *temp = *topo;

    char caractere = temp->dado;

    *topo = temp->prox;

    free(temp);

    return caractere;
}

int isEmpty(No *topo) {
    return (topo == NULL) ? 1 : 0;
}

void liberarPilha(No **topo) {
    No *atual = *topo;
    No *temp;

    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }

    *topo = NULL;

}

int verificarBalanceamento(const char *expressao) {
    No *topo = NULL;
    int tamanho = strlen(expressao);

    printf("Processando: ");

    for (int i = 0; i < tamanho; i++) {
        char caractere = expressao[i];

        if (caractere == '(') {
            push(&topo, caractere);
            printf("(");
        } else if (caractere == ')') {
            printf(")");
            char removido = pop(&topo);

            if (removido == '\0') {
                printf("\nErro: ')' sem '(' correspondente\n");
                liberarPilha(&topo);
                return 0;
            }
        } else {
            printf("%c", caractere);
        }
    }

    printf("\n");

    if (isEmpty(topo) == 1) {
        liberarPilha(&topo);
        return 1;
    } else {
        printf("Erro: '(' sem ')' correspondente\n");
        liberarPilha(&topo);
        return 0;
    }
}

void lerExpressao(char *expressao, int tamanho) {
    printf("Digite a expressão matemática: ");
    fgets(expressao, tamanho, stdin);
    expressao[strcspn(expressao, "\n")] = '\0';
}