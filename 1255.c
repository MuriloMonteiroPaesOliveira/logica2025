#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int N, i, j, max;
    char linha[201];
    int freq[26];

    scanf("%d\n", &N);
    for(i = 0; i < N; i++) {
        fgets(linha, 201, stdin);
        for(j = 0; j < 26; j++) freq[j] = 0;
        for(j = 0; linha[j] != '\0'; j++) {
            if(isalpha(linha[j])) {
                freq[tolower(linha[j]) - 'a']++;
            }
        }
        max = 0;
        for(j = 0; j < 26; j++) {
            if(freq[j] > max) max = freq[j];
        }
        for(j = 0; j < 26; j++) {
            if(freq[j] == max) {
                printf("%c", j + 'a');
            }
        }
        printf("\n");
    }
    return 0;
}
