#include <stdio.h>
#include <stdbool.h>

bool validarNota(float nota) {
    return nota >= 0.0 && nota <= 10.0;
}

void classificarNota(float nota) {
    if (nota >= 6.0) {
        printf("Status: APROVADO\n");
        printf("Parabéns por atingir a média.\n");
    } else if (nota >= 4.0) {
        printf("Status: RECUPERAÇÃO\n");
        printf("Você precisa fazer a prova de recuperação.\n");
    } else {
        printf("Status: REPROVADO\n");
        printf("Infelizmente você foi reprovado.\n");
    }
}

int main() {
    float nota;

    printf("=== SISTEMA DE CLASSIFICAÇÃO DE NOTAS ===\n");

    do {
        printf("Digite a nota do aluno (0.0 a 10.0): ");
        scanf("%f", &nota);
        
        if (!validarNota(nota)) {
            printf("ERRO: Nota deve estar entre 0.0 e 10.0!\n\n");
        }
    } while (!validarNota(nota));
    
    classificarNota(nota);

    return 0;
}