#include <stdio.h>

int main() {
    int n, sudoku[9][9], i, j, k, l, instancia = 1;
    int linha[10], coluna[10], bloco[10];

    scanf("%d", &n);
    while(n--) {
        for(i = 0; i < 9; i++) {
            for(j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        int valido = 1;

        for(i = 0; i < 9 && valido; i++) {
            for(k = 1; k <= 9; k++) linha[k] = 0;
            for(j = 0; j < 9; j++) {
                if(sudoku[i][j] < 1 || sudoku[i][j] > 9 || linha[sudoku[i][j]]++) {
                    valido = 0;
                    break;
                }
            }
        }

        for(j = 0; j < 9 && valido; j++) {
            for(k = 1; k <= 9; k++) coluna[k] = 0;
            for(i = 0; i < 9; i++) {
                if(sudoku[i][j] < 1 || sudoku[i][j] > 9 || coluna[sudoku[i][j]]++) {
                    valido = 0;
                    break;
                }
            }
        }

        for(i = 0; i < 9 && valido; i += 3) {
            for(j = 0; j < 9 && valido; j += 3) {
                for(k = 1; k <= 9; k++) bloco[k] = 0;
                for(int x = i; x < i + 3; x++) {
                    for(int y = j; y < j + 3; y++) {
                        if(sudoku[x][y] < 1 || sudoku[x][y] > 9 || bloco[sudoku[x][y]]++) {
                            valido = 0;
                            break;
                        }
                    }
                    if(!valido) break;
                }
            }
        }

        printf("Instancia %d\n", instancia++);
        printf("%s\n\n", valido ? "SIM" : "NAO");
    }
    return 0;
}
