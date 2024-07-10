#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

void testeMerge() {}

void testeQuick() {}

void testeHeap() {}

int main() {
    /*char nome[MAX_CHAR];
    int numComp;

    int tamVetor = 3;
    int *vetor = (int*) malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    vetor[0] = 1;
    vetor[1] = 10;
    vetor[2] = 12;

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    numComp = mergeSort(vetor, 3);
    printf("NumComp: %d\n", numComp);
    numComp = quickSort(vetor, 3);
    printf("NumComp: %d\n", numComp);
    numComp = heapSort(vetor, 3);
    printf("NumComp: %d\n", numComp);
    numComp = mergeSortSR(vetor, 3);
    printf("NumComp: %d\n", numComp);
    numComp = quickSortSR(vetor, 3);
    printf("NumComp: %d\n", numComp);
    numComp = heapSortSR(vetor, 3);
    printf("NumComp: %d\n", numComp);

    free(vetor);*/

    //teste pilha
  pilha_t *p ;
  int i, status, valor ;

  // cria uma pilha para até 10 elementos
  p = pilha_cria (TAMANHO) ;

  // empilha valores
  for (i = 0 ; i < TAMANHO + 2; i++)
  {
    valor = 10 * i ;
    printf ("Vou empilhar %d\n", valor) ;
    status = push (p, valor) ;
    if (status < 0)
      printf ("Pilha cheia!\n") ;
    pilha_imprime (p) ;
    pilha_topo (p, &valor) ;
    printf ("%d elementos, topo = %d\n\n", pilha_tamanho (p), valor) ;
  }

  // desempilha e imprime valores
  while (! pilha_vazia (p))
  {
    pilha_imprime (p) ;
    pilha_topo (p, &valor) ;
    printf ("%d elementos, topo = %d\n", pilha_tamanho (p), valor) ;
    pop (p, &valor) ;
    printf ("Desempilhei %d\n\n", valor) ;
  }
  printf ("Pilha vazia!\n") ;

  // destroi a pilha
  p = pilha_destroi (p);


    return 0;
}
