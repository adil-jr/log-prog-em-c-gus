#include <stdio.h>

int main() {
    int notas[3][2];

    for (int i = 0; i < 3; i++) { // linhas
        for (int j = 0; j < 2; j++) { // colunas
            printf("Digite a nota do aluno %d, prova %d: ", i + 1, j + 1);
            scanf("%d", &notas[i][j]);
        }
    }

    printf("\n=== NOTAS ===\n");

    for (int i = 0; i < 3; i++) { // linhas
        printf("Aluno %d: ", i + 1);
        for (int j = 0; j < 2; j++) { // colunas
            printf("%d ", notas[i][j]);
        }
        printf("\n");
    }

    return 0;
}