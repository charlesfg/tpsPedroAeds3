/* ******************************************************************
        main.c
    Author: Pedro Mendes

    >> Programa principal
    TP1 - The City is on Fire! (Grafos)
    Data: Outubro/2015
****************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"
#include "incendio.h"

int main()
{
    int i, num_instancias = 0; // 0 < num_instancias <= 100

    fscanf(stdin, "%d", &num_instancias); // le da entrada padrao (stdin) a quantidade de instancias a serem resolvidas

    // processa o programa para cada instancia
    for (i = 0; i < num_instancias; i++)
    {
        TipoGrafo Grafo;                // declaracao de um novo grafo

        PreencheGrafo(&Grafo);          // inicializa e preenche o grafo com os valores da entrada padrao

        ProbabilidadeIncendio(&Grafo);  // funcao principal que calcula a prob de incendio para a instancia

        LiberaGrafo(&Grafo);            // libera a memoria alocada para o grafo

        if (i < num_instancias-1)
            fprintf(stdout, "\n");      // imprime uma quebra de linha ate antes de executar a ultima instancia
    }

    return 0;
}
