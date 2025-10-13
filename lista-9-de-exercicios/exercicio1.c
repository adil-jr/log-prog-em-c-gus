#include <stdio.h>
#include <stdlib.h>

int soma(int *ptr1, int *ptr2) {
    return *ptr1 + *ptr2;
}

int main() {
    int num1, num2, resultado;

    printf("Digite um número inteiro: ");
    scanf("%d", &num1);

    printf("Digite novamente um número inteiro: ");
    scanf("%d", &num2);

    resultado = soma(&num1, &num2);

    printf("A soma dos números inteiros digitados é: %d\n", resultado);

    return 0;
}