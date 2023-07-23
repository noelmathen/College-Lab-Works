#include<stdio.h>

struct process
{
    int pid, at, bt, ct, tat, wt;
}p[20], temp;

void swap(struct process *a, struct process *b)
{
    temp = *a;
    *a = *b;
    *b = temp;
}

void ATSort(int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(p[j].at > p[j+1].at || (p[j].at==p[j+1].at && p[j].pid>p[j+1].pid))
            {
                swap(&p[j], &p[j+1]);
            }
        }
    }
}

void printTable(int n)
{
    printf("\nTABLE:-\n\nPID\tAT\tBT\tCT\tTAT\tWT");
    for(int i=0; i<n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
}

void fcfs(int n)
{
    float totTAT=0, totWT=0;
    float avgTAT=0, avgWT=0;
    ATSort(n);
    p[0].ct = p[0].at + p[0].bt;
    for(int i=0; i<n; i++)
    {
        p[i+1].ct = p[i].ct + p[i+1].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        totTAT += p[i].tat;
        totWT += p[i].wt;
    }
    avgTAT = totTAT/n;
    avgWT = totWT/n;
    printTable(n);
    printf("\n\nAverage TAT: %.2f",avgTAT);
    printf("\nAverage WT: %.2f",avgWT);
}

void main()
{
    int n;
    printf("\n*********FIRST COME FIRST SERVE*********\n");
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("\nFor process %d:-\n",i+1);
        printf("Enter PID: ");
        scanf("%d", &p[i].pid);
        printf("Enter AT: ");
        scanf("%d", &p[i].at);
        printf("Enter BT: ");
        scanf("%d", &p[i].bt);
    }
    fcfs(n);
}

