#include <stdio.h>
#include <stdlib.h>

void copiarVetor (int *v, int *u, size_t a, size_t b) {
	for (size_t i = 0; i <= b-a; i++) {
		v[i+a] = u[i];
	}
}

int verificarOrdemVetor (int *v, size_t n) {
	for (size_t i = 0; i < n-1; i++) {
		if (v[i] > v[i+1]) {
			return 0;
		}	
	}

	return 1;
}

void imprimirVetor (int *v, size_t n) {
	for (size_t i = 0; i < n; i++) {
		printf("[%d] ", v[i]);
	}
	printf("\n");
}

void merge (int *v, size_t a, size_t m, size_t b) {
	size_t i, j, n;
	int *u;

	if (a >= b) {
		return;
	}
	
	n = b - a + 1;
	i = a;
	j = m + 1;

	u = (int*) malloc(n * sizeof(int));

	for (size_t k = 0; k < n; k++) {
		if (i > m) {
			u[k] = v[j];
			j++;
		} else if (j > b) {
			u[k] = v[i];
			i++;
		} else if (v[i] < v[j]) {
			u[k] = v[i];
			i++;
		} else {
			u[k] = v[j];
			j++;
		}
	}

	copiarVetor(v, u, a, b);
	free(u);
}

void mergeSort (int *v, size_t a, size_t b) {
	size_t m;
	
	if (a >= b) {
		return;
	}
	
	m = (a + b)/2;

	mergeSort(v, a, m);
	mergeSort(v, m+1, b);
	merge(v, a, m, b);
}

int main () {
	int *v;
	size_t n;

	printf("Informe o tamanho do vetor: ");
	scanf("%ld", &n);

	v = (int*) malloc(n * sizeof(int));
	
	for (size_t i = 0; i < n; i++) {
		v[i] = n-i;
	}
	
	mergeSort(v, 0, n-1);

	if (!verificarOrdemVetor(v, n)) {
		printf("Vetor nao esta ordenado\n");
	}

	free(v);

	return 0;
}
