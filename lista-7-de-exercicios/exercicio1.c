#include <stdio.h>

int main() {
    int fps[6];
    int soma;
    float media;

    printf("Digite os FPS registrados em 6 momentos: ");
    printf("\n");

    for (int i = 0; i < 6; i++) {
        printf("Momento %d: ", i + 1);
        scanf("%d", &fps[i]);
    }

    soma = 0;

    for (int i = 0; i < 6; i++) {
        soma += fps[i];
    }

    media = soma / 6.0;

    printf("\nMédia de FPS: %.2f\n", media);

    return 0;
}