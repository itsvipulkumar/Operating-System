#include <stdio.h>
#include <stdbool.h>
struct process
{
    int pid;
    int AT, BT, TAT, RT, start, CT, WT;
} ps[100];
int max(int a, int b)
{
    return (a > b) ? a : b;
}
void sortByAT(struct process ps[], int n)
{
    struct process temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (ps[j + 1].AT < ps[j].AT)
            {
                temp = ps[j + 1];
                ps[j + 1] = ps[j];
                ps[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ps[i].AT);
}
void findValue(struct process ps[], int n)
{
    for (int i = 0; i < n; i++)
    {
        ps[i].start = (i == 0) ? ps[i].AT : max(ps[i].AT, ps[i - 1].CT);

        ps[i].CT = ps[i].start + ps[i].BT;
        ps[i].TAT = ps[i].CT - ps[i].AT;
        ps[i].WT = ps[i].TAT - ps[i].BT;
    }
    printf("\n Process\t AT\t BT\t Ct\t TAT\t WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n %d\t\t %d\t %d\t %d\t %d\t %d\n", ps[i].pid, ps[i].AT, ps[i].BT, ps[i].CT, ps[i].TAT, ps[i].WT);
    }
}
int main()
{
    int n;
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
    sortByAT(ps, n);
    findValue(ps, n);
    return 0;
}