#include <stdio.h>
#include <stdlib.h>
#include "Bola.h"
int main()
{
    int n_bolas,cont=1;
    float raio ;
    Vetorf vel;
    Bola* b = NULL;
    b = insereBola()
    printf("Qual a quantidade de bolas ? ");
    scanf("%d",&n_bolas);
    while(n_bolas>0)
    {
        printf("Qual o raio da bola N:%d ",cont);
        scanf("%f",&raio);
        printf("Qual o velocidade da bola N:%d ",cont);
        scanf("%f%f",&vel.x,&vel.y);
        cont++;
        b=insereBola(b,raio,&vel,);
        velocidade=0;
        raio=0;
        n_bolas--;

    }
    return 0;
}
