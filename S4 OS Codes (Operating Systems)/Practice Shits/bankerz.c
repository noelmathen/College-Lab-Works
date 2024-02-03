#include<stdio.h>
void main()
{
    int pno, rno, allo[20][20], max[20][20], avail[20], need[20][20], flag[20], safe[20], safeIndex = 0, isSafe;
    printf("BANKERS ALGORITHM\n\n");
    printf("Enter the number of processes: ");
    scanf("%d", &pno);

    printf("Enter the number of resources: ");
    scanf("%d", &rno);

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < pno; i++)
    {
        for (int j = 0; j < rno; j++)
        {
            scanf("%d", &allo[i][j]);
        }
    }
    printf("Enter the maximum matrix:\n");
    for (int i = 0; i < pno; i++)
    {
        for (int j = 0; j < rno; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available resources:\n");
    for (int i = 0; i < rno; i++)
    {
        scanf("%d", &avail[i]);
    }
    // Calculate the need matrix
    for (int i = 0; i < pno; i++)
    {
        for (int j = 0; j < rno; j++)
        {
            need[i][j] = max[i][j] - allo[i][j];
        }
    }
    // Initialize flag array
    for (int i = 0; i < pno; i++)
    {
        flag[i] = 0;
    }
    
    for(int k=0; k<pno; k++){
        for(int i=0; i<pno; i++){
            if(flag[i]==0){
                isSafe = 1;
                for(int j=0; j<rno; j++){
                    if(need[i][j] > avail[j]){
                        isSafe=1;
                        break;
                    }
                }
                if(isSafe){
                    safe[safeIndex++] = i;
                    for(int m=0; m<pno; m++){
                        avail[m] += allo[i][m];
                    }
                    flag[i]=1;
                }
            }
        }
    }
    isSafe=1;
    for(int i=0; i<pno; i++){
        if(flag[i]==0){
            isSafe=1;
            break;
        }
    }

    printf("\n");
}
