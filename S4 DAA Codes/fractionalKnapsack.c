#include<stdio.h>

struct knapSack{
    int index;
    float profit;
    float weight;
    float PbyW;
    float solution;
}ks[20], temp;

int i, j, n, maxWeight;

void printTable()
{
    printf("\nKnapsack Structure:\n");
    printf("Index\tProfit\tWeight\tP/W Ratio\tSolution\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\t%.0f\t%.0f\t%.2f\t\t%.2f\n", ks[i].index, ks[i].profit, ks[i].weight, ks[i].PbyW, ks[i].solution);
    }
}

void sortUsingProfitByWeight()  //sorting by profit/weight ratio in descending order to perform knapsack algorithm
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(ks[j].PbyW < ks[j+1].PbyW)
            {
                temp = ks[j];
                ks[j] = ks[j+1];
                ks[j+1] = temp;
            }
        }
    }
}

void sortUsingIndex()   //sorting using the index values so that we can print the solution tuple in the correct order
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(ks[j].index > ks[j+1].index)
            {
                temp = ks[j];
                ks[j] = ks[j+1];
                ks[j+1] = temp;
            }
        }
    }
}

void greedyKnapsack(int n, int maxWeight) {
    float tempTotalWeight = 0;
    float totalProfit = 0;
    int i = 0;
    
    while (i < n && tempTotalWeight + ks[i].weight <= maxWeight) {
        ks[i].solution = 1;
        tempTotalWeight += ks[i].weight;
        totalProfit += ks[i].profit;
        i++;
    }
    
    if (i < n) {
        ks[i].solution = (maxWeight - tempTotalWeight) / ks[i].weight;
        totalProfit += ks[i].solution * ks[i].profit;
    }
    
    printf("\nTotal profit is: %.2f", totalProfit);
}


void main()
{
    printf("\n*******FRACTIONAL KNAPSACK PROBLEM*******\n\n");
    printf("Enter the number of items: ");
    scanf("%d",&n);
    printf("Enter the maximum weight: ");
    scanf("%d",&maxWeight);
    for(i=0;i<n;i++)
    {
        ks[i].index = i;
        printf("\nFor item %d: ",i+1);
        printf("\nEnter profit: ");
        scanf("%f",&ks[i].profit);
        printf("Enter weight: ");
        scanf("%f",&ks[i].weight);
        ks[i].PbyW = ks[i].profit / ks[i].weight;
        ks[i].solution = 0;
    }
    sortUsingProfitByWeight();
    greedyKnapsack(n,maxWeight);
    sortUsingIndex();
    printf("\nSOLUTION TUPLE: (");
    for(i=0;i<n;i++)
    {
        if(i==n-1)
            printf("%0.2f",ks[i].solution);
        else
            printf("%0.2f    ",ks[i].solution);
    }
    printf(")\n");
    printTable();
}
