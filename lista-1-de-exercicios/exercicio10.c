#include <stdio.h>

int main() {
    int capacidadeTotal, torcedores;
    float taxaOcupacao;

    printf("Qual a capacidade TOTAL do estádio? ");
    scanf("%d", &capacidadeTotal);

    printf("Quantidade de torcedores presentes no jogo? ");
    scanf("%d", &torcedores);

    if (capacidadeTotal <= 0 || torcedores < 0) {
        printf("Valores inválidos. \n");
    } else if (torcedores > capacidadeTotal) {
        printf("Número de torcedores não pode exceder a capacidade total do estádio! \n");
    } else {
        taxaOcupacao = (torcedores * 100.0) / capacidadeTotal;
        if (taxaOcupacao > 90) {
            printf("Lotado! \n");
        } else if (taxaOcupacao >= 70) {
            printf("Ótima presença de público! \n");
        } else if (taxaOcupacao >= 50) {
            printf("Público razoável. \n");
        } else {
            printf("Morumbis \n");
        }
    }

    return 0;
}