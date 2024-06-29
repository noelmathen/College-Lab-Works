#include<stdio.h>

struct process{
    int pid, at, bt, ct, tat, wt;
}p[20];
float avgTAT=0, avgWT=0;

void swap(struct process *a, struct process *b){
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void sortByAT(int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((p[i].at > p[j].at) || (p[i].at == p[j].at && p[i].pid > p[j].pid)){
                swap(&p[i], &p[j]);
            }
        }
    }
}

void sortByBT(int n, int i, int ict){
    for(int a=i+1; a<n; a++){
        for(int b=a; b<n; b++){
            if((p[a].bt > p[b].bt) && (p[a].at <= ict && p[b].at <= ict)){
                swap(&p[a], &p[b]);
            }
        }
    }
}

void sortByPID(int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(p[i].pid > p[j].pid){
                swap(&p[i], &p[j]);
            }
        }
    }
}

void sjf(int n){
    sortByAT(n);
    int ict=0;
    ict = p[0].at;
    for(int i=0; i<n; i++){
        if(p[i].at > ict)
            p[i].ct = p[i].at + p[i].bt;
        else
            p[i].ct = ict + p[i].bt;
        ict = p[i].ct;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avgTAT += p[i].tat;
        avgWT += p[i].wt;
        sortByBT(n,i,ict);
    }
    avgTAT /= n;
    avgWT /= n;
}

void display(int n){
    sortByPID(n);
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++){
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage TAT: %f\nAverage WT: %f\n",avgTAT, avgWT);
}

void main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("\nFor process %d:\n",i);
        printf("Enter arrival time: ");
        scanf("%d",&p[i].at);
        printf("Enter burst time  : ");
        scanf("%d",&p[i].bt);
        p[i].pid=i;
    }
    sjf(n);
    display(n);
}