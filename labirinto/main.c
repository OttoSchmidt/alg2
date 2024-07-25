#include "labirinto.h"

#include <stdio.h>
#include <stdbool.h>

#define M 20
#define N 18

void verificarResposta(int **labirinto, int **melhorResposta, int quantMovimentos, bool resolvido) {
	if (!resolvido) {
		printf("Labirinto sem solucao\n");
		imprimirLabirinto(labirinto);
	} else {
		printf("\nMenor quantidade de movimentos: %d\n\n", quantMovimentos);
		imprimirLabirinto(melhorResposta);
	}
}

int main () {
	int **modelo, **labirinto, **melhorResposta;
	int linhaInicio, colInicio, linhaFim, colFim, quantMovimentos = 0;
	bool resolvido = false;

    gerarLabirinto(&modelo, M, N);
    gerarLabirinto(&labirinto, M, N);
    gerarLabirinto(&melhorResposta, M, N);

    lerLabirinto(modelo, &linhaInicio, &colInicio, &linhaFim, &colFim);
	
    //COM RECURSAO
    copiarLabirinto(labirinto, modelo);
    resolverLabirinto(labirinto, linhaInicio, colInicio, linhaFim, colFim, 0, &quantMovimentos, &resolvido, melhorResposta);
    verificarResposta(labirinto, melhorResposta, quantMovimentos, resolvido);

    quantMovimentos = 0;
    resolvido = false;

    //SEM RECURSAO
    copiarLabirinto(labirinto, modelo);
    resolverLabirintoSR(labirinto, linhaInicio, colInicio, linhaFim, colFim, 0, &quantMovimentos, &resolvido, melhorResposta);
    verificarResposta(labirinto, melhorResposta, quantMovimentos, resolvido);

    excluirLabirinto(melhorResposta, M);
    excluirLabirinto(labirinto, M);

	return 0;
}
