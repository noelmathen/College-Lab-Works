#include<stdio.h>
int mblock[20], msize, pblock[20], psize, allocated[20], flag[20];

void FirstFit(){
    for(int i=0; i<psize; i++){
        for(int j=0; j<msize; j++){
            if(pblock[i] <= mblock[j] && flag[j]==0){
                allocated[j] = i;
                flag[j]=1;
                break;
            }
        }
    }
}

void print(){
    printf("\nMnumber\t\t\tMBlock\t\t\tPnumber\t\t\tPBlock\t\t\t");
    for(int i=0; i<msize; i++){
        if(flag[i]==1){
            printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d",i+1, mblock[i], allocated[i]+1, pblock[allocated[i]]);
        }
        else{
            printf("\n%d\t\t\t%d\t\t\tNot Allocated\t\t\tNot Allocated",i+1, mblock[i]);
        }
    }
}

void main(){
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
        scanf("%d",&pblock[i]);
    }
    FirstFit();
    print();
}



