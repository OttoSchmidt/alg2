#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("[%d] ", v[i]);
    printf("\n");
}

void trocar (int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void maxHeapifySR(int heap[], int pos, int tamHeap) {
    int l, r, maior;
    while (true) {
        l = pos * 2 + 1;
        r = pos * 2 + 2;
        maior = pos;

        if (l < tamHeap && heap[l] > heap[maior])
            maior = l;
        if (r < tamHeap && heap[r] > heap[maior])
            maior = r;
        
        if (maior == pos) break;

        trocar(&heap[pos], &heap[maior]);
        pos = maior;
    }
}

void buildHeap(int heap[], int tamHeap) {
    for (int i = tamHeap/2; i >= 0; i--) {
        maxHeapifySR(heap, i, tamHeap);
    }
}

void verificarMaxHeap(int heap[], int pos, int tamHeap, bool *valido) {
    int l = pos * 2 + 1, r = pos * 2 + 2, maior = pos;
    
    if (!(*valido)) return;

    if (l < tamHeap && heap[l] > heap[maior])
        maior = l;
    if (r < tamHeap && heap[r] > heap[maior])
        maior = r;

    if (maior == pos) {
        verificarMaxHeap(heap, l, tamHeap, valido);
        verificarMaxHeap(heap, r, tamHeap, valido);
    } else {
        *valido = false;
    }
}

int main () {
    srand(time(NULL));
    int *heap, tam;
    bool valido = true;

    printf("Tamanho heap: ");
    scanf("%d", &tam);

    heap = (int*) malloc(tam * sizeof(int));
    if (heap == NULL) {
        printf("Nao foi possivel alocar memoria para heap\n");
        return 0;
    }

    for (int i = 0; i < tam; i++) {
        heap[i] = rand() % tam;
    }

    imprimirVetor(heap, tam);

    buildHeap(heap, tam);

    imprimirVetor(heap, tam);
    
    verificarMaxHeap(heap, 0, tam, &valido);

    if (valido) {
        printf("valido\n");
    } else {
        printf("nao valido\n");
    }

    free(heap);

    return 0;
}
