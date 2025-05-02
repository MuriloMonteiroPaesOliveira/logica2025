#include <stdio.h>
#define n 3.14159
 
int main() {

float A, R;

printf("Digite o Raio: ");
scanf("%f", &R);

A = n * (R * R);

printf("A = %.2f\n", A);
 
    return 0;
}
