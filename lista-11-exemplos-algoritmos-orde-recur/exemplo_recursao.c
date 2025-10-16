#include <stdio.h>

void contar(int n) {
    if (n > 5) return;

    printf("Número: %d\n", n);
    contar(n + 1);
}

int main() {
    contar(1);

    return 0;
}