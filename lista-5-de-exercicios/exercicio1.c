#include <stdio.h>

float media(float numero1, float numero2) {
    return (numero1 + numero2) / 2.0;
}

int main() {
    float nota1, nota2, resultado;
    
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    
    resultado = media(nota1, nota2);
    
    printf("A média é: %.2f\n", resultado);
    
    return 0;
}