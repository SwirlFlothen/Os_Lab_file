// Name: Fatematuj Johora
// ID: 22101148
// Section: C2


#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void sort(int arr[], int n)
 {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
         {
            if (arr[i] > arr[j])
             {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
 {
    int n, head, i, direction;
    int req[MAX];
    int total_seek = 0;
    int current;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1 = right, 0 = left): ");
    scanf("%d", &direction);

    sort(req, n);

    int left[MAX], right[MAX];
    int leftcount = 0, rightcount = 0;

    for (i = 0; i < n; i++)
    {
        if (req[i] < head)
            left[leftcount++] = req[i];
        else
            right[rightcount++] = req[i];
    }

    current = head;

    printf("\n--- C-SCAN Disk Scheduling ---\n");
    printf("Order of Execution: %d", current);

    if (direction == 1)
    {
        for (i = 0; i < rightcount; i++)
        {
            total_seek =total_seek + abs(right[i] - current);
            current = right[i];
            printf(" -> %d", current);
        }
           if (leftcount > 0)
          {
            total_seek = total_seek + abs(current - left[0]);
            current = left[0];
            printf(" -> %d", current);

            for (i = 1; i < leftcount; i++)
            {
                total_seek = total_seek + abs(left[i] - current);
                current = left[i];
                printf(" -> %d", current);
            }
        }
    }
     else
        {
        for (i=leftcount-1;i>=0;i--)
        {
            total_seek = total_seek + abs(left[i] - current);
            current = left[i];
            printf(" -> %d", current);
        }
        if (rightcount > 0)
         {
            total_seek =total_seek + abs(current - right[rightcount - 1]);
            current = right[rightcount - 1];
            printf(" -> %d", current);

            for (i=rightcount-2;i>=0;i--)
            {
                total_seek =total_seek + abs(right[i] - current);
                current = right[i];
                printf(" -> %d", current);
            }
        }
    }

    printf("\n\nTotal Head Movement: %d\n", total_seek);

    return 0;
}
