#include <stdio.h>

int main() {

    FILE *arquivo = fopen("alunos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char nome[100];
    int idade;

    printf("Digite o nome do aluno: ");
    scanf("%s", nome);

    printf("Digite a idade do aluno: ");
    scanf("%d", &idade);

    fprintf(arquivo, "%s %d\n", nome, idade);

    fclose(arquivo);

    printf("Dados salvos com sucesso!\n");

    return 0;
}