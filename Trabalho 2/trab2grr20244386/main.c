#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "ordenacao.h"
#include "auxiliar.h"

void verificarTeste(int *vetor, size_t tam, uint64_t numComp, bool aleatorio) {
    ssize_t resultado;

    printf("Num. comparacoes: %ld\n", numComp);

    if (aleatorio) {
        resultado = verificarOrdenacaoAleatorio(vetor, tam);
    } else {
        resultado = verificarOrdenacaoNormal(vetor, tam);
    }
    
    if (resultado != -1) {
        printf("ERRO AO ORDENADOR ELEMENTO %ld\n", resultado);
        imprimirSecaoVetor(vetor, tam, (size_t)resultado);
    }
}

void testeMergeSort(int *vetor, size_t tam, bool aleatorio, int *vetorAleatorio) {
    uint64_t numComp = 0;

    printf("MERGE SORT RECURSIVO\n");

    gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
    numComp = mergeSort(vetor, tam);
    verificarTeste(vetor, tam, numComp, aleatorio);

    printf("MERGE SORT ITERATIVO\n");
    
    gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
    numComp = mergeSortSR(vetor, tam);
    verificarTeste(vetor, tam, numComp, aleatorio);
}

void testeQuickSort(int *vetor, size_t tam, bool aleatorio, int *vetorAleatorio) {
    uint64_t numComp = 0;

    printf("QUICK SORT RECURSIVO\n");

    gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
    numComp = quickSort(vetor, tam);
    verificarTeste(vetor, tam, numComp, aleatorio);

    printf("QUICK SORT ITERATIVO\n");

    gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
    numComp = quickSortSR(vetor, tam);
    verificarTeste(vetor, tam, numComp, aleatorio);
}

void testeHeapSort(int *vetor, size_t tam, bool aleatorio, int *vetorAleatorio) {
    uint64_t numComp = 0;

    printf("HEAP SORT RECURSIVO\n");

    gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
    numComp = heapSort(vetor, tam);
    verificarTeste(vetor, tam, numComp, aleatorio);

    printf("HEAP SORT ITERATIVO\n");

    gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
    numComp = heapSortSR(vetor, tam);
    verificarTeste(vetor, tam, numComp, aleatorio);
}

int main() {
    srand(time(NULL));
    char nome[MAX_CHAR];
    size_t tamVetor, incremento = 0, quantTestes, aleatorio;
    int *vetor = NULL, *vetorAleatorio = NULL;

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n\n", getGRR());

    printf("Tamanho do vetor inicial: ");
    scanf("%ld", &tamVetor);
    
    printf("Quantidade de testes: ");
    scanf("%ld", &quantTestes);
    
    if (quantTestes > 1) {
        printf("Incremento entre testes: ");
        scanf("%ld", &incremento);
    }

    printf("Geracao do vetor:\n\t[0] - ordem decrescente\n\t[1] - aleatorio\n");
    scanf("%ld", &aleatorio);

    for (size_t i = 0; i < quantTestes; i++) {
        vetor = (int*) realloc(vetor, tamVetor * sizeof(int));
        if (vetor == NULL) {
            printf("Falha fatal. Impossível alocar memoria.");
            return 1;
        }

        if (aleatorio == 1) {
            vetorAleatorio = (int*) realloc(vetorAleatorio, tamVetor * sizeof(int));
            if (vetorAleatorio == NULL) {
                printf("Falha fatal. Impossível alocar memoria.\n");
                return 1;
            }
            gerarVetorAleatorio(vetorAleatorio, tamVetor);
        }

        printf("\nTESTE %ld\nTAMANHO DO VETOR: %ld\n\n", i+1, tamVetor);
        testeMergeSort(vetor, tamVetor, (bool)aleatorio, vetorAleatorio);
        testeQuickSort(vetor, tamVetor, (bool)aleatorio, vetorAleatorio);
        testeHeapSort(vetor, tamVetor, (bool)aleatorio, vetorAleatorio);

        tamVetor += incremento;
    }

    free(vetorAleatorio);
    free(vetor);

    return 0;
}
