#include "auxiliar.h"

#include <stdio.h>

int verificarExistencia (int vetor[], int valor, size_t local) {
    if (vetor[local] == valor) {
        return 1;
    }

    return 0;
}

void trocar (int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void trocarElementosVetor(int vetorDest[], int vetorOrigem[], size_t a, size_t b) {
    for (size_t i = a; i <= b; i++) {
        vetorDest[i] = vetorOrigem[i];
    }
}

void imprimirVetor (int vetor[], size_t tam) {
    for (size_t i = 0; i < tam; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

size_t verificarOrdemNaoCrescente (int vetor[], size_t tam) {
    for (size_t i = 0; i < tam - 1; i++) {
        if (vetor[i] > vetor[i+1]) return i;
    }

    return -1;
}