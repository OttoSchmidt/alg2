#include "ordenacao.h"

#include <string.h>

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
    size_t pivot;

    while (tam > 1) {
        pivot = tam/2;

        if (vetor[pivot] == vetor[valor]) {
            *numComparacoes += 1;
            return pivot;
        } else if (vetor[pivot] < vetor[valor]) {
            *numComparacoes += 2;
            tam = pivot - 1;
        } else {
            *numComparacoes += 2;
            tam = pivot;
            vetor += pivot;
        }
    }

    return -1;
}

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    size_t pivot = tam/2;

    if (tam < 1) return -1;

    if (vetor[pivot] == vetor[valor]) {
        return pivot;
    } else if (vetor[pivot] < vetor[valor]) {
        return buscaBinariaRec(vetor, pivot, valor, numComparacoes);
    }

    return buscaBinariaRec(vetor + pivot, pivot, valor, numComparacoes);
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