/* ******************************************************************
        anagramas.h
    Author: Pedro Mendes

    >> Leitura, manipulacao e ordenacao das strings
    TP0 - Anagramas (Manipulacao de Strings)
    Data: Setembro/2015
****************************************************************** */

// le uma linha da entrada padrao (stdin) e armazena as palavras na lista
void le_linha (TipoLista *lista);

// dado uma lista encadeada do TipoLista, retorna um Vetor de Strings
char ** ConverteLista(TipoLista *Lista);

// qsort struct comparision function (chars *c)
int compara_chars_vetor(const void *a, const void *b);

// ordena uma palavra (string) de maneira crescente (a-z)
void ordena_palavra_vetor (char *palavra);

// qsort C-string comparison function (ordem lexografica) //
int cstring_cmp(const void *a, const void *b);

// percorre um vetor de caracteres de tamanho 't' e imprime os elementos
void imprime_vetor_palavras(char ** vp, int t);

// qsort int comparison function //
int int_cmp(const void *a, const void *b);

// recebe um vetor de caracteres de tamanho 't', calcula os anagramas e imprime o resultado decrescentemente
void imprime_anagramas (char ** vp, int t);

// funcao principal que recebe uma lista de palavras e chama funcoes auxiliares para calcular e imprimir o resultado
void busca_anagramas (TipoLista *lista_palavras);
