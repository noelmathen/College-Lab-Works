#include <stdio.h>

int mblock[20];
int msize;

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

void BestFit(int process[], int allocated[], int flag[], int psize)
{
    AscSort();
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
    printf("\nBlock no\t\tBlock size\t\tProcess no\t\tProcess\n");
    for (int i = 0 ; i < msize ; i++)
    {
        if(flag[i] == 1)
        
            printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",(i+1),mblock[i],allocated[i]+1,process[allocated[i]]);
        else
            printf("%d\t\t\t%d\t\t\tAllocation failed\tAllocation failed\n",(i+1),mblock[i]);
    }
}

void main()
{
    printf("********BEST FIT********\n");
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
    BestFit(process, allocated, flag, psize);
}
