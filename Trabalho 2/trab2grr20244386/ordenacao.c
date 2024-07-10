#include "ordenacao.h"
#include "auxiliar.h"
#include <string.h>

void getNome(char nome[]) {
    strncpy(nome, "Otto Schmidt", MAX_CHAR);
    nome[MAX_CHAR - 1] = '\0';
}

uint32_t getGRR() { return 20244386; }

uint64_t mergeSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

size_t separarQuickSort (int vetor[], size_t a, size_t b, uint64_t *numComparacoes) {
	int pivo = vetor[b];
	size_t m = a;

	for (size_t i = a; i < b; i++) {
		if (vetor[i] <= pivo) {
			trocar(v, m, i);
			m++;
		}
		(*numComparacoes)++;
	}

	trocar(v, m, b);
	
	return m;
}

void quickSortOrdernar (int *v, ssize_t a, ssize_t b, uint64_t *numComparacoes) {
	if (a >= b) return;
	
	size_t m = separar(v, a, b, numComparacoes);	
	quickSort(v, a, m-1, numComparacoes);
	quickSort(v, m+1, b, numComparacoes);
}

uint64_t quickSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    quickSortOrdernar(vetor, 0, tam, &numComparacoes);
    return numComparacoes;
}

uint64_t heapSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t mergeSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t quickSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t heapSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}