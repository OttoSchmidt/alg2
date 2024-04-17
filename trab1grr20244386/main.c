#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"
#include "auxiliar.h"

void gerarVetorNaoCrescente (int vetor[], size_t tam) {
    for (size_t i = 0; i < tam; i++) {
        vetor[i] = tam - i;
    }
}

void imprimirStatus (clock_t start, clock_t end, uint64_t numComparacoes) {
    double total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\nComparacoes: %ld\n", total, numComparacoes);
}

int testeBusca (size_t tamVetor, int incremento, int numTestes, int valorBuscar) {
    size_t idxBusca;
    uint64_t numComp;
    clock_t start, end;
    
    FILE *file;
    file = fopen("testes_busca.csv", "w");
    if (!file) {
        printf("Falha ao abrir arquivo\n");
        return 2;
    }

    fprintf(file, "Quant. Elementos;Busca Linear Comp;Busca Linear Tempo;Busca Linear Recursiva Comp;Busca Linear Recursiva Tempo;Busca Binaria Comp;Busca Binaria Tempo;Busca Binaria Recursiva Comp;Busca Binaria Recursiva Tempo;\n");

    int* vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 1;
    }

    for (size_t i = 0; i < tamVetor; i++) {
        vetor[i] = i + 1;
    }

    while (numTestes > 0) {
        printf("Teste %d. ", numTestes);

        fprintf(file, "%ld;", tamVetor);

        numComp = 0;
        start = clock();
        idxBusca = buscaSequencial(vetor, tamVetor, valorBuscar, &numComp);
        end = clock();
        if (idxBusca == -1) printf("Nao existe\n");
        fprintf(file, "%ld;%lf;", numComp, ((double)end - start) / CLOCKS_PER_SEC);

        if (tamVetor <= 50000) {
            numComp = 0;
            start = clock();
            idxBusca = buscaSequencialRec(vetor, tamVetor, valorBuscar, &numComp);
            end = clock();
            if (idxBusca == -1) printf("Nao existe\n");
            fprintf(file, "%ld;%lf;", numComp, ((double)end - start) / CLOCKS_PER_SEC);
        } else {
            fprintf(file, "-1;-1;");
        }

        numComp = 0;
        start = clock();
        idxBusca = buscaBinaria(vetor, tamVetor, valorBuscar, &numComp);
        end = clock();
        if (idxBusca == -1) printf("Nao existe\n");
        fprintf(file, "%ld;%lf;", numComp, ((double)end - start) / CLOCKS_PER_SEC);

        numComp = 0;
        start = clock();
        idxBusca = buscaBinariaRec(vetor, tamVetor, valorBuscar, &numComp);
        end = clock();
        if (idxBusca == -1) printf("Nao existe\n");
        fprintf(file, "%ld;%lf;\n", numComp, ((double)end - start) / CLOCKS_PER_SEC);

        tamVetor += incremento;

        vetor = realloc(vetor, tamVetor * sizeof(int));
        if (vetor == NULL) {
            printf("Falha fatal. Impossível realocar a memória com vetor de tamanho %ld\n", tamVetor);
            return 1;
        }

        for (size_t i = 0; i < tamVetor; i++) {
            vetor[i] = i + 1;
        }

        printf("Concluido.\n");

        numTestes--;
    }

    fclose(file);
    free(vetor);

    return 0;
}


int testeOrdenacao (size_t tamVetor, int incremento, int numTestes) {
    uint64_t numComp;
    clock_t start, end;
    double total;
    
    FILE *file = fopen("testes_ordenacao.csv", "w");
    if (!file) {
        printf("Falha ao abrir arquivo\n");
        return 2;
    }

    fprintf(file, "Quant. Elementos;Insertion Sort Comp;Insertion Sort Tempo;Insertion Sort Rec Comp;Insertion Sort Rec Tempo;Selection Sort Comp;Selection Sort Tempo;Selection Sort Rec Comp;Selection Sort Rec Tempo;Merge Sort Rec Comp;Merge Sort Rec Tempo;\n");

    int *vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        fclose(file);
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 1;
    }

    gerarVetorNaoCrescente(vetor, tamVetor);

    while (numTestes > 0) {
        printf("Teste %d. ", numTestes);

        fprintf(file, "%ld;", tamVetor);

        start = clock();
        numComp = insertionSort(vetor, tamVetor);
        end = clock();

        total = ((double)end - start) / CLOCKS_PER_SEC;
        printf("\n(%ld %ld)/%ld = %lf\n", end, start, CLOCKS_PER_SEC, total);
        
        fprintf(file, "%ld;%lf;", numComp, total);

        if (tamVetor <= 100000) {
            gerarVetorNaoCrescente(vetor, tamVetor);

            start = clock();
            numComp = insertionSortRec(vetor, tamVetor);
            end = clock();

            fprintf(file, "%ld;%lf;", numComp, ((double)end - start) / CLOCKS_PER_SEC);
        } else {
            fprintf(file, "-1;-1;");
        }

        gerarVetorNaoCrescente(vetor, tamVetor);

        start = clock();
        numComp = selectionSort(vetor, tamVetor);
        end = clock();

        fprintf(file, "%ld;%lf;", numComp, ((double)end - start) / CLOCKS_PER_SEC);

        if (tamVetor <= 100000) {
            gerarVetorNaoCrescente(vetor, tamVetor);

            start = clock();
            numComp = selectionSortRec(vetor, tamVetor);
            end = clock();

            fprintf(file, "%ld;%lf;", numComp, ((double)end - start) / CLOCKS_PER_SEC);
        } else {
            fprintf(file, "-1;-1;");
        }

        gerarVetorNaoCrescente(vetor, tamVetor);

        start = clock();
        numComp = mergeSortRec(vetor, tamVetor);
        end = clock();

        total = ((double)end - start) / CLOCKS_PER_SEC;
        printf("\n(%ld %ld)/%ld = %lf\n", end, start, CLOCKS_PER_SEC, total);

        fprintf(file, "%ld;%lf;\n", numComp, ((double)end - start) / CLOCKS_PER_SEC);
        
        tamVetor += incremento;

        vetor = realloc(vetor, tamVetor * sizeof(int));
        if (vetor == NULL) {
            printf("Falha fatal. Impossível realocar a memória com vetor de tamanho %ld\n", tamVetor);
            return 1;
        }

        gerarVetorNaoCrescente(vetor, tamVetor);

        printf("Concluido.\n");

        numTestes--;
    }

    fclose(file);
    free(vetor);

    return 0;
}

int main() {
    char nome[MAX_CHAR_NOME];
    size_t tamVetor;

    int numTestes, incremento;

    printf("Quant. testes: ");
    scanf("%d", &numTestes);

    printf("Incremento: ");
    scanf("%d", &incremento);

    tamVetor = incremento;
    //int valorBuscar = 1;

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    //testeBusca(tamVetor, incremento, numTestes, valorBuscar);

    testeOrdenacao(tamVetor, incremento, numTestes);
/*
    int* vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 1;
    }

    gerarVetorNaoCrescente(vetor, tamVetor);

    clock_t start, end;
    double total;
    int statusVetor;

    start = clock();
    insertionSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%lf\n", total);
    
    statusVetor = verificarOrdemNaoCrescente(vetor, tamVetor);
    if (statusVetor == -1) {
        printf("VETOR ORDENADO\n");
    } else {
        printf("VETOR NAO ORDENADO EM %d\n", statusVetor);
    }

    free(vetor);
*/
    return 0;
}
