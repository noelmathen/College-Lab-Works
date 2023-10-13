#include<iostream>
#include<stdlib.h>
using namespace std;
#define n 10    // kind of a gloabal declaration
class queue{
    public:
        int que[n];
        int i, front=-1, rear=-1, entry;

        queue() //DEFAULT CONSTRUCTOR TO INITIALIZE VALUES TO 0
        {
            for(i=0;i<n;i++)
            {
                que[i]=0;
            }
        }

        queue(int a, int b, int c, int d, int e, int f, int g, int h, int j, int k) //DEFAULT CONSTRUCTOR TO INITIALIZE VALUES TO 0
        {
            que[0]=a;
            que[1]=b;
            que[2]=c;
            que[3]=d;
            que[4]=e;
            que[5]=f;
            que[6]=g;
            que[7]=h;
            que[8]=i;
            que[9]=j;
        }

        queue(int x)    //user input constructor
        {
            cout<<"Enter the "<<x<<" elements for queue: ";
            for(i=0;i<x;i++)
            {
                cin>>que[i];
            }

            cout<<"\nThe entered elements are: ";
            cout<<"|  ";
            for(i=0;i<x;i++)
            {   
                cout<<que[i]<<"  |  ";
            }
            
        } 

        void isEmpty()
        {
            if(front==-1 && rear==-1)
            {
                cout<<"QUEUE UNDERFLOW!(empty)";
            }
            else
            {
                cout<<"QUEUE NOT EMPTY";
            }
        }

        void isFull()
        {
            if(rear==n-1)
            {
                cout<<"QUEUE OVERFLOW!(full)";
            }
            else
            {
                cout<<"QUEUE NOT FULL";
            }
        }

        void enqueue()
        {
            if(rear==n-1)
            {
                cout<<"QUEUE OVERFLOW!(full), CANNOT ENQUEUE";
            }
            else
            {
                cout<<"Enter element to be enqueued: ";
                cin>>entry;
                if(front==-1)
                    front=0;
                rear++;
                que[rear]=entry;
            }
        }

        void dequeue()
        {    
            if(front==-1 && rear==-1)
            {
                cout<<"QUEUE UNDERFLOW!(empty), CANNOT DEQUEUE";
            }
            else{
                cout<<"The dequeued element is: "<<que[front];
                front++;
                if(front>rear)
                {
                    front=-1;
                    rear=-1;
                }
            }
        }

        void displayElements()
        {
            if(front==-1 && rear==-1)
            {
                cout<<"QUEUE UNDERFLOW!(empty), NOTHING TO DISPLAY";
            }
            else
            {
                cout<<"|  ";
                for(i=front; i<=rear; i++)
                {   
                    cout<<que[i]<<"  |  ";
                }
            }
            
        }

        void displayNumberofElements()
        {
            // cout<<"Total number of elements in queue is: "<<(rear - front + 1 + n) % n;  //easy method
            int count=0;
            for(i=front; i<=rear; i++)
            {   
                count++;
            }
            cout<<"Total number of elements in queue is: "<<count;
        }

        void sum()
        {
            int sum=0;
            for(i=front; i<=rear; i++)
            {
                sum += que[i];
            }
            cout<<"Sum of elements in queue is: "<<sum;
        }

        ~queue()
        {
            cout<<"Destructor";
        }
};

int main()
{
    queue obj1;// calls default constructor

    queue obj2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);  // calls parameterized contructor

    queue obj3(8); //user input constructor

    int ch;
	cout<<"\n\n*********QUEUE*********\n\n";

	cout<<"MENU:- \n\n1. ENQUEUE\n2. DEQUEUE\n3. IS EMPTY\n4. IS FULL\n5. DISPLAY\n6. NUMBER OF ELEMENTS\n7. SUM OF ELEMENTS\n0. EXIT";
	while(1)
	{
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: 
			{
				obj1.enqueue();
				break;
			}
			
			case 2:
			{
				obj1.dequeue();
				break;
			}
			
			case 3:
			{
				obj1.isEmpty();
				break;
			}
			
			case 4:
			{
				obj1.isFull();
				break;
			}
			
			case 5:
			{
				obj1.displayElements();
				break;
			}
			
			case 6:
			{
				obj1.displayNumberofElements();
				break;
			}
			
			case 7:
			{
				obj1.sum();
				break;
			}
			
			case 0:
			{
				cout<<"OHK BEI!:)\n";
				exit(0);
			}
			
			default:
			{
				cout<<"INVALID INPUT! TRY AGAIN\n";
				break;
			}
		}
	}
}



