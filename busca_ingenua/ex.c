/*função buscaSequencial (x,v,a,b)
entrada: vetor v ordenado, indexado por [a..b], com a ≤ b, e um valor x a ser buscado
saída: o menor m ∈ [a-1..b], tal que x < v[i] ∀i ∈ [m+1..b]
se a > b
retorne a-1
se v[b] ≤ x
retorne b
retorne buscaSequencial(x,v,a,b-1)
*/

#include <stdio.h>

int main () {
	int vet[10], tam = 10, num;

	scanf("%d", &num);

	for (int i = 0; i < tam; i++) {
		vet[i] = i+1;
	}

	buscarNum(num, vet, tam);

	return 0;
}

void buscarNum(int num, int *vet, int tam) {
	int res = busca_ingenua(num, vet, 0, tam-1);

	if (vet[res] == num) {
		printf("%d esta no vetor\n", num);
	} else {
		printf("%d nao esta no vetor\n", num);
	}
}

int busca_ingenua(int num, int *vet, int a, int b) {
	if (a > b) {
		return a - 1;
	}

	if (vet[b] <= num) {
		return b;
	}

	return busca_ingenua(num, vet, a, b-1);
}
