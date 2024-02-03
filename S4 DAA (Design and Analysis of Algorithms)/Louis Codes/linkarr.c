#include<stdio.h>
#include <time.h>
#include <stdlib.h>


struct node
{
	int val;
	struct node *next;
};

struct node *head=NULL,*pos=NULL,*tail=NULL;

void insert(int v)
{
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->val=v;
		tail=head;
	}
	else
	{
		tail->next=(struct node*)malloc(sizeof(struct node));
		tail=tail->next;
		tail->val=v;
	}

}

/*
void disp()
{
	pos=head;
	while(pos!=NULL)
	{
		printf("%d ",pos->val);
		pos=pos->next;
	}
}
*/
void removell(int v)
{
	struct node *temp=NULL,*del=NULL;
	pos=head;
	if(head->val==v)
	{
		del=head;
		head=head->next;
		del->next=NULL;
		free(del);
	}
	else
	{
		while(pos!=NULL)
		{
			if(pos->val==v)
			{
				del=pos;
				temp->next=pos->next;
				del->next=NULL;
				free(del);
				break;
			}
			temp=pos;
			pos=pos->next;
		}
	}
	
}



void nextlarll(int v)
{
	int next=-1;
	pos=head;
	while(pos!=NULL)
	{
		if(pos->val >v & (pos->val<=next || next==-1))
			next=pos->val;
		pos=pos->next;
	}
	printf("%d",next);
}


void removeArr(int v,int a[],int *n)
{
	int f=0;
	for(int i=0;i<*n;i++)
	{
		if(a[i]==v)
		{
			f=1;
		}
		
		if(f)
			a[i]=a[i+1];
			
	}
	*n=*n-1;
}

void nextlarArr(int v,int a[],int n)
{
	int next=-1;
	for(int i=0;i<n;i++)
	{
		if( a[i]>v & (a[i]<=next || next==-1))
			next=a[i];
	}
	printf("%d",next);
}

void disp(int l[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",l[i]);
	}
}

void main()
{
	srand(time(NULL));  
	
	clock_t start_t, end_t,start_t2, end_t2;

	double total_t,del_t,next_t;

	int r = rand();
	int a[1000000],n,k,num;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		num=rand()%10000;
		a[i]=num;
		insert(num);
	}
	//disp(a,n);
	printf("\nEnter number to remove: ");
	scanf("%d",&k);

	//ARRAY
	printf("\nARRAY\n");
	start_t = clock();
	removeArr(k,a,&n);
	end_t = clock();
	//disp(a,n);

	
	start_t2 = clock();
	printf("\nNext larger number: ");
	nextlarArr(k,a,n); 
	end_t2 = clock();
	

	del_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	next_t = (double)(end_t2 - start_t2) / CLOCKS_PER_SEC;
	
	printf("\nTime taken for Array\ndeletion: %f\nnext largest: %f",del_t,next_t);
	
	//LINKLIST
	printf("\n\nLINKLIST\n");
	start_t = clock();
	removell(k);
	end_t = clock();
	//disp(a,n);

	
	start_t2 = clock();
	printf("\nNext larger number: ");
	nextlarll(k); 
	end_t2 = clock();
	
	
	del_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	next_t = (double)(end_t2 - start_t2) / CLOCKS_PER_SEC;
	
	printf("\nTime taken for Linklist\ndeletion: %f\nnext largest: %f",del_t,next_t);
	
}
	
	
