#include <stdio.h>

int main() {

    FILE *arquivo;
    arquivo = fopen("nomes.txt", "r");
    char nome[100];

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }

    while(fscanf(arquivo, "%s", nome) != EOF) {
        printf("Nome: %s\n", nome);
    }

    return 0;
}