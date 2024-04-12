/*
funcao buscaMenorMaior (vet, a, b, x, y) {
    if (a > b) return nao;
    if (vet[a] > x && vet[a] < y) return a
    return buscaMenorMaior(vet, a+1, b, x, y)
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

int main () {
    srand(time(NULL));
    int vet[TAM], x = 3, y = 5;

    for (int i = 0; i < TAM; i++) {
        vet[i] = rand() % 10;
        printf("[%d] ", vet[i]);
    }

    printf("\n%d\n", buscaMenorMaior(vet, 0, TAM-1, x, y));

    return 0;
}

int buscaMenorMaior(int *vet, int a, int b, int x, int y) {
    if (a > b) return -1;
    if (vet[a] > x && vet[a] < y) return a;
    return buscaMenorMaior(vet, a+1, b, x, y);
}

/*
C(vet, a, b, x, y) = {
    0, se a > b
    3, se vet[a] > x e vet[a] < y e a <= b
    3 + C(vet, a+1, b, x, y), se vet[a] <=x ou vet[a] >= y e a <= b
}

C+ (n) = 3n
C- (n) = 3
*/