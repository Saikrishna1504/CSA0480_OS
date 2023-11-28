#include<stdio.h>
int main()
{
	int n,i,j;
	int pid[15],bt[15],wt[15],tat[15];
	printf("enter the number of processes: ");
	scanf("%d",&n);
	printf("enter the burst time for each process: \n");
	for(i=0;i<n;i++)
	{
		printf("P%d ",i+1);
		pid[i] = i+1;
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(bt[j]>bt[j+1])
			{	
				int tempbt = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = tempbt;
				
				int tempProc = pid[j];
				pid[j] = pid[j+1];
				pid[j+1] = tempProc;
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
