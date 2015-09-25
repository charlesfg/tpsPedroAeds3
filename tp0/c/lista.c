/* ******************************************************************
        lista.c
    Author: Pedro Mendes

    >> TAD Lista Encadeada
    TP0 - Anagramas (Manipulacao de Strings)
    Data: Setembro/2015
****************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


void FLVazia(TipoLista *Lista)
{
  Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
  Lista -> qtde_elementos = 0;
}

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoPalavra x, TipoLista *Lista)
{ Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
  Lista -> qtde_elementos++;
}

//void Retira(TipoApontador p, TipoLista *Lista, TipoPalavra *Item)
void Retira(TipoApontador p, TipoLista *Lista)
{ /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL)
  { printf(" Erro   Lista vazia ou posicao nao existe\n");
    return;
  }
  q = p -> Prox;
  // *Item = q -> Item;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) Lista -> Ultimo = p;
  free(q);
  Lista -> qtde_elementos--;
}

void Imprime(TipoLista *Lista)
{ TipoApontador Aux;
  Aux = Lista -> Primeiro -> Prox;
  while (Aux != NULL)
    {
      fprintf(stdout, "Chave: %d - Palavra: %s - Tam: %d\n", Aux->Item.Chave, Aux->Item.plv, Aux->Item.tamanho);
      Aux = Aux -> Prox;
    }
}

void LiberaLista(TipoLista *Lista)
{
  TipoApontador Aux;
  Aux = Lista -> Primeiro -> Prox;
  while (Aux != NULL)
    {
      Retira(Aux, Lista); // eliminei o ultimo parametro, TipoItem
      Aux = Aux -> Prox;
    }
  free(Lista);
}
