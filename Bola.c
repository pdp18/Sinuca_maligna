#include "Bola.h"

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

