#include <stdio.h>

int main() {
    char nome[10];
    int idade;
    int gol;

    printf("Qual seu nome? ");
    scanf("%s", nome);

    printf("Qual sua idade? ");
    scanf("%d", &idade);

    printf("Quantos gols na carreira? ");
    scanf("%d", &gol);

    printf("O jogador %s tem %d anos e %d gol(s) na carreira. \n", nome, idade, gol);

    return 0;
}