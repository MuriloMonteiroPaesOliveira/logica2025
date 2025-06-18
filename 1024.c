#include <stdio.h>
#include <string.h>

int main() {
    int N, i, j, len, half;
    char linha[1001];

    scanf("%d\n", &N);
    for(i = 0; i < N; i++) {
        fgets(linha, 1001, stdin);
        len = strlen(linha);
        if(linha[len - 1] == '\n') {
            linha[len - 1] = '\0';
            len--;
        }
        for(j = 0; j < len; j++) {
            if((linha[j] >= 'A' && linha[j] <= 'Z') || (linha[j] >= 'a' && linha[j] <= 'z')) {
                linha[j] += 3;
            }
        }
        for(j = 0; j < len / 2; j++) {
            char temp = linha[j];
            linha[j] = linha[len - j - 1];
            linha[len - j - 1] = temp;
        }
        half = len / 2;
        for(j = half; j < len; j++) {
            linha[j] -= 1;
        }
        printf("%s\n", linha);
    }
    return 0;
}
