#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void imprimirVetor (int *v, size_t tam) {
	for (size_t i = 0; i < tam; i++) {
		printf("[%d] ", v[i]);	
	}
	printf("\n");
}

void trocar (int *v, size_t a, size_t b) {
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

size_t separar(int *v, size_t a, size_t b, uint64_t *numComparacoes) {
	int pivo = v[b];
	size_t m = a;

	for (size_t i = a; i < b; i++) {
		if (v[i] <= pivo) {
			trocar(v, m, i);
			m++;
		}
		(*numComparacoes)++;
	}

	trocar(v, m, b);
	
	return m;
}

void quickSort (int *v, ssize_t a, ssize_t b, uint64_t *numComparacoes) {
	if (a >= b) return;
	
	size_t m = separar(v, a, b, numComparacoes);	
	quickSort(v, a, m-1, numComparacoes);
	quickSort(v, m+1, b, numComparacoes);
}

int main () {
    int *v, opcao;
	size_t tam;
	uint64_t numComparacoes = 0;

    scanf("%ld", &tam);
	printf("[1] - iniciar vetor automaticamente\n[2] - iniciar vetor manualmente\n");
	scanf("%d", &opcao);

	//gerar vetor
	v = (int*) malloc(tam * sizeof(int));

	if (opcao == 1) {
		//gerar numeros do vetor automaticamente
		for (size_t i = 0; i < tam; i++) {
			v[i] = i;	
		}
	} else {
		//gerar numeros do vetor manualmente
		for (size_t i = 0; i < tam; i++) {
			scanf("%d", &v[i]);
		}
	}

	quickSort(v, 0, tam - 1, &numComparacoes);

	//imprimir dados
	printf("comparacoes: %ld\n", numComparacoes);
	imprimirVetor(v, tam);

	free(v);

    return 0;
}
