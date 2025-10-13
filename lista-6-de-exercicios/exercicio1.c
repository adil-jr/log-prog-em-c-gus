#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    printf("Números da Mega Sena: \n");

    for (int i = 0; i < 6; i++) {
        int numero = rand() % 60 + 1;

        printf("%d", numero);
        if (i < 5) printf(" - ");
    }
    printf("\n");

    return 0;
}