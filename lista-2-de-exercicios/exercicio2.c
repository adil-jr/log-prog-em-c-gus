#include <stdio.h>

int main() {
    char verifica;
    float nota, presenca;

    printf("========== SISTEMA DE APROVAÇÃO ==========\n");
    printf("1. Verificar se o aluno foi aprovado\n");
    printf("2. Sair\n");
    printf("> ");
    scanf("%c", &verifica);

    switch (verifica) {
        case '1':
            printf("Qual a nota final (de 0 a 10) do aluno? ");
            scanf("%f", &nota);
            printf("Porcentagem de presença (de 0 a 100): ");
            scanf("%f", &presenca);

            if (nota >= 7 && presenca >= 75) {
                printf("Aluno aprovado! \n");
            } else {
                printf("Aluno reprovado. \n");
            }
            break;
        case '2':
            printf("Programa encerrado. \n");
            break;
        default:
            printf("Opção inválida! \n");
    }

    return 0;
}