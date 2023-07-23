#include<iostream>
using namespace std;
#define N 6

class arrr{
    public:
        int i, arr[N], input;
        
        void getArray()
        {
            cout<<"Enter the elements of array: ";
            for(i=0;i<N;i++)
            {
                cin>>arr[i];
            }
        }
        void putArray()
        {
            cout<<"The array is:";
            for(i=0;i<N;i++)
            {
                cout<<" "<<arr[i];
            }
        }
        void getNumber()
        {
            cout<<"\n\nEnter the number for rotation(between 0 to 4): ";
            cin>>input;
        }
        void operator ++()
        {
            while(1)
            {
                getNumber();
                try
                {
                    if(input<0 || input>4)
                    {
                        throw "INVALID! Only numbers from 0 to 4 are allowed!";
                    }
                    else
                    {
                        int temp1, temp2, j;
                        for(j=0;j<input;j++)
                        {
                            temp1=arr[0];
                            arr[0]=arr[1];
                            temp2=arr[N-1];
                            arr[N-1]=temp1;
                            for(i=1;i<N-1;i++)
                            {
                                arr[i]=arr[i+1];
                            }
                            arr[N-2]=temp2;
                        }
                        cout<<"After rotation, ";
                    }
                    putArray();
                    break;
                }
                catch(const char *msg)
                {
                    cerr<<msg;
                }
            }
        }
};

int main()
{
    arrr obj1;
    obj1.getArray();
    obj1.putArray();
    ++obj1;
}

