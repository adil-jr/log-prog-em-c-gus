#include <stdio.h>

int main() {
    float salarioUm, salarioDois, diferenca;

    printf("Digite o primeiro salário: ");
    scanf("%f", &salarioUm);

    printf("Digite o segundo salário: ");
    scanf("%f", &salarioDois);

    if (salarioUm >= 0 && salarioDois >= 0) {
        if (salarioUm > salarioDois) {
            diferenca = salarioUm - salarioDois;
            printf("O primeiro jogador ganha R$ %.2f a mais. \n", diferenca);
        } else if (salarioDois > salarioUm) {
            diferenca = salarioDois - salarioUm;
            printf("O segundo jogador ganha R$ %.2f a mais. \n", diferenca);
        } else {
            printf("Os dois jogadores têm o mesmo salário. \n");
        }
    }

    return 0;
}