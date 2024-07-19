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
void resolverLabirinto(int labirinto[][N], int linha, int coluna, int linFim, int colFim);

int main()
{
	int labirinto[M][N];
	int linhaInicio, colInicio, linhaFim, colFim;
	lerLabirinto(labirinto, &linhaInicio, &colInicio, &linhaFim, &colFim);
	imprimirLabirinto(labirinto);
	resolverLabirinto(labirinto, linhaInicio, colInicio, linhaFim, colFim);

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

void resolverLabirinto(int labirinto[][N], int linha, int coluna, int linFim, int colFim)
{
	bool caminho[4] = {false}; // 0 - cima, 1 - direita, 2 - baixo, 3 - esquerda
	int quantCaminhos = 0;

	if (linha == linFim && coluna == colFim)
	{
		printf("RESOLVIDO\n");
		imprimirLabirinto(labirinto);
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

	// explorar
	if (quantCaminhos >= 1)
	{
		if (caminho[0])
		{
			labirinto[linha - 1][coluna] = PASSOU;
			resolverLabirinto(labirinto, linha - 1, coluna, linFim, colFim);
			labirinto[linha - 1][coluna] = PASSAGEM;
		}
		if (caminho[1])
		{
			labirinto[linha][coluna + 1] = PASSOU;
			resolverLabirinto(labirinto, linha, coluna + 1, linFim, colFim);
			labirinto[linha][coluna + 1] = PASSAGEM;
		}
		if (caminho[2])
		{
			labirinto[linha + 1][coluna] = PASSOU;
			resolverLabirinto(labirinto, linha + 1, coluna, linFim, colFim);
			labirinto[linha + 1][coluna] = PASSAGEM;
		}
		if (caminho[3])
		{
			labirinto[linha][coluna - 1] = PASSOU;
			resolverLabirinto(labirinto, linha, coluna - 1, linFim, colFim);
			labirinto[linha][coluna - 1] = PASSAGEM;
		}
	}
}