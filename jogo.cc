#include <stdio.h>

int sudoku[9][9];

void imprimir_tabuleiro() {
    printf("\n");
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int jogada_valida(int linha, int coluna, int valor) {
    for (int j=0; j<9; j++) {
        if (sudoku[linha][j] == valor) return 0;
    }
    for (int i=0; i<9; i++) {
        if (sudoku[i][coluna] == valor) return 0;
    }
    int bloco_i = (linha / 3) * 3;
    int bloco_j = (coluna / 3) * 3;
    for (int i=bloco_i; i<bloco_i+3; i++) {
        for (int j=bloco_j; j<bloco_j+3; j++) {
            if (sudoku[i][j] == valor) return 0;
        }
    }
    return 1;
}

int completo() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (sudoku[i][j] == 0) return 0;
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

    printf("Bem-vindo ao Sudoku interativo!\n");
    imprimir_tabuleiro();

    while (!completo()) {
        int l, c, v;
        printf("Digite linha coluna valor (0 0 0 para sair): ");
        scanf("%d %d %d", &l, &c, &v);
        if (l == 0 && c == 0 && v == 0) {
            printf("Saindo do jogo.\n");
            break;
        }
        if (l < 1 || l > 9 || c < 1 || c > 9 || v < 1 || v > 9) {
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }
        l--; c--;
        if (sudoku[l][c] != 0) {
            printf("Posicao ja preenchida.\n");
            continue;
        }
        if (!jogada_valida(l, c, v)) {
            printf("Jogada invalida segundo as regras do Sudoku.\n");
            continue;
        }
        sudoku[l][c] = v;
        imprimir_tabuleiro();
    }
    if (completo()) {
        printf("Parabens, voce completou o Sudoku!\n");
    }
    return 0;
}
