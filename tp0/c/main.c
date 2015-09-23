/* ******************************************************************
        main.c
    Author: Pedro Mendes

    >> Programa principal
    TP0 - Anagramas (Manipulacao de Strings)
    Data: Setembro/2015
****************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "lista.h"
#include "anagramas.h"

int main()
{
    /* ***** TESTE ORDENA UMA PALAVRA (VETOR) - OK ******
    char c[] = "casa";
    fprintf(stdout, "Palavra: %s - Tam: %d\n", c, strlen(c) );
    ordena_palavra_vetor(c);
    fprintf(stdout, "Palavra: %s - Tam: %d\n", c, strlen(c) ); */

    /* ***** TESTE ORDENA UMA PALAVRA (STRUCT) - ERRO SEG FAULT ******
    TipoPalavra *p;
    p->Chave = 0;
    strcpy(p->plv,p); //p->plv = "casa";
    p->tamanho = (int) strlen(p->plv);
    fprintf(stdout, "Chave: %d - Palavra: %s - Tam: %d\n", p->Chave, p->plv, p->tamanho);
    ordena_palavra(p);
    fprintf(stdout, "Chave: %d - Palavra: %s - Tam: %d\n", p->Chave, p->plv, p->tamanho);*/

    // ***** PROGRAMA NORMAL ******
    //struct timeval tempo; // contabilizara o tempo gasto para rodar o programa
    //gettimeofday(&tempo,NULL);
    //srand((unsigned int)tempo.tv_usec);

    int i, num_listas = 0; // 1 <= n <= 10
    char quebra_linha;

    // le da entrada padrao (stdin) a quantidade de listas de palavras
    fscanf(stdin, "%d", &num_listas);

    fscanf(stdin, "%c", &quebra_linha);

    // processa o programa para cada lista
    for (i = 0; i < num_listas; i++)
    {
        fprintf(stdout, "\n  >> Lista # %d\n", i+1); // contador de referencia para as listas

        TipoLista *lista_palavras; // declaracao de uma nova lista de palavras
        FLVazia(lista_palavras); // inicializa a nova lista

        le_linha(lista_palavras); // le a linha e insere as palavras na lista

        fprintf(stdout, "qtde palavras da lista: %d\n",lista_palavras->qtde_elementos);

        Imprime(lista_palavras);

        // busca_anagramas(); // chama a funcao principal

        //free(lista_palavras); // ERRO: segfault. PQ?

    }

    return 0;
}
