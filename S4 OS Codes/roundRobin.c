#include <stdio.h>
#include <stdlib.h>

struct process
{
	int pid, at, wt, tat, bt_print, bt, ct, scheduled;
} p[20],temp;

int n, tq;
float twt, ttat, avwt, avtat;
int time_units=0;
int tail=-1, readyqueue[20];

void push(int idx)
{
	readyqueue[++tail]=idx;
}

int pop()
{
	int idx,i;
	if(tail==-1)
		return -1;
	idx=readyqueue[0];
	for(i=1;i<=tail;++i)
		readyqueue[i-1]=readyqueue[i];
	--tail;
	return idx;
}

void display_item(int i)
{
	printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt_print,p[i].ct,p[i].tat,p[i].wt);
}

void display()
{
	int i;
	printf("Time quantum: %d\n",tq);
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
		display_item(i);
	printf("\nAverage turn around time=%f\nAverage waiting time=%f\n",avtat,avwt);
}

void swap(int i, int j)
{
	temp=p[i];
	p[i]=p[j];
	p[j]=temp;
}

void pid_sort()
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(p[j].pid>p[j+1].pid)
				swap(j,j+1);
}

void at_sort()
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(p[j].at>p[j+1].at)
				swap(j,j+1);
}

int execute(int i)
{
	int time=0;
	if(p[i].bt>tq)
	{
		time=tq;
		time_units+=time;
	}
	else
	{
		time=p[i].bt;
		time_units+=time;
		p[i].ct=time_units;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt_print;
		ttat+=p[i].tat;
		twt+=p[i].wt;
	}
	p[i].bt=p[i].bt-time;
	return time;
}

void anat(int last_exec)
{
	int i;
	for(i=0;i<n;++i)
	{
		if(p[i].bt==0)
			continue;
		if(p[i].scheduled==1)
			continue;
		if(p[i].at<=time_units)
		{
			push(i);
			p[i].scheduled=1;
		}
	}
}

void rr()
{
	int current_task;
	int time;
	at_sort();
	push(0);
	p[0].scheduled=1;
	while(1)
	{
		current_task=pop();
		if(current_task==-1)
			break;
		time=execute(current_task);
		anat(current_task);
		if(p[current_task].bt>0)
			push(current_task);
	}
	avtat=ttat/n;
	avwt=twt/n;
	pid_sort();
	printf("\nRR");
	display();
}

int main()
{
	int i;
	printf("\nEnter number of processes: ");
	scanf("%d",&n);
	printf("Time Quantum: ");
	scanf("%d",&tq);
	for(i=0;i<n;i++)
	{
		printf("\nFor process %d: \n",i+1);
        p[i].pid = i;
        printf("Enter arrival time: ");
        scanf("%d",&p[i].at);
        printf("Enter burst time  : ");
        scanf("%d",&p[i].bt);
		p[i].bt_print=p[i].bt;
	}
	rr();
}
