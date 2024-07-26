#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimirTabuleiro(int *p, size_t tam) {
    for (size_t i = 0; i < tam; i++) {
        for (size_t j = 0; j < tam; j++) {
            if (p[i] == j) {
                printf("[R]");
            } else {
                printf("[ ]");
            }
        }
        printf("\n");
    }

    printf("\n");
}

void procurarRainha(int *p, int tam, int linhaAtual, bool *resolvido) {
    bool permitido;

    if (linhaAtual == tam) {
        *resolvido = true;
        return;
    }

    for (int coluna = 0; coluna < tam && !(*resolvido); coluna++) {
        permitido = true;
        
        for (int linha = 0; linha < linhaAtual; linha++) {
            if (p[linha] == coluna || p[linha] == coluna + linhaAtual - linha || p[linha] == coluna - linhaAtual + linha) {
                permitido = false;
                break;
            }
        }

        if (permitido) {
            p[linhaAtual] = coluna;
            procurarRainha(p, tam, linhaAtual + 1, resolvido);
        }
    }
}

/*
linhaAtual = 2
  0   1   2   3
1[ ] [x] [ ] [ ]
2[ ] [ ] [ ] [x]
3[x] [ ] [ ] [ ]
4[ ] [ ] [x] [ ]
*/

int main() {
    int *p;
    size_t tam;
    bool resolvido = false;

    printf("Digite o tamanho do tabuleiro: ");
    scanf("%lu", &tam);

    p = (int *)calloc(tam, sizeof(int));
    if (p == NULL) {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }

    procurarRainha(p, tam, 0, &resolvido);
    imprimirTabuleiro(p, tam);

    free(p);

    return 0;
}
