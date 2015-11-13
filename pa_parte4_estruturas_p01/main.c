/* ***********************************************************************************

    PRAZO: 13-11-2015 (sexta) as 23h55

URI Online Judge | 1523
Estacionamento Linear

Por Cristhian Bonilha, UTFPR BR Brazil
Timelimit: 1

Após muito tempo juntando dinheiro, Rafael finalmente conseguiu comprar seu carro
(parcelado, é claro). Chega de pegar ônibus, agora sua vida será mais fácil. Pelo
menos isso é o que ele pensava, até ouvir falar do estacionamento perto da faculdade
onde ele decidiu estacionar o carro todos os dias.

O estacionamento tem apenas um corredor, com largura o suficiente para acomodar um
carro, e profundidade suficiente para acomodar K carros, um atrás do outro. Como
este estacionamento só tem um portão, só é possível entrar e sair por ele.

Quando o primeiro carro entra no estacionamento, o mesmo ocupa a posição próxima à
parede, ao fundo do estacionamento. Todos os próximos carros estacionam logo atrás
dele, formando uma fila. Obviamente, não é possível que um carro passe por cima de
outro, portanto só é possível que um carro saia do estacionamento se ele for o último
da fila.

Dados o horário de chegada e saída prevista de N motoristas, incluindo Rafael, diga
se é possível que todos consigam estacionar e remover seus carros no estacionamento
citado.

Entrada

Haverá diversos casos de teste. Cada caso de teste inicia com dois inteiros N e K
(3 ≤ N ≤ 10⁴, 1 ≤ K ≤ 10³), representando o número de motoristas que farão uso do
estacionamento, e o número de carros que o estacionamento consegue comportar,
respectivamente.

Em seguida haverá N linhas, cada uma contendo dois inteiros Ci e Si (1 ≤ Ci, Si ≤ 10⁵),
representando, respectivamente, o horário de chegada e saída do motorista i (1 ≤ i ≤ N).
Os valores de Ci são dados de forma crescente, ou seja, Ci < Ci+1 para todo 1 ≤ i < N.

Não haverá mais de um motorista que chegam ao mesmo tempo, e nem mais de um motorista
que saiam ao mesmo tempo. É possível que um motorista consiga estacionar no mesmo momento
em que outro motorista deseja sair.

O último caso de teste é indicado quando N = K = 0, o qual não deverá ser processado.

Exemplo de Entrada

3 2
1 10
2 5
6 9
3 2
1 10
2 5
6 12
0 0

Saída

Para cada caso de teste imprima uma linha, contendo a palavra “Sim”, caso seja possível
que todos os N motoristas façam uso do estacionamento, ou “Nao” caso contrário.

Exemplo de Saída

Sim
Nao

*********************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

typedef struct _TipoVeiculo
{
    int chegada; // (1 ≤ Ci, Si ≤ 10⁵)
    int saida;
} TipoVeiculo;

void imprime_lista (TipoVeiculo * lst, int qtde_elem)
{
    int i;
    for (i = 0; i < qtde_elem; i++)
    {
        fprintf(stdout, "%d ", lst[i]);
    }
}

/* ************************************************************************************************
            DESNECESSARIO ORDENAR - AS ENTRADAS JA VEM ORDENADAS
            -----------------------------------------------------

// qsort int comparison function //
int int_cmp(const void *a, const void *b)
{
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;

    return *ia - *ib; // positivo se (a > b) e negativo se (b > a)
}

// funcao que ordena os carros na lista por ORDEM DE CHEGADA
void ordena_carros (TipoVeiculo * lst, int qtde_elem)
{
    // params: lista, qtde de elementos, tamanho de cada elemento, funcao aux de comparacao
    qsort (lst, qtde_elem, sizeof(TipoVeiculo), int_cmp );
}
************************************************************************************************ */

int verifica_estacionamento(TipoVeiculo *lst, int num_carros)
{
    int i, j;
    for (i = 0; i < num_carros; i++)
    {
        for (j = i; j < num_carros; j++)
        {
            if (lst[j].saida > lst[i].saida)
            {
                return FALSE;
            }
        }
    }

    /*for (i = num_carros-1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (lst[i].saida < lst[j].saida)
            {
                return FALSE;
            }
        }
    }*/

    return TRUE;
}

int main()
{
    int num_motoristas, num_carros, resultado; // (3 ≤ num_motoristas ≤ 10⁴, 1 ≤ num_carros ≤ 10³)
    TipoVeiculo carro_aux;

    fscanf(stdin, "%d %d", &num_motoristas, &num_carros); // le uma nova entrada

    // roda o programa enqto a qtde de motoristas e num_carros do estacionamento forem diferentes de ZERO
    while( (num_motoristas != 0) && (num_carros != 0) )
    {
        // aloca a memoria necessaria para armazenar a quantidade especificada de veiculos
        TipoVeiculo *lista_carros = (TipoVeiculo*) malloc (num_motoristas * sizeof(TipoVeiculo) );

        int i;
        for (i = 0; i < num_motoristas; i++)
        {
            fscanf(stdin, "%d %d", &carro_aux.chegada, &carro_aux.saida);
            lista_carros[i] = carro_aux;
        }

        //ordena_carros(lista_carros, num_motoristas);

        imprime_lista(lista_carros, num_motoristas);

        resultado = verifica_estacionamento(lista_carros, num_motoristas); // funcao principal

        if (resultado == TRUE)
            fprintf(stdout, "Sim");
        else
            fprintf(stdout, "Nao");

        free(lista_carros); // desaloca memoria da lista para essa instancia

        fscanf(stdin, "%d %d", &num_motoristas, &num_carros); // le uma nova entrada

        if ( (num_motoristas != 0) && (num_carros != 0) )
            fprintf(stdout, "\n"); // imprime uma quebra de linha se houver mais casos de teste a serem processadas
    }

    return 0;
}
