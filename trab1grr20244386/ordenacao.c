#include "ordenacao.h"

#include <string.h>
#include <stdio.h>

void getNome(char nome[]) {
    strncpy(nome, "Otto Schmidt", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] = '\0';
}

uint32_t getGRR() { return 20244386; }

ssize_t buscaSequencial(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {

    for (size_t i = 0; i < tam; i++) {
        *numComparacoes += 1;
        
        if (vetor[i] == valor) {
            return i;
        }
    }

    return -1;
}

ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor,
                            uint64_t* numComparacoes) {
    if (tam < 1) return -1;
    
    *numComparacoes += 1;
    if (vetor[tam - 1] == valor) return tam - 1;

    return buscaSequencialRec(vetor, tam - 1, valor, numComparacoes);
}

ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                    uint64_t* numComparacoes) {
    size_t pivot, head = 0, tail = tam - 1;

    while (head <= tail) {
        pivot = (head + tail + 1)/2;

        if (vetor[pivot] == valor) {
            *numComparacoes += 1;        
            return pivot;
        } else if (vetor[pivot] < valor) {
            *numComparacoes += 2;
            head = pivot + 1;
        } else {
            *numComparacoes += 2;
            tail = pivot - 1;
        }
    } 

    return -1;
}

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    size_t pivot;

    if (tam < 1) return -1;

    pivot = tam/2;

    if (vetor[pivot] == valor) {
        return pivot;
    } else if (vetor[pivot] < valor) {
        return (pivot + 1) + buscaBinariaRec(vetor + (pivot + 1), pivot, valor, numComparacoes);
        // retornei (pivot + 1) + buscaBinaria pois o vetor foi deslocado pivot + 1
    }

    return buscaBinariaRec(vetor, pivot - 1, valor, numComparacoes);
}

uint64_t insertionSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t insertionSortRec(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t selectionSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t selectionSortRec(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t mergeSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}