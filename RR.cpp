#include <stdio.h>

void turnaround_t(int ct[], int arrival_time[], int tat[], int n) {
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - arrival_time[i];
    }
}

void waiting_t(int tat[], int burst_time[], int wt[], int n) {
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - burst_time[i];
    }
}

float avg(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (float)sum / n;
}

void c_time(int bt[], int n, int ct[], int TQ) {
    int remaining_bt[n], time = 0, done = 0;

    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
    }
    while (done != n) {
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                if (remaining_bt[i] > TQ) {
                    time += TQ;
                    remaining_bt[i] -= TQ;
                } else {
                    time += remaining_bt[i];
                    ct[i] = time;
                    remaining_bt[i] = 0;
                    done++;
                }
            }
        }
    }
}

void printTableHeader() {
    printf("| Process | Arrival Time | Burst Time | Waiting Time | Turnaround Time |\n");
}

void printTableRow(int id, int at, int bt, int wt, int tat) {
    printf("|   P%2d   | %12d | %9d | %13d | %15d |\n", id, at, bt, wt, tat);
}

int main() {
    int n , TQ;
    printf("Enter no. of processes : ");
    scanf("%d",&n);
    int bt[n], at[n], ct[n], tat[n], wt[n];
    
    
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter the arrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &TQ);

    c_time(bt, n, ct, TQ);
    turnaround_t(ct, at, tat, n);
    waiting_t(tat, bt, wt, n);

    // Print the table header
    printTableHeader();

    // Print each process' details in the table
    for (int i = 0; i < n; i++) {
        printTableRow(i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage completion time = %.2f\n", avg(ct, n));
    printf("Average turn-around time = %.2f\n", avg(tat, n));
    printf("Average waiting time = %.2f\n", avg(wt, n));

    return 0;
}


