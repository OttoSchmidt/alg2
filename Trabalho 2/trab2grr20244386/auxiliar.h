#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

//verificar a existencia de um valor num vetor na posicao local
int verificarExistencia(int vetor[], int valor, size_t local);

//trocar elementos num vetor localizados em i e j
void trocarElemento(int vetor[], size_t i, size_t j);

//troca todos os elementos do vetorOrigem para vetorDest
void trocarElementosVetor(int vetorDest[], int vetorOrigem[], size_t a, size_t b);

//mostra na tela todos os elementos do vetor
void imprimirVetor(int vetor[], size_t tam);

//verifica a ordem não crescente de um vetor
size_t verificarOrdemNaoCrescente(int vetor[], size_t tam);

#endif  // AUXILIAR_H_