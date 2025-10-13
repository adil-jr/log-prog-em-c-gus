#include <stdio.h>

char *classificarDesempenho(float media) {
    if (media >= 9.0) {
        return "EXCELENTE";
    } else if (media >= 7.0) {
        return "BOM";
    } else if (media >= 5.0) {
        return "REGULAR";
    } else {
        return "RUIM";
    }
}

int main() {
    int jogador, i;
    float nota, soma, media;
    char *classificacao;

    printf("=== SISTEMA DE AVALIAÇÃO DE JOGADORES ===\n");

    for (jogador = 1; jogador <= 5; jogador++) {
        printf("JOGADOR %d: \n", jogador);

        soma = 0;

        for (i = 1; i <= 3; i++) {
            printf("Nota %d: ", i);
            scanf("%f", &nota);
            soma += nota;
        }

        media = soma / 3.0;
        classificacao = classificarDesempenho(media);

        printf("Média: %.1f\n", media);
        printf("Classificação: %s\n", classificacao);
        printf("\n");
    }

    return 0;
}