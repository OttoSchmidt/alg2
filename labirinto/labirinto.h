#ifndef _LABIRINTO_H
#define _LABIRINTO_H

#include <stdbool.h>

// Alocar memoria para labirinto[m][n]
void gerarLabirinto(int ***labirinto, int m, int n);

// Imprimir labirinto
void imprimirLabirinto(int **labirinto);

// Ler labirinto e passar para uma matriz
void lerLabirinto(int **labirinto, int *linInicio, int *colInicio, int *linFim, int *colFim);

// Copiar os dados de um labirinto origem para destino
void copiarLabirinto(int **destino, int **origem);

// Liberar memoria para labirinto[m][n]
void excluirLabirinto(int **labirinto, int m);

// Resolver o labirinto usando recursao
void resolverLabirinto(int **labirinto, int linha, int coluna, int linFim, int colFim, int movimentos, int *menorMovimentos, bool *resolvido, int **resposta);

// Resolver o labirinto sem recursao
    void resolverLabirintoSR(int **labirinto, int linha, int coluna, int linFim, int colFim, int movimentos, int *menorMovimentos, bool *resolvido, int **resposta);

#endif 
