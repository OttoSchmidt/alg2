#include "pilha.h"

#include <stdlib.h>
#include <stdio.h>

pilha_t* criarPilha (int capacidade) {
    pilha_t *pilha = (pilha_t*) malloc(1 * sizeof(pilha_t));    
    
    pilha->elementos = (int*) malloc(capacidade * sizeof(int));

    if (pilha->elementos == NULL) return NULL;

    pilha->tamanho = 0;
    pilha->capacidade = capacidade;

    return pilha;
}

void destruirPilha (pilha_t* pilha) {
    free(pilha->elementos);
    free(pilha);
}

size_t push (pilha_t* pilha, int elem) {
    if (pilha_cheia(pilha)) return -1;

    pilha->elementos[pilha->tamanho] = elem;
    pilha->tamanho++;

    return pilha->tamanho;
}

size_t pop (pilha_t* pilha, int *elem) {
    if (pilha_vazia(pilha)) return -1;

    *elem = pilha->elementos[pilha->tamanho-1];
    pilha->tamanho--;

    return pilha->tamanho;
}

size_t pilha_topo (pilha_t* pilha, int *elem) {
    if (pilha_vazia(pilha)) return -1;

    *elem = pilha->elementos[pilha->tamanho-1];

    return pilha->tamanho;
}

bool pilha_vazia (pilha_t* pilha) {
    return pilha->tamanho == 0;
}

bool pilha_cheia (pilha_t* pilha) {
    return pilha->tamanho == pilha->capacidade;
}

size_t pilha_tamanho (pilha_t* pilha) {
    return pilha->tamanho;
}

// Imprime o conteúdo da pilha, do topo à base (opcional, mas útil para testes)
void pilha_imprime (pilha_t* pilha) {
    printf("PILHA:\n");
    for (int i = pilha->tamanho-1; i >= 0; i--) {
        printf("%d\n", pilha->elementos[i]);
    }
}