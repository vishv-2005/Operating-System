#include <stdio.h>
#define LARGE_CONSTANT 1000000

void printTableHeader() {
    printf("| Process | Arrival Time | Burst Time | Waiting Time | Turnaround Time |\n");
}

void printTableRow(int id, int at, int bt, int wt, int tat) {
    printf("|   p%2d   | %12d | %9d | %13d | %15d |\n", id, at, bt, wt, tat);
}

int main() {
    int process;
    printf("Enter the number of processes: ");
    scanf("%d", &process);
    printf("\n");

    int BT[process], AT[process];
    float total_WT = 0, total_TAT = 0;

    for (int i = 0; i < process; i++) {
        printf("Enter the burst time for process p%d: ", i + 1);
        scanf("%d", &BT[i]);
        printf("Enter the arrival time for process p%d: ", i + 1);
        scanf("%d", &AT[i]);
        printf("\n");
    }

    int WT[process], TAT[process], completed[process];
    int time = 0; // Current time
    int count = 0; // Number of completed processes

    // Initialize completed array
    for (int i = 0; i < process; i++) {
        completed[i] = 0;
    }

    // Main loop to process each job
    while (count < process) {
        int smallest = -1;
        int min_BT = LARGE_CONSTANT; // Use the large constant here

        // Find the process with the smallest burst time that is yet to be completed
        for (int i = 0; i < process; i++) {
            if (AT[i] <= time && completed[i] == 0 && BT[i] < min_BT) {
                min_BT = BT[i];
                smallest = i;
            }
        }

        // If no process is ready to execute, increment time
        if (smallest == -1) {
            time++;
            continue;
        }

        // Calculate waiting time for the current process
        WT[smallest] = time - AT[smallest];
        TAT[smallest] = WT[smallest] + BT[smallest];

        // Update total waiting time and turnaround time
        total_WT += WT[smallest];
        total_TAT += TAT[smallest];

        // Print waiting time and turnaround time for the current process
        printf("Waiting time for process p%d: %d\n", smallest + 1, WT[smallest]);
        printf("Turn Around Time for process p%d: %d\n", smallest + 1, TAT[smallest]);

        // Update time and mark process as completed
        time += BT[smallest];
        completed[smallest] = 1;
        count++;
    }

    printTableHeader();
    for (int i = 0; i < process; i++) {
        printTableRow(i + 1, AT[i], BT[i], WT[i], TAT[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_WT / process);
    printf("Average Turnaround Time: %.2f\n", total_TAT / process);
    return 0;
}

