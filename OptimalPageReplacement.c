#include <stdio.h>
int main()
{
    int a, b, page_fault = 0, pos, max, c;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);

    int nf = 3;
    int frame[nf];
    for (int i = 0; i < nf; i++)
        frame[i] = -1;

    int temp[nf];

    for (int i = 0; i < n; i++)
    {
        a = 0;
        b = 0;
        for (int j = 0; j < nf; j++)
        {
            if (frame[j] == pages[i])
            {
                a = 1;
                b = 1;
                break;
            }
        }
        if (a == 0)
        {
            for (int j = 0; j < nf; j++)
            {
                if (frame[j] == -1)
                {
                    frame[j] = pages[i];
                    b = 1;
                    page_fault++;
                    break;
                }
            }
        }
        if (b == 0)
        {
            c = 0;
            for (int j = 0; j < nf; j++)
            {
                temp[j] = -1;

                for (int k = i + 1; k < n; k++)
                {
                    if (frame[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }
            for (int j = 0; j < nf; j++)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    c = 1;
                    break;
                }
            }
            if (c == 0)
            {
                max = temp[0];
                pos = 0;
                for (int j = 1; j < nf; j++)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frame[pos] = pages[i];
            page_fault++;
        }
        printf("\n");
        for(int j = 0; j < nf; j++){
            printf("%d\t", frame[j]);
        }
    }
    printf("\nTotal page fault : %d", page_fault);
     printf("\nTotal Hits : %d", n-page_fault);
    return 0;
}