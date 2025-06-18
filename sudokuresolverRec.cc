#include <stdio.h>

int sudoku[9][9];

int pode_colocar(int linha, int coluna, int val) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[linha][i] == val) return 0;
        if (sudoku[i][coluna] == val) return 0;
    }
    int bi = (linha / 3) * 3;
    int bj = (coluna / 3) * 3;
    for (int i = bi; i < bi + 3; i++) {
        for (int j = bj; j < bj + 3; j++) {
            if (sudoku[i][j] == val) return 0;
        }
    }
    return 1;
}

int resolver() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (pode_colocar(i, j, val)) {
                        sudoku[i][j] = val;
                        if (resolver()) return 1;
                        sudoku[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    FILE *f = fopen("input2.txt", "r");
    if (!f) {
        printf("Erro ao abrir input2.txt\n");
        return 1;
    }
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            fscanf(f, "%d", &sudoku[i][j]);
        }
    }
    fclose(f);

    if (resolver()) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Nao ha solucao.\n");
    }

    return 0;
}
