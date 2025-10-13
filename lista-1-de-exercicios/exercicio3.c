#include <stdio.h>

int main() {
    int tempoMinutos, horas, minutosRestantes;


    printf("Digite o tempo jogado em minutos: ");
    scanf("%d", &tempoMinutos);

    if (tempoMinutos > 0) {
        horas = tempoMinutos / 60;
        minutosRestantes = tempoMinutos % 60;
        printf("Tempo de jogo: %d hora(s) e %d minuto(s). \n", horas, minutosRestantes);        
    } else {
        printf("Tempo deve ser maior que zero!");
    }

    return 0;
}