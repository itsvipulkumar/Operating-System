#include <stdio.h>
int main()
{
    int st[] = {4, 1, 2, 4, 5};
    int page_fault = 0;
    int no_of_frames = 3;
    int m, n, s, pages;
    pages = sizeof(st) / sizeof(st[0]);
    int temp[no_of_frames];
    for (m = 0; m < no_of_frames; m++)
    {
        temp[m] = -1;
    }

    for (int i = 0; i < pages; i++)
    {
        s = 0;
        for (int j = 0; j < no_of_frames; j++)
        {
            if (st[i] == temp[j])
            {
                s++;
                page_fault--;
            }
        }
        page_fault++;
        if ((page_fault <= no_of_frames) && (s == 0))
        {
            temp[i] = st[i];
        }
        else if (s == 0)
        {
            temp[(page_fault - 1) % no_of_frames] = st[i];
        }
    }
    printf("page fault : %d", page_fault);

    return 0;
}