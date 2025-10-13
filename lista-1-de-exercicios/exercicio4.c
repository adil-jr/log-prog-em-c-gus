#include <stdio.h>

int main() {
    int vitorias, derrotas, empates, totalPontos;

    printf("Número de vitórias: ");
    scanf("%d", &vitorias);

    printf("Número de derrotas: ");
    scanf("%d", &derrotas);

    printf("Número de empates: ");
    scanf("%d", &empates);

    if (vitorias >= 0 && derrotas >= 0 && empates >= 0) {
        totalPontos = (vitorias * 3) + empates;
        
        printf("Total de pontos: %d \n", totalPontos);
    } else {
        printf("Valores não podem ser negativos! \n");
    }

    return 0;
}