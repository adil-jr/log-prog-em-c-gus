#include <stdio.h>

int contarVogais(char palavra[]) {
    int contador = 0, i = 0;
    char caractere;

    while (palavra[i] != '\0') {
        caractere = palavra[i];

        if (caractere == 'a' || caractere == 'e' || caractere == 'i' ||
            caractere == 'o' || caractere == 'u' || caractere == 'A' || 
            caractere == 'E' || caractere == 'I' ||
            caractere == 'O' || caractere == 'U') {
                contador += 1;
            }
            i += 1;
    }
    return contador;
}

int main() {
    char palavra[100];
    int resultado;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    resultado = contarVogais(palavra);

    printf("A palavra '%s' tem %d vogais. \n", palavra, resultado);

    return 0;
}