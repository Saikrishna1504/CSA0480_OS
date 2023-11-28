#include <stdio.h>
int main() 
{
    int pid[20], bt[20], priority[20], wt[20], tat[20], n,i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) 
	{
        printf("P%d ", i + 1);
        scanf("%d %d", &bt[i], &priority[i]);
        pid[i] = i + 1;
    }
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (priority[j] > priority[j + 1]) 
			{
                // Swap burst times
                int tempBurst = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = tempBurst;

                // Swap priority values
                int tempPriority = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = tempPriority;

                // Swap process IDs
                int tempPid = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = tempPid;
            }
        }
    }
	wt[0] = 0;
	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1]+bt[i-1];
	}
	for(i=0;i<n;i++)
	{
		tat[i] = wt[i] + bt[i];
	}
	printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t\t%d\t\t%d\n",pid[i],bt[i],wt[i],tat[i]);
	}
	int twt = 0,ttt = 0;
	for(i=0;i<n;i++)
	{
		twt += wt[i];
		ttt += tat[i];
	}
	float avg_w = (float)twt/n;
	float avg_t = (float)ttt/n;
	printf("Average Waiting Time = %.2f\n",avg_w);
	printf("Average Turnaround Time = %.2f",avg_t);
    return 0;
}

