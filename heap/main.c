#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void imprimirVetor (int *v, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void trocar (int *v, int a, int b) {
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

size_t filhoEsquerdo (size_t i) {
    return (i+1) * 2 - 1;
}

size_t filhoDireito (size_t i) {
    return (i+1) * 2;
}

void maxHeapify (int *v, size_t i, size_t n) {
    size_t esq = filhoEsquerdo(i);
    size_t dir = filhoDireito(i);
    size_t maior = i;

    if (esq <= n && v[esq] > v[maior]) {
        maior = esq;
    }
    if (dir <= n && v[dir] > v[maior]) {
        maior = dir;
    }
    if (maior != i) {
        trocar(v, i, maior);
        maxHeapify(v, maior, n);
    }
}

void construirHeap (int *v, size_t n) {
    for (ssize_t i = (n+1)/2; i >= 0; i--) {
        maxHeapify(v, i, n);
    }
}

int main () {
    srand(time(NULL));
    int *v;
    size_t n;
    FILE *file;

    scanf("%zu", &n);

    v = (int*) malloc(n * sizeof(int));

    for (size_t i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }

    imprimirVetor(v, n);

    construirHeap(v, n-1);

    imprimirVetor(v, n);

    file = fopen("heap.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
    } else {
        for (size_t i = 0; i < n; i++) {
            fprintf(file, "%d;", v[i]);
        }

        fclose(file);
    }

    free(v);

    return 0;
}