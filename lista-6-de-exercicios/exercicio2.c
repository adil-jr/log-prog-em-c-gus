#include <stdio.h>
#include <stdlib.h>

int main() {
    char idadeTexto[10];
    int idadeNumero;

    printf("Digite sua idade: ");
    fgets(idadeTexto, sizeof(idadeTexto), stdin);

    idadeNumero = atoi(idadeTexto);

    printf("Idade informada: %d anos. \n", idadeNumero);

    if (idadeNumero >=18) {
        printf("Você é maior de idade! \n");
    } else {
        printf("Você é menor de idade. \n");
    }

    return 0;
}