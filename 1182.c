#include <stdio.h>

int main() {
    int C, i;
    char T;
    float M[12][12], resultado = 0.0;

    scanf("%d", &C);
    scanf(" %c", &T);

    for (i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%f", &M[i][j]);
        }
    }

    for (i = 0; i < 12; i++) {
        resultado += M[i][C];
    }

    if (T == 'M') {
        resultado /= 12.0;
    }

    printf("%.1f\n", resultado);

    return 0;
}
