#include "Vetores.h"

#include <math.h>

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

/*
float norma(Vetorf* u, Vetorf* v)
{
    return ( sqrt( pow((u->x - v->x), 2) + pow((u->y - v->y), 2) ) );
}*/
float norma(Vetorf* u)
{
    return ( sqrt( pow(u->x, 2) + pow((u->y), 2) ) );
}


float  produto_escalar (Vetorf* A, Vetorf* B)
{
    return ((A->x*B->x)+(A->y*B->y));
}

void multiplicaVetorf(Vetorf* vet, float escalar)
{
    vet->x*=escalar;
    vet->y*=escalar;
}

/*Vetorf projecao(Vetorf eixo, Vetorf projetado)
{
    multiplicaVetorf( &eixo, (produto_escalar(&eixo,projetado)/produto_escalar(&eixo,&eixo)) );
    return(eixo);

}*/
Vetorf projecao(Vetorf eixo, float norma,Vetorf* projetado)
{
    Vetorf novo;

    return(novo);
}
