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
void resolverLabirinto(int labirinto[][N], int linha, int coluna, int linFim, int colFim, bool resolvido, int movimentos, int *menorMovimentos, int resposta[][N]);

int main()
{
	int labirinto[M][N];
	int resposta[M][N];
	int linhaInicio, colInicio, linhaFim, colFim, quantMovimentos = 0;
	lerLabirinto(labirinto, &linhaInicio, &colInicio, &linhaFim, &colFim);
	imprimirLabirinto(labirinto);
	resolverLabirinto(labirinto, linhaInicio, colInicio, linhaFim, colFim, false, 0, &quantMovimentos, resposta);

	printf("Quantidade de passos: %d\n", quantMovimentos);
	imprimirLabirinto(resposta);

	return 0;
}

void lerLabirinto(int labirinto[][N], int *linInicio, int *colInicio, int *linFim, int *colFim)
{
	scanf("%d %d %d %d", linInicio, colInicio, linFim, colFim);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &labirinto[i][j]);
}

void imprimirLabirinto(int labirinto[][N])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%c", labirinto[i][j]);
		}
		printf("\n");
	}
}

void copiarLabirinto(int destino[][N], int origem[][N])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			destino[i][j] = origem[i][j];
		}
	}
}

void resolverLabirinto(int labirinto[][N], int linha, int coluna, int linFim, int colFim, bool resolvido, int movimentos, int *menorMovimentos, int resposta[][N])
{
	bool caminho[4] = {false}; // 0 - cima, 1 - direita, 2 - baixo, 3 - esquerda
	int quantCaminhos = 0;

	if (linha == linFim && coluna == colFim)
	{
		if (resolvido && movimentos < *menorMovimentos)
		{
			*menorMovimentos = movimentos;
			copiarLabirinto(resposta, labirinto);
			return;
		}

		imprimirLabirinto(labirinto);

		resolvido = true;
		return;
	}

	// verificar possiveis caminhos
	if (linha - 1 >= 0 && labirinto[linha - 1][coluna] == PASSAGEM)
	{
		caminho[0] = true;
		quantCaminhos++;
	}
	if (coluna + 1 < N && labirinto[linha][coluna + 1] == PASSAGEM)
	{
		caminho[1] = true;
		quantCaminhos++;
	}
	if (linha + 1 < M && labirinto[linha + 1][coluna] == PASSAGEM)
	{
		caminho[2] = true;
		quantCaminhos++;
	}
	if (coluna - 1 >= 0 && labirinto[linha][coluna - 1] == PASSAGEM)
	{
		caminho[3] = true;
		quantCaminhos++;
	}

	// retornar sem saida
	if (quantCaminhos == 0)
		return;

	// explorar caminhos
	if (quantCaminhos >= 1)
	{
		if (caminho[0])
		{
			labirinto[linha - 1][coluna] = PASSOU;
			movimentos++;
			resolverLabirinto(labirinto, linha - 1, coluna, linFim, colFim, resolvido, movimentos, menorMovimentos, resposta);
			labirinto[linha - 1][coluna] = PASSAGEM;
			movimentos--;
		}
		if (caminho[1])
		{
			labirinto[linha][coluna + 1] = PASSOU;
			movimentos++;
			resolverLabirinto(labirinto, linha, coluna + 1, linFim, colFim, resolvido, movimentos, menorMovimentos, resposta);
			labirinto[linha][coluna + 1] = PASSAGEM;
			movimentos--;
		}
		if (caminho[2])
		{
			labirinto[linha + 1][coluna] = PASSOU;
			movimentos++;
			resolverLabirinto(labirinto, linha + 1, coluna, linFim, colFim, resolvido, movimentos, menorMovimentos, resposta);
			labirinto[linha + 1][coluna] = PASSAGEM;
			movimentos--;
		}
		if (caminho[3])
		{
			labirinto[linha][coluna - 1] = PASSOU;
			movimentos++;
			resolverLabirinto(labirinto, linha, coluna - 1, linFim, colFim, resolvido, movimentos, menorMovimentos, resposta);
			labirinto[linha][coluna - 1] = PASSAGEM;
			movimentos--;
		}
	}
}