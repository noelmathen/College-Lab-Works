#include <stdio.h>

struct Process {
    int pid, at, bt, original_bt, ct, tat, wt, scheduled;
} p[100];

int n, tq;
float avtat = 0, avwt = 0;

void sortByAT() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((p[i].at > p[j].at) || (p[i].at == p[j].at && p[i].pid > p[j].pid))
                swap(&p[i], &p[j]);
        }
    }
}

void push(int rq[], int *tail, int index) {
    rq[++(*tail)] = index;
}

int pop(int rq[], int *tail) {
    if (*tail == -1)
        return -1;
    int del = rq[0];
    for (int i = 0; i < *tail; i++)
        rq[i] = rq[i + 1];
    (*tail)--;
    return del;
}

void execute(int i, int *tu) {
    int time = (p[i].bt > tq) ? tq : p[i].bt;
    *tu += time;
    p[i].bt -= time;
    if (p[i].bt == 0) {
        p[i].ct = *tu;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].original_bt;
        avtat += p[i].tat;
        avwt += p[i].wt;
    }
}

void addNewProcesses(int rq[], int *tail, int tu) {
    for (int i = 0; i < n; i++) {
        if (p[i].bt == 0 || p[i].scheduled == 1)
            continue;
        if (p[i].at <= tu) {
            push(rq, tail, i);
            p[i].scheduled = 1;
        }
    }
}

void rr() {
    sortByAT();
    int rq[20];
    int tail = -1;
    int tu = 0;
    push(rq, &tail, 0);
    p[0].scheduled = 1;
    while (1) {
        int current_task = pop(rq, &tail);
        if (current_task == -1)
            break;
        execute(current_task, &tu);
        addNewProcesses(rq, &tail, tu);
        if (p[current_task].bt > 0)
            push(rq, &tail, current_task);
    }
    avtat /= n;
    avwt /= n;
}

void display() {
    printf("\nRR\n");
    printf("Time quantum: %d\n", tq);
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].original_bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage turn around time = %f\nAverage waiting time = %f\n", avtat, avwt);
}

void main() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Time Quantum: ");
    scanf("%d", &tq);
    for (int i = 0; i < n; i++) {
        printf("\nFor process %d:\n", i + 1);
        p[i].pid = i + 1;
        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
        p[i].original_bt = p[i].bt;
        p[i].scheduled = 0;
    }
    rr();
    display();
}
