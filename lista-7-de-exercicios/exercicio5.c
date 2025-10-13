#include <stdio.h>

int main() {
    int recorde = 5000, score;

    printf("Digite os 5 scores do jogador:");
    printf("\n");

    for (int i = 1; i <= 5; i++) {
        printf("Score %d: ", i);
        scanf("%d", &score);

        if (score > recorde) {
            printf("Parabéns! Score %d superou o recorde!\n", score);
            recorde = score;
        }
    }

    printf("\n");
    printf("Recorde final: %d\n", recorde);

    return 0;
}