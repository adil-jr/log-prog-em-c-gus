#include <stdio.h>

int main() {
    int quantidadeCarro, anoFabricacao, funcionamento;
    char carroModelo[50];

    printf("Quantos carros serão registrados? ");
    scanf("%d", &quantidadeCarro);

    for (int i = 1; i <= quantidadeCarro; i++) {

        printf("Carro %d: \n", i);

        printf("Digite o nome do modelo: ");
        scanf("%s", carroModelo);

        printf("Digite o ano de fabricação: ");
        scanf("%d", &anoFabricacao);

        printf("Está funcionando normalmente (1 para SIM | 0 para NÃO): ");
        scanf("%d", &funcionamento);

        if (anoFabricacao < 2005 && funcionamento == 0) {
            printf("O carro %s precisa de REPAROS URGENTES! \n", carroModelo);
        } else if (anoFabricacao < 2005) {
            printf("O carro %s é antigo, recomenda-se uma revisão! \n", carroModelo);
        } else if (funcionamento == 0) {
            printf("O carro %s precisa de manutenção! \n", carroModelo);
        } else {
            printf("O carro %s está em boas condições! \n", carroModelo);
        }
    }

    return 0;
}