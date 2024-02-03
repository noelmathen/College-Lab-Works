#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 100000

void printArray(int a[], int n){
    printf("\nThe array is: ");
    for(int i=0; i<n; i++){
        printf("%d  ",a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j=low; j<high; j++){
        if(a[j]<=pivot){
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high){
    if(low<high){
        int pIndex = partition(a, low, high);
        quickSort(a, low, pIndex-1);
        quickSort(a, pIndex+1, high);
    }
}


void bubbleSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void main(){
    time_t start1, start2, end1, end2;
    double time1, time2;
    int n, a[MAX], b[MAX];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        a[i]=rand()%100;
        b[i]=a[i];
    }
    // printArray(a, n);

    start1 = clock();
    bubbleSort(a, n);
    end1 = clock();
    time1 = (double)(end1-start1)/CLOCKS_PER_SEC;

    for(int i=0; i<n; i++){
       a[i]= b[i];
    }

    start2 = clock();
    quickSort(a, 0, n-1);
    end2 = clock();
    time2 = (double)(end2-start2)/CLOCKS_PER_SEC;
    // printArray(a, n);


    printf("\nTime taken for bubble sort: %0.21lfs",time1);
    printf("\nTime taken for quick  sort: %0.21lfs",time2);

    FILE *fptr;
    fptr = fopen("C:\\Users\\noelm\\Desktop\\Saadhangal\\STUDY STEFF\\RSET\\CLASSES\\S4\\DAA\\DAA LAB\\Practice Shits\\sort.txt","a+");
    fprintf(fptr, "\n%-15d%-15f%-15f",n, time1, time2);
    fclose(fptr);
}
/*
    set terminal postscript
    set out "sort.ps"
    set autoscale
    set title
    set xlabel
    set ylabel
    set grod
    set logscale
    plot "sort.txt" using 1:2 title "Bubble" with lines, "sort.txt" using 1:3 title "Quick" with lines

*/












