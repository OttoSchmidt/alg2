#include "pilha.h"

#include <stdlib.h>
#include <stdio.h>

pilha_t *criarPilha(size_t capacidade)
{
    pilha_t *pilha = (pilha_t *)malloc(1 * sizeof(pilha_t));

    pilha->elementos = (int *)malloc(capacidade * sizeof(int));

    if (pilha->elementos == NULL)
        return NULL;

    pilha->tamanho = 0;
    pilha->capacidade = capacidade;

    return pilha;
}

void destruirPilha(pilha_t *pilha)
{
    free(pilha->elementos);
    free(pilha);
}

size_t push(pilha_t *pilha, int elem)
{
    if (pilhaCheia(pilha))
        return -1;

    pilha->elementos[pilha->tamanho] = elem;
    pilha->tamanho++;

    return pilha->tamanho;
}

size_t pop(pilha_t *pilha, int *elem)
{
    if (pilhaVazia(pilha))
        return -1;

    *elem = pilha->elementos[pilha->tamanho - 1];
    pilha->tamanho--;

    return pilha->tamanho;
}

size_t topoPilha(pilha_t *pilha, int *elem)
{
    if (pilhaVazia(pilha))
        return -1;

    *elem = pilha->elementos[pilha->tamanho - 1];

    return pilha->tamanho;
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

// Imprime o conteúdo da pilha, do topo à base (opcional, mas útil para testes)
void imprimirPilha(pilha_t *pilha)
{
    printf("PILHA:\n");
    for (int i = pilha->tamanho - 1; i >= 0; i--)
    {
        printf("%d\n", pilha->elementos[i]);
    }
}