#include <stdio.h>
 
int n, i, j, visited[10], queue[10], front = -1, rear = -1;
int adj[10][10];
 
void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (adj[v][i] && !visited[i])
            queue[++rear] = i;
    if (front <= rear)
    {
        visited[queue[front]] = 1;
        bfs(queue[front++]);
    }
}
 
void main()
{
    int v,flag=0,cflag=0,comp=0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        queue[i] = 0;
        visited[i] = 0;
    }
    printf("Enter adjacency matrix:    \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    v=1;
    for (int k = 1; k <= n; k++)
    {
    	cflag=0;
    	comp++;
    	bfs(v);
    	visited[v]=1;
    	for (i = 1; i <= n; i++)
        {	
        	if (!visited[i])
        	{    
        		v=i;
        		cflag=1;
        		break;
        	}
       			
    	}
    	if(cflag==0)
    		break;
	}
	printf("Number of Components= %d",comp);
}

