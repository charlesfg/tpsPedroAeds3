#include <stdlib.h>
#include <stdio.h>

/* ========================================================================= */

typedef int TipoChave;

typedef struct {
    int Chave;
    char *plv;
    int tamanho;
} TipoPalavra; // antigo TipoItem

//typedef struct TipoItem TipoPalavra;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoPalavra Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================= */

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

void Insere(TipoPalavra x, TipoLista *Lista);

void Retira(TipoApontador p, TipoLista *Lista, TipoPalavra *Item);

void Imprime(TipoLista Lista);
