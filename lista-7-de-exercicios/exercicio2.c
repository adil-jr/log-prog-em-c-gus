#include <stdio.h>

int main() {
    int dano [4];
    int maiorDano;

    printf("Digite o dano de 4 ataques:");
    printf("\n");

    for (int i = 0; i < 4; i++) {
        printf("Ataque %d: ", i + 1);
        scanf("%d", &dano[i]);
    }

    maiorDano = dano[0];

    for (int i = 1; i < 4; i++) {
        if (dano[i] > maiorDano) {
            maiorDano = dano[i];
        }
    }

    printf("\n");
    printf("Maior dano causado: %d\n", maiorDano);

    return 0;
}