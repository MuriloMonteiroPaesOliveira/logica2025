#include <stdio.h>
 
int main() {
 
 int cod1, cod2, num1, num2;
 float val1, val2, valf;
 
 printf("Digite o código, número de peças e valor de cada peça do produto 1: ");
 scanf("%d %d %f", &cod1, &num1, &val1);
 
 printf("Digite o código, número de peças e valor de cada peça do produto 2: ");
 scanf("%d %d %f", &cod2, &num2, &val2);
 
 valf = (num1 * val1) + (num2 * val2);
 
 printf("Valor a pagar: R$%.2f\n", valf);
 
    return 0;
}