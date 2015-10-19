/* ****************************************************************************

    PRAZO DE ENTREGA: 22-10-2015 (quarta) as 23h55

URI Online Judge | 1029
Fibonacci, Quantas Chamadas?

Por Neilor Tonin, URI  Brasil
Timelimit: 1

Quase todo estudante de Ciência da Computação recebe em algum momento no início
de seu curso de graduação algum problema envolvendo a sequência de Fibonacci.
Tal sequência tem como os dois primeiros valores 0 (zero) e 1 (um) e cada próximo
valor será sempre a soma dos dois valores imediatamente anteriores. Por definição,
podemos apresentar a seguinte fórmula para encontrar qualquer número da sequência
de Fibonacci:

fib(0) = 0
fib(1) = 1
fib(n) = fib(n-1) + fib(n-2);

Uma das formas de encontrar o número de Fibonacci é através de chamadas recursivas.
Isto é ilustrado a seguir, apresentando a árvore de derivação ao calcularmos o valor
fib(4), ou seja o 5º valor desta sequência:

    [fib_tree.png]

Desta forma,

fib(4) = 1+0+1+1+0 = 3

Foram feitas 8 calls, ou seja, 8 chamadas recursivas.

Entrada

A primeira linha da entrada contém um único inteiro N, indicando o número de casos de
teste. Cada caso de teste contém um inteiro X (1 ≤ X ≤ 39) .

Exemplo de Entrada

2
5
4

Saída

Para cada caso de teste de entrada deverá ser apresentada uma linha de saída, no seguinte
formato: fib(n) = num_calls calls = result, aonde num_calls é o número de chamadas
recursivas, tendo sempre um espaço antes e depois do sinal de igualdade, conforme o exemplo
abaixo.

Exemplo de Saída

fib(5) = 14 calls = 5
fib(4) = 8 calls = 3

**************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
