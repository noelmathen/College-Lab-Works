#include<stdio.h>
struct process{
    int pid, at, bt, original_bt, ct, tat, wt, scheduled;
}p[20];
int n, tq;
float avgTAT=0, avgWT=0;

void push(int rq[], int *tail, int index){
    rq[++(*tail)] = index;
}

int pop(int rq[], int *tail){
    int del = rq[0];
    if(*tail==-1)
        return -1;
    for(int i=0; i<*tail; i++){
        rq[i] = rq[i+1];
    }
    (*tail)--;
    return del;
}

void execute(int i, int *tu){
    int time = p[i].bt>tu?tu:p[i].bt;
    *tu += time;
    p[i].bt -= *tu;
    if(p[i].bt == 0){
        p[i].ct = *tu;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avgTAT += p[i].tat;
        avgWT += p[i].wt;
    }
}

void addNewProcess(int rq[], int *tail, int tu){
    for(int i=0; i<n; i++){
        if(p[i].bt == 0 || p[i].scheduled == 1)
            continue;
        if(p[i].at <= tu){
            p[i].scheduled = 1;
            push(rq, *tail, i);
        }
    }
}

void rr(){
    int rq[100], tail=-1, tu=0;
    push(rq, &tail, 0);
    p[0].scheduled = 0;
    while(1){
        int currentTask = pop(rq, &tail);
        if(currentTask == -1)
            break;
        execute(currentTask, &tu);
        addNewProcess(rq, &tail, tu);
        if(p[currentTask].bt > 0){
            pudh(rq, &tail, currentTask);
        }
    }
    avgTAT /= n;
    avgWT /= n;
}

void display(){
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++){
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t", p[i].pid, p[i].at, p[i].original_bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage TAT: %f\nAverage WT: %f\n",avgTAT, avgWT);
}

void main(){
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum       : ");
    scanf("%d", &tq);
    for(int i=0; i<n; i++){
        printf("\nFor process %d:\n",i);
        printf("Enter arrival time: ");
        scanf("%d",&p[i].at);
        printf("Enter burst time  : ");
        scanf("%d",&p[i].bt);
        p[i].pid=i+1;
        p[i].original_bt = p[i].bt;
        p[i].scheduled = 0;
    }
    rr();
    display();
}