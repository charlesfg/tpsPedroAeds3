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
#define MAX     50000000 // 50 chars por palavra * 10^6 palavras

void le_linha (TipoLista *lista)
{
    char *linha =  (char*) malloc((MAX+1) * sizeof(char)); // tamanho maximo
    char *token;
    TipoPalavra pToken;
    const char delim[] = " \n"; // delimitadores: espaco (" ") e quebra de linha (\n)
    int i = 0; // contador para a Chave de cada palavra

    // le a linha da entrada padrao (stdin) e armazena em 'linha'
    fgets(linha, MAX, stdin);

    // pega o primeiro token
    token = strtok(linha, delim);

    // percorre enquanto ainda houver tokens
    while( token != NULL )
    {
        i++; // incrementa o contador para as Chaves

        // atualiza as demais informacoes do TipoPalavra: Chave e Tamanho (alocado dinamicamente)
        pToken.Chave = i;
        pToken.tamanho = strlen(token);
        pToken.plv = (char*) malloc( pToken.tamanho + 1 * sizeof(char) );

        // copia o conteudo do token para o pToken
        strcpy( pToken.plv , token);

        //insere palavra na lista
        Insere(pToken, lista);

        // processa o proximo token
        token = strtok(NULL, delim);
    }
}

char ** ConverteLista(TipoLista *l)
{
    // aloca memoria dinamica para um vetor de caracteres
    char **lista = (char**) malloc( l->qtde_elementos * sizeof(char*));

    int i = 0;
    TipoApontador Aux;
    Aux = l->Primeiro->Prox;

    // percorre os elementos da lista atraves do apontador Aux
    while (Aux != NULL)
    {
        lista[i] = (char *) malloc( strlen(Aux->Item.plv) + 1 * sizeof(char)); // cada elemento do vetor eh uma string de ate 50 chars
        strcpy(lista[i],Aux->Item.plv);

        Aux = Aux -> Prox;
        i++;
    }

    return lista;
}

// qsort struct comparision function (chars *c)
int compara_chars_vetor(const void *a, const void *b)
{
    char *ia = (char *)a;
    char *ib = (char *)b;

    return (*ia > *ib) ;
}

// ordena uma palavra (string) de maneira crescente (a-z)
void ordena_palavra_vetor (char *palavra)
{
    qsort (palavra, strlen(palavra), sizeof(char), compara_chars_vetor );
}

// qsort C-string comparison function (ordem lexografica) //
int cstring_cmp(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;

    return strcmp(*ia, *ib); // negativo se (a < b), ZERO se iguais, positivo se (a > b)
}

void imprime_vetor_palavras(char ** vp, int t)
{
    int j = 0;
    for(j = 0; j < t ; j++)
    {
        printf("Vetor[%d] - %s\n", j, vp[j]);
    }
}

// qsort int comparison function //
int int_cmp(const void *a, const void *b)
{
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;

    // Como queremos ordem decrescente, invertemos a ordem
    return *ib - *ia; // negativo se (b < a) e positivo se (b > a)
}

void imprime_anagramas (char ** vp, int t)
{
    int num_anagramas = 1; // variavel que armazenara o número de anagramas de cada grupo, ja inclui a primeira palavra
    int *grupos_anagramas = calloc( t , sizeof(int) ); // vetor para armazenar as qtdes de cada grupo de anagramas

    int i, j = 0;

    // percorre o vetor exceto a ultima posicao, para nao correr o risco de sair do vetor
    for (i = 0; i < t-1 ; i++)
    {
        if ( !strcmp(vp[i], vp[i+1]) )
        {
            num_anagramas++; // incrementa o contador se as palavras forem iguais
        }
        else
            {
                grupos_anagramas[j] = num_anagramas;
                j++;
                num_anagramas = 1; // reseta o contador para o proximo grupo
            }
    }
    grupos_anagramas[j] = num_anagramas; // para o ultimo elemento

    // ordena o vetor da qtde de anagramas em cada grupo, de maneira decrescente
    qsort(grupos_anagramas, t, sizeof(int), int_cmp );

    // imprime o grupo ordenado, se ele existir (contador >= 1)
    for (j = 0; j < t ; j++)
    {
        // grupo atual existe e o seguinte tambem
        if (grupos_anagramas[j] != 0 && grupos_anagramas[j+1] != 0)
        {
            fprintf(stdout, "%d ", grupos_anagramas[j]);
        }

        // grupo atual existe mas o seguinte NAO
        else if (grupos_anagramas[j] != 0 && grupos_anagramas[j+1] == 0)
            {
                fprintf(stdout, "%d", grupos_anagramas[j]);
            }

            // grupo atual NAO existe e NEM o seguinte
            else if (grupos_anagramas[j] == 0 && grupos_anagramas[j+1] == 0)
                {
                    break; // encerra o loop, pois os proximos elementos serao ZEROS (vetor ordenado decrescentemente)
                }
    }
}

void busca_anagramas (TipoLista *lista_palavras)
{
    // a lista de palavras do TipoLista sera convertido num vetor dinamico de strings
    char ** vetor_palavras = ConverteLista(lista_palavras);

    int vp_tamanho = lista_palavras->qtde_elementos; // tamanho do vetor de palavras

    // ordena as palavras no vetor
    int j = 0;
    for(j = 0; j < vp_tamanho ; j++)
    {
        ordena_palavra_vetor( vetor_palavras[j] );
    }

    // ordena lista de palavras
    qsort( vetor_palavras, vp_tamanho, sizeof(char *), cstring_cmp);

    // chama a funcao que imprimira o resultado
    imprime_anagramas(vetor_palavras, vp_tamanho);
}
