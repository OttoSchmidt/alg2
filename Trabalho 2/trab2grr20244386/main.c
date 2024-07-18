#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"
#include "auxiliar.h"

void testeMerge() {}

void testeQuick() {}

void testeHeap(int *vetor, size_t tam)
{
	uint64_t numComp = 0;
	ssize_t resultado;

	/*printf("HEAP SORT RECURSIVO\n");

	gerarOrdemNaoCrescente(vetor, tam);
	numComp = heapSort(vetor, tam);
	printf("Num. comparacoes: %ld\n", numComp);

	resultado = verificarOrdenacao(vetor, tam);
	if (resultado != -1)
	{
		printf("ERRO AO ORDERNAR ELEMENTO %ld\n", resultado);
		imprimirSecaoVetor(vetor, tam, (size_t)resultado);
	}*/

	printf("\nHEAP SORT ITERATIVO\n");

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
	else
	{
		printf("TUDO CERTO\n");
	}
}

int main()
{
	char nome[MAX_CHAR];

	size_t tamVetor = 5;
	int *vetor;

	vetor = (int *)malloc(tamVetor * sizeof(int));
	if (vetor == NULL)
	{
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	testeHeap(vetor, tamVetor);

	free(vetor);

	return 0;
}
