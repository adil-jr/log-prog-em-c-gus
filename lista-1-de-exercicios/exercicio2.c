#include <stdio.h>

int main() {
    int gol;
    int partidas;
    float media;

    printf("Seus gols totais: ");
    scanf("%d", &gol);

    printf("Suas partidas totais: ");
    scanf("%d", &partidas);

    if (partidas > 0) {
        media = (float)gol / partidas;
        printf("O jogador tem uma média de %.2f gol(s) por partida! \n", media);
    } else {
        printf("O número de partidas deve ser maior que zero. \n");
    }

    return 0;
}