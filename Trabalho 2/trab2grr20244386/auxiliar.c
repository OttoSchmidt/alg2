#include "auxiliar.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void trocarElemento(int *vetor, size_t i, size_t j) {
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

void trocarElementosVetor(int vetorDest[], int vetorOrigem[], size_t a, size_t b) {
    for (size_t i = a; i <= b; i++) {
        vetorDest[i] = vetorOrigem[i];
    }
}

void imprimirVetor(int vetor[], size_t tam) {
    for (size_t i = 0; i < tam; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

void imprimirSecaoVetor(int vetor[], size_t tam, size_t elem) {
    int elemDeslocado;

    for (int i = -2; i < 3; i++) {
        elemDeslocado = elem + i;
        if (elemDeslocado >= 0 && elemDeslocado < (int)tam) {
            printf("[%d] ", vetor[elemDeslocado]);
        }
    }
    printf("\n");
}

void gerarVetor(int vetor[], size_t tam, bool aleatorio, int vetorAleatorio[]) {
  if (aleatorio) {
    trocarElementosVetor(vetor, vetorAleatorio, 0, tam-1);
  } else {
    for (size_t i = 0; i < tam; i++) {
      vetor[i] = tam - i;
    }
  }
}

void gerarVetorAleatorio(int vetor[], size_t tam) {
  srand(time(NULL));

  for (size_t i = 0; i < tam; i++) {
    vetor[i] = rand() % tam;
  }
}

ssize_t verificarOrdenacao(int vetor[], size_t tam) {
    for (size_t i = 0; i < tam-1; i++) {
        if (vetor[i] > vetor[i+1]) return i;
    }

    return -1;
}
