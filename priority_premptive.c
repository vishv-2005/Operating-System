#include <stdio.h>

void printTableHeader() {
    printf("| Process | Arrival Time | Burst Time | Priority | Waiting Time | Turnaround Time |\n");
}

void printTableRow(int id, int at, int bt, int p, int wt, int tat) {
    printf("|   P%2d   | %12d | %9d | %13d | %13d | %15d |\n", id, at, bt, p, wt, tat);
}

int main() {
    int n, i, j, time = 0, pos, smallest;
    int AT[10], BT[10], Priority[10], RT[10], WT[10], TAT[10], CT = 0;
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the burst time for P%d: ", i + 1);
        scanf("%d", &BT[i]);
        printf("Enter the arrival time for P%d: ", i + 1);
        scanf("%d", &AT[i]);
        RT[i] = BT[i]; // Initialize remaining time with burst time
    }

    printf("Enter the priorities of the processes (lower value indicates higher priority):\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &Priority[i]);
    }

    printf("\nGantt chart:\n");

    Priority[9] = 9999;  // High priority for idle state
    while (CT != n) {
        smallest = 9;  // Initialize to an out-of-range index with high priority
        
        // Find the highest priority process that has arrived
        for (i = 0; i < n; i++) {
            if (AT[i] <= time && RT[i] > 0 && Priority[i] < Priority[smallest]) {
                smallest = i;
            }
        }

        printf("| P%d ", smallest + 1);
        RT[smallest]--;  // Decrease remaining time of the selected process
        time++;

        // If the process finishes
        if (RT[smallest] == 0) {
            CT++;
            TAT[smallest] = time - AT[smallest];  // Turnaround time = completion time - arrival time
            WT[smallest] = TAT[smallest] - BT[smallest];  // Waiting time = turnaround time - burst time

            total_wt += WT[smallest];
            total_tat += TAT[smallest];
        }
    }
    printf("|\n");

    // Calculate averages
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    // Print the table header
    printTableHeader();

    // Print each process' details in the table
    for (i = 0; i < n; i++) {
        printTableRow(i + 1, AT[i], BT[i], Priority[i], WT[i], TAT[i]);
    }

    printf("\nAverage waiting time = %.2f", avg_wt);
    printf("\nAverage turnaround time = %.2f\n", avg_tat);
    
    return 0;
}

