#include<stdio.h>
#define MAX 10

int main()
{
    int n,i,tq,time=0,completed=0;
    int p[MAX],at[MAX],bt[MAX],ct[MAX],tat[MAX],rt[MAX],wt[MAX];
    int queue[20],front=0,rear=0,visited[MAX]={0},done[MAX]={0};

    printf("Enter the No of process:");
    scanf("%d",&n);

    printf("Enter the Process Id:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }

    printf("Enter the Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }

    printf("Enter the Burst time:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
         rt[i]=bt[i];
    }
    printf("Enter the Quant Time:\n");

        scanf("%d",&tq);

    queue[rear++]=0;
    visited[0]=1;
    while(completed<n)
    {
        int index=queue[front++];
        if(rt[index]>tq)
        {
            time=time+tq;
            rt[index]=rt[index]-tq;
        }

        else
        {
        time=time+rt[index];
        rt[index]=0;
        ct[index]=time;
        done[index]=1;
        completed++;

        tat[index]=ct[index]-at[index];
        wt[index]=tat[index]-bt[index];
        }
      for(i=0;i<n;i++)
      {
          if(!visited[i]&&at[i]<=time)
          {
              queue[rear++]=i;
              visited[i]=1;
          }
      }

    if(rt[index>0])
    {
        queue[rear++]=index;
    }
    if(front == rear)
        {
            for(i=0;i<n;i++)
            {
                if(!done[i])
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                    break;
                }
            }
        }
    }


    printf("\n--- Round Robin Scheduling Result ---\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}








