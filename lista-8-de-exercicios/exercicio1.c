#include <stdio.h>

int main() {
    int arrecadacao[2][3];
    int total;

    printf("Digite os valores arrecadados:\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Agência %d, Dia %d: ", i + 1, j + 1);
            scanf("%d", &arrecadacao[i][j]);
        }
    }

    total = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            total += arrecadacao[i][j];
        }
    }

    printf("\n");
    printf("Total arrecadado: %d\n", total);

    return 0;
}