#include<stdio.h>
#include<stdbool.h>
#define MAX_N 100

int graph[MAX_N][MAX_N];
int nodes;

void initgraph()
{
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			graph[i][j]=0;
		}
	}
}

void addedge(int st,int en, int weight)
{
	graph[st][en]=weight;
	graph[en][st]=weight;
}	

int minkey(int key[],bool mstset[])
{
	int min=9999999;
	int minI;
	for(int i=0;i<nodes;i++)
	{
		if(mstset[i] == false && key[i] < min)
		{
			min = key[i];
			minI=i;
		}
	}

	return minI;
}

void printMST(int parent[], int n)
{
	printf("Edge \tWeight\n");
	for(int i=1; i<nodes; i++)
		printf("%d - %d \t%d\n", parent[i],i,graph[i][parent[i]]);
}


void primMST()
{
	int parent[MAX_N];
	int key[MAX_N];
	bool mstset[MAX_N];
	
	for(int i=0;i<nodes;i++)
	{
		key[i]=9999999;
		mstset[i]=false;	
	}
	key[0]=0;
	parent[0]=-1;

	for(int no=0;no<nodes;no++)
	{
		int u=minkey(key,mstset);
		mstset[u]=true;
		
		for(int v=0;v<nodes;v++)
		{
			if(graph[u][v] && mstset[v] == false && graph[u][v] < key[v])
			{
				parent[v]=u;
				key[v]=graph[u][v];
			}
		}
	}
	printMST(parent,nodes);
}

int main()
{
	int x,y,z,edge;
	printf("Enter number of nodes: ");
	scanf("%d",&nodes);
	printf("Enter number of edges: ");
	scanf("%d",&edge);
	for(int i=0;i<edge;i++)
	{
		printf("Enter start node: ");
		scanf("%d",&x);
		printf("Enter end node: ");
		scanf("%d",&y);
		printf("Enter weight: ");
		scanf("%d",&z);
		addedge(x,y,z);
	}
	primMST();

	return 0;
}
