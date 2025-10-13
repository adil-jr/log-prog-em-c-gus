#include <stdio.h>

int main() {
    int matriz[4][4];
    int eIdentidade = 1;

    printf("Digite os elementos da matriz 4x4:\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                if (matriz[i][j] != 1) {
                    eIdentidade = 0;
                    break;
                }
            } else if (matriz[i][j] != 0) {
                eIdentidade = 0;
                break;
            }
        }
        if (eIdentidade == 0) {
            break;
        }
    }

    printf("\n");

    if (eIdentidade == 1) {
        printf("Matriz identidade? SIM\n");
    } else {
        printf("Matriz identidade? NÃO\n");
    }

    printf("\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}