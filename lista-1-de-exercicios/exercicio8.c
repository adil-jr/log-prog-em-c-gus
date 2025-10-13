#include <stdio.h>

int main() {
    int golsMarcados;

    printf("Quantos gols você fez nesta temporada? ");
    scanf("%d", &golsMarcados);

    if (golsMarcados < 0) {
        printf("Não é permitido números negativos.");
    } else if (golsMarcados > 10) {
        printf("Excelente temporada! \n");
    } else if (golsMarcados >= 5) {
        printf("Boa temporada! \n");
    } else {
        printf("Temporada abaixo do esperado \n");
    }

    return 0;
}