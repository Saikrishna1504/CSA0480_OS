#include<stdio.h>
int main() 
{
    int bt[15], wt[15], tat[15];
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time for each process:\n");
    for(i = 0; i < n; i++)
	 {
        printf("P%d ", i);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for(i = 1; i < n; i++) 
	{
        wt[i] = wt[i-1] + bt[i-1];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) 
	{
        tat[i] = bt[i] + wt[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }
    int twt = 0, tatotal = 0;
    for(i = 0; i < n; i++) 
	{
        twt += wt[i];
        tatotal += tat[i];
    }
    float awt = (float)twt / n;
    float att = (float)tatotal / n;
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", att);
    return 0;
}
