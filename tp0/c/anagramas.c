/* ******************************************************************
        anagramas.c
    Author: Pedro Mendes

    >> Leitura, manipulacao e ordenacao das strings
    TP0 - Anagramas (Manipulacao de Strings)
    Data: Setembro/2015
****************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "anagramas.h"

#define TRUE    1
#define FALSE   0
#define MAX     999999 //50000000 // 50 chars por palavra * 10^6 palavras

// compara o tamanho de 2 palavras (strings) e retorna TRUE (1) caso verdadeiro
int compara_tamanho (char *p1, char *p2)
{
    if ( strlen(p1) == strlen(p2) )
        return TRUE;
    else
        return FALSE;
}

int compara_tamanho_palavra (TipoPalavra *p1, TipoPalavra *p2)
{
    if ( p1->tamanho == p2->tamanho )
        return TRUE;
    else
        return FALSE;
}

void imprimir_anagramas ()
{
    //
}

/* qsort struct comparision function (TipoPalavra p.plv)
fonte: http://www.anyexample.com/programming/c/qsort__sorting_array_of_strings__integers_and_structs.xml
ou http://pastie.org/783004 ou http://terminaldeinformacao.com/2013/05/10/ordenando-vetores-usando-linguagem-c/
*/
int compara_string(const void *a, const void *b)
{
    TipoPalavra *ia = (TipoPalavra *)a;
    TipoPalavra *ib = (TipoPalavra *)b;

    return strcmp(ia->plv, ib->plv);
}

void ordena_string (TipoLista *lista)
{
    //size_t lista_len = sizeof(lista) / sizeof (TipoCelula);

}

// qsort struct comparision function (chars *c)
int compara_chars_vetor(const void *a, const void *b)
{
    char *ia = (char *)a;
    char *ib = (char *)b;

    return (*ia > *ib) ;
}

// ordena uma palavra (string) de maneira crescente (a-z) - OK
void ordena_palavra_vetor (char *palavra)
{
    qsort (palavra, strlen(palavra), sizeof(char), compara_chars_vetor );
}

// qsort struct comparision function (TipoPalavra *c)
int compara_chars(const void *a, const void *b)
{
    TipoPalavra *ia = (TipoPalavra *)a;
    TipoPalavra *ib = (TipoPalavra *)b;

    return (*ia->plv > *ib->plv) ;
}

// ordena uma palavra (string) de maneira crescente (a-z) - ERRO
void ordena_palavra (TipoPalavra *palavra)
{
	qsort (palavra->plv, palavra->tamanho, sizeof(TipoPalavra), compara_chars );
}

void busca_anagramas ()
{
/*    //int i;

    // ordena cada palavra. Assim, se as palavras forem iguais, significa que sao anagramas
    // params qsort (lista_palavras, qtde_palavras, tamanho_palavras, funcao_compare)
    qsort(ataques, numAtaques, sizeof(TipoAtaque), compare );*/
}

void le_linha (TipoLista *lista)
{
    char linha[MAX + 1]; // tamanho maximo
    char *token;
    TipoPalavra pToken;
    const char delim[] = " \n"; // delimitadores: espaco (" ") e quebra de linha (\n)
    int i = 0; // contador para a Chave de cada palavra

    // le a linha da entrada padrao (stdin) e armazena em 'linha'
    fgets(linha, MAX, stdin);

    // pega o primeiro token
    token = strtok(linha, delim);

    // atualiza as demais informacoes do TipoPalavra: Chave e Tamanho (alocado dinamicamente)
    pToken.Chave = i;
    pToken.tamanho = strlen(token);
    pToken.plv = (char*) malloc( pToken.tamanho * sizeof(char) );

    // copia o conteudo do token para o pToken
    strcpy(pToken.plv , token);

    // insere palavra na lista
    Insere(pToken, lista);

    // percorre os tokens restantes
    while( token != NULL )
    {
        i++; // incrementa o contador para as Chaves

        lista->qtde_elementos++; // incrementa o contador de palavras na lista

        // atualiza as demais informacoes do TipoPalavra: Chave e Tamanho (alocado dinamicamente)
        pToken.Chave = i;
        pToken.tamanho = strlen(token);
        pToken.plv = (char*) malloc( pToken.tamanho * sizeof(char) );

        // copia o conteudo do token para o pToken
        strcpy( pToken.plv , token);

        //insere palavra na lista
        Insere(pToken, lista);

        // processa o proximo token
        token = strtok(NULL, delim);
    }
}

char ** ConverteLista(TipoLista * l)
{

    char **lista = (char**) malloc( l->qtde_elementos * sizeof(char*));

    int i = 0;
    TipoApontador Aux;
    Aux = l -> Primeiro -> Prox;

    while (Aux != NULL)
    {
        
        lista[i] = (char *) malloc(50 * sizeof(char));
        strcpy(lista[i],Aux->Item.plv);        
        Aux = Aux -> Prox;
        i++;
    }

    return lista;

}


void imprime_vetor_palavras(char ** vp, int t)
{
    int j = 0;
    for(j = 0; j <= t ; j++){
        printf("Vetor[%d] - %s\n", j, vp[j]);            
    }

}
