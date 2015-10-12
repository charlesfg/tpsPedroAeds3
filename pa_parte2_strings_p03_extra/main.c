/* ************************************************************************************************
        PRAZO: QUARTA, 14-10-2015 as 23h55

URI Online Judge | 1519
Abreviações

Por Cristhian Bonilha, UTFPR Brazil
Timelimit: 1

Blogs são muito populares hoje em dia, e há inclusive ferramentas que te permitem manter o seu
blog sem que você pague nada por isso. Rafael resolveu então criar um blog, onde irá arquivar todas
as suas experiências diárias de sua vida agitada.

Por mais que estas ferramentas sejam gratuitas, há porém um limite de caracteres que se pode
escrever por dia, e Rafael está preocupado que essa limitação o irá impedir de contar suas melhores
experiências. Decidiu então usar um sistema de abreviação de palavras em seus posts.

O sistema de abreviações funciona da seguinte maneira: para cada letra, é possível escolher uma
palavra que inicia com tal letra e que aparece no post. Uma vez escolhida a palavra, sempre que ela
aparecer no post, ela será substituída por sua letra inicial e um ponto, diminuindo assim o número de
caracteres impressos na tela.

Por exemplo, na frase: “hoje eu visitei meus pais”, podemos escolher a palavra “visitei” para
representar a letra 'v', e a frase ficará assim: “hoje eu v. meus pais”, economizando assim cinco
caracteres. Uma mesma palavra pode aparecer mais de uma vez no texto, e será abreviada todas as
vezes. Note que, se após uma abreviação o número de caracteres não diminuir, ela não deve ser
usada, tal como no caso da palavra “eu” acima.

Rafael precisa que seu post tenha o menor número de caracteres possíveis, e por isso pediu a sua
ajuda. Para cada letra escolha uma palavra, de modo que ao serem aplicadas todas as abreviações, o
texto contenha o menor número de caracteres possíveis.

--------
Entrada
--------

Haverá diversos casos de teste. Cada caso de teste é composto de uma linha, contendo uma frase de
até 104 caracteres. A frase é composta de palavras e espaços em branco, e cada palavra é composta de
letras minúsculas ('a'‐'z'), e contém entre 1 e 30 caracteres cada.
O último caso de teste é indicado quando a linha dada conter apenas um “.”, o qual não deverá ser
processado.

Exemplo de Entrada

hoje eu visitei meus pais
tive  que  lavar  meu  cachorro  pois  ele estava fedendo
.

------
Saída
------

Para cada caso de teste, imprima uma linha contendo a frase já com as abreviações escolhidas e
aplicadas.
Em seguida, imprima um inteiro N, indicando o número de palavras em que foram escolhidas uma
letra para a abreviação no texto. Nas próximas N linhas, imprima o seguinte padrão “C. = P”, onde C
é a letra inicial e P é a palavra escolhida para tal letra. As linhas devem ser impressas em ordem
crescente da letra inicial.

Exemplo de Saída

h. eu v. m. p.
4
h. = hoje
m. = meus
p. = pais
v. = visitei
t. q. l. m. c. p. ele e. f.
8
c. = cachorro
e. = estava
f. = fedendo
l. = lavar
m. = meu
p. = pois
q. = que
t. = tive

************************************************************************************************ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define MAX     124

// funcao que recebe uma letra minuscula a-z e retorna a posicao dela num vetor 0-25
int pos_char (char c)
{
    // ascii table (http://www.ascii-code.com/) -> 'a' = 97 ... 'z' = 122
    // valores de retorno: 'a' = 97 - 97 = 0 ... 'z' = 122 - 97 = 25
    return (c - 97);
}

void imprime_resultado_ordenado(char ** plvs_abrevs)
{
    //
}

void abrevia_frase (char *frs, int tam)
{
    fprintf(stdout, "\n frase: %s - tam: %d", frs, tam );

    char letras[] = "abcdefghijklmnopqrstuvwxyz", frase_final[tam+1];
    int *letras_escolhidas = calloc(26, sizeof(int) ); // valores: 0 nao escolhido, 1 escolhido ... indices: a = 0, b = 1, ... , z = 25
    int qtde_abreviacoes = 0;

    char **plvs_abreviadas;

    char *token;
    const char delim[] = " "; // delimitadores: espaco (" ") e quebra de linha (\n)
    char c_atual;
    int i_atual = 0;
    int j_frs_final = 0;

    // pega o primeiro token
    token = strtok(frs, delim);

    // percorre enquanto ainda houver tokens
    while( token != NULL )
    {
        // a abreviacao eh constituida de uma letra e um ponto final, portanto 2 chars.
        // a palavra atual (token) soh sera abreviada se tiver um tamanho maior que 2 chars.
        if( strlen(token) > 2 )
        {
            c_atual = token[0];
            i_atual = pos_char(c_atual);

            // teste se alguma palavra com a primeira letra do token ja foi abreviada
            if(letras_escolhidas[i_atual] == 1)
            {
                // --> precisa olhar se tem outro maior, que economizara mais chars
                continue;
            }

            // a palavra atual sera abreviada
            else
                {
                    // teste somente para nao exceder o limite do vetor
                    if (j_frs_final < tam)
                    {
                        frase_final[j_frs_final] = c_atual; // insere a primeira letra na posicao corrente
                        frase_final[j_frs_final+1] = '.';   // insere um ponto
                        frase_final[j_frs_final+2] = ' ';   // insere um espaco
                        j_frs_final += 3;                   // incrementa o contador

                        // insere 'token' em 'plvs_abreviadas'

                        qtde_abreviacoes++;                 // incrementa a quantidade de palavras abreviadas
                    }
                }
        }

        // insere a palavra atual (token), com tamanho menor ou igual a 2 chars, na frase final
        else
            {
                // teste somente para nao exceder o limite do vetor
                if (j_frs_final < tam)
                {
                    // percorre os chars do token copiando um a um para o vetor da frase final
                    int cont;
                    for (cont = 0; cont < strlen(token); cont++)
                    {
                        frase_final[j_frs_final] = token[cont];
                        j_frs_final++;
                    }

                    frase_final[j_frs_final] = ' ';  // insere um espaco
                    j_frs_final++;                   // incrementa o contador
                }
            }

        // processa o proximo token
        token = strtok(NULL, delim);
    }

    // imprime a frase final, abreviada
    fprintf(stdout, "\n nova frase: %s - tam: %d", frase_final, (int)strlen(frase_final) );

    // imprime a quantidade de abreviacoes
    fprintf(stdout, "\n qtde abreviacoes: %d", qtde_abreviacoes);

    // ordena e imprime as palavras ordenadas
    imprime_resultado_ordenado(plvs_abreviadas);
}

int main()
{
    char frase[MAX+1]; // max 104 chars na frase
    char cond_terminacao[] = ".\n" ; // condicao de terminacao da leitura

    while ( TRUE )
    {
        fgets(frase, MAX, stdin); // le uma nova string da entrada padrao

        // interrompe o loop caso a frase lida seja igual a condicacao de terminacao: um ponto final ('.')
        if ( !strcmp(frase , cond_terminacao ) )
            break;

        // realiza a execucao normal do programa
        else
        {
            abrevia_frase(frase, (int)strlen(frase)-1 ); // funcao principal que calcula as abreviacoes possiveis na frase

            fprintf(stdout, "\n"); // imprime uma quebra de linha entre os resultados
        }
    }

    return 0;
}
