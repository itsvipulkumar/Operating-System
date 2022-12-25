#include <stdio.h>
int main()
{
    int n, tq,x, counter=0;
    int wt=0, tat=0;
    int sum=0,i;
    printf("Enter number of process : ");
    scanf("%d", &n);
    x=n;
    int bt[10], at[10];
    int pid[n];
    printf("Enter AT : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &at[i]);
    printf("Enter BT : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &bt[i]);
    int temp[10];
    for (int i = 0; i < n; i++)
    {
        temp[i] = bt[i];
        pid[i] = i;
    }

    printf("Enter time quanta ");
    scanf("%d", &tq);
       printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");

    for ( sum = 0, i = 0; x != 0;)
    {
        if (temp[i] <= tq && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if (temp[i] > 0)
        {
            sum = sum + tq;
            temp[i] = temp[i] - tq;
        }
        if (temp[i] == 0 && counter == 1)
        {
            // print value
            x--;
            printf("\n%d\t%d\t%d", i+1, sum - bt[i] - at[i], sum -at[i]);
            wt = wt + sum - bt[i] - at[i];
            tat = tat + sum - at[i];
            counter=0;
        }
        if(i==n-1)
        {
            i=0;
        }
        else if(at[i+1]<=sum)
        i++;
        else 
        i=0;
    }
    return 0;
}