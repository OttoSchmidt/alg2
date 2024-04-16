#include <stdio.h>


//a*b + 1
int misterio (int a, int b, int *divisoes, int *somas) {
    if (b == 0) return 1;

    (*somas) += 1;
    (*divisoes) += 1;
    if (b % 2 == 0) return misterio (a + a, b/2, divisoes, somas);

    (*somas) += 1;
    return misterio(a+a, b/2, divisoes, somas) + a;
}

int main () {
    int a, b, divisoes, somas;

    while(1) {
        divisoes = 0;
        somas = 0;

        scanf("%d %d", &a, &b);

        printf("%d", misterio(a, b, &divisoes, &somas));
        printf(", divisoes = %d e somas = %d\n", divisoes, somas);
    }

    return 0;
}