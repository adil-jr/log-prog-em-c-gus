#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverterString(char *original) {

    if (original == NULL) {
        return NULL;
    }

    int tamanho, indiceFim;
    char *invertida;

    tamanho = strlen(original);
    invertida = (char *) malloc((tamanho + 1) * sizeof(char));

    if (invertida == NULL) {
        printf("Erro: falha na alocação de memória!");
        return NULL;
    }

    indiceFim = tamanho - 1;

    for (int i = 0; i < tamanho; i++) {
        invertida[i] = original[indiceFim];
        indiceFim--;
    }

    invertida[tamanho] = '\0';

    return invertida;
}

int main() {
    char *stringOriginal;
    char *stringInvertida;
    int tamanhoMaximo = 100;

    stringOriginal = (char *) malloc((tamanhoMaximo + 1) * sizeof(char));

    if (stringOriginal == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        return 1;
    }

    printf("Digite uma string: ");
    fgets(stringOriginal, tamanhoMaximo + 1, stdin);

    int tam = strlen(stringOriginal);

    if (stringOriginal[tam - 1] == '\n') {
        stringOriginal[tam - 1] = '\0';
    }

    stringInvertida = inverterString(stringOriginal);

    if (stringInvertida == NULL) {
        printf("Erro: falha ao inverter string!\n");
        free(stringOriginal);
        stringOriginal = NULL;
        return 1;
    }

    printf("\nString original: %s\n", stringOriginal);
    printf("\nString invertida: %s\n", stringInvertida);

    free(stringOriginal);
    stringOriginal = NULL;

    free(stringInvertida);
    stringInvertida = NULL;

    return 0;
}