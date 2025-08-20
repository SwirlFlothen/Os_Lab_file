#include <stdio.h>
#define MAX 100

int absolute(int x)
 {
    if (x < 0)
        return -x;
    return x;
}

int main()
{
    int n, head, i, count = 0;
    int req[MAX], completed[MAX] = {0}, order[MAX];
    int total_seek = 0, current;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    current = head;
    order[count++] = current;


    for (i = 0; i < n; i++)
    {
        if (req[i] == current)
        {
            completed[i] = 1;
            break;
        }
    }


    while (count < n)
    {
        int min_dist = -1, pos = -1;
        for (i = 0; i < n; i++)
        {
            if (!completed[i])
            {
                int dist = absolute(req[i] - current);
                if (min_dist == -1 || dist < min_dist)
                {
                    min_dist = dist;
                    pos = i;
                }
            }
        }
        total_seek += absolute(req[pos] - current);
        current = req[pos];
        completed[pos] = 1;
        order[count++] = current;
    }

    printf("\n--- SSTF Disk Scheduling ---\n");
    printf("Order of Execution: ");
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            printf("%d", order[i]);
        else
            printf(" -> %d", order[i]);
    }

    printf("\nTotal Head Movement: %d\n", total_seek);

    return 0;
}

