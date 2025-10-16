#include <stdio.h>

int fibonacci(int numero) {
    // caso base
    if (numero == 0) return 0;
    if (numero == 1) return 1;

    return fibonacci(numero - 1) + fibonacci(numero - 2);
}

int main() {
    int n;

    printf("Digite qual o número de Fibonacci você quer: ");
    scanf("%d", &n);

    printf("Sequência de Fibonacci: \n");

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");

    return 0;
}