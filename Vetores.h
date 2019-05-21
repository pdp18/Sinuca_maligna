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

void multiplicaVetorf(Vetorf* vet, float escalar);

float norma(Vetorf* u);

float  produto_escalar(Vetorf* A, Vetorf* B);



