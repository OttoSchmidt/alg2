#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"

int main() {
    char nome[MAX_CHAR_NOME];
    size_t idxBusca;
    uint64_t numComp;

    ssize_t tamVetor = 12;
    int* vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    //gerando vetor organizado
    for (size_t i = 0; i < tamVetor; i++) {
        vetor[i] = i + 1;
        printf("[%d] ", vetor[i]); //REMOVER
    }
    printf("\n");

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

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

    int valor = 8;

    numComp = 0;
    idxBusca = buscaSequencial(vetor, tamVetor, valor, &numComp);
    printf("\n%zd \n", idxBusca);

    numComp = 0;
    idxBusca = buscaSequencialRec(vetor, tamVetor, valor, &numComp);
    printf("\n%zd \n", idxBusca);

    numComp = 0;
    idxBusca = buscaBinaria(vetor, tamVetor, valor, &numComp);
    printf("\n%zd \n", idxBusca);

    numComp = 0;
    idxBusca = buscaBinariaRec(vetor, tamVetor, valor, &numComp);
    printf("\n%zd \n", idxBusca);


    free(vetor);

    return 0;
}
