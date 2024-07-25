#include "pilha.h"

#include <stdlib.h>
#include <stdio.h>

pilha_t *criarPilha() {
    const size_t TAM_PILHA = 1048576;

    pilha_t *pilha = (pilha_t*) malloc(1 * sizeof(pilha_t));
    if (pilha == NULL) {
        printf("Impossivel alocar a pilha.\n");
        return NULL;
    }
    
    pilha->elementos = (int*) malloc(TAM_PILHA * sizeof(int));

    if (pilha->elementos == NULL) {
        printf("Impossivel alocar a pilha.\n");
        return NULL;
    }

    pilha->tamanho = 0;
    pilha->capacidade = TAM_PILHA;

    return pilha;
}

bool aumentarPilha(pilha_t *pilha) {
    int *novosElementos;
    const int NOVO_TAMANHO = pilha->capacidade + 100000; 

    novosElementos = (int*) realloc(pilha->elementos, NOVO_TAMANHO * sizeof(int));
    if (novosElementos == NULL) {
        return false;
    }
    
    pilha->elementos = novosElementos;
    pilha->capacidade = NOVO_TAMANHO;

    return true;
}

void destruirPilha(pilha_t *pilha) {
    free(pilha->elementos);
    free(pilha);
}

void empilhar(pilha_t *pilha, int elem) {
    if (pilhaCheia(pilha)) {
        if (!aumentarPilha(pilha)) {
            printf("Impossivel aumentar pilha.\n");
            return; 
        }
    }
    
    pilha->elementos[pilha->tamanho++] = elem;
}

int desempilhar(pilha_t *pilha) {
    if (pilhaVazia(pilha)) return -1;

    pilha->tamanho--;

    return pilha->elementos[pilha->tamanho];
}

bool pilhaVazia(pilha_t *pilha) {
    return pilha->tamanho == 0;
}

bool pilhaCheia(pilha_t *pilha) {
    return pilha->tamanho == pilha->capacidade;
}

size_t tamanhoPilha(pilha_t *pilha) {
    return pilha->tamanho;
}

void imprimirPilha(pilha_t *pilha) {
    printf("PILHA:\n");
    for (int i = pilha->tamanho - 1; i >= 0; i--) {
        printf("%d\n", pilha->elementos[i]);
    }
}
