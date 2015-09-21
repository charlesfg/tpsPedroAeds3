#include <stdlib.h>
#include <stdio.h>

/* ========================================================================= */

typedef int TipoChave;

typedef struct {
    int Chave;
    char *strg;
    int tamanho;
} TipoItem;

typedef struct TipoItem TipoString;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoString Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================= */

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

void Insere(TipoString x, TipoLista *Lista);

void Retira(TipoApontador p, TipoLista *Lista, TipoString *Item);

void Imprime(TipoLista Lista);
