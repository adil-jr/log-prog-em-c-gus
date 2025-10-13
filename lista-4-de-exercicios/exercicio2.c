#include <stdio.h>

int main() {
    int palpite;

    do {
        printf("Qual seu palpite para o número secreto? ");
        scanf("%d", &palpite);
    } while (palpite != 7);

    printf("Você acertou! \n");

    return 0;
}