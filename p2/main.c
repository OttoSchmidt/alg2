#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("[%d] ", v[i]);
    printf("\n");
}

void backtrack(int v[], int n, int i, int k) {
    if (i == n) {
        imprimirVetor(v, n);
        return;
    }

    for (int j = 0; j <= k; j++) {
        v[i] = j;
        backtrack(v, n, i+1, k);
    }
}

int main(int argc, char *argv[]) {
    int *v, n, k;

    printf("Tamanho vetor: ");
    scanf("%d", &n);

    printf("Numero k: ");
    scanf("%d", &k);

    v = (int*) malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Impossivel alocar vetor\n");
        return 0;
    }

    backtrack(v, n, 0, k);

    return 0;
}
