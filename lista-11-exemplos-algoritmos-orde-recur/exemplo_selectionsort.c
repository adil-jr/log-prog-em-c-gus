#include <stdio.h>

void selectionSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;

        // Encontra o menor elemento à frente de i
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }

        // Troca o menor encontrado com o elemento da posição atual
        if (indiceMenor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[indiceMenor];
            vetor[indiceMenor] = temp;
        }
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
}

int main() {
    int numeros[] = {5, 3, 1, 4, 2};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    printf("Vetor original: \n");
    imprimirVetor(numeros, tamanho);

    selectionSort(numeros, tamanho);

    printf("\n\nVetor ordenado: \n");
    imprimirVetor(numeros, tamanho);
    printf("\n");

    return 0;
}