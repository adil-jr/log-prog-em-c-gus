#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float soma = 0.0, media, *vetor;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Erro: quantidade deve ser maior que zero!\n");
        return 1;
    }

    vetor = (float *) malloc(n * sizeof(float));

    if (vetor == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        return 1;
    }

    printf("\nDigite os valores:\n");

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vetor[i]);
        soma += vetor[i];
    }

    media = soma / n;

    printf("\nA média dos valores é: %.2f\n", media);

    free(vetor);
    vetor = NULL;

    return 0;
}