#include<stdio.h>

struct process
{
    int pid, at, bt, ct, tat, wt;
}p[20], temp;

void swap(struct process *a, struct process *b)
{
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void sortByAT(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if( (p[i].at > p[j].at) || (p[i].at==p[j].at && p[i].pid>p[j].pid)) //if the arrival times are same, then it is sorted based on the pid
                swap(&p[i], &p[j]);
        }
    }
}

void sortByBT(int i, int n, int ict)
{
    for(int a=i+1; a<n; a++)
    {
        for(int b=a; b<n; b++)
        {
            if( (p[a].bt>p[b].bt) && (p[a].at<=ict) && (p[b].at<=ict))
                swap(&p[a], &p[b]);
        }
    }
}

void sortByPID(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(p[i].pid > p[j].pid)
                swap(&p[i], &p[j]);
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

void sjf(int n)
{
    sortByAT(n);
    int ict = p[0].at;
    float totTAT=0, totWT=0;
    float avgTAT=0, avgWT=0;
    for(int i=0; i<n; i++)
    {
        if(p[i].at > ict)               //If the arrival time of the current process (p[i].at) is greater than the previous completion time (ict), it means that the current process arrived after the previous process completed. In this case, the current process starts executing from its arrival time (p[i].at) and its completion time is calculated as p[i].at + p[i].bt.
            p[i].ct = p[i].at + p[i].bt;
        else                            //If the arrival time of the current process is less than or equal to the previous completion time, it means that the current process arrived either simultaneously or before the previous process completed. In this case, the current process starts executing immediately after the previous process and its completion time is calculated as ict + p[i].bt, where ict represents the previous completion time.
            p[i].ct = ict + p[i].bt;
        ict = p[i].ct;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        sortByBT(i, n, ict);
        totTAT += p[i].tat;
        totWT += p[i].wt;
    }
    avgTAT = totTAT/n;
    avgWT = totWT/n;
    sortByPID(n);
    printTable(n);
    printf("\n\nAverage TAT: %.2f",avgTAT);
    printf("\nAverage WT: %.2f",avgWT);
}

void main()
{
    int n;
    printf("\n*********SHORTEST JOB FIRST*********\n");
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("\nFor process %d:-\n",i+1);
        p[i].pid = i;
        printf("Enter AT: ");
        scanf("%d", &p[i].at);
        printf("Enter BT: ");
        scanf("%d", &p[i].bt);
    }
    sjf(n);
    printf("EXIT");
}
