#include "ordenacao.h"
#include "auxiliar.h"
#include "pilha.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 1048576

void getNome(char nome[])
{
    strncpy(nome, "Otto Schmidt", MAX_CHAR);
    nome[MAX_CHAR - 1] = '\0';
}

uint32_t getGRR() { return 20244386; }

void mergeSortAuxiliar(int vetor[], int vetorTemp[], size_t a, size_t b, uint64_t *numComparacoes)
{
    size_t metade, idxEsquerdo, idxDireito;

    if (a >= b)
        return;

    metade = (a + b) / 2;

    mergeSortAuxiliar(vetor, vetorTemp, a, metade, numComparacoes);
    mergeSortAuxiliar(vetor, vetorTemp, metade + 1, b, numComparacoes);

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

    mergeSortAuxiliar(vetor, vetorTemp, 0, tam - 1, &numComparacoes);

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

void quickSortAuxiliar(int vetor[], ssize_t a, ssize_t b, uint64_t *numComparacoes)
{
    if (a >= b)
        return;

    size_t m = separarQuickSort(vetor, a, b, numComparacoes);
    quickSortAuxiliar(vetor, a, m - 1, numComparacoes);
    quickSortAuxiliar(vetor, m + 1, b, numComparacoes);
}

uint64_t quickSort(int vetor[], size_t tam)
{
    uint64_t numComparacoes = 0;

    quickSortAuxiliar(vetor, 0, tam, &numComparacoes);

    return numComparacoes;
}

void maxHeapify(int vetor[], size_t n, size_t tam, uint64_t *numComparacoes)
{
    size_t maior = n;
    size_t esquerdo = 2 * n + 1;
    size_t direito = 2 * n + 2;

    if (esquerdo < tam)
    {
        (*numComparacoes)++;
        if (vetor[esquerdo] > vetor[maior])
        {
            maior = esquerdo;
        }
    }

    if (direito < tam)
    {
        (*numComparacoes)++;
        if (vetor[direito] > vetor[maior])
        {
            maior = direito;
        }
    }

    if (maior != n)
    {
        trocarElemento(vetor, n, maior);
        maxHeapify(vetor, maior, tam, numComparacoes);
    }
}

void heapSortAuxiliar(int vetor[], ssize_t tam, uint64_t *numComparacoes)
{
    if (tam <= 1)
        return;

    tam--;

    trocarElemento(vetor, 0, tam);
    maxHeapify(vetor, 0, tam, numComparacoes);

    heapSortAuxiliar(vetor, tam, numComparacoes);
}

uint64_t heapSort(int vetor[], size_t tam)
{
    uint64_t numComparacoes = 0;

    for (ssize_t i = tam / 2 - 1; i >= 0; i--)
    {
        maxHeapify(vetor, i, tam, &numComparacoes);
    }

    heapSortAuxiliar(vetor, tam, &numComparacoes);

    return numComparacoes;
}

uint64_t mergeSortSR(int vetor[], size_t tam)
{
    uint64_t numComparacoes = 0;
    size_t metade, idxEsquerdo, idxDireito, a = 0, b = tam - 1;
    pilha_t *pilha;
    int *vetorTemp = NULL;

    if (tam <= 1)
        return 0;

    pilha = criarPilha(STACK_SIZE);

    vetorTemp = (int *)malloc(tam * sizeof(int));
    if (vetorTemp == NULL)
    {
        printf("Falha fatal.\n");
        return 0;
    }

    push(pilha, a);
    push(pilha, b);

    while (!pilhaVazia(pilha))
    {
        b = pop(pilha);
        a = pop(pilha);

        if (a >= b)
            continue;

        metade = (a + b) / 2;

        push(pilha, a);
        push(pilha, metade);
        push(pilha, metade + 1);
        push(pilha, b);

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
                numComparacoes++;
                vetorTemp[i] = vetor[idxEsquerdo];
                idxEsquerdo++;
            }
            else
            {
                numComparacoes++;
                vetorTemp[i] = vetor[idxDireito];
                idxDireito++;
            }
        }

        trocarElementosVetor(vetor, vetorTemp, a, b);
    }

    free(vetorTemp);

    destruirPilha(pilha);

    return numComparacoes;
}

uint64_t quickSortSR(int vetor[], size_t tam)
{
    uint64_t numComparacoes = 0;
    pilha_t *pilha;
    size_t a = 0, b = tam - 1, pivo;

    pilha = criarPilha(STACK_SIZE);

    push(pilha, a);
    push(pilha, b);

    while (!pilhaVazia(pilha))
    {
        b = pop(pilha);
        a = pop(pilha);

        if (a < b)
        {
            pivo = separarQuickSort(vetor, a, b, &numComparacoes);
            push(pilha, a);
            push(pilha, pivo - 1);
            push(pilha, pivo + 1);
            push(pilha, b);
        }
    }

    destruirPilha(pilha);

    return numComparacoes;
}

void maxHeapifySR(int vetor[], size_t n, size_t tam, uint64_t *numComparacoes)
{
    size_t maior, esquerdo, direito;

    while (true)
    {
        maior = n;
        esquerdo = 2 * n + 1;
        direito = 2 * n + 2;

        if (esquerdo < tam)
        {
            if (vetor[esquerdo] > vetor[maior])
            {
                maior = esquerdo;
            }
            (*numComparacoes)++;
        }

        if (direito < tam)
        {
            if (vetor[direito] > vetor[maior])
            {
                maior = direito;
            }
            (*numComparacoes)++;
        }

        if (maior == n)
        {
            break;
        }

        trocarElemento(vetor, n, maior);
        n = maior;
    }
}

uint64_t heapSortSR(int vetor[], size_t tam)
{
    uint64_t numComparacoes = 0;

    for (ssize_t i = tam / 2 - 1; i >= 0; i--)
    {
        maxHeapifySR(vetor, i, tam, &numComparacoes);
    }

    // heapsort
    for (size_t i = tam - 1; i > 0; i--)
    {
        trocarElemento(vetor, 0, i);
        maxHeapifySR(vetor, 0, i, &numComparacoes);
    }

    return numComparacoes;
}
