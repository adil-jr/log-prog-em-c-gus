#include <stdio.h>

int main() {
    int numeros[10];
    int pares [10];
    int contadorPares;

    printf("Digite 10 números inteiros:");
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    contadorPares = 0;

    for (int i = 0; i < 10; i++) {
        if (numeros[i] % 2 == 0) {
            pares[contadorPares] = numeros[i];
            contadorPares++;
        }
    }

    printf("\n");

    if (contadorPares > 0) {
        printf("Números pares: ");

        for (int i = 0; i < contadorPares; i++) {
            printf("%d ", pares[i]);
        }
        printf("\n");
    } else {
        printf("Nenhum número par foi encontrado.\n");
    }

    return 0;
}