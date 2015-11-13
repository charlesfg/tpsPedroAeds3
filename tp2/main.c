/* ******************************************************************
        main.c
    Author: Pedro Mendes

    >> Programa principal
    TP2 - The Force Awakens (Paradigmas)
    Data: Novembro/2015
****************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pd.h"
#include "ag.h"
#include "fb.h"

typedef enum { PD = 1, AG = 2, FB = 3 } TipoParadigma;

void le_paradigma_terminal (TipoParadigma *paradigma, int argc, char *argv[])
{
    fprintf(stdout, "argc = %d\n", argc);
    // le o tipo de paradigma do UNICO parametro inicial
    if (argc == 3)
    {
        //strcpy(paradigma, argv[2]);
        //paradigma = atoi(argv[2]);              // armazena na variavel 'paradigma'
        paradigma = argv[2];              // armazena na variavel 'paradigma'
        //paradigma = (TipoParadigma) argv[2]; // armazena na variavel 'paradigma'
        fprintf(stdout, "Paradigma OK lido: %d\n", paradigma);
    }
    else
    {
        fprintf(stdout, "ERRO no paradigma (%d) informado!\n", paradigma);
        return -1;
    }
}

void chama_paradigma_correto (TipoParadigma p)
{
    switch(p)
    {
        case PD:
            // funPD
            fprintf(stdout, "paradigmaPD: 1\n");
            break;

        case AG:
            // funAG
            fprintf(stdout, "paradigmaAG: 2\n");
            break;

        case FB:
            // funFB
            fprintf(stdout, "paradigmaFB: 3\n");
            break;

        default:
            fprintf(stdout, "ERRO paradigma %d invalido!\n", p);
            break;
    }
}

int main(int argc, char* argv[])
{
    int i, num_instancias = 0;              // 0 < num_instancias <= 100
    int planetas_rota, planetas_a_reconq;   // 0 < planetas_rota <= 500 , 0 < planetas_a_reconq <= 250
    int qtde_distancias;                    // planetas_rota + 1

    TipoParadigma paradigma;
    le_paradigma_terminal(&paradigma, argc, argv);

    fscanf(stdin, "%d", &num_instancias); // le da entrada padrao (stdin) a quantidade de instancias a serem resolvidas

    // processa o programa para cada instancia
    for (i = 0; i < num_instancias; i++)
    {
        fscanf(stdin, "%d %d", &planetas_rota, &planetas_a_reconq); // le da entrada padrao a qtde de planetas na rota e a qtde a reconquistar

        qtde_distancias = planetas_rota + 1; // para N planetas, ha N-1 dists entre eles + 2 dist (INICIAL e FINAL), total N+1

        // vetor que armazenara as distancias
        int *distancias = calloc(qtde_distancias, sizeof(int) );

        int i;
        for(i = 0; i < qtde_distancias; i++)
        {
            fscanf(stdin, "%d", &distancias[i]); // le as distancias e as armazena no vetor
        }

        chama_paradigma_correto(paradigma); // roda o programa conforme o paradigma solicitado inicialmente

        free(distancias);                   // libera a memoria alocada para o vetor de distancias na instancia atual

        if (i < num_instancias-1)
            fprintf(stdout, "\n");          // imprime uma quebra de linha ate antes de executar a ultima instancia
    }

    return 0;
}
