#include <stdio.h>

int main() {
    int totalMoedas = 0;
    int rodadas = 0;
    int moedasRodada;

    while (totalMoedas < 100) {
        printf("Quantas moedas de 1 a 10 você ganhou? ");
        scanf("%d", &moedasRodada);
        
        if (moedasRodada < 1 || moedasRodada > 10) {
            printf("Valor inválido! Digite entre 1 e 10. \n");
            continue;
        }

        totalMoedas += moedasRodada;
        rodadas++;

        printf("Total atual: %d moedas em %d rodadas! \n", totalMoedas, rodadas);
    }

    printf("\nParabéns! Você atingiu %d moedas em %d rodadas! \n", totalMoedas, rodadas);

    return 0;
}