#include "Bola.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Insere sempre no início */
Bola* insereBola(Bola* b, float raio, Vetorf* pos, Vetorf* vel)
{
    Bola* novo = (Bola*) malloc(sizeof(Bola));
    novo->raio = raio;
    copiaVetorf(&(novo->pos), pos);
    copiaVetorf(&(novo->vel), vel);
    novo->prox = b;

    return novo;
}

void limpaBolas(Bola* b)
{
    Bola* aux = b;

    while(b != NULL)
    {
        b = b->prox;
        free(aux);
        aux = b;
    }
}

Vetorf posicaoAleatoria(int raio, Vetori* limitex, Vetori* limitey)
{
    Vetorf novo;

    srand(time(NULL));

    novo.x = rand()%(limitex->y - 2*raio + 1) + raio + limitex->x; /* Posiciona aleatoriamente as coordenadas */
    novo.y = rand()%(limitey->y - 2*raio + 1) + raio + limitey->x; /*       x e y dentro do tabuleiro         */

    return novo;
}

void colisaoParede(Bola* b, Vetori* limhor, Vetori* limver)
{
    /* limhor = bordas horizontais */
    /* limver = bordas verticais */

    if ( (b->pos.x - b->raio) <= limhor->x ) //Se bate na esquerda
    {
        b->pos.x = (limhor->x + b->raio);
        b->vel.x *= -1;
    }

    else if ( (b->pos.x + b->raio) >= limhor->y ) //Se bate na direita
    {
        b->pos.x = (limhor->y - b->raio);
        b->vel.x *= -1;
    }

    if ( (b->pos.y - b->raio) <= limver->x ) //Se bate em baixo
    {
        b->pos.y = (limver->x + b->raio);
        b->vel.y *= -1;
    }

    else if ( (b->pos.y + b->raio) >= limver->y ) //Se bate em cima
    {
        b->pos.y = (limver->y - b->raio);
        b->vel.y *= -1;
    }
}


void bola_com_bola(Bola* A,Bola* B)
{
    Vetorf eixo,proje_a,proje_b;
    float distancia_centro =0,norma_vetorial;

    distancia_centro=(A->pos.x-B->pos.x)*(A->pos.x-B->pos.x)+(A->pos.y-B->pos.y)*(A->pos.y-B->pos.y);
    eixo.x= A->pos.x - B->pos.x;
    eixo.y= A->pos.y - B->pos.y;
    norma_vetorial= eixo.x*eixo.x + eixo.y*eixo.y;

    if(sqrt(distancia_centro) <=  A->raio*2)
    {
        proje_a.x=((((A->vel.x)*eixo.x)+(A->vel.y*eixo.y))*eixo.x)/norma_vetorial;
        proje_b.x=(((B->vel.x*eixo.x)+(B->vel.y*eixo.y))*eixo.x)/norma_vetorial;
        proje_a.y=(((A->vel.x*eixo.x)+(A->vel.y*eixo.y))*eixo.y)/norma_vetorial;
        proje_b.y=(((B->vel.x*eixo.x)+(B->vel.y*eixo.y))*eixo.y)/norma_vetorial;
        A->vel.x-=(proje_a.x-proje_b.x);
        B->vel.x-=(proje_b.x-proje_a.x);
        A->vel.y-=(proje_a.y-proje_b.y);

        B->vel.y-=(proje_b.y-proje_a.y);

    }

    ///


}
