#include<iostream>
#include<string>
using namespace std;
class vehiclereg{
    private :
        int chasisno,vehicletype;
        string name;
    public :
        int regno=0,regyear;
      
     vehiclereg(int a,int b)
     {
        regno=a;
        regyear=b;
      }
        void getdata()
        {
            cout<<"Enter Chasisno :";
            cin>>chasisno;
            cout<<"Enter Vehicletype :";
            cin>>vehicletype;
            cout<<"Enter name of owner :";
            cin>>name;
         }
      void vehicletransfer()
      {
        cout<<"Enter the new owner :";
        cin>>name;
        cout<<"Ownership changed"<<endl;
       }
      ~vehiclereg()
      {
        cout<<"Object destroyed"<<endl;
      }
 };
int main()
{
    int ch,regno=0;
    vehiclereg v1(regno,2000);
    cout<<"Enter vehicle details of first one \n";
    v1.getdata();
    regno=regno+1;
    vehiclereg v2(regno,2003);
    cout<<"Enter vehicle details of second one \n";
    v2.getdata();
    cout<<"Ownership change"<<endl;
    cout<<"Enter regno for ownership change :";
    cin>>ch;
    if(ch==0)
        v1.vehicletransfer();
    else if(ch==1)
        v2.vehicletransfer();
    else 
        cout<<"Regno not found";
     
 }
