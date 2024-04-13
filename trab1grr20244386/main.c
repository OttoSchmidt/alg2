#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"

int verificarExistencia (int vetor[], int num, size_t local) {
    if (vetor[local] == num) {
        return 1;
    }

    return 0;
}

int main() {
    char nome[MAX_CHAR_NOME];
    size_t idxBusca;
    uint64_t numComp;

    clock_t start, end;
    double total;

    ssize_t tamVetor = 10;
    int* vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    //gerando vetor organizado
    for (size_t i = 0; i < tamVetor; i++) {
        vetor[i] = i + 1;
    }

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    int valorBuscar = 8;

    printf("BUSCA SEQUENCIAL\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaSequencial(vetor, tamVetor, valorBuscar, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\n Comparacoes: %ld\n", total, numComp);
    if (!verificarExistencia(vetor, valorBuscar, idxBusca)) {
        printf("VALOR ERRADO: %zd (%d)\n", idxBusca, vetor[idxBusca]);
    }

    
    printf("BUSCA SEQUENCIAL RECURSIVA\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaSequencialRec(vetor, tamVetor, valorBuscar, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\n Comparacoes: %ld\n", total, numComp);
    if (!verificarExistencia(vetor, valorBuscar, idxBusca)) {
        printf("VALOR ERRADO: %zd (%d)\n", idxBusca, vetor[idxBusca]);
    }
    

    printf("BUSCA BINARIA\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaBinaria(vetor, tamVetor, valorBuscar, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\n Comparacoes: %ld\n", total, numComp);
    if (!verificarExistencia(vetor, valorBuscar, idxBusca)) {
        printf("VALOR ERRADO: %zd (%d)\n", idxBusca, vetor[idxBusca]);
    }

    printf("BUSCA BINÁRIA RECURSIVA\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaBinariaRec(vetor, tamVetor, valorBuscar, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\n Comparacoes: %ld\n", total, numComp);
    if (!verificarExistencia(vetor, valorBuscar, idxBusca)) {
        printf("VALOR ERRADO: %zd (%d)\n", idxBusca, vetor[idxBusca]);
    }

    /*
    clock_t start, end;
    double total;

    start = clock();  // start recebe o "ciclo" corrente
    numComp = insertionSortRec(vetor, 3);
    end = clock();  // end recebe o "ciclo" corrente
    // o tempo total é a diferença dividia pelos ciclos por segundo
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total: %f", total);

    numComp = selectionSortRec(vetor, 3);
    numComp = selectionSort(vetor, 3);

    for (int i = 0; i < 3; i++) {
        printf("%d ", vetor[i]);
    }
    */

    


    free(vetor);

    return 0;
}
