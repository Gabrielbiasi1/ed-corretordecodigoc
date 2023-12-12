#include <stdio.h>

int main() {
    float velocidade_inicial, velocidade_final, tempo, aceleracao;


   
    scanf("%f", &velocidade_inicial);

    
    scanf("%f", &velocidade_final);

   
    scanf("%f", &tempo);

 
    aceleracao = (velocidade_final - velocidade_inicial) / tempo;


    printf("%.2f", aceleracao);

    return 0;
}
