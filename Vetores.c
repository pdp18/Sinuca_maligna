#include "Vetores.h"

void copiaVetorf(Vetorf* copia, Vetorf* original)
{
  copia->x = original->x;
  copia->y = original->y;
}

void somaVetorf(Vetorf* soma, Vetorf* acrescimo)
{
    soma->x += acrescimo->x;
    soma->y += acrescimo->y;
}

float norma(Vetorf* u, Vetorf* v)
{
    return ( sqrt( pow((u->x - v->x), 2) + pow((u->y - v->y), 2) ) );
}

