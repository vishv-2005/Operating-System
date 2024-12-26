//priority non premeptive
#include <stdio.h>
int main() {
    int n,i,j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], priority[n];
    int pid[n];
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter the arrival time, burst time, and priority of process P%d: ", i + 1);
        scanf("%d %d %d", &arrival_time[i], &burst_time[i], &priority[i]);
    }

    int waiting_time[n], turnaround_time[n];
    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];
    int current_time = arrival_time[0];
    for (i = 1; i < n; i++) {
        int min_priority = priority[i];
        int min_priority_index = i;
        for (j = i + 1; j < n; j++) {
            if (arrival_time[j] <= current_time && priority[j] < min_priority) {
                min_priority = priority[j];
                min_priority_index = j;
            }
        }
        int temp = burst_time[i];
        burst_time[i] = burst_time[min_priority_index];
        burst_time[min_priority_index] = temp;

        temp = priority[i];
        priority[i] = priority[min_priority_index];
        priority[min_priority_index] = temp;

        temp = arrival_time[i];
        arrival_time[i] = arrival_time[min_priority_index];
        arrival_time[min_priority_index] = temp;

        temp = pid[i];
        pid[i] = pid[min_priority_index];
        pid[min_priority_index] = temp;

        if (current_time < arrival_time[i]) {
            current_time = arrival_time[i];
        }
        waiting_time[i] = current_time - arrival_time[i];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        current_time += burst_time[i];
    }

    printf("Process\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], arrival_time[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }

	    printf("   Average of AWT and TAT    \n");

    int Avg_wt = 0;
    float Avg_turntime = 0;

    for (i = 0; i < n; i++) {
        Avg_wt += waiting_time[i];
        Avg_turntime += turnaround_time[i];
    }
    Avg_wt /= n;
    Avg_turntime /= n;
    printf("Average waiting time: %d\n", Avg_wt);
    printf("Average turnaround time: %f\n", Avg_turntime);
    return 0;
}
