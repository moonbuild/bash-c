#include <stdio.h>

void main() {
    int n;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    int bt[n];
    int priority[n];
    int wt[n];
    int tat[n];
    float awt = 0;
    float atat = 0;

    printf("\nEnter the burst time: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("\nEnter the priority: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &priority[i]);
    }

    // Structure to represent a process with attributes
    struct Process {
        int pid; // Process ID
        int burstTime; // BurstTime
        int priority; // Priority
    };

    // Create an array of processes
    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i;
        p[i].burstTime = bt[i];
        p[i].priority = priority[i];
    }

    // Sort processes based on priority (non-preemptive)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].priority > p[j + 1].priority) {
                // Swap the processes
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    wt[0] = 0;
    tat[0] = p[0].burstTime;
    int comTime = p[0].burstTime; // Completion Time
    for (int i = 1; i < n; i++) {
        wt[i] = comTime;
        comTime += p[i].burstTime;
        tat[i] = wt[i] + p[i].burstTime;
    }

    // Print the sorted table
    printf("Sorted Process Table\n");
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burstTime,
               p[i].priority, wt[i], tat[i]);
        awt += wt[i];
        atat += tat[i];
    }

    awt /= n;
    atat /= n;

    printf("\nAverage waiting time = %.2f", awt);
    printf("\nAverage turnaround time = %.2f\n", atat);

    // Gantt Chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("|  P%d  ", p[i].pid);
    }
    printf("|\n");

    // Current Time
    int ct = 0;
    for (int i = 0; i < n; i++) {
        printf("%d      ", ct);
        ct += p[i].burstTime;
    }
    printf("%d\n", ct);
}
