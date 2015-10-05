/* ************************************************************************************************
        PRAZO: QUARTA, 07-10-2015 as 23h55

URI Online Judge | 1024
Criptografia

Por Neilor Tonin, URI
Brasil - Timelimit: 1

Solicitaram para que você construisse um programa simples de criptografia. Este programa deve
possibilitar enviar mensagens codificadas sem que alguém consiga lê‐las. O processo é muito simples.
São feitas três passadas em todo o texto.

. Na primeira passada, somente caracteres que sejam letras minúsculas e maiúsculas devem ser
deslocadas 3 posições para a direita, segundo a tabela ASCII: letra 'a' deve virar letra 'd',
letra 'y' deve virar caractere '|' e assim sucessivamente.

. Na segunda passada, a linha deverá ser invertida.

. Na terceira e última passada, todo e qualquer caractere a partir da metade em diante (truncada) devem
ser deslocados uma posição para a esquerda na tabela ASCII. Neste caso, 'b' vira 'a' e 'a' vira '`'.

Por exemplo, se a entrada for “Texto #3”, o primeiro processamento sobre esta entrada deverá
produzir “Wh{wr #3”. O resultado do segundo processamento inverte os caracteres e produz “3#
rw{hW”. Por último, com o deslocamento dos caracteres da metade em diante, o resultado final deve
ser “3# rvzgV”.

-------
Entrada
-------

A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro N
(1 ≤ N ≤ 1*10^4 ), indicando a quantidade de linhas que o problema deve tratar. As N linhas contém cada
uma delas M (1 ≤ M ≤ 1*10^3 ) caracteres.

Exemplo de Entrada

4
Texto #3
abcABC1
vxpdylY .ph
vv.xwfxo.fd

-----
Saída
-----

Para cada entrada, deve‐se apresentar a mensagem criptografada.

Exemplo de Saida

3# rvzgV
1FECedc
ks. \n{frzx
gi.r{hyz­-xx

************************************************************************************************ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void criptografa_frase (char *frs, int tam)
{
    //fprintf(stdout, "\n\n Frase: %s - Tam: %d\n", frs, tam);

    // *** 1a PASSADA ***

    int i;

    // percorre todo o vetor
    for (i = 0; i < tam; i++)
    {
        // verifica se o char passado como parametro eh ALPHABETIC (A-Z, a-z)
        if ( isalpha( frs[i]) )
        {
            frs[i] += 3; // letras deslocadas 3 posicoes pra direita, conforme tabela ASCII ( http://www.ascii-code.com/ )
        }
    }

    // *** 2a PASSADA ***

    char c_aux;

    // percorre a primeira metade do vetor
    for (i = 0; i < tam/2; i++)
    {
        // teste para tratar a diferenca entre vetores com tamanho par e impar (com elem central)
        if (i != (tam-1-i) )
        {
            c_aux = frs[i];
            frs[i] = frs[tam-2-i]; // troca os caracteres de posicoes opostas
            frs[tam-2-i] = c_aux;
        }
    }

    // *** 3a PASSADA ***

    // percorre a segunda metade do vetor
    for (i = (tam-1)/2; i < tam; i++)
    {
        frs[i]--; // char deslocado 1 posicao pra esquerda, conforme tabela ASCII ( http://www.ascii-code.com/ )
    }

    // *** IMPRESSAO DO RESULTADO ***

    // percorre o vetor ate antes do char '\0'
    for (i = 0; i < tam-1; i++)
    {
        fprintf(stdout, "%c", frs[i]); // imprime 1 char
    }
}

int main()
{
    int i, num_casos_teste;
    char frase[1101], bn;

    fscanf(stdin, "%d", &num_casos_teste); // le da entrada padrao o numero de casos de teste

    fscanf(stdin, "%c", &bn); // le da entrada padrao caractere especial de quebra de linha, '\n'

    for (i = 0; i < num_casos_teste; i++)
    {
        fgets(frase, 1100, stdin); // le a frase da entrada padrao

        criptografa_frase( frase, strlen(frase) ); // funcao principal que criptografa a frase

        fprintf(stdout, "\n"); // imprime uma quebra de linha entre cada resultado
    }

    return 0;
}
