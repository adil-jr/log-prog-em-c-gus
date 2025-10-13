#include <stdio.h>

int main() {
    int n;

    printf("Digite um número: ");
    scanf("%d", &n);

    printf("Números pares de 1 até %d: \n", n);

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}