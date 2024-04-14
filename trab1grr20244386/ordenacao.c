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

    for (size_t i = tam - 1; i > 0; i--) {
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

ssize_t buscaBinariaRecReal(int vetor[], size_t a, size_t b, int valor, uint64_t* numComparacoes) {
    size_t pivot;

    if (a > b) return -1;

    pivot = (a + b + 1)/2;

    if (vetor[pivot] == valor) {
        *numComparacoes += 1;
        return pivot;
    } else if (vetor[pivot] < valor) {
        *numComparacoes += 2;
        return buscaBinariaRecReal(vetor, pivot + 1, b, valor, numComparacoes);
    }

    *numComparacoes += 2;
    return buscaBinariaRecReal(vetor, a, pivot - 1, valor, numComparacoes);
}

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    return buscaBinariaRecReal(vetor, 0, tam - 1, valor, numComparacoes);
}

void trocarElementos (int vetor[], size_t i, size_t j) {
    size_t temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

uint64_t insertionSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;

    for (size_t i = 1; i < tam; i++) {
        for (size_t j = i; j > 0; j--) {
            numComparacoes++;
            if (vetor[j] < vetor[j-1]) {
                trocarElementos(vetor, j, j-1);
            }
        }
    }
    
    return numComparacoes;
}

uint64_t insertionSortRec(int vetor[], size_t tam) {
    uint64_t numComp = 0;
	
	if (tam <= 1) return 0;
	
	numComp = insertionSortRec(vetor, tam-1);
	
	for (int i = tam-1; i > 0; i--) {
        numComp++;
		if (vetor[i-1] > vetor[i]) {
			trocarElementos(vetor, i, i-1);
		}
	}

	return numComp;
}

uint64_t selectionSort(int vetor[], size_t tam) {
    size_t idxMenor;
    uint64_t numComp = 0;

    for (size_t i = 0; i < tam; i++) {
        idxMenor = i;

        for (size_t j = i+1; j < tam; j++) {
            numComp++;
            if (vetor[j] < vetor[idxMenor]) {
                idxMenor = j;
            }
        }

        trocarElementos(vetor, i, idxMenor);
    }

    return numComp;
}

uint64_t selectionSortRec(int vetor[], size_t tam) {
    size_t idxMaior, idxAtual = tam - 1;
    uint64_t numComp = 0;

    if (tam <= 1) return 0;

    idxMaior = idxAtual;
    for (ssize_t i = idxAtual - 1; i >= 0; i--) {
        numComp++;
        if (vetor[i] > vetor[idxMaior]) {
            idxMaior = i;
        }
    }

    trocarElementos(vetor, idxAtual, idxMaior);

    return numComp + selectionSortRec(vetor, tam-1);
}

uint64_t mergeSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}