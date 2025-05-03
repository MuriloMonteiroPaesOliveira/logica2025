#include <stdio.h>
#include <math.h>
#define pi 3.1415926535897

int main() {
	float a, b, c, p, At, r, R, Gir, Vio, Ros;

printf("Digite os lados do triangulo: ");
scanf("%f %f %f", &a, &b, &c);

p=((a+b+c)/2);

At = sqrt(p*(p-a)*(p-b)*(p-c));

r=At/p;

Ros = pi*(r*r);

R = (a*b*c)/(4*At);

Vio = At - Ros;

Gir = ((pi)*(R*R))-At;

printf("Area dos Girassóis: %.2f\n", Gir);
printf("Area das Rosas: %.2f\n", Ros);
printf("Area das Violetas: %.2f\n", Vio);

return 0;
}