#include<stdio.h>
#define N 4
void init(int arr[][N])
{
	int i, j;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			arr[i][j]=0;
	}
}

void addedge(int arr[][N], int s, int d)
{
	arr[s][d]=1;
	arr[d][s]=1;
}

void printgraph(int arr[][N])
{
	int i,j;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
}

void main()
{
	int graph[N][N];
	init(graph);
	addedge(graph, 0, 1);
	addedge(graph, 0, 2);
	addedge(graph, 1,3);
	addedge(graph, 3,2);
	printgraph(graph);
}