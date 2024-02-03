#include <stdio.h>
#include <stdlib.h>


int m[4][4]={{0,10,15,20},
			 {5,0, 9, 10},
		  	 {6,13,0, 12},
			 {8,8, 9, 0}};
/*
			 
 int m[4][4]={{ 0, 10, 15, 20 },{ 10, 0, 35, 25 },{ 15, 35, 0, 30 },{ 20, 25, 30, 0 } };*/
 

int path[5]={1,-1,-1,-1,1}; 
int n=4;

int mem[30][30];
void ini()
{
	for(int i=0;i<30;i++)
		for(int j=0;j<40;j++)
			mem[i][j]=-1;
}

struct ar
{
	int d[4];
};

void dup(int ac[],int ab[])
{
	for(int i=0;i<n;i++)
	{
		ac[i]=ab[i];
		printf("%d ",ac[i]);
	}
}

void removeArr(int q,int a[],int *n)
{
	int flag=0;
	for(int i=0;i<*n;i++)
	{
		if(a[i]==q)
			flag=1;
		if(flag)
			a[i]=a[i+1];
	}
	*n=*n-1;
}

void disp(int l[],int n)
{
	printf("\n^");
	for(int i=0;i<n;i++)
	{
		printf("%d ",l[i]+1);
	}
	printf("^\n");
}

void check(int r,struct ar s,int sz);
		
	
	
/*
int travelee(int r,int s[],int sz)
{	
	
	removeArr(r,s,&sz);
	disp(s,sz);
	int aa;
	if(sz<=1)
	{	printf("#m=%d\n ",m[r][0]);
		return m[r][0];
}		
	
	else
	{	
		int v=-1,c,g,t;
		for(int j=0;j<sz;j++)
		{	//printf("#%d,%d\n ",r,j);
			t=s[j];
			c=m[r][t];
			g=travel(t,s,sz);
			printf(" $%d @%d ",g,s[j]);
			if(v==-1 || v<c+g)
				v=c+g;
		}
		printf("#v=%d\n ",v);
		return v;
	}
}
*/
int travel(int r,struct ar s,int sz)
{	
	
	removeArr(r,s.d,&sz);
	disp(s.d,sz);
	if(sz<1)
	{	printf("#m=%d	r=%d	sz=%d\n ",m[r][0],r+1,sz);
		path[sz+1]=r+1;
		return m[r][0];
}		
	
	else
	{	
		int v=-1,c,g,t,nod;
		for(int j=0;j<sz;j++)
		{	//printf("#%d,%d\n ",r,j);
			t=s.d[j];
			c=m[r][t];
			g=travel(t,s,sz);
			printf(" $%d @%d ",g,s.d[j]+1);
			if(v==-1 || v>c+g)
			{	
				v=c+g;
				nod=t;
			}
		}
		if(sz!=4)
		path[sz+1]=r+1;
		printf("#v=%d	r=%d	t=%d	sz=%d\n ",v,r+1,nod,sz);
		
		return v;
	}
}
void main()
{
	ini();
	struct ar h;
	int b[4]={0,1,2,3};
	dup(h.d,b);
	disp(h.d,4);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			printf("%d\t",m[i][j]);
		printf("\n");
	}
	int f;
	f=travel(0,h,4);
	printf("\nMAX=%d\n",f);
	
	for(int j=0;j<5;j++)
		printf("%d\t",path[j]);
	
	
}	
