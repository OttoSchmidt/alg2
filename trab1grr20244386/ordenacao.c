#include "ordenacao.h"
#include "auxiliar.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void getNome(char nome[]) {
    strncpy(nome, "Otto Schmidt", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] = '\0';
}

uint32_t getGRR() { return 20244386; }

ssize_t buscaSequencial(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    ssize_t retorno = -1;
    for (ssize_t i = tam - 1; i >= 0; i--) {
        *numComparacoes += 1;
        
        if (vetor[i] <= valor) {
            retorno = i;
            break;
        }
    }

    if (retorno >= 0 && verificarExistencia(vetor, valor, retorno)) {
        return retorno;
    }
    return -1;
}

ssize_t buscaSequencialRecAuxiliar(int vetor[], size_t a, size_t b,
                            int valor, uint64_t *numComparacoes) {
    if (a > b) return a-1;

    *numComparacoes += 1;
    if (vetor[b] <= valor) return b;

    return buscaSequencialRecAuxiliar(vetor, 0, b - 1, valor, numComparacoes);
}

ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor,
                            uint64_t* numComparacoes) {
    ssize_t retorno = buscaSequencialRecAuxiliar(vetor, 0, tam-1, valor, numComparacoes);

    if (retorno == -1 || verificarExistencia(vetor, valor, retorno) != 1) {
        return -1;
    }
    return retorno;
}

ssize_t buscaBinariaAuxiliar(int vetor[], ssize_t a, ssize_t b,
                    int valor, uint64_t *numComparacoes) {
    size_t pivot;

    while (a <= b) {
        pivot = (a+b)/2;
        
        *numComparacoes += 1;
        if (valor < vetor[pivot]) {
            b = pivot - 1;
        } else {
            a = pivot + 1;
        }
    }    

    return a-1;
}

ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                    uint64_t* numComparacoes) {
    ssize_t retorno = buscaBinariaAuxiliar(vetor, 0, tam-1, valor, numComparacoes);

    if (retorno == -1 || verificarExistencia(vetor, valor, retorno) != 1) {
        return -1;
    }
    return retorno;
}

ssize_t buscaBinariaRecAuxiliar(int vetor[], ssize_t a, ssize_t b, 
                        int valor, uint64_t* numComparacoes) {
    size_t pivot;

    if (a > b) return a-1;

    pivot = (a+b)/2;

    if (vetor[pivot] <= valor) {
        *numComparacoes += 1;
        return buscaBinariaRecAuxiliar(vetor, pivot + 1, b, valor, numComparacoes);
    } else {
        *numComparacoes += 1;
        return buscaBinariaRecAuxiliar(vetor, a, pivot - 1, valor, numComparacoes);
    }
}

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    size_t retorno = buscaBinariaRecAuxiliar(vetor, 0, tam - 1, valor, numComparacoes);

    if (retorno == -1 || verificarExistencia(vetor, valor, retorno) != 1) {
        return -1;
    }
    return retorno;
}

uint64_t insertionSort(int vetor[], size_t tam) {
    uint64_t numComp = 0;
    size_t localDest;

    for (size_t i = 1; i < tam; i++) {
        localDest = buscaBinaria(vetor, i+1, vetor[i], &numComp);

        for (ssize_t j = i; j > localDest+1; j--) {
            trocarElementos(vetor, j, j-1);
        }
    }
    
    return numComp;
}

uint64_t insertionSortRec(int vetor[], size_t tam) {
    uint64_t numComp = 0;
    ssize_t localDest, idxFinal = tam - 1;
	
	if (idxFinal <= 0) return 0;
	
	numComp = insertionSortRec(vetor, idxFinal);
	
	localDest = buscaBinaria(vetor, tam, vetor[idxFinal], &numComp);
    for (ssize_t j = idxFinal; j > localDest+1; j--) {
        trocarElementos(vetor, j, j-1);
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

uint64_t mergeSortRecursivo(int vetor[], int vetorTemp[], size_t a, size_t b) {
    uint64_t numComp = 0;
    size_t metade, idxEsquerdo, idxDireito;

    if (a >= b) return 0;

    metade = (a+b)/2;

    numComp += mergeSortRecursivo(vetor, vetorTemp, a, metade);
    numComp += mergeSortRecursivo(vetor, vetorTemp, metade+1, b);

    idxEsquerdo = a;
    idxDireito = metade+1;

    for (size_t i = a; i <= b; i++) {
        if (idxEsquerdo > metade) {
            vetorTemp[i] = vetor[idxDireito];
            idxDireito++;
        } else if (idxDireito > b) {
            vetorTemp[i] = vetor[idxEsquerdo];
            idxEsquerdo++;
        } else if (vetor[idxEsquerdo] < vetor[idxDireito]) {
            numComp++;
            vetorTemp[i] = vetor[idxEsquerdo];
            idxEsquerdo++;
        } else {
            numComp++;
            vetorTemp[i] = vetor[idxDireito];
            idxDireito++;
        }
    }

    trocarElementosVetor(vetor, vetorTemp, a, b);

    return numComp;
}

uint64_t mergeSortRec(int vetor[], size_t tam) {
    uint64_t numComp;
    int *vetorTemp;
    
    vetorTemp = calloc(tam, sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal.\n");
        return 0;
    }

    numComp = mergeSortRecursivo(vetor, vetorTemp, 0, tam-1);

    free(vetorTemp);

    return numComp;
}