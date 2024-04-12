#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *v, int a, int b) {
	int temp;
	
	if (a >= b) return;
	
	insertion_sort(v, a, b-1);
	
	for (int i = b; i > a; i--) {
		if (v[i-1] > v[i]) {
			temp = v[i];
			v[i] = v[i-1];
			v[i-1] = temp;
		}
	}

	return;
}

int main () {
	int *vetor, tam, num;

	printf("Tamanho vetor: ");
	scanf("%d", &tam);

	vetor = (int*) calloc(tam, sizeof(int));

	for (int i = 0; i < tam; i++) {
		printf("NUM %d: ", i+1);
		scanf("%d", &vetor[i]);
	}

	insertion_sort(vetor, 0, tam-1);

	printf("\nVETOR ORDENADO:\n");
	for (int i = 0; i < tam; i++) {
		printf("[%d] ", vetor[i]);
	}
	printf("\n");

	free(vetor);
	return 0;
}
