#include <stdio.h>

int main() {
    int N, i, fatorial = 1;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        fatorial *= i;
    }

    printf("%d\n", fatorial);

    return 0;
}