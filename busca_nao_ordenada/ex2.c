/*
 * funcao palindromo (v, a, b) {
 *	if (a > b) return sim;
 *	if (vet[a] == vet[b]) return palindromo(v, a+1, b-1);
 *	return nao;
 * }
 * */

#include <stdio.h>
#include <stdlib.h> 

int main () {
    int tam, metade, *vet;

    scanf("%d", &tam);

    if (tam % 2 == 1) {
        metade = tam/2 + 1;
    } else {
        metade = tam/2;
    }

    vet = calloc(tam, sizeof(int)); 

	for (int i = 0; i < metade; i++) {
		vet[i] = i + 1;
	    vet[tam - i - 1] = i + 1;
	}

	for (int i = 0; i < tam; i++) {
		printf("[%d] ", vet[i]);
	}

	palindromoSimNao(vet, 0, tam - 1);

    free(vet);
	return 0;
}	

void palindromoSimNao (int *vet, int a, int b) {
	int resposta = verificarPalindromo(vet, a, b);

	if (resposta) {
		printf("\nSIM\n");
	} else {
		printf("\nNAO\n");
	}
}

int verificarPalindromo (int *vet, int a, int b) {
	if (a > b) return 1;
	if (vet[a] == vet[b]) return verificarPalindromo(vet, a+1, b-1);
	return 0;
}

/*
C(vet, a, b) = {
    0, se a > b ou vet[a] != vet[b]
    1 + C(vet, a+1, b-1), se a <= b e vet[a] == vet[b]
}

C+ = {
    0, se a > b
    1 + C(vet, a+1, b-1) se a <= b e vet[a] == vet[b]
}
C+ = n/2
C- = 0
*/