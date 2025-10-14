#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main() {
    Pessoa pessoas[3];
    int indiceMaisVelha = 0;
    int c;

    printf("=== CADASTRO DE PESSOAS ===\n");

    for (int i = 0; i < 3; i++) {
        printf("--- Pessoa %d ---\n", i + 1);
        printf("Nome: ");
        fgets(pessoas[i].nome, 50, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);

        while (pessoas[i].idade <= 0) {
            printf("Erro! Idade deve ser maior que zero. Digite novamente: ");
            scanf("%d", &pessoas[i].idade);
        }

        printf("Altura (em metros): ");
        scanf("%f", &pessoas[i].altura);

        while (pessoas[i].altura <= 0.0) {
            printf("Erro! Altura deve ser maior que zero. Digite novamente: ");
            scanf("%f", &pessoas[i].altura);
        }

        while ((c = getchar()) != '\n' && c != EOF) { }
        printf("\n");
    }

    for (int i = 1; i < 3; i++) {
        if (pessoas[i].idade > pessoas[indiceMaisVelha].idade) {
            indiceMaisVelha = i;
        }
    }

    printf("=== PESSOA MAIS VELHA ===\n");
    printf("Nome: %s\n", pessoas[indiceMaisVelha].nome);
    printf("Idade: %d\n", pessoas[indiceMaisVelha].idade);
    printf("Altura: %.2f\n", pessoas[indiceMaisVelha].altura);

    return 0;
}