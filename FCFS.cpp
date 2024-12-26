#include<stdio.h>

int main(){
    int n,i;
    
    printf("Enter the number of process : ");
    scanf("%d",&n);
    int process[n];
    int arrival_time[n];
    int buzz_time[n];
    
    for (i = 0;i < n;i++)
    {
        printf("Enter the process : ");
        scanf("%d",&process[i]);
        printf("Enter the buzztime : ");
        scanf("%d",&buzz_time[i]);
        printf("Enter the arrival time : ");
        scanf("%d",&arrival_time[i]);
    }
    printf(" p at bt \n");
    for (i = 0; i < n; i++)
    {
        printf(" %d  %d  %d \n",process[i],arrival_time[i],buzz_time[i]);
    }

    int waiting_time[n];
    int turnaround_time[n];
    int completion_time[n];
    
    waiting_time[0] = 0;
    turnaround_time[0] = buzz_time[0];
    completion_time[0] = buzz_time[0];
    for (int i = 0; i < n; i++){
        completion_time[i] = completion_time[i - 1] + buzz_time[i];
        printf("completion time for process %d : %d \n",i,completion_time[i]);
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - buzz_time[i];
		printf(" ct tat wt\n");
        printf(" %d   %d   %d \n",completion_time[i],turnaround_time[i],waiting_time[i]);
    }
    
    
    
    printf("   Average of FCFS    \n");

    int Avg_ct = 0;
    int Avg_wt = 0;
    float Avg_turntime = 0;

    for (int i = 0; i < n; i++) {
        Avg_ct += completion_time[i];
        Avg_wt += waiting_time[i];
        Avg_turntime += turnaround_time[i];
    }

    Avg_ct /= n;
    Avg_wt /= n;
    Avg_turntime /= n;

    printf("Average completion time: %d\n", Avg_ct);
    printf("Average waiting time: %d\n", Avg_wt);
    printf("Average turnaround time: %f\n", Avg_turntime);
}

