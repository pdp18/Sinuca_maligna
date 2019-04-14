#include <stdio.h>
#include <stdlib.h>
#include "Bola.h"

int main()
{
    int n_bolas, i;
    float raio ;
    Vetorf vel, pos;
    Vetori limx, limy;
    Bola* b = NULL;

    limx.x = 0;
    limx.y = 1024;

    limy.x = 0;
    limy.y = 720;

    printf("Qual a quantidade de bolas? ");
    scanf("%d", &n_bolas);

    printf("Qual o raio das bolas? ");
    scanf("%f", &raio);

    printf("Qual o velocidade da bola em pixels? ");
    scanf("%f%f", &vel.x, &vel.y);

    for (i = 0; i < n_bolas; i++)
    {
        pos = posicaoAleatoria(raio, &limx, &limy);
        b = insereBola(b, raio, &vel, &pos);
    }

    return 0;
}
