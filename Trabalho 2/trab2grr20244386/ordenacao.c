#include "ordenacao.h"
#include "auxiliar.h"
#include "pilha.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void getNome(char nome[]) {
    strncpy(nome, "Otto Schmidt", MAX_CHAR);
    nome[MAX_CHAR - 1] = '\0';
}

uint32_t getGRR() { return 20244386; }

void merge(int vetor[], int vetorTemp[], size_t a, size_t metade, size_t b, uint64_t *numComparacoes) {
    size_t idxEsquerdo, idxDireito;

    idxEsquerdo = a;
    idxDireito = metade + 1;

    for (size_t i = a; i <= b; i++) {
        if (idxEsquerdo > metade) {
            vetorTemp[i] = vetor[idxDireito];
            idxDireito++;
        } else if (idxDireito > b) {
            vetorTemp[i] = vetor[idxEsquerdo];
            idxEsquerdo++;
        } else if (vetor[idxEsquerdo] < vetor[idxDireito]) {
            (*numComparacoes)++;
            vetorTemp[i] = vetor[idxEsquerdo];
            idxEsquerdo++;
        } else {
            (*numComparacoes)++;
            vetorTemp[i] = vetor[idxDireito];
            idxDireito++;
        }
    }

    trocarElementosVetor(vetor, vetorTemp, a, b);
}

void mergeSortAuxiliar(int vetor[], int vetorTemp[], size_t a, size_t b, uint64_t *numComparacoes) {
    size_t metade = (a + b) / 2;

    if (a >= b) return;

    mergeSortAuxiliar(vetor, vetorTemp, a, metade, numComparacoes);
    mergeSortAuxiliar(vetor, vetorTemp, metade + 1, b, numComparacoes);
    merge(vetor, vetorTemp, a, (a + b) / 2, b, numComparacoes);
}

uint64_t mergeSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;

    int *vetorTemp = (int *)malloc(tam * sizeof(int));
    if (vetorTemp == NULL) {
        printf("Falha fatal.\n");
        return 0;
    }

    mergeSortAuxiliar(vetor, vetorTemp, 0, tam - 1, &numComparacoes);

    free(vetorTemp);

    return numComparacoes;
}

size_t separarQuickSort(int vetor[], ssize_t a, ssize_t b, uint64_t *numComparacoes) {
    int pivo = vetor[b];
    size_t m = a;

    for (ssize_t i = a; i < b; i++) {
        if (vetor[i] <= pivo) {
            trocarElemento(vetor, m, i);
            m++;
        }
        (*numComparacoes)++;
    }

    trocarElemento(vetor, m, b);

    return m;
}

void quickSortAuxiliar(int vetor[], ssize_t a, ssize_t b, uint64_t *numComparacoes) {
    if (a >= b) return;

    ssize_t m = separarQuickSort(vetor, a, b, numComparacoes);
    quickSortAuxiliar(vetor, a, m - 1, numComparacoes);
    quickSortAuxiliar(vetor, m + 1, b, numComparacoes);
}

uint64_t quickSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;

    quickSortAuxiliar(vetor, 0, tam - 1, &numComparacoes);

    return numComparacoes;
}

void maxHeapify(int vetor[], size_t n, size_t tam, uint64_t *numComparacoes) {
    size_t maior = n;
    size_t esquerdo = 2 * n + 1;
    size_t direito = 2 * n + 2;

    if (esquerdo < tam) {
        (*numComparacoes)++;
        if (vetor[esquerdo] > vetor[maior]) {
            maior = esquerdo;
        }
    }

    if (direito < tam) {
        (*numComparacoes)++;
        if (vetor[direito] > vetor[maior]) {
            maior = direito;
        }
    }

    if (maior != n) {
        trocarElemento(vetor, n, maior);
        maxHeapify(vetor, maior, tam, numComparacoes);
    }
}

void heapSortAuxiliar(int vetor[], ssize_t tam, uint64_t *numComparacoes) {
    if (tam <= 1) return;

    tam--;

    trocarElemento(vetor, 0, tam);
    maxHeapify(vetor, 0, tam, numComparacoes);

    heapSortAuxiliar(vetor, tam, numComparacoes);
}

uint64_t heapSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;

    for (ssize_t i = tam / 2 - 1; i >= 0; i--) {
        maxHeapify(vetor, i, tam, &numComparacoes);
    }

    heapSortAuxiliar(vetor, tam, &numComparacoes);

    return numComparacoes;
}

uint64_t mergeSortSR(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    int *vetorTemp = (int *)malloc(tam * sizeof(int));
    size_t b, metade;

    if (vetorTemp == NULL) {
        printf("Falha fatal.\n");
        return 0;
    }

    // Divide o vetor em tamanhos de 1 para 2 para 4 e assim por diante
    for (size_t tamVetor = 1; tamVetor <= tam - 1; tamVetor *= 2) {
        for (size_t a = 0; a < tam - 1; a += 2 * tamVetor) {
            metade = a + tamVetor - 1;
            if (metade >= tam - 1) break;

            b = a + 2 * tamVetor - 1;
            if (b >= tam - 1) b = tam - 1;

            merge(vetor, vetorTemp, a, metade, b, &numComparacoes);
        }
    }

    free(vetorTemp);

    return numComparacoes;
}

uint64_t quickSortSR(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    pilha_t *pilha;
    ssize_t a = 0, b = tam - 1, pivo;

    pilha = criarPilha();

    empilhar(pilha, a);
    empilhar(pilha, b);

    while (!pilhaVazia(pilha)) {
        b = desempilhar(pilha);
        a = desempilhar(pilha);

        if (b > a && b > 0) {
            pivo = separarQuickSort(vetor, a, b, &numComparacoes);
            empilhar(pilha, a);
            empilhar(pilha, pivo - 1);
            empilhar(pilha, pivo + 1);
            empilhar(pilha, b);
        }
    }

    destruirPilha(pilha);

    return numComparacoes;
}

void maxHeapifySR(int vetor[], size_t n, size_t tam, uint64_t *numComparacoes) {
    size_t maior, esquerdo, direito;

    while (true) {
        maior = n;
        esquerdo = 2 * n + 1;
        direito = 2 * n + 2;

        if (esquerdo < tam) {
            if (vetor[esquerdo] > vetor[maior]) {
                maior = esquerdo;
            }
            (*numComparacoes)++;
        }

        if (direito < tam) {
            if (vetor[direito] > vetor[maior]) {
                maior = direito;
            }
            (*numComparacoes)++;
        }

        if (maior == n) break;

        trocarElemento(vetor, n, maior);
        n = maior;
    }
}

uint64_t heapSortSR(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;

    for (ssize_t i = tam / 2 - 1; i >= 0; i--) {
        maxHeapifySR(vetor, i, tam, &numComparacoes);
    }

    // heapsort
    for (size_t i = tam - 1; i > 0; i--) {
        trocarElemento(vetor, 0, i);
        maxHeapifySR(vetor, 0, i, &numComparacoes);
    }

    return numComparacoes;
}
