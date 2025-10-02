#include <stdio.h>

int main()
 {
    int i,j,n;
    int frames,index=0,pageFaults=0,found;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    int referenceString[n];

    printf("Enter the reference string: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&referenceString[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d",&frames);

    int memory[frames];
    for(i=0;i<frames; i++)
    {
        memory[i]=-1;
    }

    printf("\nReference String: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",referenceString[i]);
    }
    printf("\n\n");

    for(i=0;i<n;i++)
        {
        found = 0;
        for (j=0;j<frames;j++)
         {
            if (memory[j]==referenceString[i])
            {
                found=1;
                break;
            }
        }

        if (!found)
        {
            memory[index]=referenceString[i];
            index=(index+1)%frames;
            pageFaults++;
        }

        printf("Step %d: ",i+1);
        for (j = 0; j < frames; j++)
        {
            if (memory[j]==-1)
                printf("- ");
            else
                printf("%d ",memory[j]);
        }
        if (!found)
            printf("  <-- Page Fault");
        else
            printf("  <-- No Fault");
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

