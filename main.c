#include <stdio.h>
#include <stdlib.h>
#include "Bola.h"
int main()
{
    int n_bolas,cont=0;
    float raio ;
    Vetorf vel;
    Vetorf pos;
    Bola* b = NULL;
    b = insereBola();
    b = insereBola()
    printf("Qual a quantidade de bolas ? ");
    scanf("%d",&n_bolas);
    printf("Qual o raio da bola N:%d ",cont);
    scanf("%f",&raio);
    printf("Qual o velocidade da bola N:%d ",cont);
    scanf("%f%f",&vel.x,&vel.y);
    while(n_bolas>cont)
    {
        b=insereBola(b,raio,&vel,&pos);
        cont++;
        b=insereBola(b,raio,&vel,);
        velocidade=0;
        raio=0;
        n_bolas--;
    }
    return 0;
}
