#include <stdio.h>
#include <stdlib.h>

void inverteVetor(int *vetor, int tamanho) {
    int temp;

    for (int i = 0; i < tamanho / 2; i++) {
        temp = vetor[i];
        vetor[i] = vetor[tamanho - 1 - i];
        vetor[tamanho - 1 - i] = temp;
    }
}

int main() {
    int tamanho, *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *) malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("Deu ruim!");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\n=== Vetor original ===\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    inverteVetor(vetor, tamanho);

     printf("\n=== Vetor invertido ===\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    
    printf("\n");

    free(vetor);

    return 0;
}