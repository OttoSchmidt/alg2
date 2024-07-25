//==========================================
// Author: Paulo R. Lisboa de Almeida
// Date:   7 Feb 2023
//==========================================

#include <stdio.h>
#include <stdbool.h>

#define M 20
#define N 18
#define PAREDE 64
#define PASSAGEM 32
#define PASSOU 46

void imprimirLabirinto(int labirinto[][N]);
void lerLabirinto(int labirinto[][N], int *linInicio, int *colInicio, int *linFim, int *colFim);
void copiarLabirinto(int destino[][N], int origem[][N]);
void resolverLabirinto(int labirinto[][N], int linha, int coluna, int linFim, int colFim, int movimentos, int *menorMovimentos, bool *resolvido, int resposta[][N]);

int main () {
	int labirinto[M][N], melhorResposta[M][N];
	int linhaInicio, colInicio, linhaFim, colFim, quantMovimentos = 0;
	bool resolvido = false;
	lerLabirinto(labirinto, &linhaInicio, &colInicio, &linhaFim, &colFim);
	resolverLabirinto(labirinto, linhaInicio, colInicio, linhaFim, colFim, 0, &quantMovimentos, &resolvido, melhorResposta);

	if (!resolvido) {
		printf("Labirinto sem solucao\n");
		imprimirLabirinto(labirinto);
	} else {
		printf("\nMenor quantidade de movimentos: %d\n\n", quantMovimentos);
		imprimirLabirinto(melhorResposta);
	}

	return 0;
}

void lerLabirinto(int labirinto[][N], int *linInicio, int *colInicio, int *linFim, int *colFim) {
	scanf("%d %d %d %d", linInicio, colInicio, linFim, colFim);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &labirinto[i][j]);
}

void imprimirLabirinto(int labirinto[][N]) {
	for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) 
			printf("%c", labirinto[i][j]);
		printf("\n");
	}
}

void copiarLabirinto(int destino[][N], int origem[][N]) {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			destino[i][j] = origem[i][j];
}

void resolverLabirinto(int labirinto[][N], int linha, int coluna, int linFim, int colFim, int movimentos, int *menorMovimentos, bool *resolvido, int resposta[][N]) {
    labirinto[linha][coluna] = PASSOU;	

    // verificar se chegou no final, se sim, salvar
    if (linha == linFim && coluna == colFim) {
        if (!(*resolvido) || (movimentos < *menorMovimentos)) {
            *menorMovimentos = movimentos;
			copiarLabirinto(resposta, labirinto);
		}

		*resolvido = true;
        labirinto[linha][coluna] = PASSAGEM;
        return;
	}

	// verificar possiveis caminhos
	if (linha - 1 >= 0 && labirinto[linha - 1][coluna] == PASSAGEM) {
	    resolverLabirinto(labirinto, linha - 1, coluna, linFim, colFim, ++movimentos, menorMovimentos, resolvido, resposta);
	}
	if (coluna + 1 < N && labirinto[linha][coluna + 1] == PASSAGEM) {
		resolverLabirinto(labirinto, linha, coluna + 1, linFim, colFim, ++movimentos, menorMovimentos, resolvido, resposta);
	}
	if (linha + 1 < M && labirinto[linha + 1][coluna] == PASSAGEM) {
		resolverLabirinto(labirinto, linha + 1, coluna, linFim, colFim, ++movimentos, menorMovimentos, resolvido, resposta);
	}
	if (coluna - 1 >= 0 && labirinto[linha][coluna - 1] == PASSAGEM) {
		resolverLabirinto(labirinto, linha, coluna - 1, linFim, colFim, ++movimentos, menorMovimentos, resolvido, resposta);
	}

    //sem saida, portanto deve retornar por onde veio
    labirinto[linha][coluna] = PASSAGEM;
    movimentos--;
}
