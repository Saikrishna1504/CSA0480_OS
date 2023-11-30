#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	printf("enter the number of requests: ");
	scanf("%d",&n);
	int req[n];
	printf("enter the requests: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&req[i]);
	}
	int head;
	printf("enter the initial head position: ");
	scanf("%d",&head);
	int total=0;
	for(i=0;i<n;i++)
	{
		total += abs(head-req[i]);
		head = req[i];
	}
	float avg = (float)total/n;
	printf("Average Head Movement is %.2f",avg);
	return 0;
}
