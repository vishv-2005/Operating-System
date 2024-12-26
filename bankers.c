#include <stdio.h>
#define P 5
#define R 3
int isSafe(int processes[], int avail[], int max[][R], int allot[][R]) {
    int need[P][R], work[R], finish[P], safeSeq[P],i,j,p,k;
    for (i = 0; i < P; i++)
        for (j = 0; j < R; j++)
            need[i][j] = max[i][j] - allot[i][j];
    for (i = 0; i < R; i++)
        work[i] = avail[i];
   
    for (i = 0; i < P; i++)
        finish[i] = 0;

    int count = 0;
    while (count < P) {
        int found = 0;
        for (p = 0; p < P; p++) {
            if (finish[p] == 0) {
                int j;
                for (j = 0; j < R; j++) {
                    if (need[p][j] > work[j])
                        break;
                }
                if (j == R) {
                    for (k = 0; k < R; k++)
                        work[k] += allot[p][k];

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("System is not in a safe state\n");
            return 0;
        }
    }
    printf("System is in a safe state.\nSafe sequence is: ");
    for (i = 0; i < P; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");
    return 1;
}
int main() {
    int processes[] = {0, 1, 2, 3, 4};
    int avail[] = {2, 3, 0};
    int max[P][R] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};
    int allot[P][R] = {{0, 1, 0},
                       {3, 0, 2},
                       {3, 0, 2},
                       {2, 1, 1},
                       {0, 0, 2}};
    isSafe(processes, avail, max, allot);
    return 0;
}

