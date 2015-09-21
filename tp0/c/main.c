#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define TRUE    1
#define FALSE   0
#define QUEBRA_DE_LINHA "\n"

/*
typedef struct {
    char *strg;
    int tamanho;
} TipoString;
*/

// compara o tamanho de 2 palavras (strings) e retorna TRUE (1) caso verdadeiro
int compara_tamanho (char *p1, char *p2)
{
    if ( strlen(p1) == strlen(p2) )
        return TRUE;
    else
        return FALSE;
}

int compara_tamanho_string (TipoString *p1, TipoString *p2)
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
    //int i;

    //for
}

void busca_anagramas ()
{
    //int i;

    // ordena cada palavra. Assim, se as palavras forem iguais, significa que sao anagramas
    // params qsort (lista_palavras, qtde_palavras, tamanho_palavras, funcao_compare)
    //qsort(ataques, numAtaques, sizeof(TipoAtaque), compare );
}

void insere_palavra_na_lista (char *lista, char *palavra, int *tam)
{
    int i = 0;

    do
    {
        lista[i] = palavra[i]; // copia cada char para a palavra ate que encontre o final
        i++; // incrementa o contador e avanca para a proxima posicao do buffer

    } while (palavra[i] != '\0');
}

void le_palavra (char *palavra)
{
    char c = 'a', buffer_palavra[50]; // tamanho maximo da palavra: 50 chars
    int i = 0, tam_palavra;


    fscanf(stdin, "%c", &c); // le o primeiro char da palavra

    while (c != ' ')
    {
        buffer_palavra[i] = c; // copia o char lido para o buffer


        fscanf(stdin, "%c", &c); // le o proximo char da palavra

        if (c = ' ')
        {
            buffer_palavra[i] = '\0'; // insere o char de fim da palavra
        }
        else
            i++; // incrementa o contador e avanca para a proxima posicao do buffer
    }

    tam_palavra = strlen(buffer_palavra) + 1; // tamanho da palavra = qtde chars + char '\0' de fim de string
    palavra = (char*) malloc(tam_palavra * sizeof(char));

    i = 0; // reinicia o contador
    do
    {
        palavra[i] = buffer_palavra[i]; // copia cada char para a palavra ate que encontre o final
        i++; // incrementa o contador e avanca para a proxima posicao do buffer

    } while (buffer_palavra[i] != '\0');

}

void le_linha (TipoString *lista)
{
    /*int i = 0;
    char c, buffer_palavra[50]; // tamanho maximo da palavra: 50 chars
    TipoPalavra p;
    //int tam_palavra;

    fscanf(stdin, "%s", &buffer_palavra); // le a primeira palavra da lista
    fprintf(stdout, "palavra: %s - tamanho: %d\n", buffer_palavra, strlen(buffer_palavra)); // imprime a palavra lida

    fscanf(stdin, "%c", &c); // le o prox char
    while (c != '\n')
    {
        if (c == ' ')
            {
                fprintf(stdout,"\n Leu um ESPACO.\n");
                p->tamanho = strlen(buffer_palavra) + 1; // tamanho da palavra = qtde chars + char '\0' de fim de string
                p->palavra = (char*) malloc(p->tamanho * sizeof(char));
                strcpy(lista->palavra[i],buffer_palavra); // copia o conteudo do BUFFER pra PALAVRA
                i++;
                // insere palavra na lista
                continue;
            }

        else if (c == '\n')
            {
                fprintf(stdout,"\n Leu um BARRA N - dentro do while.\n");
                break;
            }

        fscanf(stdin, "%c", &c); // le o prox char
    }
    fprintf(stdout,"\n Leu um BARRA N - fora do while.\n");*/

}

int main()
{
    int i, num_listas = 0; // 1 <= n <= 10
    char *palavra, buffer_palavra[50], lista_palavras[2];
    //TipoPalavra lista_palavras[2];

    char txt[] = {"teste"};
    fprintf(stdout, "palavra: %s - tamanho: %d\n", txt, strlen(txt)); // imprime a palavra lida

    fscanf(stdin, "%d", &num_listas);

    //fscanf(stdin, "%s", &buffer_palavra); // le a primeira palavra da lista
    //le_palavra(buffer_palavra);
    //fprintf(stdout, "palavra: %s - tamanho: %d\n", buffer_palavra, strlen(buffer_palavra)); // imprime a palavra lida

    //le_palavra(buffer_palavra);
    //fprintf(stdout, "palavra: %s - tamanho: %d\n", buffer_palavra, strlen(buffer_palavra)); // imprime a palavra lida

    //char quebra_linha = fscanf(stdin, "%c", &quebra_linha);

    //le_palavra(&palavra);
    //fprintf(stdout, "palavra: %s - tamanho: %d\n", palavra, strlen(palavra)); // imprime a palavra lida
    //free(palavra);

    // processa o programa para cada lista
    for (i = 0; i < 2; i++)
    {
        fprintf(stdout, "Lista n: %d\n", i+1); // contador de referencia para as listas

        //le_linha(lista_palavras);
        le_palavra(palavra);
        fprintf(stdout, "palavra: %s - tamanho: %d\n", palavra, strlen(palavra)); // imprime a palavra lida
        lista_palavras[i] = palavra;
        fprintf(stdout, "lista_palavras[i]: %s - tamanho: %d\n", lista_palavras[i], strlen(lista_palavras[i])); // imprime a palavra lida

        /*fscanf(stdin, "%s", &buffer_palavra); // le a primeira palavra da lista

        // continua lendo as palavras da lista ate que seja encontrada uma quebra de linha ('\n')
        while ( !strcmp(buffer_palavra, "\n" ) )
        {
            fprintf(stdout, "palavra: %s - tamanho: %d\n", buffer_palavra, (int)strlen(buffer_palavra)); // imprime a palavra lida

            fscanf(stdin, "%s", &buffer_palavra); // le a proxima palavra
        }*/

    }

    return 0;
}
