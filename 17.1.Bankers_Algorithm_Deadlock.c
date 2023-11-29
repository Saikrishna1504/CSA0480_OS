#include <stdio.h>
#define PROCESSES 3
#define RESOURCES 3

int main() 
{
    int max[PROCESSES][RESOURCES];
    int allocation[PROCESSES][RESOURCES];
    int avail[RESOURCES];

    printf("Enter the Maximum Matrix:\n");
    for (int i = 0; i < PROCESSES; i++) {
        for (int j = 0; j < RESOURCES; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < PROCESSES; i++) {
        for (int j = 0; j < RESOURCES; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the Available Resources:\n");
    for (int i = 0; i < RESOURCES; i++) {
        scanf("%d", &avail[i]);
    }

    int need[PROCESSES][RESOURCES];
    int work[RESOURCES];
    int finish[PROCESSES] = {0};
    int processes[PROCESSES];

    for (int i = 0; i < PROCESSES; i++) 
	{
        for (int j = 0; j < RESOURCES; j++) 
		{
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    for (int i = 0; i < RESOURCES; i++) 
	{
        work[i] = avail[i];
    }

    int deadlock = 1; 
    for (int i = 0; i < PROCESSES; i++) 
	{
        if (!finish[i]) {
            int j;
            for (j = 0; j < RESOURCES; j++) 
			{
                if (need[i][j] > work[j]) 
				{
                    break;
                }
            }
            if (j == RESOURCES) 
			{
                for (int k = 0; k < RESOURCES; k++) 
				{
                    work[k] += allocation[i][k];
                }
                finish[i] = 1;
                processes[i] = -1; 
                deadlock = 0; 
                i = -1; 
            }
        }
    }

    if (deadlock) 
	{
        printf("System is in deadlock.\nDeadlocked processes: ");
        for (int i = 0; i < PROCESSES; i++) 
		{
            if (processes[i] != -1) 
			{
                printf("%d ", processes[i] + 1);
            }
        }
        printf("\n");
    } 
	else 
	{
        printf("System is in a safe state. No deadlock detected.\n");
    }

    return 0;
}
