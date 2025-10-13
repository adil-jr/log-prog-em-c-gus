#include <stdio.h>

int main() {
    int idade;

    printf("Qual a sua idade? ");
    scanf("%d", &idade);

    if (idade <= 0) {
        printf("Idade não pode ser negativa. \n");
    } else if (idade > 20) {
        printf("Você irá para categoria profissional. \n");
    } else {
        printf("Você irá para categoria sub-20. \n");
    }

    return 0;
}