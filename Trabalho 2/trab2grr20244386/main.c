#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "ordenacao.h"
#include "auxiliar.h"

void testeMergeSort(int *vetor, size_t tam, bool aleatorio, int *vetorAleatorio) {
    uint64_t numComp = 0;
	  ssize_t resultado;

	  printf("MERGE SORT RECURSIVO\n");

    gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
    numComp = mergeSort(vetor, tam);
	  printf("Num. comparacoes: %ld\n", numComp);

	  resultado = verificarOrdenacao(vetor, tam);
	  if (resultado != -1) {
        printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
        imprimirSecaoVetor(vetor, tam, (size_t)resultado);
	  }

	  printf("MERGE SORT ITERATIVO\n");
    
    gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
	  numComp = mergeSortSR(vetor, tam);
	  printf("Num. comparacoes: %ld\n", numComp);

	  resultado = verificarOrdenacao(vetor, tam);
	  if (resultado != -1) {
        printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
        imprimirSecaoVetor(vetor, tam, (size_t)resultado);
	  }
}

void testeQuickSort(int *vetor, size_t tam, bool aleatorio, int *vetorAleatorio) {
    uint64_t numComp = 0;
    ssize_t resultado;

	  printf("QUICK SORT RECURSIVO\n");

    gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
	  numComp = quickSort(vetor, tam);
	  printf("Num. comparacoes: %ld\n", numComp);

	  resultado = verificarOrdenacao(vetor, tam);
	  if (resultado != -1) {
        printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
        imprimirSecaoVetor(vetor, tam, (size_t)resultado);
	  }

	  printf("QUICK SORT ITERATIVO\n");

    gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
	  numComp = quickSortSR(vetor, tam);
	  printf("Num. comparacoes: %ld\n", numComp);

	  resultado = verificarOrdenacao(vetor, tam);
	  if (resultado != -1) {
        printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
        imprimirSecaoVetor(vetor, tam, (size_t)resultado);
	  }
}

void testeHeapSort(int *vetor, size_t tam, bool aleatorio, int *vetorAleatorio) {
    uint64_t numComp = 0;
    ssize_t resultado;

	  printf("HEAP SORT RECURSIVO\n");

	  gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
	  numComp = heapSort(vetor, tam);
	  printf("Num. comparacoes: %ld\n", numComp);

	  resultado = verificarOrdenacao(vetor, tam);
	  if (resultado != -1) {
        printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
        imprimirSecaoVetor(vetor, tam, (size_t)resultado);
	  }

	  printf("HEAP SORT ITERATIVO\n");

	  gerarVetor(vetor, tam, aleatorio, vetorAleatorio);
	  numComp = heapSortSR(vetor, tam);
	  printf("Num. comparacoes: %ld\n", numComp);

	  resultado = verificarOrdenacao(vetor, tam);
	  if (resultado != -1) {
        printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
        imprimirSecaoVetor(vetor, tam, (size_t)resultado);
	  }
}

int main() {
	  char nome[MAX_CHAR];
	  size_t tamVetor = 10000, tamVetorMax = 30000, opcao, aleatorio;
	  int *vetor = NULL, *vetorAleatorio = NULL;

	  getNome(nome);
	  printf("Trabalho de %s\n", nome);
	  printf("GRR %u\n\n", getGRR());

    printf("[0] - automatico\n[1] - manual\n");
    scanf("%ld", &opcao);
    printf("[0] - ordem decrescente\n[1] - aleatorio\n");
    scanf("%ld", &aleatorio);

    if (opcao == 1) {
        printf("TAMANHO VETOR: ");
        scanf("%ld", &tamVetor);
        tamVetorMax = tamVetor;
    }  

    for (; tamVetor <= tamVetorMax; tamVetor += 10000) {
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

        printf("\nTAMANHO DO VETOR: %ld\n\n", tamVetor);
        testeMergeSort(vetor, tamVetor, (bool)aleatorio, vetorAleatorio);
        testeQuickSort(vetor, tamVetor, (bool)aleatorio, vetorAleatorio);
        testeHeapSort(vetor, tamVetor, (bool)aleatorio, vetorAleatorio);
    }

    free(vetorAleatorio);
    free(vetor);

    return 0;
}
