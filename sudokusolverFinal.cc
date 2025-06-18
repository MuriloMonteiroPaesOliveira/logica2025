#include <stdio.h>

int sudoku[9][9];
int solucoes = 0;

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

void imprimir() {
    printf("Solucao %d:\n", ++solucoes);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void resolver(int linha, int coluna) {
    if (linha == 9) {
        imprimir();
        return;
    }

    if (sudoku[linha][coluna] != 0) {
        if (coluna == 8) resolver(linha+1, 0);
        else resolver(linha, coluna+1);
        return;
    }

    for (int val = 1; val <= 9; val++) {
        if (pode_colocar(linha, coluna, val)) {
            sudoku[linha][coluna] = val;
            if (coluna == 8) resolver(linha+1, 0);
            else resolver(linha, coluna+1);
            sudoku[linha][coluna] = 0;
        }
    }
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

    resolver(0, 0);

    if (solucoes == 0) {
