#include <stdio.h>
#include <stdbool.h>

bool validarTamanho(int n) {
    return n > 0 && n <=50;
}

void imprimirQuadrado(int tamanho, char caractere) {
    int i, j;

    printf("Quadrado tamanho %d com '%c': \n", tamanho, caractere);

    for (i = 1; i <= tamanho; i++) {
        for (j = 1; j <= tamanho; j++) {
            printf("%c ", caractere);
        }
        printf("\n");
    }
}

int main() {
    int n;
    char caracter;

    printf("=== GERADOR DE QUADRADOS ===\n");

    do {
        printf("Digite o tamanho do lado (1-50): ");
        scanf("%d", &n);

        if (!validarTamanho(n)) {
            printf("ERRO: Tamanho deve estar entre 1 e 50!\n\n");
        }
    } while (!validarTamanho(n));

    printf("Digite o caractere a ser usado: ");
    scanf(" %c", &caracter);

    printf("\n");
    imprimirQuadrado(n, caracter);

    return 0;
}