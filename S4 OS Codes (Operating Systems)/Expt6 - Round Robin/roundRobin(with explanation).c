// I WOULD SUGGEST SOLVING ATLEAST 1 ROUND ROBIN PROBLEM BEFORE U TRY TO LEARN THIS CODE. TRUST ME, IT WILL BE WAY EASIER.
// This round robing program was not asked for both the lab exams...so...idk....who knows...
// And also...u can make this code more easier by declaring many of the variables globally. I just tried to stick on to good coding practices for once hehehehe. The sem is over and im too lazy tired and drained from the rajagiri bs i dont wanna make this code better. so....enjoy
// If u feel like there are too much comments, go to chatgpt and ask it to remove comments. simple.
#include <stdio.h>
struct Process {
    int pid, at, bt, original_bt, ct, tat, wt, scheduled;
}p[100];

int n, tq;
float avtat=0, avwt=0;

void sortByAT()
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if( (p[i].at > p[j].at) || (p[i].at==p[j].at && p[i].pid>p[j].pid)) //if the arrival times are same, then it is sorted based on the pid(or bt, im not really sure)
                swap(&p[i], &p[j]);
        }
    }
}

void push(int rq[], int *tail, int index) { //here the star(pointer) is used as a reference to the variable from the calling function so that the changes made in this function is also applied to the variable in the calling function. index is the index.number of the process that is pushed to thr RQ
    rq[++(*tail)] = index;  //first increment tail, then push
}

int pop(int rq[], int *tail) {
    if (*tail == -1)    //if queue is empty
        return -1;
    int del = rq[0];    //the is the deleted/dequed element, here, the process index/number
    for (int i=0; i < *tail; i++)
        rq[i] = rq[i+1];    //left shift
    (*tail)--; //tail is decremented after dequeue
    return del; 
}

void execute(int i, int *tu) {  
    int time = (p[i].bt > tq) ? tq : p[i].bt;   //If the current process's BT is greater than TQ, then the time of execution of process is the TQ. otherwise, the time of execution of process is its BT itself
    *tu += time;    //'time' variable is the time taken to exectue that particular process. thus this time is added to the time units.If current time is 2(tu), and a process gets executed for 3 seeconds(time), then the tu = 2+3 = 5.
    p[i].bt -= time;    //the bt of the current process is decremented
    if (p[i].bt == 0) { //checks if the current process is completely executed. Only then its CT, TAT and WT is calculated.
        p[i].ct = *tu;  //CT is of the process is the current time till now
        p[i].tat = p[i].ct - p[i].at;   //hope u know all this:)
        p[i].wt = p[i].tat - p[i].original_bt;
        avtat += p[i].tat;
        avwt += p[i].wt;
    }
}

void addNewProcesses(int rq[], int *tail, int tu) {     //"This function is to check whether we should add newly arrived processes to the ready queue based on their AT
    for (int i = 0; i < n; i++) {
        if (p[i].bt == 0 || p[i].scheduled == 1)    //if the process has completely finshed its execution or is already in the readyqueue, then skip this iteration and continue to next iteration
            continue;
        if (p[i].at <= tu) {    //if the process has arrived already(its arrival time <= the current time), then add it to the ready queue
            push(rq, tail, i);
            p[i].scheduled = 1; //mark it as scheduled
        }
    }
}

void rr() {
    sortByAT();
    int rq[20]; //ready queue
    int tail = -1;  //tail's(end/back of queue) initial position
    int tu = 0;     //time units/present time
    push(rq, &tail, 0); //pushing the 1st process(with index 0) to the RQ to start the RR scheduling
    p[0].scheduled = 1; //since it is p[0] is now present in RQ, it is scheduled. Therefore 1.
    while (1) {
        int current_task = pop(rq, &tail);  // pop/dequeue the frontmost process in the queue.
        if (current_task == -1) //checking if queue is empty. If empty, it means all the process are scheduled and executed
            break;
        execute(current_task, &tu); //the current task is executed. check function defenition for more.
        addNewProcesses(rq, &tail, tu);
        if (p[current_task].bt > 0) //if the current process hasnt completely executed(BT>0), then is is enqueued
            push(rq, &tail, current_task);
    }
    avtat /= n;
    avwt /= n;
}

void display() {    //PMDisplayDisplay(only legends will understand)
    printf("\nRR\n");   //this is to print "RR"
    printf("Time quantum: %d\n", tq);   //This is to print "Time quantum"
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n"); //This is to print the column names of the table
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].original_bt, p[i].ct, p[i].tat, p[i].wt);    //This is to print the table
    }
    printf("\nAverage turn around time = %f\nAverage waiting time = %f\n", avtat, avwt);    //This is to print your mom
}

void main() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Time Quantum: ");
    scanf("%d", &tq);
    for (int i = 0; i < n; i++) {
        printf("\nFor process %d:\n", i + 1);
        p[i].pid = i+1; //P1, P2, P3.....
        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
        p[i].original_bt = p[i].bt; //since the BT of every process is decremented, the original bt is stored for every process for the final calculations
        p[i].scheduled = 0; //0 means the process is not currently being schesuled
    }
    rr();
    display();
}
// GPAY 100 Rs. 
// Phone number: 9188022697
