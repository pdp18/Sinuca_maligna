#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  float x;
  float y;
}Vetorf;

typedef struct No
{
  float raio;
  Vetorf vel;
  Vetorf pos;

  struct No* prox;
}Bola;

void copiaVetorf(Vetorf* copia, Vetorf* original)
{
  copia->x = original->x;
  copia->y = original->y;
}

Bola* insereBola(Bola* b, float raio, Vetorf* vel, Vetorf* pos)
{
  if (b == NULL)
  {
    b = (Bola*) malloc(sizeof(Bola));
    b->raio = raio;
    copiaVetorf(&(b->pos), &pos);
    copiaVetorf(&(b->vel), &vel);
    b->prox = NULL;
  }

  else
    b->prox = insereBola(b->prox, raio, vel, pos);

  return b;
}

/* testando commits */
