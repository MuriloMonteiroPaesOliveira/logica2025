#include <stdio.h>

int main() {
    int numero, horas;
    double valorHora, salario;
    scanf("%d", &numero);
    scanf("%d", &horas);
    scanf("%lf", &valorHora);
    salario = horas * valorHora;
    printf("NUMBER = %d\n", numero);
    printf("SALARY = U$ %.2lf\n", salario);
    return 0;
}
