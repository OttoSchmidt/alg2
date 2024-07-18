#include "pilha.h"

#include <stdlib.h>
#include <stdio.h>

pilha_t *criarPilha(size_t capacidade)
{
    pilha_t *pilha = (pilha_t *)malloc(1 * sizeof(pilha_t));

    pilha->elementos = (int *)malloc(capacidade * sizeof(int));

    if (pilha->elementos == NULL)
    {
        printf("Erro ao alocar memória para a pilha.\n");
        return NULL;
    }

    pilha->tamanho = 0;
    pilha->capacidade = capacidade;

    return pilha;
}

void destruirPilha(pilha_t *pilha)
{
    free(pilha->elementos);
    free(pilha);
}

void empilhar(pilha_t *pilha, int elem)
{
    if (pilhaCheia(pilha))
        return;

    pilha->elementos[pilha->tamanho] = elem;
    pilha->tamanho++;
}

int desempilhar(pilha_t *pilha)
{
    if (pilhaVazia(pilha))
        return -1;

    pilha->tamanho--;

    return pilha->elementos[pilha->tamanho];
}

bool pilhaVazia(pilha_t *pilha)
{
    return pilha->tamanho == 0;
}

bool pilhaCheia(pilha_t *pilha)
{
    return pilha->tamanho == pilha->capacidade;
}

size_t tamanhoPilha(pilha_t *pilha)
{
    return pilha->tamanho;
}

void imprimirPilha(pilha_t *pilha)
{
    printf("PILHA:\n");
    for (int i = pilha->tamanho - 1; i >= 0; i--)
    {
        printf("%d\n", pilha->elementos[i]);
    }
}