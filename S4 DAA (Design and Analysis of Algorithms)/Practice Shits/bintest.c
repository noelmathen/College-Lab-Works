#include<stdio.h>
#include<math.h>

int NextFit(int weights[], int capacity, int n){
    int bins=0, remainingCapacity=capacity;
    for(int i=0; i<n; i++){
        if(weights[i] > remainingCapacity){
            remainingCapacity = capacity - weights[i];
            bins++;
        }
        else{
            remainingCapacity -= weights[i];
        }
    }
    return bins+1;
}

int FirstFit(int weights[], int capacity, int n){
    int bins=0, remainingCapacity[100];
    for(int i=0; i<n; i++){
        int j=0;
        for(j=0; j<bins; j++){
            if(weights[i] <= remainingCapacity[j]){
                remainingCapacity[j] -= weights[i];
                break;
            }
        }
        if(j==bins){
            remainingCapacity[bins] = capacity - weights[i];
            bins++;
        }
    }
    return bins;
}

int BestFit(int weights[], int capacity, int n){
    int bins=0, remainingCapacity[100];
    for(int i=0; i<n; i++){
        int minimum = capacity+1;
        int index = 0;
        for(int j=0; j<bins; j++){
            if((weights[i] <= remainingCapacity[j]) && (remainingCapacity[j] - weights[i] < minimum)){
                minimum = remainingCapacity[j] - weights[i];
                index = j;
            }
        }
        if(minimum == capacity+1){
            remainingCapacity[bins] = capacity - weights[i];
            bins++;
        }
        else{
             remainingCapacity[index] -= weights[i];
        }
    }
    return bins;
}

void main(){
    int n, weights[100], capacity;
    float totalWeight=0;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter item %d: ",i+1);
        scanf("%d", &weights[i]);
        totalWeight += weights[i];
    }
    printf("Enter maximum capacity of bin: ");
    scanf("%d",&capacity);
    int upperBound = ceil(totalWeight / (float)capacity);
    printf("\nUpper bound: %d",upperBound);
    printf("\n\nNumber of bins using Next Fit: %d", NextFit(weights, capacity, n));
    printf("\nNumber of bins using First Fit: %d", FirstFit(weights, capacity, n));
    printf("\nNumber of bins using Best Fit: %d", BestFit(weights, capacity, n));
}

//TEST CASES
// {5, 7, 5, 2, 4, 2, 5, 1, 6}; 6 5 5
// {2, 5, 4, 7, 1, 3, 8}; 5 4 4
// {4, 1, 8, 1, 4, 2}; 3 2 3
// {2, 3, 4, 5, 1, 6, 7, 8, 9}; 6 6 6
