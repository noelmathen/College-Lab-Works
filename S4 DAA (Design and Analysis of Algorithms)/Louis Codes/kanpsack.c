#include <stdio.h>
#include <stdlib.h>


void swap(float *a, float *b)
{
	float t = *a;
	*a = *b;
	*b = t;
}

void main()
{
	int n,m;
	float x[10],p[10],w[10],r[10],o[10];
	int i, j;
	printf("Enter number of objects: ");
	scanf("%d",&n);
	printf("Enter max capacity: ");
	scanf("%d",&m);
	
	for(i=0; i<n; i++)
	{
		printf("Enter profit of object %d: ",i+1);
		scanf("%f",&p[i]);
		printf("Enter weight of object %d: ",i+1);
		scanf("%f",&w[i]);
		r[i]=p[i]/w[i];
		o[i]=i+1;
	}
	
	
	for (i=0; i<n-1; i++)
	{
		for (j=0; j<n-i-1; j++)
		{
			if (r[j] <r[j+1])
			{
				swap(&r[j], &r[j + 1]);
				swap(&o[j], &o[j + 1]);
				swap(&p[j], &p[j + 1]);
				swap(&w[j], &w[j + 1]);
			}
		}
	}
	for(i=0; i<n; i++)
		x[i]=0;
		
	int u=m;
	for(i=0; i<n; i++)
	{
		if(w[i]>u)
			break;
		x[i]=1;
		u=u-w[i];
	}
	
	if(i<n)
		x[i]=u/w[i];
	
	printf("Solution set:(\n");
	for(i=0; i<n; i++)
	{
		//printf("%.2f\t%.2f\t%.2f\t%.2f\n",r[i],x[i],p[i],w[i]);
		printf("%.2f\t",x[i]);
	}
	printf(")\nObject: \n");
	for(i=0; i<n; i++)
	{
		printf("%.0f\t",o[i]);
	}
	float maxc=0;
	for(i=0; i<n; i++)
		maxc=maxc+x[i]*p[i];
		
	printf("\nmax profit=$%.2f\n",maxc);
	
}
				

