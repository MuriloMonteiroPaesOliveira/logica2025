#include <stdio.h>

int main() {
    int N;
    while (scanf("%d", &N), N != 0) {
        int solved = 0, total_time = 0;
        int incorrect[26] = {0};
        int solved_time[26];
        for (int i = 0; i < 26; i++) solved_time[i] = -1;

        for (int i = 0; i < N; i++) {
            char problem;
            int time;
            char verdict[10];
            scanf(" %c %d %s", &problem, &time, verdict);
            int idx = problem - 'A';

            if (solved_time[idx] != -1) continue; // already solved

            if (verdict[0] == 'c') { // correct
                solved++;
                solved_time[idx] = time;
                total_time += time + 20 * incorrect[idx];
            } else { // incorrect
                incorrect[idx]++;
            }
        }
        printf("%d %d\n", solved, total_time);
    }
    return 0;
}
