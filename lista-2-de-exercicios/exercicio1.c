#include <stdio.h>

int main() {
    char opcao;

    printf("O que você deseja? 1 - Hambúrguer 2 - Cachorro-quente 3 - Pizza 4 - Sair \n");
    scanf("%c", &opcao);

    switch (opcao) {
        case '1':
            printf("Aproveite seu Hambúrguer! \n");
            break;
        case '2':
            printf("Aproveite seu Cachorro-quente! \n");
            break;
        case '3':
            printf("Aproveite sua Pizza! \n");
            break;
        case '4':
            printf("Encerrando pedido... \n");
            break;
        default:
            printf("Opção inválida! \n");
    }

    return 0;
}