#include "Bola.h"

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
