#include <stdio.h>

int fatorial(int n) {
    // caso base (n = 1 || 0)
    if (n == 0 || n == 1) return 1;

    return n * fatorial(n - 1);
}

int main() {
    int resultado = fatorial(5);

    printf("5! = %d\n", resultado);

    return 0;
}