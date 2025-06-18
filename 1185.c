#include <stdio.h>

int main() {
    char O;
    float M[12][12], resultado = 0.0;
    int count = 0;

    scanf(" %c", &O);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%f", &M[i][j]);
        }
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12 - 1 - i; j++) {
            resultado += M[i][j];
            count++;
        }
    }

    if (O == 'M') {
        resultado /= count;
    }

    printf("%.1f\n", resultado);

    return 0;
}
