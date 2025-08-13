// Name: Fatematuj Johora
// ID: 22101148
// Section : C-2


#include <stdio.h>
#define MAX 100

int main()
 {
    int n, head, i;
    int req[MAX];
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

    printf("\n--- FCFS Disk Scheduling ---\n");
    printf("Order of Execution: %d", current);

    for (i = 0; i < n; i++)
    {
        total_seek += abs(req[i] - current);
        current = req[i];
        printf(" -> %d", current);
    }

    printf("\n\nTotal Head Movement: %d\n", total_seek);

    return 0;
}

