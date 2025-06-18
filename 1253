#include <stdio.h>
#include <string.h>

int main() {
    int N, i, j, deslocamento;
    char texto[51];

    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%s", texto);
        scanf("%d", &deslocamento);
        for(j = 0; texto[j] != '\0'; j++) {
            texto[j] = (texto[j] - 'A' - deslocamento + 26) % 26 + 'A';
        }
        printf("%s\n", texto);
    }
    return 0;
}
