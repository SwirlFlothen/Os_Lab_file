#include <stdio.h>
#define MAX 100

int absolute(int x)
{
    if(x<0)
        return -x;
    return x;
}
void sort(int arr[], int n)
 {
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
             {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n,head,i,direction;
    int req[MAX],order[MAX],count=0,total_seek=0;

    printf("Enter the number of disk request: ");
    scanf("%d",&n);

    printf("Enter the disk request sequence:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("Enter head movement direction (1 for right, 0 for left): ");
    scanf("%d",&direction);

    req[n++]=head;
    sort(req,n);

    int index=0;
    for(i=0;i<n;i++)
    {
        if(req[i]==head)
         {
            index=i;
            break;
        }
    }

    if (direction==1)
    {
        for(i=index;i<n;i++)
            order[count++]=req[i];
        for(i=index-1;i>=0;i--)
            order[count++]=req[i];
    }

    else
     {
        for(i=index;i>=0;i--)
        {
            order[count++]=req[i];
        }
        for(i=index+1;i<n;i++)
        {
            order[count++]=req[i];
        }

    }

    for (i=0;i<count-1;i++)
    {
        total_seek +=absolute(order[i + 1]-order[i]);
    }
    printf("\n--- SCAN Disk Scheduling ---\n");
    printf("Order of Execution: ");
    for (i = 0; i < count; i++)
    {
        if (i == 0)
            printf("%d", order[i]);
        else
            printf(" -> %d", order[i]);
    }

    printf("\nTotal Head Movement: %d\n", total_seek);

    return 0;
}


