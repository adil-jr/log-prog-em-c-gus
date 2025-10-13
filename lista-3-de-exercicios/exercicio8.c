#include <stdio.h>

int main() {
    int quantidadeProduto, estoque, estoqueMinimo;
    char nomeProduto[50];

    printf("Digite a quantidade de produtos a serem cadastrados: ");
    scanf("%d", &quantidadeProduto);

    for (int i = 1; i <= quantidadeProduto; i++) {

    printf("Produto %d: \n", i);

    printf("Nome do produto: ");
    scanf("%s", nomeProduto);

    printf("Quantidade em estoque? ");
    scanf("%d", &estoque);

    printf("Estoque mínimo recomendado: ");
    scanf("%d", &estoqueMinimo);

    if (estoque < estoqueMinimo) {
        printf("-> O produto '%s' precisa ser reposto! (Estoque: %d, Mínimo: %d) \n", nomeProduto, estoque, estoqueMinimo);
    } else {
        printf("O produto '%s' tem estoque suficiente. (Estoque: %d, Mínimo: %d) \n", nomeProduto, estoque, estoqueMinimo);
    }

    printf("\n");
}

    return 0;
}