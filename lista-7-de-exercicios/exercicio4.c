#include <stdio.h>
#include <string.h>

int main() {
    char nomes[5][50];
    char caractereBusca;
    int tamanho;

    printf("Digite 5 nomes:");
    printf("\n");

    for( int i = 0; i < 5; i++) {
        printf("Nome %d: ", i + 1);
        fgets(nomes[i], sizeof(nomes[i]), stdin);

        tamanho = strlen(nomes[i]);

        if (tamanho > 0 && nomes[i][tamanho - 1] == '\n') {
            nomes[i][tamanho - 1] = '\0';
        }
    }

    printf("\n");
    printf("Digite o caractere para buscar: ");
    scanf(" %c", &caractereBusca);

    printf("\n");
    printf("Nomes que contêm '%c':", caractereBusca);
    printf("\n");

    for (int i = 0; i < 5; i++) {
        if (strchr(nomes[i], caractereBusca) != NULL) {
            printf("%s\n", nomes[i]);
        }
    }

    printf("\n");

    return 0;
}