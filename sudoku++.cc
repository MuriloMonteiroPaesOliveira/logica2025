#include <stdio.h>

int sudoku[10][10];

int main() {
    int n = 1; // 1 instância para este exemplo
    int valido = 1;

    FILE *f = fopen("input3.txt", "r");
    if (!f) {
        printf("Erro ao abrir input3.txt\n");
        return 1;
    }

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            fscanf(f, "%d", &sudoku[i][j]);
        }
    }
    fclose(f);

    for (int i=0; i<10 && valido; i++) {
        int linha[11] = {0};
        for (int j=0; j<10; j++) {
            int val = sudoku[i][j];
            if (val < 1 || val > 10 || linha[val]) {
                valido = 0;
                break;
            }
            linha[val] = 1;
        }
    }

    for (int j=0; j<10 && valido; j++) {
        int coluna[11] = {0};
        for (int i=0; i<10; i++) {
            int val = sudoku[i][j];
            if (val < 1 || val > 10 || coluna[val]) {
                valido = 0;
                break;
            }
            coluna[val] = 1;
        }
    }

    // blocos 2x5
    for (int bi=0; bi<10 && valido; bi+=2) {
        for (int bj=0; bj<10 && valido; bj+=5) {
            int bloco[11] = {0};
            for (int i=bi; i<bi+2; i++) {
                for (int j=bj; j<bj+5; j++) {
                    int val = sudoku[i][j];
                    if (val < 1 || val > 10 || bloco[val]) {
                        valido = 0;
                        break;
                    }
                    bloco[val] = 1;
                }
                if (!valido) break;
            }
        }
    }

    printf("%s\n", valido ? "SIM" : "NAO");
    return 0;
}
