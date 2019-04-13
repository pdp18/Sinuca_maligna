#pragma once

#include <math.h>

typedef struct
{
  float x;
  float y;
}Vetorf;

void copiaVetorf(Vetorf* copia, Vetorf* original);

void somaVetorf(Vetorf* soma, Vetorf* acrescimo);

float norma(Vetorf* u, Vetorf* v);
