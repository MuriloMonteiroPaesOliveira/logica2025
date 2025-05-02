#include <stdio.h>
 
int main() {
 
float p1[2], p2[2], D;

printf("Digite as coodernadas de p1: ");
scanf("%f %f", &p1[0], &p1[1]);

printf("Digite as coodernadas de p2: ");
scanf("%f %f", &p2[0], &p2[1]);

D = sqrt(((p2[1]-p1[1])*(p2[1]-p1[1]))+((p2[0]-p1[0])*(p2[0]-p1[0])));

printf("%.4f", D);
 
    return 0;
}