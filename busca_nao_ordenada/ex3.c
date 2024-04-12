/*
busca(vet, a, b, x) {
    int metade;

    if (a > b) return -1;
    
    metade = (a+b+1)/2;
    if (vet[metade] == x) return metade;
    if (vet[metade] < x) {
        return busca(vet, a, metade, x)
    } else {
        return busca(vet, metade, b, x)
    }
}
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int *vet, tam, num, res;

    printf("Tamanho vetor: ");
    scanf("%d", &tam);

    printf("Numero procurado: ");
    scanf("%d", &num);

    vet = calloc(tam, sizeof(int));

    for (int i = 0; i < tam; i++) {
        vet[i] = i+1;
    }

    res = busca(vet, 0, tam-1, num);

    if (res > -1) {
        printf("\n%d encontra-se em %d ([%d])\n", num, res, vet[res]);
    } else {
        printf("\nNão existe\n");
    }

    free(vet);
    return 0;
}

int busca (int *vet, int a, int b, int num) {
    int metade;

    if (a > b) return -1;

    metade = (a + b)/2;
    printf("a: %d | b: %d | metade: %d\n", a, b, metade);

    if (vet[metade] == num) return metade;

    if (vet[metade] > num) {
        busca(vet, a, metade-1, num);
    } else {
        busca(vet, metade+1, b, num);
    }
}