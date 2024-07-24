#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

//trocar elementos num vetor localizados em a e b
void trocarElemento(int vetor[], size_t a, size_t b);

//troca todos os elementos do vetorOrigem para vetorDest
void copiarVetor(int vetorDest[], int vetorOrigem[], size_t a, size_t b);

//mostra na tela todos os elementos do vetor
void imprimirVetor(int vetor[], size_t tam);

//mostra na tela 2 elementos antes e depois (se existirem) do elemento dado no vetor
void imprimirSecaoVetor(int vetor[], size_t tam, size_t elem);

//gera um vetor com elementos ordenados de forma não crescente ou copia de um vetor aleatorio
void gerarVetor(int vetor[], size_t tam, bool aleatorio, int vetorAleatorio[]);

//gera um vetor aleatorio
void gerarVetorAleatorio(int vetor[], size_t tam);

//verificar ordenacao do vetor quando ele foi gerado de forma aleatoria
//retorno: -1 se estiver ordenado ou indice do elemento fora de lugar
ssize_t verificarOrdenacaoAleatorio(int vetor[], size_t tam);

//verifciar ordenacao do vetor quando ele foi gerado pela funcao gerarVetor de forma ao aleatoria
//retorno: -1 se estiver ordenado ou indice do elemento fora de lugar
ssize_t verificarOrdenacaoNormal(int vetor[], size_t tam);

#endif  // AUXILIAR_H_
