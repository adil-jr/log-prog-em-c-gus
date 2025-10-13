#include <stdio.h>
#include <string.h>

int main() {
    char nomeUsuario[51];
    int tamanho, contador;

    printf("Digite seu nome de usuário: ");
    fgets(nomeUsuario, sizeof(nomeUsuario), stdin);

    tamanho = strlen(nomeUsuario);

    if (tamanho > 0 && nomeUsuario[tamanho - 1] == '\n') {
        nomeUsuario[tamanho - 1] = '\0';
        tamanho--;
    }

    contador = 0;

    for (int i = 0; i < tamanho; i++) {
        if (nomeUsuario[i] == '@' || nomeUsuario[i] == '#' || nomeUsuario[i] == '$' ||
            nomeUsuario[i] == '%' || nomeUsuario[i] == '!') {
                contador++;
        }
    }

    if (contador > 0) {
        printf("Nome inválido! %d caractere(s) proibido(s).\n", contador);
    } else {
        printf("Nome válido - nenhum caractere proibido encontrado.\n");
    }

    return 0;
}