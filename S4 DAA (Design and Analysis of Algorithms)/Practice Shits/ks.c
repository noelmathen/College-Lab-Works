#include<stdio.h>

struct knapSack{
    float num, p, w, x, sol;
}ks[20], temp;

void printTable(int n)
{
    printf("\nKnapsack Structure:\n");
    printf("Index\tProfit\tWeight\tP/W Ratio\tSolution\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%.0f\t%.0f\t%.0f\t%.2f\t\t%.2f\n", ks[i].num, ks[i].p, ks[i].w, ks[i].x, ks[i].sol);
    }
}

void sortWithPbyW(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(ks[j].x < ks[j+1].x)
            {
                temp = ks[j];
                ks[j] = ks[j+1];
                ks[j+1] = temp;
            }
        }
    }
}

void sortWithNumber(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(ks[j].num > ks[j+1].num)
            {
                temp = ks[j];
                ks[j] = ks[j+1];
                ks[j+1] = temp;
            }
        }
    }
}

float greedyKnapsack(int n, float maxWeight)
{
    float totalProfit=0, currentWeight=0;
    int i=0;
    while((i<n) && (currentWeight + ks[i].w < maxWeight))
    {
        ks[i].x = 1;
        totalProfit += ks[i].p;
        currentWeight += ks[i].w;
        i++;
    }
    if(i<n)
    {
        ks[i].x = (maxWeight - currentWeight)/ks[i].w;
        ks[i].p = ks[i].x * ks[i].p; 
    }
}

void main()
{
    int n;
    float maxWeight;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter maximum weight: ");
    scanf("%f", &maxWeight);
    for(int i=0; i<n; i++)
    {
        ks[i].num = i+1;
        printf("\nFor item %d: \n",i+1);
        printf("Enter profit: ");
        scanf("%f", &ks[i].p);
        printf("Enter weight: ");
        scanf("%f", &ks[i].w);
        ks[i].x = ks[i].p / ks[i].w;
        ks[i].sol = 0;
    }
    printTable(n);
    sortWithPbyW(n);
    printTable(n);
    printf("Total profit: %f", greedyKnapsack(n, maxWeight));
    printTable(n);
    sortWithNumber(n);
    printTable(n);
    
}
