#include <stdio.h>

int main() {
    int n;
    int par = 2;

    printf("Digite um número para o tamanho do triângulo: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", par);
            par += 2;
        }
        printf("\n");
    }

    return 0;
}