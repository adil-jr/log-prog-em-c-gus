#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo = fopen("alunos.txt", "r");
    char nome[100];
    int idade;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while (fscanf(arquivo, "%s %d", nome, &idade) != EOF) {
        printf("Nome: %s | Idade: %d\n", nome, idade);
    }

    system("kate alunos.txt");

    fclose(arquivo);

    return 0;
}