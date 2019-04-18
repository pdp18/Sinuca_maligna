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

float norma(Vetorf* u, Vetorf* v);

///pair programing
float  produto_escalar(Vetorf* A, Vetorf* B);


Vetorf projecao(Vetorf eixo, Vetorf* projetado);

