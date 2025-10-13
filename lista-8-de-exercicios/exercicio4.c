#include <stdio.h>

int main() {
    int original[3][2];
    int transposta[2][3];

    printf("Digite os 6 valores da matriz 3x2 (linha por linha):\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &original[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            transposta[i][j] = original[j][i];
        }
    }

    printf("\nMatriz original:\n");

    for (int i = 0; i < 3; i++) {

        printf("|");

        for (int j = 0; j < 2; j++) {
            printf("%4d", original[i][j]);
        }
        printf("   |\n");
    }

    printf("\nMatriz transposta:\n");

    for (int i = 0; i < 2; i++) {

        printf("|");

        for (int j = 0; j < 3; j++) {
            printf("%4d", transposta[i][j]);
        }
        printf("   |\n");
    }


    return 0;
}