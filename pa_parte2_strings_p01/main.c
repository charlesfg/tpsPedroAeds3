/* *****************************************************************************************************
URI Online Judge | 1551
Frase Completa

Por Cristhian Bonilha, UTFPR Brazil
Timelimit: 1

Seu professor de português não para de trazer coisas novas para a sala, e hoje não foi diferente.
Existe uma cidade, segundo seu professor, onde as pessoas levam muito a sério a forma como elas
se comunicam. Em especial, quando duas pessoas estão conversando, elas pensam muito nas frases
antes de dizê‐las, de forma a garantir que tal frase seja uma “frase completa”, ou talvez uma “frase
quase completa”.

Considerando o nosso alfabeto de 26 letras, uma frase é dita “completa” quando ela contém todas as
letras do alfabeto contidas nela. De modo semelhante, uma frase é dita “quase completa” se ela não
é completa, porém contém ao menos metade das letras do alfabeto contidas nela. Quando uma frase
não é “completa” e nem “quase completa”, ela é dita “mal elaborada”. Seu professor lhe deu uma
tarefa muito difícil: dadas várias frases trocadas entre vários habitantes da cidade citada,
diga em qual das categorias acima a frase se encaixa.

Entrada

A primeira linha contém um inteiro N, indicando o número de casos de teste a seguir.
Cada caso de teste contém uma linha, contendo letras minúsculas, espaços em branco e/ou vírgulas.
O número de caracteres de cada linha é no mínimo 3 e no máximo 1000, contando com os espaços.

Exemplo de Entrada

2
ola, como voce esta hoje
hoje  fui  na  feira,  e  comprei  banana, melao e abacates


Saída

Para cada caso de teste, imprima uma linha contendo uma das seguintes frases: “frase completa”,
quando a frase é considerada completa; “frase quase completa”, quando a frase não é completa, mas
é considerada quase completa; ou “frase mal elaborada”, quando ela não é completa e nem quase
completa.

Exemplo de Saída

frase mal elaborada
frase quase completa

***************************************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// verifica quais chars do alfabeto estao presentes na frase e retorna a quantidade presente
int verifica_frase (char *fr)
{
    char alfab[] = {"abcdefghijklmnopqrstuvwxyz"};
    int i, j, qtde_chars_lidos = 0;

    // percorre o vetor do alfabeto
    for (j = 0; j < 26; j++)
    {
        i = 0;
        // percorre o texto ate encontrar o caractere especial de fim de string '\0'
        while(fr[i] != '\0')
        {
            if (fr[i] == alfab[j])
            {
                qtde_chars_lidos++;
                break; // nao precisa continuar o loop interno pois ja encontrou o char do alfabeto
            }
            i++;
        }
    }
    return qtde_chars_lidos;
}

// imprime o resultado com base no numero de chars presentes na frase
void imprime_resultado (int n)
{
    if (n == 26)
        fprintf(stdout, "frase completa\n"); // contem todas as letras do alfabeto
    else if (n >= 13 && n < 26)
            fprintf(stdout, "frase quase completa\n"); // contem pelo menos a metade das letras
        else
            fprintf(stdout, "frase mal elaborada\n");
}

int main()
{
    int i, num_casos_teste;
    char frase[1100], c_aux;
    int num_chars_lidos;

    fscanf(stdin, "%d", &num_casos_teste); // le da entrada padrao o numero de casos de teste

    fscanf(stdin, "%c", &c_aux); // le da entrada padrao caractere especial de quebra de linha, '\n'

    for (i = 0; i < num_casos_teste; i++)
    {
        num_chars_lidos = 0; // reseta o contador do numero de caracteres lidos

        fgets(frase, 1100, stdin); // le a frase da entrada padrao

        num_chars_lidos = verifica_frase(frase); // funcao principal que verifica a qtde de caracteres do alfabeto na frase

        imprime_resultado(num_chars_lidos);
    }

    return 0;
}
