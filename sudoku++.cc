#include <stdio.h>

int sudoku[9][9];

int main() {
    FILE *f = fopen("input3.txt", "r");
    if (!f) {
        printf("Erro ao abrir input3.txt\n");
        return 1;
    }

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            fscanf(f, "%d", &sudoku[i][j]);
        }
    }
    fclose(f);

    int valido = 1;
    for (int i=0; i<9 && valido; i++) {
        int linha[11] = {0};
        for (int j=0; j<9; j++) {
            int val = sudoku[i][j];
            if (val < 1 || val > 10 || linha[val]) {
                valido = 0;
                break;
            }
            linha[val] = 1;
        }
    }

    for (int j=0; j<9 && valido; j++) {
        int coluna[11] = {0};
        for (int i=0; i<9; i++) {
            int val = sudoku[i][j];
            if (val < 1 || val > 10 || coluna[val]) {
                valido = 0;
                break;
            }
            coluna[val] = 1;
        }
    }

    for (int bi=0; bi<9 && valido; bi+=3) {
        for (int bj=0; bj<9 && valido; bj+=3) {
            int bloco[11] = {0};
            for (int i=bi; i<bi+3; i++) {
                for (int j=bj; j<bj+3; j++) {
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
