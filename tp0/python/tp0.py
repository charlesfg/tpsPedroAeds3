#!/usr/bin/python
# -*- coding: utf8 -*-
import sys

def length_cmp(x,y):
    return cmp(len(x),len(y))

def print_anagram(l):
    # agruparemos em uma lista pois precisamos da lista ordenada decrescentemente pela frequencia de anagramas
    group_list = []
    # contador para o numero de anagramas, ja incluimos a prórpia palavra no contador
    count = 1
    # deixar o ultimo elemento de fora para evitar de sair do array    
    for i in xrange(len(l)-1):
        if l[i] == l[i+1]:
            count +=1
        else:
            # imprimimos 
            group_list.append(count)
            count = 1
    group_list.append(count)
    # finalmente ordenamos a lista por ordem reversa e imprimimos ela
    group_list.sort(cmp,None,True)
    for i in group_list:
        print i,
    print

def search_anagram(w_list):    
        
    for i in xrange(len(w_list)):
        #   ordenamos cada palavra, pois assim teremos só que comparar cada palavra depois para 
        # saber se é um anagrama, use a função qsort
        # http://en.cppreference.com/w/c/algorithm/qsort
        w_list[i] = ''.join(sorted(w_list[i]))

    # ordenamos a lista de forma decrescente com base no tamanho das palavras
    w_list.sort(length_cmp,None,True)
    # ordenamos a lista agora de forma lexicografica para que os anagramas fiquem lado a lado, o problema é que o algoritmo deve ser
    # estavel para preservar a ordem, se o qsort nao preservar pode nao funcionar, dai teremos que usar um do nivio
    w_list.sort()


    # Agora e so contar os item que possuem adjacencias iguais e imprimir na saida padrao
    print_anagram(w_list)   





def main():
    N = int(sys.stdin.readline().strip())

    for i in xrange(N):
        line = sys.stdin.readline().strip()
        w_list = line.split()
        search_anagram(w_list)



if __name__ == '__main__':
    main()
