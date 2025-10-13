#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, somaLinha;
    int **matriz;

    printf("Digite o número de linhas (m): ");
    scanf("%d", &m);

    printf("Digite o número de colunas (n): ");
    scanf("%d", &n);

    if (m <= 0 || n <= 0) {
        printf("Erro: dimensões devem ser maiores que zero!");
        return 1;
    }

    matriz = (int **) malloc(m * sizeof(int *));

    if (matriz == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        matriz[i] = (int *) malloc(n * sizeof(int));

        if (matriz[i] == NULL) {
            printf("Erro: falha na alocação de memória na linha %d\n", i);
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
                matriz[j] = NULL;
            }

            free(matriz);
            matriz = NULL;

            return 1;
        }
    }

    printf("\nDigite os elementos da matriz:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nSoma de cada linha:\n");

    for (int i = 0; i < m; i++) {

        somaLinha = 0;

        for (int j = 0; j < n; j++) {
            somaLinha += matriz[i][j];
        }

        printf("Linha %d: %d\n", i + 1, somaLinha);

    }

    for (int i = 0; i < m; i++) {
        free(matriz[i]);
        matriz[i] = NULL;
    }

    free(matriz);
    matriz = NULL;

    return 0;
}