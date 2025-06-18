#include <stdio.h>
#include <math.h>

#define MAX 100

int tab[MAX][MAX];

int main() {
    FILE *f = fopen("input4.txt", "r");
    if (!f) {
        printf("Erro ao abrir input4.txt\n");
        return 1;
    }

    int N;
    fscanf(f, "%d", &N);

    double raiz = sqrt(N);
    if (raiz != (int)raiz) {
        printf("NAO\n");
        fclose(f);
        return 0;
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            fscanf(f, "%d", &tab[i][j]);
        }
    }
    fclose(f);

    int valido = 1;
    for (int i=0; i<N && valido; i++) {
        int usado[MAX*MAX] = {0};
        for (int j=0; j<N; j++) {
            int val = tab[i][j];
            if (val < 0 || val >= MAX*MAX || usado[val]) {
                valido = 0;
                break;
            }
            usado[val] = 1;
        }
    }

    for (int j=0; j<N && valido; j++) {
        int usado[MAX*MAX] = {0};
        for (int i=0; i<N; i++) {
            int val = tab[i][j];
            if (val < 0 || val >= MAX*MAX || usado[val]) {
                valido = 0;
                break;
            }
            usado[val] = 1;
        }
    }

    int bloco = (int)raiz;
    for (int bi=0; bi<N && valido; bi+=bloco) {
        for (int bj=0; bj<N && valido; bj+=bloco) {
            int usado[MAX*MAX] = {0};
            for (int i=bi; i<bi+bloco; i++) {
                for (int j=bj; j<bj+bloco; j++) {
                    int val = tab[i][j];
                    if (val < 0 || val >= MAX*MAX || usado[val]) {
                        valido = 0;
                        break;
                    }
                    usado[val] = 1;
                }
                if (!valido) break;
            }
        }
    }

    printf("%s\n", valido ? "SIM" : "NAO");
    return 0;
}
