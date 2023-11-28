#include <stdio.h>
int main() 
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
    	printf("P%d ",i+1);
        scanf("%d", &bt[i]);
    }

    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int remaining[n];
    for (int i = 0; i < n; i++)
    {
        remaining[i] = bt[i];
    }

    int t = 0;
    while (1) 
	{
        int done = 1;

        for (int i = 0; i < n; i++) 
		{
            if (remaining[i] > 0) 
			{
                done = 0;

                if (remaining[i] > quantum) 
				{
                    t += quantum;
                    remaining[i] -= quantum;
                } 
				else 
				{
                    t += remaining[i];
                    wt[i] = t - bt[i];
                    remaining[i] = 0;
                }
            }
        }

        if (done == 1) break;
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }

    printf("Process   Burst Time   Waiting Time   Turnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) 
	{
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);
    printf("Average Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}
