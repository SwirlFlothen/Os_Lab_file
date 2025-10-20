#include <stdio.h>
int main()
 {
    int n;
    printf("Enter number of frames: ");
    scanf("%d", &n);

    int m;
    printf("Enter number of pages in reference string: ");
    scanf("%d", &m);

    int pages[100], frames[50], counter[50];
    int i, j, time = 0, faults = 0, hits = 0;

    printf("Enter the reference string: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &pages[i]);
    }
    for (i = 0; i < n; i++)
    {
        frames[i] = -1;
        counter[i] = 0;
    }

    for (i = 0; i < m; i++)
    {
        int page = pages[i];
        int hit = 0;
        for (j = 0; j < n; j++)
        {
            if (frames[j] == page)
            {
                hit = 1;
                counter[j] = ++time;
                hits++;
                break;
            }
        }

        if (!hit)
        {
            int pos = 0, minTime = counter[0];
            for (j = 1; j < n; j++)
            {
                if (counter[j] < minTime)
                 {
                    minTime = counter[j];
                    pos = j;
                }
            }
            frames[pos] = page;
            counter[pos] = ++time;
            faults++;
        }
        printf("Frames: ");
        for (j = 0; j < n; j++)
        {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        if (hit)
            printf(" -> HIT");
        else
            printf(" -> MISS");

        printf("\n");
    }

    printf("\nTotal Hits   = %d\n", hits);
    printf("Total Misses = %d\n", faults);
    printf("Total Page Faults = %d\n", faults);

    return 0;
}


