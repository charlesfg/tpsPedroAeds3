/* ****************************************************************************

    PRAZO DE ENTREGA: 22-10-2015 (quarta) as 23h55

URI Online Judge | 1767
Saco do Papai Noel

Por Neilor Tonin, URI Online Judge BR Brazil
Timelimit: 2


Papai Noel vai começar a fazer as suas viagens de trenó para entregar os presentes
de Natal. A SBC (Sociedade Brasileira de Carregadores) determinou que o máximo de
peso de cada saco com presentes, poderá ser 50 kgs, para que os elfos, que são
"puxa-sacos" ou ajudantes de Papai Noel não fiquem com dores nas costas ao carregarem
o trenó e também para que o Papai Noel não se machuque ao entregar os brinquedos.

Uma vez que todos os brinquedos estão agrupados em pacotes, sua tarefa é auxiliar
com um programa que agrupe o máximo de brinquedos possíveis dentro do peso limite
de 50 kgs. Logo na sequência Y-URI, que é o elfo chefe, levará este saco até o
trenó para que Noel possa seguir com sua viagem.

Entrada

A entrada contém vários casos de teste. A primeira linha de entrada contém um
inteiro N que é o número de casos de teste, ou melhor, o número viagens que Papai
Noel irá fazer para entregar os presentes. Cada viagem inicia com um inteiro
Pac (1 < Pac < 100) que indica a quantidade de pacotes disponíveis para esta viagem.
As próximas Pac linhas irão conter dois valores inteiros cada uma, qt (1 < qt ≤ 300) e
peso (1 ≤ peso ≤ 50) que são respectivamente a quantidade de brinquedos e o peso de
cada um destes pacotes, separados por um espaço em branco.

Exemplo de Entrada

2
4
6 17
21 23
72 24
143 2
10
1 17
11 23
22 24
13 2
23 3
24 4
9 5
8 6
7 7
15 8

Saída

Para cada caso de teste de entrada, seu programa deverá imprimir três linhas de saída,
com mensagem correspondente conforme o exemplo abaixo, seguidas por uma linha em branco.
A primeira destas linhas deverá conter a quantidade de brinquedos que Y-URI irá carregar
até o trenó. A segunda linha conterá o peso total destes brinquedos. A última linha, por
pedido de Noel, será a quantidade de pacotes que sobraram para uma viagem futura.

No segundo caso de teste abaixo, por exemplo, foram selecionados para a viagem 106 brinquedos
que estão agrupados nos pacotes com 24, 2, 3, 4, 5 e 8 kg, somando um total de 46 kg.

Para a maior quantidade de brinquedos selecionada, haverá apenas uma quantidade de peso e
pacote que irá sobrar.

Exemplo de Saída

236 brinquedos
Peso: 49 kg
sobra(m) 1 pacote(s)

106 brinquedos
Peso: 46 kg
sobra(m) 4 pacote(s)

**************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
