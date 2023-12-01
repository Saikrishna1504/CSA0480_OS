#include<stdio.h>
int main()
{
	int n,i,j;
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
    int end;
    printf("enter the end of the disk: ");
    scanf("%d",&end);
    for(i=0;i<n-1;i++)
    {
    	for(j=0;j<n-i-1;j++)
    	{
    		if(req[j]>req[j+1])
    		{
    			int temp = req[j];
    			req[j]=req[j+1];
    			req[j+1]= temp;
			}
		}
	}
	int small = req[0];
    int total = end-head+end-small;
	float avg= (float)total/n;
	printf("Average Head Movement is %.2f",avg);
	return 0;
}











#include<stdio.h>
int main()
{
	int n,i,j;
	printf("enter the number of requests: ");
	scanf("%d",&n);
	int req[n+1];
	printf("enter the requests: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&req[i]);
	}
	int head;
	printf("enter the initial head position: ");
	scanf("%d",&head);
	req[n]=head;
    int end;
    printf("enter the end of the disk: ");
    scanf("%d",&end);
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n-i;j++)
    	{
    		if(req[j]>req[j+1])
    		{
    			int temp = req[j];
    			req[j]=req[j+1];
    			req[j+1]= temp;
			}
		}
	}
	int key;
	for(i=0;i<=n;i++)
	{
		if(req[i]==head)
		{
			key = i;
		}
	}
    int total = end-head+end-0+req[key-1]-0;
	float avg= (float)total/n;
	printf("Average Head Movement is %.2f",avg);
	return 0;
}
