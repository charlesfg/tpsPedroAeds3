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
#include <sys/time.h>

#include "lista.h"
#include "anagramas.h"

int main()
{
    int i, num_listas = 0; // 1 <= n <= 10
    char quebra_linha;

    fscanf(stdin, "%d", &num_listas); // le da entrada padrao (stdin) a quantidade de listas de palavras

    fscanf(stdin, "%c", &quebra_linha); // leitura do char de quebra de linha

    // processa o programa para cada lista
    for (i = 0; i < num_listas; i++)
    {
        TipoLista lista_palavras; // declaracao de uma nova lista de palavras
        FLVazia(&lista_palavras); // inicializa a nova lista

        // Aqui só usamos lista encadeada para evitar alocação máxima 10^6 do pior caso
        le_linha(&lista_palavras); // le a linha e insere as palavras na lista

        busca_anagramas(&lista_palavras); // chama a funcao principal

        if (i < num_listas-1)
            fprintf(stdout, "\n"); // imprime uma quebra de linha ate antes de executar a ultima lista
    }

    return 0;
}
