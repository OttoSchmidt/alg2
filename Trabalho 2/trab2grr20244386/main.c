#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"
#include "auxiliar.h"

void testeMergeSort(int *vetor, size_t tam)
{
	uint64_t numComp = 0;
	ssize_t resultado;

	printf("MERGE SORT RECURSIVO\n");

	gerarOrdemNaoCrescente(vetor, tam);
	numComp = mergeSort(vetor, tam);
	printf("Num. comparacoes: %ld\n", numComp);

	resultado = verificarOrdenacao(vetor, tam);
	if (resultado != -1)
	{
		printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
		imprimirSecaoVetor(vetor, tam, (size_t)resultado);
	}
}

void testeQuickSort(int *vetor, size_t tam)
{
	uint64_t numComp = 0;
	ssize_t resultado;

	printf("QUICK SORT RECURSIVO\n");

	gerarOrdemNaoCrescente(vetor, tam);
	numComp = quickSort(vetor, tam);
	printf("Num. comparacoes: %ld\n", numComp);

	resultado = verificarOrdenacao(vetor, tam);
	if (resultado != -1)
	{
		printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
		imprimirSecaoVetor(vetor, tam, (size_t)resultado);
	}

	printf("QUICK SORT ITERATIVO\n");

	gerarOrdemNaoCrescente(vetor, tam);
	numComp = quickSortSR(vetor, tam);
	printf("Num. comparacoes: %ld\n", numComp);

	resultado = verificarOrdenacao(vetor, tam);
	if (resultado != -1)
	{
		printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
		imprimirSecaoVetor(vetor, tam, (size_t)resultado);
	}
}

void testeHeapSort(int *vetor, size_t tam)
{
	uint64_t numComp = 0;
	ssize_t resultado;

	printf("HEAP SORT RECURSIVO\n");

	gerarOrdemNaoCrescente(vetor, tam);
	numComp = heapSort(vetor, tam);
	printf("Num. comparacoes: %ld\n", numComp);

	resultado = verificarOrdenacao(vetor, tam);
	if (resultado != -1)
	{
		printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
		imprimirSecaoVetor(vetor, tam, (size_t)resultado);
	}

	printf("HEAP SORT ITERATIVO\n");

	gerarOrdemNaoCrescente(vetor, tam);
	numComp = heapSortSR(vetor, tam);
	printf("Num. comparacoes: %ld\n", numComp);

	resultado = verificarOrdenacao(vetor, tam);
	if (resultado != -1)
	{
		printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
		imprimirSecaoVetor(vetor, tam, (size_t)resultado);
		imprimirVetor(vetor, tam);
	}
}

int main()
{
	char nome[MAX_CHAR];

	size_t tamVetor;
	int *vetor;

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n\n", getGRR());

	printf("Insira o tamanho do vetor inicial: ");
	scanf("%ld", &tamVetor);
	printf("\n");

	vetor = (int *)malloc(tamVetor * sizeof(int));
	if (vetor == NULL)
	{
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	testeMergeSort(vetor, tamVetor);
	testeQuickSort(vetor, tamVetor);
	testeHeapSort(vetor, tamVetor);

	free(vetor);

	return 0;
}
