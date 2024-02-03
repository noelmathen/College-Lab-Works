//This code is very completed because i tried to handle all kinds of errors....refer linkArr from Louis Codes

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define arraySize 1000000000
int a[arraySize];
int size=0, flag=0, largeArray, largeList, tempDeleteArray, tempDeleteList, delPos;
static clock_t start1, start2, start3, start4, end1, end2, end3, end4;
static double timeElapsed1, timeElapsed2, timeElapsed3, timeElapsed4;

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL, *pos=NULL, *tail=NULL, *temp=NULL, *temp2=NULL, *del=NULL;

void displayArray(int a[], int *n)
{
    int i;
	printf("\nThe array is: ");
    for(i=0; i<*n; i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\n");
}

void displayLinkedList()
{
    pos = head;
	printf("\nThe list is: ");
	while(pos!=NULL)
	{
		printf("%d  ",pos->data);
		pos=pos->next;
	}
    printf("\n");
}

int deleteFromArray(int a[], int *n, int delPosArray)
{
    start1 = clock();
    int i;
    tempDeleteArray = a[delPosArray];
    if(delPosArray>=*n) //if entered position is out of bound, return -1
    {
        return -1;
    }
    else
    {    
        //deletion by left shift
        for(i=delPosArray; i<*n; i++)
        {
            a[i]=a[i+1];
        }
        (*n)--;
        //largest element in array
        largeArray = a[0];
        for(i=1; i<*n; i++)
        {
            if(a[i] > largeArray)
            {
                largeArray = a[i];
            }
        }
        end1 = clock();
        timeElapsed1 = (double)(end1 - start1)/CLOCKS_PER_SEC;

        //finding next greatest element in Array
        start2=clock();
        if(tempDeleteArray >= largeArray)   //if the element to be deleted is greater than or equal to the largest element in the array, then there is no next largest element. therefore, return -2
        {
            return -2;
        }
        else
        {
            //checking for the next largest element wrt to the largest element and the deleted element
            for(i=0; i<*n; i++)
            {
                if(a[i]>tempDeleteArray && a[i]<largeArray)
                {
                    largeArray = a[i];
                }
            }
            // printf("\nThe next greatest element in the array after %d(deleted element) is: %d\n",tempDeleteArray,largeArray);	 
        }
        end2=clock();
        timeElapsed2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
    }
    return largeArray;  //return the next largest element
}

int deleteFromLinkedList(int size, int delPosList)
{
    start3=clock();
    int i;
    //DELETION IN LINKED LIST
    if(head==NULL)
    {
        printf("LIST EMPTY! CANNOT DELETE!");
    }
    else
    {
        if(delPosList == 0)
        {
            del=head;
            head=head->next;
            del->next=NULL;
            tempDeleteList = del->data;
            free(del);
            size--;
            flag=1;
        }
        else if(delPosList>0 && delPosList<size-1)
        {
            pos=head;
            for(i=0; i<delPosList-1; i++)
            {
                pos=pos->next;
            }
            del=pos->next;
            pos->next = pos->next->next;
            del->next=NULL;
            tempDeleteList = del->data;
            free(del);
            size--;
            flag=1;
        }
        else if(delPosList == size-1)
        {
            pos=head;
			for(i=0;i<delPosList-1;i++)
			{
				pos=pos->next;	
			}
			tail = pos;
			del = pos->next;
			tail->next = NULL;
			tempDeleteList = del->data;
			free(del);
			size--;
			flag = 1;
        }
        else
        {
            return -1;  //if entered position is out of bound, return -1
        }
        end3=clock();
        timeElapsed3 = (double)(end3 - start3)/CLOCKS_PER_SEC;
        
        //NEXT LARGEST ELEMENT IN LINKED LIST
        start4=clock();
        if(flag==1)//if deletion occured.....
        {
            largeList = head->data;
            pos = head;
            //finding the largest element in the list
            while(pos!=NULL)
            {
                if(pos->data > largeList)
                {
                    largeList = pos->data;
                }
                pos=pos->next;
            }
            if(tempDeleteList >=largeList)  //if the element to be deleted is greater than or equal to the largest element in the array, then there is no next largest element. therefore, return -2
            {
                return -2;
            }
            else
            {
                pos=head;
                while(pos!=NULL)
                {
                    if(pos->data > tempDeleteList && pos->data < largeList)
                    {
                        largeList = pos->data;
                    }
                    pos=pos->next;
                }
                // printf("\nThe next greatest element in the list after %d(deleted element) is: %d\n",tempDeleteList,largeList);	
            }
        }
        end4=clock();
        timeElapsed4 = (double)(end4 - start4)/CLOCKS_PER_SEC;
    }
    return largeList;   //return the next largest element
}

void main()
{
    int n, i, temporary, nextLargestArray, nextLargestList;
    printf("\nEnter the number of elements in the array/list: ");
    scanf("%d",&n);
    printf("The randomy generated array/list is: ");
    for(i=0; i<n; i++)
    {
        a[i]=rand()%100;//generates random array
        temp=(struct node*)malloc(sizeof(struct node)); //generates random linked list
        temp->data=a[i];
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            pos=head;
            tail=head;
        }
        else
        {
            tail->next=temp;
            tail=tail->next;
        }
        size++;
        // printf("%d  ",a[i]);//need not print randomly generated array/list
    }
    printf("\nEnter the position of element you want to delete: ");
    scanf("%d",&delPos);
    temporary = a[delPos];
    nextLargestArray = deleteFromArray(a,&n,delPos);
    nextLargestList = deleteFromLinkedList(size,delPos);
    if((nextLargestArray == nextLargestList) && nextLargestArray == -1)// checks if the the entered position if out of bound(-1 returned)
    {
        printf("\nOUT OF BOUND POSITION!\n");
    }
    else if((nextLargestArray == nextLargestList) && nextLargestArray == -2)// checks if the element to be deleted is hreater than or equal to the largest element in the list/array(-2 returned)
    {
        printf("\nThere is no element greater than %d(deleted element)!\n",temporary);
    }
    else//if there are no errors, print the next largest element
    {
        printf("\nThe next largest element after %d(deleted element) is: %d\n",temporary,nextLargestList);
    }
    printf("\nTime take for deletion in array                               : %.6f",timeElapsed1);
    printf("\nTime take for deletion in linked list                         : %.6f",timeElapsed3);
    printf("\nTime take for finding the next largest element in array       : %.6f",timeElapsed2);
    printf("\nTime take for finding the next largest element in linked list : %.6f\n",timeElapsed4);
}
