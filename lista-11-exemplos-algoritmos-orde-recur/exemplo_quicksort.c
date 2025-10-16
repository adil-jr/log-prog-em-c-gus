#include <stdio.h>

int particionar(int vetor[], int inicio, int fim) {
    int meio = inicio + (fim - inicio) / 2;

    // Troca vetor[meio] <-> vetor[fim]
    int temp = vetor[meio];
    vetor[meio] = vetor[fim];
    vetor[fim] = temp;

    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] < pivo) {
            i++;
            // Troca vetor[i] <-> vetor[j]
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    // Troca vetor[i + 1] <-> vetor[fim]
    temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;

    return i + 1;
}

void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, indicePivo - 1); // Parte esquerda
        quickSort(vetor, indicePivo + 1, fim); // Parte direita
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
}

int main() {
    int numeros[] = {9, 2, 5, 1, 8, 3, 7, 4, 6};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    printf("Vetor original: \n");
    imprimirVetor(numeros, tamanho);

    quickSort(numeros, 0, tamanho - 1);

    printf("\n\nVetor ordenado: \n");
    imprimirVetor(numeros, tamanho);
    printf("\n");

    return 0;
}