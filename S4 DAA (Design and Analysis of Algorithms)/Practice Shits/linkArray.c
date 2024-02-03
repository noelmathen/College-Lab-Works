#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL, *tail=NULL, *pos=NULL, *del=NULL, *temp=NULL;
int count=0;
static clock_t start1, start2, start3, start4, end1, end2, end3, end4;
static double time1, time2, time3, time4;

void insertToLinkedList(int x)
{
    if(head==NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data=x;
        head->next=NULL;
        pos=head;
        tail=head;
    }
    else{
        tail->next = (struct node*)malloc(sizeof(struct node));
        tail = tail->next;
        tail->data=x;
        tail->next=NULL;
    }
    count++;
}

void displayArray(int a[], int n)
{
    printf("\nThe array is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\n");
}

void displayLinkedList()
{
    printf("\nThe List is : ");
    pos=head;
    while(pos!=NULL)
    {
        printf("%d  ",pos->data);
        pos=pos->next;
    }
    printf("\n");
}

void deleteFromArray(int a[], int *n, int delPos)
{
    for(int i=delPos; i<*n-1; i++)
    {
        a[i] = a[i+1];
    }
    (*n)--;
    // printf("The new array is: ");
    displayArray(a,*n);
}

void NextLargestArray(int a[], int *n, int delPos, int delElement)
{
    int large=0;
    for(int i=0; i<*n; i++) //finds the alrgest element in array
    {
        if(a[i]>large)
            large=a[i];
    }
    for(int i=delPos; i<*n; i++)    //finds the next bgreates elemnt after deleted element using ther deleted element and the largest element in the arra
    {
        if(a[i]>delElement && a[i]<large)
            large = a[i];
    }
    printf("Next Largest element after %d is: %d", delElement, large);
}

void deleteFromList(int delPos, int x){
    if(delPos==0){
        del=head;
        head=head->next;
        del->next=NULL;
        free(del);
        count--;
    }
    else if(delPos > 0 && delPos<count-1){
        pos=head;
        for(int i=0; i<delPos-1; i++){
            temp = temp->next;
        }
        del = temp->next;
        temp->next = temp->next->next;
        del->next = NULL;
        free(del);
        count--;
    }
    else if(delPos == count-1)
    {
        pos=head;
        for(int i=0;i<delPos-1;i++)
        {
            pos=pos->next;	
        }
        tail = pos;
        del = pos->next;
        tail->next = NULL;
        free(del);
        count--;
    }
    else{
        printf("\nOut of Bound!\n");
        return;
    }
}

void NextLargestList(int delPos, int x){

            int large = head->data;
            pos = head;
            //finding the largest element in the list
            while(pos!=NULL)
            {
                if(pos->data > large)
                {
                    large = pos->data;
                }
                pos=pos->next;
            }
            //finding the next largest element in the list
            pos=head;
            while(pos!=NULL)
            {
                if(pos->data > x && pos->data < large)
                {
                    large = pos->data;
                }
                pos=pos->next;
            }
}

void main()
{
    int n, a[100000], delPos;
    printf("Enter the number of elements in array/list: ");
    scanf("%d", &n);
    // printf("The randomly array/list is: ")
    for(int i=0; i<n; i++)
    {
        a[i] = rand()%100;  //random bs
        insertToLinkedList(a[i]);   //inserting the same elment into the list
    }
    // displayArray(a, n);     // not necessary, but to verify things, ith venam
    displayLinkedList();    // not necessary, but to verify things, ith venam

    printf("Enter position of element to remove: ");
    scanf("%d", &delPos);   //the position is taken as input. not the value.
    int delElement = a[delPos]; //temporarily stores the delted variable for further purposes

    // start1 = clock();
    // deleteFromArray(a, &n, delPos); //check function
    // end1 = clock();
    // time1 = (double)(end1-start1)/CLOCKS_PER_SEC;

    // start2 = clock();
    // NextLargestArray(a, &n, delPos, delElement);    //check function
    // end2 = clock();
    // time2 = (double)(end2-start2)/CLOCKS_PER_SEC;

    start3 = clock();
    deleteFromList(delPos, delElement);   //perform linked list deletion(i hope you know it. i am too lazy and its kore pani). i did it based on the position of the element to be deleted. not with the element itself
    end3 = clock();
    time3 = (double)(end3-start3)/CLOCKS_PER_SEC;
    displayLinkedList();    // not necessary, but to verify things, ith venam


    start4 = clock();
    NextLargestList(delPos, delElement);  //you may complete this function using the same logic used in the array. first fine the largest element in the list. then find the next largest elemnt after deleted element
    end4 = clock();
    time4 = (double)(end4-start4)/CLOCKS_PER_SEC;
    displayLinkedList();    // not necessary, but to verify things, ith venam


    // printf("\nTime for deletion in array: %0.6f", time1);
    // printf("\nTime for nextLEle in array: %0.6f", time2);
    printf("\nTime for deletion in linkL: %0.6f", time3);
    printf("\nTime for nextLEle in linkL: %0.6f", time4);   //printing all of this toigehter would be noiz
    printf("\n");   //5 marks extra for neat output(if i was the teacher, then def yeah hahahahha)
    printf("<3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3");
}
//all the best dear <3
