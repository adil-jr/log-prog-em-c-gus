#include <stdio.h>

int main() {
    char operador;
    float a, b;

    printf("Digite a operação (+, -, *, /): ");
    scanf("%c", &operador);

    printf("Digite os dois valores: ");
    scanf("%f %f", &a, &b);

    switch (operador) {
        case '+': 
            printf("%.2f %c %.2f = %.2f \n", a, operador, b, (a + b));
            break;
        case '-': 
            printf("%.2f %c %.2f = %.2f \n", a, operador, b, (a - b));
            break;
        case '*': 
            printf("%.2f %c %.2f = %.2f \n", a, operador, b, (a * b));
            break;
        case '/': 
            if (a != 0 && b != 0) {
                printf("%.2f %c %.2f = %.2f \n", a, operador, b, (a / b));
            } else {
                printf("Não é possível fazer uma divisão por zero. \n");
            }
            break;
        default:
            printf("Operador inválido! \n");
    }

    return 0;
}