#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

int main()
{
  // teste pilha
  pilha_t *p;
  int i, status, valor;
  int TAMANHO = 10;

  // cria uma pilha para até 10 elementos
  p = criarPilha(TAMANHO);

  // empilha valores
  for (i = 0; i < TAMANHO + 2; i++)
  {
    valor = 10 * i;
    printf("Vou empilhar %d\n", valor);
    status = push(p, valor);
    if (status < 0)
      printf("Pilha cheia!\n");
    imprimirPilha(p);
    topoPilha(p, &valor);
    printf("%ld elementos, topo = %d\n\n", tamanhoPilha(p), valor);
  }

  // desempilha e imprime valores
  while (!pilhaVazia(p))
  {
    imprimirPilha(p);
    topoPilha(p, &valor);
    printf("%ld elementos, topo = %d\n", tamanhoPilha(p), valor);
    pop(p, &valor);
    printf("Desempilhei %d\n\n", valor);
  }
  printf("Pilha vazia!\n");

  // destroi a pilha
  destruirPilha(p);

  return 0;
}
