#include <stdio.h>

int main() {
    float raio, circunferencia;
    const float pi = 3.14159;

    scanf("%f", &raio);

    circunferencia = 2 * pi * raio;

    printf("%.2f", circunferencia);

    return 0;
}

