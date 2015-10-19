/* ******************************************************************
        grafo.h
    Author: Pedro Mendes

    >> TAD Grafo
    TP1 - The City is on Fire! (Grafos)
    Data: Outubro/2015
****************************************************************** */

#ifndef _GRAFOH_
#define _GRAFOH_

#include <stdio.h>
#include <stdlib.h>

#define MAX         100

typedef int TipoValorVertice;

typedef int TipoPeso; // mudar pra FLOAT!! e corrigir as referencias

typedef struct TipoGrafo {
  TipoPeso **Mat;// era TipoPeso Mat[MAX + 1][MAX + 1];
  int  NumVertices;
  int  NumArestas;
} TipoGrafo;

typedef TipoValorVertice TipoApontador;
typedef int TipoIndice;
typedef struct TipoItem {
  TipoPeso Chave;
} TipoItem;

typedef TipoItem TipoVetor[MAX + 1];

void FGVazio(TipoGrafo *Grafo);

void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso,
          TipoGrafo *Grafo);

void PreencheGrafo(TipoGrafo *Grafo);

short  ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2,
            TipoGrafo *Grafo);

//-- Operadores para obter a lista de adjacentes --//

short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo);
TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo);

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo,
         TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox,
         short *FimListaAdj);

void ImprimeGrafo(TipoGrafo *Grafo);

void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *A, TipoPeso *P,
            TipoValorVertice *Pos);

void Constroi(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos);

TipoItem RetiraMinInd(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos);

void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *A,
             TipoPeso *P,  TipoValorVertice *Pos);

void Dijkstra(TipoGrafo *Grafo, TipoValorVertice *Raiz);

void LiberaGrafo(TipoGrafo *Grafo);

#endif
