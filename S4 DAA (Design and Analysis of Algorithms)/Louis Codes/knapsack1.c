#include <stdio.h>
#include <stdlib.h>


void swap(float *a, float *b)
{
	float t = *a;
	*a = *b;
	*b = t;
}

struct obj
{
	int o;
	int p;
	int w;
	float x;
	float r;
}k[10],tem;

void sort(int n)
{
	for (int i=0; i<n-1; i++)
	{
		for (int j=0; j<n-i-1; j++)
		{
			if (k[j].r <k[j+1].r)
			{
				tem=k[j];
				k[j]=k[j+1];
				k[j+1]=tem;
			}
		}
	}
}

void main()
{
	int n,m;
	int i, j;
	printf("Enter number of objects: ");
	scanf("%d",&n);
	printf("Enter max capacity: ");
	scanf("%d",&m);
	
	for(i=0; i<n; i++)
	{
		printf("Enter profit of object %d: ",i+1);
		scanf("%d",&k[i].p);
		printf("Enter weight of object %d: ",i+1);
		scanf("%d",&k[i].w);
		k[i].r=k[i].p/k[i].w;
		k[i].o=i+1;
	}
	
	
	
	for(i=0; i<n; i++)
		k[i].x=0;
		
	int u=m;
	for(i=0; i<n; i++)
	{
		if(k[i].w>u)
			break;
		k[i].x=1;
		u=u-k[i].w;
	}
	
	if(i<n)
		k[i].x= u / (k[i].w);
	
	printf("Solution set\nRatio\t(");
	for(i=0; i<n; i++)
	{
		//printf("%.2f\t%.2f\t%.2f\t%.2f\n",r[i],x[i],p[i],w[i]);
		printf("%.2f\t",k[i].x);
	}
	printf(")\nObject\t");
	for(i=0; i<n; i++)
	{
		//printf("%.2f\t%.2f\t%.2f\t%.2f\n",r[i],x[i],p[i],w[i]);
		printf("%d\t",k[i].o);
	}
	float maxc=0;
	for(i=0; i<n; i++)
		maxc=maxc+(k[i].x)*(k[i].p);
		
	printf("\nmax profit=$%.2f\n",maxc);
	
}
				
