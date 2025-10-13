#include <stdio.h>

int main() {
    int n, soma;

    printf("Digite o número para soma: ");
    scanf("%d", &n);

    soma = 0;

    for (int i = 1; i <= n; i++) {
        soma += i;
    }

    printf("A soma de 1 até %d é: %d \n", n, soma);

    printf("(Cálculo: ");

    for (int i = 1; i <= n; i++) {
        printf("%d", i);

        if (i < n) {
            printf(" + ");
        }
    }

    printf(" = %d) \n", soma);


    return 0;
}