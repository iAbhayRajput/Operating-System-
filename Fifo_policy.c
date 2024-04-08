#include<stdio.h>

int main()
{
    int x;
    printf("Enter no. of Pages in sequence:");
    scanf("%d", &x);

    int incomingStream[x];
    for (int i = 0; i < x; i++)
    {
        printf("Enter sequence for order %d:", i + 1);
        scanf("%d", &incomingStream[i]);
    }

    int pageFaults = 0;
    int frames;
    printf("Enter no. of frames:");
    scanf("%d", &frames);

    int pages = x;

    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3\n");
    int temp[frames];
    for (int m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }

    for (int m = 0; m < pages; m++)
    {
        int found = 0;
        for (int n = 0; n < frames; n++)
        {
            if (incomingStream[m] == temp[n])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            int replace_index = -1;
            int min_page_age = 99999;
            for (int n = 0; n < frames; n++)
            {
                int current_page_age = 0;
                for (int k = m - 1; k >= 0; k--)
                {
                    current_page_age++;
                    if (temp[n] == incomingStream[k])
                    {
                        break;
                    }
                }
                if (current_page_age < min_page_age)
                {
                    min_page_age = current_page_age;
                    replace_index = n;
                }
            }
            temp[replace_index] = incomingStream[m];
            pageFaults++;
        }

        printf("%d\t\t\t", incomingStream[m]);
        for (int n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}
