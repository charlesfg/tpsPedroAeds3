/* ******************************************************************
        anagramas.h
    Author: Pedro Mendes

    >> Leitura, manipulacao e ordenacao das strings
    TP0 - Anagramas (Manipulacao de Strings)
    Data: Setembro/2015
****************************************************************** */

// compara o tamanho de 2 palavras (strings) e retorna TRUE (1) caso verdadeiro
int compara_tamanho (char *p1, char *p2);

int compara_tamanho_palavra (TipoPalavra *p1, TipoPalavra *p2);

void imprimir_anagramas ();

/* qsort struct comparision function (TipoPalavra p.plv)
fonte: http://www.anyexample.com/programming/c/qsort__sorting_array_of_strings__integers_and_structs.xml
ou http://pastie.org/783004 ou http://terminaldeinformacao.com/2013/05/10/ordenando-vetores-usando-linguagem-c/
*/
int compara_string(const void *a, const void *b);

void ordena_string (TipoLista *lista);

// qsort struct comparision function (chars *c)
int compara_chars_vetor(const void *a, const void *b);

// ordena uma palavra (string) de maneira crescente (a-z) - OK
void ordena_palavra_vetor (char *palavra);

// qsort struct comparision function (TipoPalavra *c)
int compara_chars(const void *a, const void *b);

// ordena uma palavra (string) de maneira crescente (a-z) - ERRO
void ordena_palavra (TipoPalavra *palavra);

void busca_anagramas ();

void le_linha (TipoLista *lista);

// Dado uma lista encadeada do TipoLista, retorna um Vetor de Strings
char ** ConverteLista(TipoLista *Lista);

void imprime_vetor_palavras(char ** vp, int t);
