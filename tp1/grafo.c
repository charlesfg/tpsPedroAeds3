/* ******************************************************************
        grafo.c
    Author: Pedro Mendes

    >> TAD Grafo
    TP1 - The City is on Fire! (Grafos)
    Data: Outubro/2015
****************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h> // incluir -lm no makefile

#include "grafo.h"

#define FALSE       0
#define TRUE        1
#define MAX         100
#define INFINITO    INT_MAX

TipoApontador Aux;
int  i, NArestas;
short FimListaAdj;
TipoValorVertice V1, V2, Adj;
TipoPeso Peso;
TipoGrafo Grafo;
TipoValorVertice NVertices;
TipoIndice n;   /*Tamanho do heap*/
TipoValorVertice Raiz;

void FGVazio(TipoGrafo *Grafo)
{ int  i;

  // aloca memoria dinamica para as linhas da matriz
  Grafo->Mat = (TipoPeso**) calloc (Grafo->NumVertices, sizeof(TipoPeso*) );

  // aloca memoria dinamica para as colunas da matriz
  for (i = 0; i < Grafo->NumVertices; i++)
    Grafo->Mat[i] = (TipoPeso *) calloc (Grafo->NumVertices, sizeof(TipoPeso) );

}

void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso,
          TipoGrafo *Grafo)

{ Grafo->Mat[*V1][*V2] = *Peso;
}

void PreencheGrafo(TipoGrafo *Grafo)
{
    int num_quarteiroes, num_ruas;      // vertices (0 < Q <= 1000) e arestas (0 < R <= Q*(Q-1)/2 )
    int vs, vc;                         // vertice de saida (origem), vertice de chegada (destino)
    int dmax_bombeiros, num_bombeiros;  // distancia max ate um corpo d bombeiros, qtde de corpos d bombeiros na cidade (0<D<=Q)

    TipoValorVertice V1, V2;               // variaveis auxiliares para ler os vertices
    TipoPeso prob_incend;                  // probabilidade de incendio no trecho (0.00 - 1.00)

    // leitura dos parametros iniciais da entrada padrao
    fscanf(stdin, "%d %d %d %d %d %d", &num_quarteiroes, &num_ruas, &vs, &vc, &dmax_bombeiros, &num_bombeiros);

    // inicializa o novo grafo
    Grafo->NumVertices = num_quarteiroes;
    Grafo->NumArestas = 0;
    FGVazio(Grafo);

    // preenche o grafo
    int i;
    for (i = 0; i < num_ruas; i++)
    {
        fscanf(stdin, "%d %d %d", &V1, &V2, &prob_incend);

        InsereAresta(&V1, &V2, &prob_incend, Grafo); // 2 chamadas: Grafo nao-direcionado
        InsereAresta(&V2, &V1, &prob_incend, Grafo);
        Grafo->NumArestas++;                            // incrementa a qtde de arestas do grafo
    }
}

short  ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2,
            TipoGrafo *Grafo)
{ return (Grafo->Mat[Vertice1][Vertice2] > 0);
}

/*-- Operadores para obter a lista de adjacentes --*/

short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{ TipoApontador Aux = 0;
  short ListaVazia = TRUE;
  while (Aux < Grafo->NumVertices && ListaVazia)
    { if (Grafo->Mat[*Vertice][Aux] > 0)
      ListaVazia = FALSE;
      else
      Aux++;
    }
  return (ListaVazia == TRUE);
}

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{ TipoValorVertice Result;
  TipoApontador Aux = 0;
  short Listavazia = TRUE;
  while (Aux < Grafo->NumVertices && Listavazia)
    { if (Grafo->Mat[*Vertice][Aux] > 0)
      { Result = Aux; Listavazia = FALSE;
      }
      else  Aux++;
    }
  if (Aux == Grafo->NumVertices)
  printf("Erro: Lista adjacencia vazia (PrimeiroListaAdj)\n");
  return Result;
}

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo,
         TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox,
         short *FimListaAdj)
{ // --Retorna Adj apontado por Prox--//
  *Adj = *Prox;
  *Peso = Grafo->Mat[*Vertice][*Prox];
  (*Prox)++;
  while (*Prox < Grafo->NumVertices && Grafo->Mat[*Vertice][*Prox] == 0)
    (*Prox)++;
  if (*Prox == Grafo->NumVertices)  *FimListaAdj = TRUE;
}

void ImprimeGrafo(TipoGrafo *Grafo)

{ int i, j;
  printf("   ");
  for (i = 0; i < Grafo->NumVertices; i++) printf("%3d", i); putchar('\n');
  for (i = 0; i < Grafo->NumVertices; i++)
    { printf("%3d", i);
      for (j = 0; j < Grafo->NumVertices; j++)
        printf("%3d", Grafo->Mat[i][j]);
      putchar('\n');
    }
}

void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *A, TipoPeso *P,
            TipoValorVertice *Pos)

{ TipoIndice i = Esq;  int j;  TipoItem x;
  j = i * 2;  x = A[i];
  while (j <= Dir)
    { if (j < Dir)
      { if (P[A[j].Chave] > P[A[j+1].Chave]) j++;
      }
      if (P[x.Chave] <= P[A[j].Chave])  goto L999;
      A[i] = A[j]; Pos[A[j].Chave] = i;
      i = j;   j = i * 2;
    }
  L999:  A[i] = x;  Pos[x.Chave] = i;
}

void Constroi(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos)

{ TipoIndice Esq;
  Esq = n / 2 + 1;
  while (Esq > 1)
    { Esq--;
      RefazInd(Esq, n, A, P, Pos);
    }
}

TipoItem RetiraMinInd(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos)
{ TipoItem Result;
  if (n < 1)
  { printf("Erro: heap vazio\n");
    return Result;
  }
  Result = A[1];
  A[1] = A[n]; Pos[A[n].Chave] = 1;
  n--;
  RefazInd(1, n, A, P, Pos);
  return Result;
}

void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *A,
             TipoPeso *P,  TipoValorVertice *Pos)
{ TipoItem x;
  if (ChaveNova > P[A[i].Chave])
  { printf("Erro: ChaveNova maior que a chave atual\n");
    return;
  }
  P[A[i].Chave] = ChaveNova;
  while (i > 1 && P[A[i / 2].Chave] > P[A[i].Chave])
    { x = A[i / 2];
      A[i / 2] = A[i];
      Pos[A[i].Chave] = i / 2;
      A[i] = x;
      Pos[x.Chave] = i;
      i /= 2;
    }
}

void Dijkstra(TipoGrafo *Grafo, TipoValorVertice *Raiz)
{ TipoPeso P[MAX + 1];
  TipoValorVertice Pos[MAX + 1];
  long Antecessor[MAX + 1];
  short Itensheap[MAX + 1];
  TipoVetor A;
  TipoValorVertice u, v;
  TipoItem temp;
  for (u = 0; u <= Grafo->NumVertices; u++)
  { /*Constroi o heap com todos os valores igual a INFINITO*/
    Antecessor[u] = -1; P[u] = INFINITO;
    A[u+1].Chave = u;   /*Heap a ser construido*/
    Itensheap[u] = TRUE;  Pos[u] = u + 1;
  }
  n = Grafo->NumVertices;
  P[*(Raiz)] = 0;
  Constroi(A, P, Pos);
  while (n >= 1)
  { /*enquanto heap nao vazio*/
    temp = RetiraMinInd(A, P, Pos);
    u = temp.Chave; Itensheap[u] = FALSE;
    if (!ListaAdjVazia(&u, Grafo))
    { Aux = PrimeiroListaAdj(&u, Grafo); FimListaAdj = FALSE;
      while (!FimListaAdj)
      { ProxAdj(&u, Grafo, &v, &Peso, &Aux, &FimListaAdj);
        if (P[v] > (P[u] + Peso))
        { P[v] = P[u] + Peso; Antecessor[v] = u;
          DiminuiChaveInd(Pos[v], P[v], A, P, Pos);
          printf("Caminho: v[%d] v[%ld] d[%d]",
	         v, Antecessor[v], P[v]);
          scanf("%*[^\n]");
          getchar();
        }
      }
    }
  }
}

void LiberaGrafo(TipoGrafo *Grafo)
{
  int i;

  // libera memoria de cada coluna da matriz
  for (i = 0; i < Grafo->NumVertices; i++)
    free(Grafo->Mat[i]);

  // libera memoria do vetor de linhas da matriz
  free (Grafo->Mat);
}
