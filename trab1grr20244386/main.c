#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"
#include "auxiliar.h"

void gerarVetorNaoCrescente (int vetor[], size_t tam) {
    for (size_t i = 0; i < tam; i++) {
        vetor[i] = tam - i;
    }
}

void imprimirStatus (clock_t start, clock_t end, uint64_t numComparacoes) {
    double total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\nComparacoes: %ld\n", total, numComparacoes);
}

int main() {
    char nome[MAX_CHAR_NOME];
    size_t idxBusca, tamVetor;
    uint64_t numComp;

    clock_t start, end;

    scanf("%ld", &tamVetor);
    int* vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 1;
    }

    //gerando vetor organizado de maneira não decrescente
    for (size_t i = 0; i < tamVetor; i++) {
        vetor[i] = i + 1;
    }

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    int valorBuscar = 10;

    printf("\nBUSCA SEQUENCIAL\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaSequencial(vetor, tamVetor, valorBuscar, &numComp);
    end = clock();
    printf("%ld\n", idxBusca);
    imprimirStatus(start, end, numComp);
    if (idxBusca != -1 && !verificarExistencia(vetor, valorBuscar, idxBusca)) {
        printf("VALOR ERRADO: %zd (%d)\n", idxBusca, vetor[idxBusca]);
    }

    // NÃO FUNCIONA EM VETORES MUITO GRANDES    
    printf("\nBUSCA SEQUENCIAL RECURSIVA\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaSequencialRec(vetor, tamVetor, valorBuscar, &numComp);
    end = clock();
    printf("%ld\n", idxBusca);
    imprimirStatus(start, end, numComp);
    if (idxBusca != -1 && !verificarExistencia(vetor, valorBuscar, idxBusca)) {
        printf("VALOR ERRADO: %zd (%d)\n", idxBusca, vetor[idxBusca]);
    }

    printf("\nBUSCA BINARIA\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaBinaria(vetor, tamVetor, valorBuscar, &numComp);
    end = clock();
    printf("%ld\n", idxBusca);
    imprimirStatus(start, end, numComp);
    if (idxBusca != -1 && !verificarExistencia(vetor, valorBuscar, idxBusca)) {
        printf("VALOR ERRADO: %zd (%d)\n", idxBusca, vetor[idxBusca]);
    }

    printf("\nBUSCA BINÁRIA RECURSIVA\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaBinariaRec(vetor, tamVetor, valorBuscar, &numComp);
    end = clock();
    printf("%ld\n", idxBusca);
    imprimirStatus(start, end, numComp);
    if (idxBusca != -1 && !verificarExistencia(vetor, valorBuscar, idxBusca)) {
        printf("VALOR ERRADO: %zd (%d)\n", idxBusca, vetor[idxBusca]);
    }

    tamVetor = 10000;
    vetor = (int*) realloc(vetor, tamVetor * sizeof(int));

    //gerando vetor organizado de forma não crescente
    gerarVetorNaoCrescente(vetor, tamVetor);

    printf("\nINSERTION SORT ITERATIVO\n");
    start = clock();
    numComp = insertionSort(vetor, tamVetor);
    end = clock();
    imprimirStatus(start, end, numComp);
    idxBusca = verificarOrdemNaoCrescente(vetor, tamVetor);
    if (idxBusca != -1) {
        printf("\nVETOR DESORDENADO\n");
        printf("%d (i = %ld) > %d (i = %ld)\n", vetor[idxBusca], idxBusca, vetor[idxBusca+1], idxBusca+1);
    }

    //gerando vetor organizado de forma não crescente
    gerarVetorNaoCrescente(vetor, tamVetor);

    printf("\nINSERTION SORT RECURSIVO\n");
    start = clock();
    numComp = insertionSortRec(vetor, tamVetor);
    end = clock();
    imprimirStatus(start, end, numComp);
    idxBusca = verificarOrdemNaoCrescente(vetor, tamVetor);
    if (idxBusca != -1) {
        printf("\nVETOR DESORDENADO\n");
        printf("%d (i = %ld) > %d (i = %ld)\n", vetor[idxBusca], idxBusca, vetor[idxBusca+1], idxBusca+1);
    }

    //gerando vetor organizado de forma não crescente
    gerarVetorNaoCrescente(vetor, tamVetor);

    printf("\nSELECTION SORT ITERATIVO\n");
    start = clock();
    numComp = selectionSort(vetor, tamVetor);
    end = clock();
    imprimirStatus(start, end, numComp);
    idxBusca = verificarOrdemNaoCrescente(vetor, tamVetor);
    if (idxBusca != -1) {
        printf("\nVETOR DESORDENADO\n");
        printf("%d (i = %ld) > %d (i = %ld)\n", vetor[idxBusca], idxBusca, vetor[idxBusca+1], idxBusca+1);
    }

    //gerando vetor organizado de forma não crescente
    gerarVetorNaoCrescente(vetor, tamVetor);

    printf("\nSELECTION SORT RECURSIVO\n");
    start = clock();
    numComp = selectionSortRec(vetor, tamVetor);
    end = clock();
    imprimirStatus(start, end, numComp);
    idxBusca = verificarOrdemNaoCrescente(vetor, tamVetor);
    if (idxBusca != -1) {
        printf("\nVETOR DESORDENADO\n");
        printf("%d (i = %ld) > %d (i = %ld)\n", vetor[idxBusca], idxBusca, vetor[idxBusca+1], idxBusca+1);
    }

    //gerando vetor organizado de forma não crescente
    gerarVetorNaoCrescente(vetor, tamVetor);

    printf("\nMERGE SORT\n");
    start = clock();
    numComp = mergeSortRec(vetor, tamVetor);
    end = clock();
    imprimirStatus(start, end, numComp);
    idxBusca = verificarOrdemNaoCrescente(vetor, tamVetor);
    if (idxBusca != -1) {
        printf("\nVETOR DESORDENADO\n");
        printf("%d (i = %ld) > %d (i = %ld)\n", vetor[idxBusca], idxBusca, vetor[idxBusca+1], idxBusca+1);
    }

    free(vetor);

    return 0;
}
