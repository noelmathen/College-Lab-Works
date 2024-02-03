#include<stdio.h>
#include<stdlib.h>

struct process
{
	int pid;
	int pri;
	int at;
	int wt;
	int tat;
	int bt;
	int ct;
};

void swap(int i,int j,struct process p[20])
{
	struct process temp=p[i];
	p[i]=p[j];
	p[j]=temp;
}


void atsort(struct process p[20],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				swap(i,j,p);
			}
		}
	}
}


void pidsort(struct process p[20],int n)
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{	
			{
				if((p[i].at==p[j].at) && (p[i].pid>p[j].pid))
				{
					swap(i,j,p);
				}
			}
		}
	}
}


void btsort(struct process p[20],int i,int n,int ict)
{
	
	for(int a=i+1;a<n;a++)
	{
		for(int b=a;b<n;b++)
		{	
			if((p[a].at<=ict) && (p[b].at<=ict))
			{
				if(p[a].pri>p[b].pri)
				{
					swap(a,b,p);
				}
			}
		}
	}
}

void sjf(struct process p[20],int n)
{
	atsort(p,n);
	pidsort(p,n);
	
	int ict=p[0].at;
	for(int i=0;i<n;i++)
	{
		if(ict<p[i].at)
			p[i].ct=p[i].at+p[i].bt;
		else
			p[i].ct=ict+p[i].bt;
		ict=p[i].ct;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		btsort(p,i,n,ict);
		
	}
}

void main()
{
	struct process p[20];
	int n;
	float avwt,avtat,twt=0,ttat=0;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		printf("Enter pid: ");
		scanf("%d",&p[i].pid);
		printf("Enter pri: ");
		scanf("%d",&p[i].pri);
		printf("Enter at: ");
		scanf("%d",&p[i].at);
		printf("Enter bt: ");
		scanf("%d",&p[i].bt);
	}
	
	sjf(p,n);
	
	printf("Process id\tPriority\tArrival time\tburst time\tcompletion time\tTurn Around time\twait time\n");
	for(int i=0;i<n;i++)
	{
		twt+=p[i].wt;
		ttat+=p[i].tat;
		printf("%d\t\t",p[i].pid);
		printf("%d\t\t",p[i].pri);
		printf("%d\t\t",p[i].at);
		printf("%d\t\t",p[i].bt);
		printf("%d\t\t",p[i].ct);
		printf("%d\t\t\t",p[i].tat);
		printf("%d\n",p[i].wt);
	}
	
	avwt=twt/(float)n;
	avtat=ttat/(float)n;
	
	printf("\nAverage Turn Around time: %f",avtat);
	printf("\nAverage wait time: %f\n",avwt);
}
