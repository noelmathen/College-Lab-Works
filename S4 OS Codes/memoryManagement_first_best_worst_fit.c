#include <stdio.h>
int mblock[20];
int msize;
void SetToDefault(int flag[])
{
    for (int i = 0; i < msize; i++)
    {
        flag[i]=0;
    }
    
}

void DescSort()
{	
	int temp;
    for (int i = 0; i < msize; i++)
    {   
        for (int j = 0; j < msize - i- 1; j++)
        {
          	if (mblock[j] < mblock[j+1])
            {
            	temp = mblock[j];
                mblock[j] = mblock[j+1];
                mblock[j+1] = temp;
           	}
        }
    }
   
}

void AscSort()
{	
	int temp;
    for (int i = 0; i < msize; i++)
    {   
        for (int j = 0; j < msize - i- 1; j++)
        {
          	if (mblock[j] > mblock[j+1])
            {
            	temp = mblock[j];
                mblock[j] = mblock[j+1];
                mblock[j+1] = temp;
           	}
        }
    }
   
}

void AllocateMemory(int process[], int allocated[], int flag[], int psize)
{
    for (int i = 0 ; i < psize ; i++)
    {
        for (int j = 0 ; j < msize ; j++)
        {
            if(process[i] <= mblock[j] && flag[j] == 0)
            {
                allocated[j] = i;
                flag[j] = 1;
                break;
            }
        }
    }
    printf("Block no\t\tBlock size\t\tProcess no\t\tProcess\n");
    for (int i = 0 ; i < msize ; i++)
    {
        if(flag[i] == 1)
        
            printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",(i+1),mblock[i],allocated[i]+1,process[allocated[i]]);
        else
            printf("%d\t\t\t%d\t\t\tAllocation failed\tAllocation failed\n",(i+1),mblock[i]);
    }
}

void FirstFit(int process[], int allocated[], int flag[], int psize)
{
    printf("***FIRST FIT***\n");
    SetToDefault(flag);
    AllocateMemory(process, allocated, flag, psize);
}

void BestFit(int process[], int allocated[], int flag[], int psize)
{
    printf("\n***BEST FIT***\n");
    SetToDefault(flag);
    AscSort();
    AllocateMemory(process, allocated, flag, psize);
}

void WorstFit(int process[], int allocated[], int flag[], int psize)
{
    printf("\n***WORST FIT***\n");
    SetToDefault(flag);
    DescSort();
    AllocateMemory(process, allocated, flag, psize);
}

void main()
{
    printf("********FIRST FIT, BEST FIT AND WORST FIT********\n");
    int process[20];
    int allocated[20];
    int flag[20];
    int psize;
    printf("\nEnter the no of memory blocks: ");
    scanf("%d",&msize);
    for (int i = 0 ; i < msize ; i++)
    {
        printf("Enter size of memory block %d: ",(i+1));
        scanf("%d",&mblock[i]);
        flag[i] = 0;
    }
    printf("\nEnter the number of processes: ");
    scanf("%d",&psize);
    for (int i = 0 ; i < psize; i++)
    {
        printf("Enter size of process %d: ",(i+1));
        scanf("%d",&process[i]);
    }
    FirstFit(process, allocated, flag, psize);  //execute first fit before both best and worst else the logic wont work
    BestFit(process, allocated, flag, psize);
    WorstFit(process, allocated, flag, psize);
}
