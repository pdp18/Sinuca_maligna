#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "Vetores.h"

typedef struct No
{
  float raio;
  Vetorf vel;
  Vetorf pos;

  struct No* prox;
}Bola;

Bola* insereBola(Bola* b, float raio, Vetorf* pos, Vetorf* vel);

void limpaBolas(Bola* b);

//void colisaoParede(Bola* b, );

Vetorf posicaoAleatoria(int raio, Vetori* limitex, Vetori* limitey);
