/* ****************************************************************************

    PRAZO DE ENTREGA: 22-10-2015 (quinta) as 23h55

URI Online Judge | 1661
Comércio de Vinhos na Gergóvia

Contest Local, Universidade de Ulm DE Alemanha
Timelimit: 2

Como você deve saber do cômico "Astérix e o Escudo de Arverne", Gergóvia consiste
de uma única rua e cada habitante da cidade é um vendedor de vinho. Você quer saber
como essa economia funciona? Bem simples: todos compram vinhos dos outros habitantes
da cidade. Cada dia, cada habitante decide quanto vinho ele quer comprar ou vender.
Curiosamente, a demanda e o fornecimento são sempre os mesmos de modo que cada
habitante consegue o que deseja.

Contudo, há um problema: transportar o vinho de uma casa para outra resulta em trabalho.
Sendo todos os vinhos igualmente bons, os habitantes de Gergóvia não se importam com
quais pessoas eles irão comercializar, eles estão somente interessados em vender e comprar
um quantidade específica de vinho. Eles são espertos o suficiente para imaginar uma forma
de negociar de modo que todo o montante de trabalho necessário para o transporte seja minimizado.

Nesse problema você está sendo inquerido para reconstruir o comércio durante um dia em Gergóvia.
Para simplificar, nós assumimos que as casas são construidas ao longo de uma linha reta com a
mesma distância entre as casas adjacentes. Transportar uma garrafa de vinho de uma casa para
uma casa adjacente resulta em uma unidade de trabalho.

Entrada

A entrada consiste de vários casos de teste.

Cada caso de teste inicia com o número de habitantes n (2 ≤ n ≤ 100000). A linha seguinte
contém n inteiros ai (-1000 ≤ ai ≤ 1000). Se ai ≥ 0, isso significa que cada habitante que
vive na ith casa, deseja comprar ai garrafas de vinho, caso contrário se ai < 0, ele deseja
vender -ai garrafas de vinho. Você pode assumir que os números ai resumem a 0.

O último caso de teste é seguido por uma linha contendo 0.

Exemplo de Entrada
5
5 -4 1 -3 1
6
-1000 -1000 -1000 1000 1000 1000
0

Saída

Para cada caso de teste, imprima a quantidade mínima de unidades de trabalho necessárias para
que todo habitante tenha sua demanda cumprida. Você pode assumir que este número cabe em um
inteiro de 64 bits com sinal (em C/C++ você pode usar o tipo de dados "long long", em JAVA
o tipo de dados "long").

Exemplo de Saída

9
9000

dica: Muda todas as suas variáveis para long long int, e imprime ela com %lld, costuma funfar.

**************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1

// funcao que retorna o modulo do valor recebido como parametro
long long int modulo (long long int n)
{
    long long int res;

    if (n >= 0)
        res = n;    // retorna o valor de 'n'
    else
        res = -n;   // retorna o oposto de 'n'

    return res;
}

void comercio_vinhos(signed int *hab, int qt_hab)
{
    long long int min_unid_trab = 0;

    int i;
    for (i = 0; i < qt_hab; i++)
    {
        min_unid_trab += modulo(hab[i]); // cada garrafa a ser vendida/comprada sera convertida em uma unid de trab

        // controle para nao exceder o limite do vetor (seg fault)
        if (i < qt_hab-1)
        {
            hab[i+1] += hab[i]; // transporta as garrafas de vinho para o vizinho adj
            //hab[i] = 0;
        }
    }

    fprintf(stdout, "%lld", min_unid_trab); // imprime o resultado final
}

/*
void imprime_vetor (signed int *hab, int qt_hab)
{
    int j;
    for (j = 0; j < qt_hab; j++)
        fprintf(stdout, "%d ", hab[j]);
    fprintf(stdout, "\n");
}*/

int main()
{
    int i, num_hab; // (2 ≤ num_hab ≤ 100000)

    while ( TRUE )
    {
        fscanf(stdin, "%d", &num_hab); // le da entrada padrao o numero de habitantes

        // interrompe o loop caso o valor lido seja a condicao de terminacao (0).
        if ( num_hab == 0 )
            break;

        // realiza a execucao normal do programa
        else
        {
            // aloca memoria para o vetor de habitantes
            signed int *habitantes = (signed int*) calloc(num_hab, sizeof(signed int) );

            // le da entrada padrao os valores de cada habitante
            for (i = 0; i < num_hab; i++)
            {
                fscanf(stdin, "%d", &habitantes[i]);
            }

            comercio_vinhos(habitantes, num_hab);   // funcao principal que calcula as unidades de trabalho

            fprintf(stdout, "\n");                  // imprime uma quebra de linha entre os resultados

            free(habitantes);                       // desaloca a memoria do vetor
        }
    }
}
