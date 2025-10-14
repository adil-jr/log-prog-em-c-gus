#include <stdio.h>
#include <stdlib.h>

enum TipoValor {
    TIPO_INT = 1,
    TIPO_FLOAT = 2,
    TIPO_CHAR = 3
};

typedef struct {
    enum TipoValor tipo;
    union {
        int i;
        float f;
        char c;
    } valor;
} Dado;

void exibirMenu();
int lerOpcao();
void lerValor(Dado *dado);
void exibirValor(Dado dado);
void limparBuffer();

int main() {
    Dado meuDado;
    int opcao;

    printf("========================================\n");
    printf("      PROGRAMA DE UNION EM C      \n");
    printf("========================================\n");

    exibirMenu();

    opcao = lerOpcao();

    meuDado.tipo = opcao;

    lerValor(&meuDado);

    exibirValor(meuDado);

    return 0;
}

void exibirMenu() {
    printf("Escolha o tipo de valor que deseja armazenar:\n");
    printf("[1] - Inteiro (int)\n");
    printf("[2] - Decimal (float)\n");
    printf("[3] - Caractere (char)\n");
}

int lerOpcao() {
    int opcao;

    do {
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        if (opcao < 1 || opcao > 3) {
            printf("Erro! Opção inválida. Escolha entre 1 e 3.\n");
        }
    } while (opcao < 1 || opcao > 3);

    printf("\n");

    return opcao;
}

void lerValor(Dado *dado) {
    printf("=== ENTRADA DE DADOS ===\n");

    switch (dado->tipo) {
        case TIPO_INT:
            printf("Digite um valor inteiro: ");
            scanf("%d", &dado->valor.i);
            limparBuffer();
            break;
        case TIPO_FLOAT:
            printf("Digite um valor decimal: ");
            scanf("%f", &dado->valor.f);
            limparBuffer();
            break;
        case TIPO_CHAR:
            printf("Digite um caractere: ");
            limparBuffer();
            dado->valor.c = getchar();
            break;
        default:
            printf("Erro: tipo inválido!\n");
            break;
    }

    printf("\n");
}

void exibirValor(Dado dado) {
    printf("========================================\n");
    printf("           VALOR ARMAZENADO           \n");
    printf("========================================\n");

    switch (dado.tipo) {
        case TIPO_INT:
            printf("Tipo: Inteiro\n");
            printf("Valor: %d\n", dado.valor.i);
            break;
        case TIPO_FLOAT:
            printf("Tipo: Decimal\n");
            printf("Valor: %.2f\n", dado.valor.f);
            break;
        case TIPO_CHAR:
            printf("Tipo: Caractere\n");
            printf("Valor: %c\n", dado.valor.c);
            break;
        default:
            printf("Erro: tipo desconhecido!\n");
            break;
    }

    printf("========================================\n");
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}