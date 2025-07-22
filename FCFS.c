//Name: Fatematuj Johora
//ID:22101148
//Section:C-2


#include <stdio.h>
#define MAX 10

int main()
{
    int i,j,n;
    int p[MAX],at[MAX],bt[MAX],ct[MAX],tat[MAX],wt[MAX];
    float totalWT,avgWT;
    printf("Enter the number of process: ");
    scanf("%d",&n);

    printf("Enter Process ID:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }

    printf("Enter Arrival Time of the of the process:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }

    printf("Enter the Burst Time of the process:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {

                int temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;

                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;

                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

            }
        }
    }


    int previousct=0;  //previous completion time.

    for(i=0;i<n;i++)
    {

        ct[i]=previousct+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        previousct=ct[i];
        totalWT=totalWT+wt[i];
    }

    // Print results

    printf("\n--- FCFS Scheduling Result ---\n");

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    avgWT=totalWT/n;
    printf("\nAverage Waiting Time: %.2f\n",avgWT);

    return 0;
}
