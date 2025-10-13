#include <stdio.h>

int parImpar(int numero) {
    if (numero % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);

    if (parImpar(num)) {
        printf("PAR \n");
    } else {
        printf("ÍMPAR \n");
    }

    return 0;
}