#include <stdio.h>

int main() {
    int idade, golsMarcados;

    printf("Qual a idade do jogador? ");
    scanf("%d", &idade);

    printf("Gol(s) marcado(s)? ");
    scanf("%d", &golsMarcados);

    if (idade < 0 || golsMarcados < 0) {
        printf("Informe números positivos. \n");
    } else if (idade <= 20 && golsMarcados > 10) {
        printf("Jovem talento promissor! \n");
    } else if (idade <= 20 && golsMarcados <= 10) {
        printf("Jovem em desenvolvimento. \n");
    } else if (idade > 20 && golsMarcados > 15) {
        printf("Jogador experiente em grande fase! \n");
    } else {
        printf("Estevão \n");
    }

    return 0;
}