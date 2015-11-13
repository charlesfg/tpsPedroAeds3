/* ******************************************************************
        fb.c
    Author: Pedro Mendes

    >> Implementacao FORCA BRUTA
    TP2 - The Force Awakens (Paradigmas)
    Data: Novembro/2015
****************************************************************** */

/* PA forca bruta

void imprime_lista(TipoPacote *lst_pct, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        fprintf(stdout, "lst[%d]: Qtde brinq = %3d  |  Peso: %2d\n", i, lst_pct[i].qtde_brinquedos, lst_pct[i].peso);
    }
}

void imprime_vetor(short *v, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        fprintf(stdout, "%d ", v[i]);
    }
    fprintf(stdout, "\n");
}

void copia_vetor(short *v_max, TipoVetorFlags v_atual, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        v_max[i] = v_atual.v[i];
    }
}

// implementacao utilizando o paradigma da FORCA BRUTA
void calc_presentesFB (TipoPacote *lst_pct, int tam, int *maior_brinq, int pct_atual, int peso_atual, int qtde_brinq_atual, short *v_max, TipoVetorFlags v_atual)
{
    if (peso_atual > MAX_PESO)
    {
        return;    // no caso, retorna pois excedeu o peso maximo de 50kg
    }

    v_atual.v[pct_atual] = 1;   // inclui o pacote atual na lista

    // se a quantidade de brinquedos (validos) atual for maior do que a maior ja encontrada ate o momento, atualizar
    if (qtde_brinq_atual > (*maior_brinq) )
    {
        (*maior_brinq) = qtde_brinq_atual;
        copia_vetor(v_max, v_atual, tam); // cria uma copia do 'vetor atual' no 'vetor max'
    }

    // chama recursivamente para cada elemento da lista que ainda nao tenha sido escolhido
    int j;
    for (j = pct_atual; j < tam; j++)
    {
        if (v_atual.v[j] == 0)
        {
            calc_presentesFB(lst_pct, tam, maior_brinq, j, (peso_atual+lst_pct[j].peso), (qtde_brinq_atual+lst_pct[j].qtde_brinquedos), v_max, v_atual);
        }
    }
}

// implementacao utilizando o paradigma da FORCA BRUTA
void calcula_max_presentesFB (TipoPacote *lst_pct, int tam)
{
    int i, maior_brinq = 0, peso_final = 0, pcts_sobra = tam, qtde_brinqs_final = 0;

    TipoVetorFlags vet_max; // vetor que armazenara se um pacote esta (1) ou nao (0) incluso na solucao GLOBAL

    for (i = 0; i < tam; i++)
    {
        vet_max.v[i] = 0;   // inicializa os elementos do vetor como 0, ou seja, nao inclusos na solucao
    }

    TipoVetorFlags vet_aux; // vetor que armazenara se um pacote esta (1) ou nao (0) incluso na solucao ATUAL
    copia_vetor(vet_aux.v, vet_max, tam); // cria uma copia do 'vetor max' no 'vetor aux'

    // chamada inicial para a funcao recursiva
    for (i = 0; i < tam; i++)
    {
        calc_presentesFB(lst_pct, tam, &maior_brinq, i, lst_pct[i].peso, lst_pct[i].qtde_brinquedos, vet_max.v, vet_aux);
    }

    for (i = 0; i < tam; i++)
    {
        if (vet_max.v[i])
        {
            qtde_brinqs_final += lst_pct[i].qtde_brinquedos;    // atualiza a qtde de brinquedos
            peso_final += lst_pct[i].peso;                      // atualiza o peso total do saco
            pcts_sobra--;                                       // pacote inserido == -1 pacote que sobra
        }
    }

    // saida do programa
    fprintf(stdout, "%d brinquedos\n", qtde_brinqs_final);
    fprintf(stdout, "Peso: %d kg\n", peso_final);
    fprintf(stdout, "sobra(m) %d pacote(s)\n", pcts_sobra);
}

*/
