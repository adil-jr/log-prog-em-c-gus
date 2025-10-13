#include <stdio.h>

int main() {
    for (int i = 0; i <= 10; i++) {
        printf("====================");
        printf("\nTabuada do %d \n", i);

        for (int j = 0; j <= 10; j++) {
            printf("%d x %d = %d \n", i, j, i * j);
        }
    }

    return 0;
}