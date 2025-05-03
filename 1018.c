#include <stdio.h>

int main() {
	int N, i, qtd, notas[] = {100, 50, 20, 10, 5, 2, 1};

	printf("Digite o valor: ");
	scanf("%d", &N);
    
    	for (i = 0; i < 7; i++) {
        qtd = N / notas[i];
        N = N % notas[i];
        
        printf("%d nota(s) de R$ %d,00\n", qtd, notas[i]);
    }

    return 0;
}