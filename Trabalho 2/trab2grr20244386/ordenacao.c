#include "ordenacao.h"
#include "auxiliar.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void getNome(char nome[])
{
    strncpy(nome, "Otto Schmidt", MAX_CHAR);
    nome[MAX_CHAR - 1] = '\0';
}

uint32_t getGRR() { return 20244386; }

void mergeSortOrdenacao(int vetor[], int vetorTemp[], size_t a, size_t b, uint64_t *numComparacoes)
{
    size_t metade, idxEsquerdo, idxDireito;

    if (a >= b)
        return;

    metade = (a + b) / 2;

    mergeSortOrdenacao(vetor, vetorTemp, a, metade, numComparacoes);
    mergeSortOrdenacao(vetor, vetorTemp, metade + 1, b, numComparacoes);

    idxEsquerdo = a;
    idxDireito = metade + 1;

    for (size_t i = a; i <= b; i++)
    {
        if (idxEsquerdo > metade)
        {
            vetorTemp[i] = vetor[idxDireito];
            idxDireito++;
        }
        else if (idxDireito > b)
        {
            vetorTemp[i] = vetor[idxEsquerdo];
            idxEsquerdo++;
        }
        else if (vetor[idxEsquerdo] < vetor[idxDireito])
        {
            (*numComparacoes)++;
            vetorTemp[i] = vetor[idxEsquerdo];
            idxEsquerdo++;
        }
        else
        {
            (*numComparacoes)++;
            vetorTemp[i] = vetor[idxDireito];
            idxDireito++;
        }
    }

    trocarElementosVetor(vetor, vetorTemp, a, b);
}

uint64_t mergeSort(int vetor[], size_t tam)
{
    uint64_t numComparacoes = 0;

    int *vetorTemp = (int *)malloc(tam * sizeof(int));
    if (vetorTemp == NULL)
    {
        printf("Falha fatal.\n");
        return 0;
    }

    mergeSortOrdenacao(vetor, vetorTemp, 0, tam - 1, &numComparacoes);

    free(vetorTemp);

    return numComparacoes;
}

size_t separarQuickSort(int vetor[], size_t a, size_t b, uint64_t *numComparacoes)
{
    int pivo = vetor[b];
    size_t m = a;

    for (size_t i = a; i < b; i++)
    {
        if (vetor[i] <= pivo)
        {
            trocarElemento(vetor, m, i);
            m++;
        }
        (*numComparacoes)++;
    }

    trocarElemento(vetor, m, b);

    return m;
}

void quickSortOrdernar(int vetor[], ssize_t a, ssize_t b, uint64_t *numComparacoes)
{
    if (a >= b)
        return;

    size_t m = separarQuickSort(vetor, a, b, numComparacoes);
    quickSortOrdernar(vetor, a, m - 1, numComparacoes);
    quickSortOrdernar(vetor, m + 1, b, numComparacoes);
}

uint64_t quickSort(int vetor[], size_t tam)
{
    uint64_t numComparacoes = 0;

    quickSortOrdernar(vetor, 0, tam, &numComparacoes);

    return numComparacoes;
}

void maxHeapify(int vetor[], size_t n, size_t tam, uint64_t *numComparacoes)
{
    size_t maior = n;
    size_t esquerdo = 2 * n + 1;
    size_t direito = 2 * n + 2;

    if (esquerdo < tam && vetor[esquerdo] > vetor[maior] && ++(*numComparacoes))
    {
        maior = esquerdo;
    }

    if (direito < tam && vetor[direito] > vetor[maior] && ++(*numComparacoes))
    {
        maior = direito;
    }

    if (maior != n)
    {
        trocarElemento(vetor, n, maior);
        maxHeapify(vetor, maior, tam, numComparacoes);
    }
}

void createMaxHeap(int vetor[], size_t tam, uint64_t *numComparacoes)
{
    for (ssize_t i = tam / 2; i >= 0; i--)
    {
        maxHeapify(vetor, i, tam, numComparacoes);
    }
}

uint64_t heapSort(int vetor[], size_t tam)
{
    uint64_t numComparacoes = 0;

    createMaxHeap(vetor, tam, &numComparacoes);
    for (size_t i = tam - 1; i > 0; i--)
    {
        trocarElemento(vetor, 0, i);
        maxHeapify(vetor, 0, i - 1, &numComparacoes);
    }

    return numComparacoes;
}

uint64_t mergeSortSR(int vetor[], size_t tam)
{
    vetor[0] = 99;
    return -1;
}

uint64_t quickSortSR(int vetor[], size_t tam)
{
    if (tam <= 1)
        return 0;

    return -1;
}

uint64_t heapSortSR(int vetor[], size_t tam)
{
    uint64_t numComparacoes = 0;

    createMaxHeap(vetor, tam, &numComparacoes);
    for (size_t i = tam - 1; i > 0; i--)
    {
        trocarElemento(vetor, 0, i);
        maxHeapify(vetor, 0, i - 1, &numComparacoes);
    }

    return numComparacoes;
}
