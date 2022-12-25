#include <stdio.h>
#include <stdbool.h>
#include <math.h>
struct process
{
    int pid;
    int AT, BT, TAT, RT, start, CT, WT;
} ps[100];
int main()
{
    int n;
    int complted = 0;
    int currTime = 0;
    bool isComplted[100] = {false};
    printf("Enter no of process : ");
    scanf("%d", &n);
    printf("Enetr AT for %d process ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &ps[i].AT);
    printf("Enetr BT for %d process ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ps[i].BT);
        ps[i].pid = i;
    }

    while (complted != n)
    {

        int min_index = -1;
        int min_BT = 999999;
        for (int i = 0; i < n; i++)
        {
            if (ps[i].AT <= currTime && isComplted[i] == false)
            {
                if (ps[i].BT < min_BT)
                {
                    min_BT = ps[i].BT;
                    min_index = i;
                }
                else if (ps[i].BT == min_BT)
                {
                    if (ps[i].AT < ps[min_index].AT)
                    {
                        min_BT = ps[i].BT;
                        min_index = i;
                    }
                }
            }
        }
        if (min_index == -1)
        {
            currTime++;
        }
        else
        {
            ps[min_index].start = currTime;
            ps[min_index].CT = ps[min_index].start + ps[min_index].BT;
            ps[min_index].TAT = ps[min_index].CT - ps[min_index].AT;
            ps[min_index].WT = ps[min_index].TAT - ps[min_index].BT;

            currTime = ps[min_index].CT;

            complted++;
            isComplted[min_index] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n %d\t\t %d\t %d\t %d\t %d\t %d\n", ps[i].pid, ps[i].AT, ps[i].BT, ps[i].CT, ps[i].TAT, ps[i].WT);
    }

    return 0;
}