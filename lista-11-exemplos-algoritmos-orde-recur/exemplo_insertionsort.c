#include <stdio.h>

void imprimirVetor(int numeros[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
}

void insertionSort(int numeros[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = numeros[i];
        int j = i - 1;

        while (j >= 0 && numeros[j] > chave) {
            numeros[j + 1] = numeros[j];
            j--;
        }

        numeros[j + 1] = chave;
    }
}

int main() {
    int numeros[] = {1, 3, 5, 7, 2, 4, 8, 9, 6};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    printf("Vetor original: \n");
    imprimirVetor(numeros, tamanho);

    insertionSort(numeros, tamanho);

    printf("\n\nVetor ordenado: \n");
    imprimirVetor(numeros, tamanho);
    printf("\n");

    return 0;
}