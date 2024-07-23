#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

//trocar elementos num vetor localizados em i e j
void trocarElemento(int vetor[], size_t i, size_t j);

//troca todos os elementos do vetorOrigem para vetorDest
void trocarElementosVetor(int vetorDest[], int vetorOrigem[], size_t a, size_t b);

//mostra na tela todos os elementos do vetor
void imprimirVetor(int vetor[], size_t tam);

//mostra na tela 2 elementos antes e depois (se existirem) do elemento dado no vetor
void imprimirSecaoVetor(int vetor[], size_t tam, size_t elem);

//gera um vetor com elementos ordenados de forma não crescente ou copia de um vetor aleatorio
void gerarVetor(int vetor[], size_t tam, bool aleatorio, int vetorAleatorio[]);

//gera um vetor aleatorio
void gerarVetorAleatorio(int vetor[], size_t tam);

//verificar ordenacao do vetor
//retorno: -1 se estiver ordenado ou indice do elemento fora de lugar
ssize_t verificarOrdenacao(int vetor[], size_t tam);

#endif  // AUXILIAR_H_
