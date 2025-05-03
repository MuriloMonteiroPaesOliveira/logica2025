#include <stdio.h>

int main() {
    int T, i, count, num;

    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        scanf("%d", &num);
    	count=0;
        while (num > 0) {
            if (num % 2 == 1) {
                count++;
            }
            num /= 2;
        }

        printf("%d\n", count);
    }

    return 0;
}
