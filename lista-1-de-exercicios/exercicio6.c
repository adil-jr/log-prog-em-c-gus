#include <stdio.h>

int main() {
    int cartoesAmarelos;

    printf("Quantos cartões amarelos você recebeu? ");
    scanf("%d", &cartoesAmarelos);

    if (cartoesAmarelos < 0) {
        printf("Número de cartões não pode ser negativo. \n");
    } else if(cartoesAmarelos >= 2) {
        printf("Você está expulso! \n");
        printf("Regra: 2 cartões amarelos = expulsão. \n");
    } else if (cartoesAmarelos == 1) {
        printf("Cuidado! Mais um cartão e você está expulso. \n");
    } else {
        printf("Parabéns, continue assim. \n");
    }

    return 0;
}