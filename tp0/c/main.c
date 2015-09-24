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

/* qsort C-string comparison function */ 
int cstring_cmp(const void *a, const void *b) 
{ 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
    /* strcmp functions works exactly as expected from
    comparison function */ 
} 

/* qsort int comparison function */ 
int int_cmp(const void *a, const void *b) 
{ 
    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    // Como queremos decrescente, invertemos a ordem
    return *ib - *ia; 
    /* integer comparison: returns negative if b > a 
    and positive if a > b */ 
} 

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

        // Aqui só usamos lista encadeada para evitar alocação máxima 10^6 do pior caso
        le_linha(lista_palavras); // le a linha e insere as palavras na lista

        char ** vetor_palavras = ConverteLista(lista_palavras);
        // Tamanho do vetor palavras
        int vp_tamanho = lista_palavras->qtde_elementos;

        fprintf(stdout, "qtde palavras da lista: %d\n",lista_palavras->qtde_elementos);

        Imprime(lista_palavras);

printf("\n");
        imprime_vetor_palavras(vetor_palavras,vp_tamanho);
        
        // Ordena Palavras no Vetor
        int j = 0;
        for(j = 0; j <= vp_tamanho ; j++){
            ordena_palavra_vetor(vetor_palavras[j]);
        }

        imprime_vetor_palavras(vetor_palavras,vp_tamanho);
        printf("\n");

        // Ordena Lista 
        qsort(vetor_palavras,vp_tamanho+1,sizeof(char *),cstring_cmp);

        imprime_vetor_palavras(vetor_palavras,vp_tamanho);



        //busca_anagramas(); // chama a funcao principal

        //free(lista_palavras); // ERRO: segfault. PQ?

    }

    return 0;
}
