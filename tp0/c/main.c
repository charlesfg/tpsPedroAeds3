#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

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

int compara_tamanho_string (TipoPalavra *p1, TipoPalavra *p2)
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

void ordena_palavra (char *palavra, int *tam)
{
    //
}

void busca_anagramas ()
{
    //int i;

    // ordena cada palavra. Assim, se as palavras forem iguais, significa que sao anagramas
    // params qsort (lista_palavras, qtde_palavras, tamanho_palavras, funcao_compare)
    //qsort(ataques, numAtaques, sizeof(TipoAtaque), compare );
}

void le_linha (TipoLista *lista)
{
    char linha[MAX + 1]; // tamanho maximo
    char *token; 

    TipoPalavra pToken;
    
    const char delim[] = " ";
    
    int i = 0; // contador para a Chave de cada palavra

    // le a linha da entrada padrao (stdin) e armazena em 'linha'
    fgets(linha, MAX, stdin);

    // pega o primeiro token
    token = strtok(linha, delim);

    // imprime a palavra lida
    fprintf(stdout, " %s\n", token );

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

        // imprime a palavra lida
        fprintf(stdout, " %s\n", token );

        // atualiza as demais informacoes do TipoPalavra: Chave e Tamanho (alocado dinamicamente)
        pToken.Chave = i;
        pToken.tamanho = strlen(token);
        pToken.plv = (char*) malloc( pToken.tamanho * sizeof(char) );

        // copia o conteudo do token para o pToken
        strcpy( pToken.plv , token);

        // imprime a palavra copiada
        fprintf(stdout, " %s\n", pToken.plv );

        //insere palavra na lista
        Insere(pToken, lista);

        // processa o proximo token
        token = strtok(NULL, delim);
    }
}

int main()
{
    int i, num_listas = 0; // 1 <= n <= 10
    TipoLista *lista_palavras;
    FLVazia(lista_palavras);

    // le da entrada padrao (stdin) a quantidade de listas de palavras
    fscanf(stdin, "%d", &num_listas);

    // processa o programa para cada lista
    for (i = 0; i < 2; i++)
    {
        fprintf(stdout, "Lista n: %d\n", i+1); // contador de referencia para as listas

        le_linha(lista_palavras); // le a linha e insere as palavras na lista

        // busca_anagramas(); // chama a funcao principal

        FLVazia(lista_palavras); //

    }

    free(lista_palavras); // ERRO: segfault. PQ?

    return 0;
}
