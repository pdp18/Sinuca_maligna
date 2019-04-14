#pragma once

typedef struct
{
  float x;
  float y;
}Vetorf;

typedef struct
{
  int x;
  int y;
}Vetori;

void copiaVetorf(Vetorf* copia, Vetorf* original);

void somaVetorf(Vetorf* soma, Vetorf* acrescimo);

float norma(Vetorf* u, Vetorf* v);
