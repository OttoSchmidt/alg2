#ifndef _PILHA_H
#define _PILHA_H

#include <stddef.h>
#include <sys/types.h>
#include <stdbool.h>

// estrutura da pilha de inteiros
typedef struct
{
  int *elementos;
  size_t capacidade;
  size_t tamanho;
} pilha_t;

// Cria uma pilha vazia de inteiros com a capacidade informada
// Retorno: ponteiro p/ a pilha ou NULL se falhar
pilha_t *criarPilha(size_t capacidade);

// Remove todos os elementos da pilha, libera espaço
void destruirPilha(pilha_t *pilha);

// Insere o elemento no topo da pilha (politica LIFO)
// Retorno: número de elementos na pilha após a operação ou -1 se falhar
size_t push(pilha_t *pilha, int elem);

// Retira o elemento do topo da pilha (politica LIFO) e o devolve
// Retorno: número de elementos na pilha após a operação ou -1 se falhar
size_t pop(pilha_t *pilha, int *elem);

// devolve o elemento no topo da pilha, sem removê-lo
// Retorno: número de elementos na pilha após a operação ou -1 se falhar
size_t topoPilha(pilha_t *pilha, int *elem);

// Testa se a pilha está vazia
// Retorno: 1 se a pilha está vazia ou 0 caso contrário
bool pilhaVazia(pilha_t *pilha);

// Testa se a pilha está cheia
// Retorno: 1 se a pilha está cheia ou 0 caso contrário
bool pilhaCheia(pilha_t *pilha);

// Informa o tamanho da pilha (o número de elementos presentes nela)
// Retorno: número de elementos na pilha
size_t tamanhoPilha(pilha_t *pilha);

// Imprime o conteúdo da pilha, do topo à base (opcional, mas útil para testes)
void imprimirPilha(pilha_t *pilha);

#endif
