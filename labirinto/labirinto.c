#include "labirinto.h"
#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 20
#define N 18
#define PAREDE 64
#define PASSAGEM 32
#define PASSOU 46

void gerarLabirinto(int ***labirinto, int m, int n) {
    *labirinto = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        *((*labirinto)+i) = (int*) malloc(n * sizeof(int));
    }
}

void lerLabirinto(int **labirinto, int *linInicio, int *colInicio, int *linFim, int *colFim) {
	scanf("%d %d %d %d", linInicio, colInicio, linFim, colFim);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &labirinto[i][j]);
}

void imprimirLabirinto(int **labirinto) {
	for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) 
			printf("%c", labirinto[i][j]);
		printf("\n");
	}
}

void copiarLabirinto(int **destino, int **origem) {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			destino[i][j] = origem[i][j];
}

void excluirLabirinto(int **labirinto, int m) {
    for (int i = m-1; i >= 0; i--) 
        free(labirinto[i]);
    free(labirinto);
}

void resolverLabirinto(int **labirinto, int linha, int coluna, int linFim, int colFim, int movimentos, int *menorMovimentos, bool *resolvido, int **resposta) {
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
        movimentos--;
	}
	if (coluna + 1 < N && labirinto[linha][coluna + 1] == PASSAGEM) {
		resolverLabirinto(labirinto, linha, coluna + 1, linFim, colFim, ++movimentos, menorMovimentos, resolvido, resposta);
	    movimentos--;
    }
	if (linha + 1 < M && labirinto[linha + 1][coluna] == PASSAGEM) {
		resolverLabirinto(labirinto, linha + 1, coluna, linFim, colFim, ++movimentos, menorMovimentos, resolvido, resposta);
	    movimentos--;
    }
	if (coluna - 1 >= 0 && labirinto[linha][coluna - 1] == PASSAGEM) {
		resolverLabirinto(labirinto, linha, coluna - 1, linFim, colFim, ++movimentos, menorMovimentos, resolvido, resposta);
	    movimentos--;
    }

    //sem saida, portanto deve retornar por onde veio
    labirinto[linha][coluna] = PASSAGEM;
    movimentos--;
}

void resolverLabirintoSR(int **labirinto, int linha, int coluna, int linFim, int colFim, int movimentos, int *menorMovimentos, bool *resolvido, int **resposta) {
    pilha_t *pilha = criarPilha();
    int quantCaminhos = 0;

    empilhar(pilha, linha);
    empilhar(pilha, coluna);
    empilhar(pilha, 0);

    while (!pilhaVazia(pilha)) {
        movimentos = desempilhar(pilha);
        coluna = desempilhar(pilha);
        linha = desempilhar(pilha);
        quantCaminhos = 0;

        //printf("linha: %d | coluna: %d\n", linha, coluna);
        labirinto[linha][coluna] = PASSOU;	

        // verificar se chegou no final, se sim, salvar
        if (linha == linFim && coluna == colFim) {
            printf("teste\n");
            if (!(*resolvido) || (movimentos < *menorMovimentos)) {
                *menorMovimentos = movimentos;
			    copiarLabirinto(resposta, labirinto);
		    }

            *resolvido = true;
            continue;
	    }

	    // verificar possiveis caminhos
	    if (linha - 1 >= 0 && labirinto[linha - 1][coluna] == PASSAGEM) {
            empilhar(pilha, linha-1);
            empilhar(pilha, coluna);
            empilhar(pilha, movimentos+1);
            quantCaminhos++;
        }
	    if (coluna + 1 < N && labirinto[linha][coluna + 1] == PASSAGEM) {
		    empilhar(pilha, linha);
            empilhar(pilha, coluna+1);
            empilhar(pilha, movimentos+1);
	        quantCaminhos++;
        }
	    if (linha + 1 < M && labirinto[linha + 1][coluna] == PASSAGEM) {
	        empilhar(pilha, linha+1);
            empilhar(pilha, coluna);
            empilhar(pilha, movimentos+1);
            quantCaminhos++;
        }
	    if (coluna - 1 >= 0 && labirinto[linha][coluna - 1] == PASSAGEM) {
	        empilhar(pilha, linha);
            empilhar(pilha, coluna-1);
            empilhar(pilha, movimentos+1);
            quantCaminhos++;
        }
    }

    destruirPilha(pilha);
}
