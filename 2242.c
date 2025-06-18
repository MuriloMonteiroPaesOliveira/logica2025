#include <stdio.h>
#include <string.h>

int is_vogal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    char risada[51], vogais[51];
    int i, len, v_len = 0;
    
    fgets(risada, 51, stdin);
    len = strlen(risada);
    if(risada[len - 1] == '\n') risada[len - 1] = '\0';

    for(i = 0; risada[i] != '\0'; i++) {
        if(is_vogal(risada[i])) {
            vogais[v_len++] = risada[i];
        }
    }
    vogais[v_len] = '\0';

    for(i = 0; i < v_len / 2; i++) {
        if(vogais[i] != vogais[v_len - 1 - i]) {
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");
    return 0;
}
