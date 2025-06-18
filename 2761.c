#include <stdio.h>

int main() {
    int A;
    float B;
    char C;
    char D[51];

    while(scanf("%d %f %c %[^\n]", &A, &B, &C, D) == 4) {
        printf("%d %.6f %c %s\n", A, B, C, D);
        printf("%d\t%.6f\t%c\t%s\n", A, B, C, D);
        printf("%10d%10.6f%10c %s\n", A, B, C, D);
    }
    return 0;
}
