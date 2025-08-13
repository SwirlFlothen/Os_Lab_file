// Name: Fatematuj Johora
// ID: 22101148
// Section: C-2


#include <stdio.h>
#define MAX 10

int main()
 {
    int n, i, time = 0, completed = 0;
    int p[MAX], at[MAX], bt[MAX], pr[MAX];
    int ct[MAX], tat[MAX], wt[MAX];
    int done[MAX] = {0};
    float totalWT = 0, avgWT;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Process IDs:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter Arrival Times:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter Burst Times:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("Enter Priorities (lower number = higher priority):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pr[i]);
    }

   // Start of Scheduling Process

    while (completed < n) {
        int idx = -1;
        int highest_priority = 9999;

        // Find the highest priority process
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && done[i] == 0)
             {
                if (pr[i] < highest_priority ||(pr[i] == highest_priority && at[i] < at[idx]))
                {
                    highest_priority = pr[i];
                    idx = i;
                }
            }
        }

        if (idx != -1)
        {
            // Process execute
            time = time+bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            totalWT =totalWT + wt[idx];
            done[idx] = 1;
            completed++;
        }

        else

        {
            time++; //If no process is available then increment time
        }
    }

    // Output of the Problem

    printf("\n--- Priority Scheduling Result ---\n");
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    avgWT = totalWT / n;
    printf("\nAverage Waiting Time: %.2f\n", avgWT);

    return 0;
}
