#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

void calculateWaitingTurnaroundTime(struct Process processes[], int n) {
    int total_waiting_time = 0;

    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }
}

void displayResults(struct Process processes[], int n) {
    printf("PID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time,
               processes[i].burst_time, processes[i].priority, processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority for Process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
    }

    int currentTime = 0;
    int completed = 0;
    
    while (completed < n) {
        int highestPriority = -1;
        int selectedProcess = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= currentTime && processes[i].remaining_time > 0) {
                if (highestPriority == -1 || processes[i].priority < highestPriority) {
                    highestPriority = processes[i].priority;
                    selectedProcess = i;
                }
            }
        }

        if (selectedProcess == -1) {
            currentTime++;
        } else {
            processes[selectedProcess].remaining_time--;
            currentTime++;

            if (processes[selectedProcess].remaining_time == 0) {
                completed++;
                processes[selectedProcess].turnaround_time = currentTime - processes[selectedProcess].arrival_time;
            }
        }
    }

    calculateWaitingTurnaroundTime(processes, n);
    displayResults(processes, n);

    return 0;
}
