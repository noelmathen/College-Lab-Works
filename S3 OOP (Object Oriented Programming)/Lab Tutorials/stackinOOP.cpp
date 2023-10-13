#include<iostream>
#include<stdlib.h>
using namespace std;
#define n 10    //DECLARING SIZE PF ARRAY GLOABALLY. U MAY CHANGE IT ACCORDING TO YOUR NEEDS
class stack{
    public:
        int stk[n];
        int i, top=-1, entry;

        stack() //DEFAULT CONSTRUCTOR TO INITIALIZE VALUES TO 0
        {
            for(i=0;i<n;i++)
            {
                stk[i]=0;
            }
        }

        stack(int a, int b, int c, int d, int e, int f, int g, int h, int j, int k) //PARAMETERIZED CONSTRUCTOR TO INITIALIZE VALUES TO 0
        {
            stk[0]=a;
            stk[1]=b;
            stk[2]=c;
            stk[3]=d;
            stk[4]=e;
            stk[5]=f;
            stk[6]=g;
            stk[7]=h;
            stk[8]=j;
            stk[9]=k;
        }

        stack(int x)    //user input
        {
            cout<<"Enter the "<<x<<" elements for stack: ";
            for(i=0;i<x;i++)
            {
                cin>>stk[i];
            }

            cout<<"\nThe entered elements are: ";
            for(i=x-1;i>=0;i--)
            {
                cout<<endl<<stk[i];
            }
        } 

        void isEmpty()
        {
            if(top==-1)
            {
                cout<<"STACK UNDERFLOW(EMPTY)!";
            }
            else{
                cout<<"STACK NOT EMPTY!";
            }
        }

        void isFull()
        {
            if(top==n-1)
            {
                cout<<"STACK OVERFLOW(EMPTY)!";
            }
            else{
                cout<<"STACK NOT FULL!";
            }
        }

        void push()
        {
            if(top==n-1)
            {
                cout<<"STACK OVERFLOW(FULL) CANNOT PUSH!";
            }
            else
            {
                cout<<"Enter element to be pushed: ";
                cin>>entry;
                top++;
                stk[top] = entry;
            }
        }

        void pop()
        {    
            if(top==-1)
            {
                cout<<"STACK UNDERFLOW(EMPTY) CANNOT POP!";
            }
            else
            {
                cout<<"The popped element is: "<<stk[top];
                stk[top] = -1;  //we cant delete a value from stack per se. we r just moving the top pointer. so just change the top value to -1 for fun hehehe
                top--;  //actual code for pop
            }
        }

        void displayElements()
        {
            if(top==-1)
            {
                cout<<"STACK UNDERFLOW(EMPTY) NOTHING TO DISPLAY!";
            }
            else
            {
                for(i=top; i>=0; i--)
                {
                    cout<<endl<<stk[i];
                }
            }
            
        }

        void displayNumberofElements()
        {
            cout<<"Total number of elements in stack is: "<<top+1;
        }

        void sum()
        {
            int sum=0;
            for(i=top; i>=0; i--)
            {
                sum += stk[i];
            }
            cout<<"Sum of elements in stack is: "<<sum;
        }

        ~stack()
        {
            cout<<"Destructor";
        }
};

int main()
{
    stack obj1;// calls default constructor

    stack obj2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);  // calls parameterized contructor

    stack obj3(8); //user input constructor

    int ch;
	cout<<"\n\n*********STACK*********\n\n";

	cout<<"MENU:- \n\n1. PUSH\n2. POP\n3. IS EMPTY\n4. IS FULL\n5. DISPLAY\n6. NUMBER OF ELEMENTS\n7. SUM OF ELEMENTS\n0. EXIT";
	while(1)
	{
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: 
			{
				obj1.push();
				break;
			}
			
			case 2:
			{
				obj1.pop();
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

