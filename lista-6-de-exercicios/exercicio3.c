#include <stdio.h>
#include <stdlib.h>

int main() {
    char temperaturaTexto[20];
    float temperatura;

    printf("Digite a temperatura do ambiente (°C): ");
    fgets(temperaturaTexto, sizeof(temperaturaTexto), stdin);

    temperatura = atof(temperaturaTexto);

    printf("Temperatura registrada: %.1f°C\n", temperatura);

    if (temperatura < 18) {
        printf("O ambiente está frio.\n");
    } else if (temperatura <= 26) {
        printf("O ambiente está agradável.\n");
    } else {
        printf("O ambiente está quente.\n");
    }

    return 0;
}