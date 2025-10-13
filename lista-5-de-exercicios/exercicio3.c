#include <stdio.h>

int encontrarMaior(int a, int b, int c) {
    if (a >= b) {
        if (a >= c) {
            return a;
        } else {
            return c;
        }
    } else if (b >= c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int num1, num2, num3, resultado;

    printf("=== ENCONTRAR O MAIOR DE TRÊS NÚMEROS ===\n");

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    printf("Digite o terceiro número: ");
    scanf("%d", &num3);

    resultado = encontrarMaior(num1, num2, num3);

    printf("Os números digitados foram: %d - %d - %d\n", num1, num2, num3);
    printf("O maior número é: %d\n", resultado);

    if (num1 == resultado && num2 == resultado && num3 == resultado) {
        printf("\nTodos os números são iguais!\n");
    }

    return 0;
}