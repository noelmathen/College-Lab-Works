#include<iostream>
#include<string.h>
#include<cmath>
#include<ctype.h>
using namespace std;

int main()
{
	string mail, pass;
	long int phone, ch, phonesize, passsize;
	cout<<"MENU:-\n1. USERID\n2. PASSWORD\n3. MOBILE NUMBER\n0. EXIT\n";
	while(1)
    {
        cout<<"\n\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:{
                
                
                break;
            }

            case 2:{
                cout<<"Enter Password: ";
                cin>>pass;
                passsize=pass.length();
                try
                {
                	if(passsize<6)
                	{
                		throw "6 or more character!";
                	}
                	else
                	{
                		cout<<"Successful!";
                	}
                }
                
                catch(const char *msg)
                {
                	cerr<<msg<<endl;
                }
                
                break;
            }

			case 3:{
                cout<<"Enter Mobile Number: ";
                cin>>phone;
                phonesize=log10(phone)+1;            
                try
                {
                	if(phonesize!=10)
                	{
                		throw "Phone number must be 10 digits!";
                	}
                	else
                	{
                		cout<<"Mobile Number: "<<phone;
                	}
                }
                
                catch(const char *msg)
                {
                	cerr<<msg<<endl;
                }
                break;
            }
            
            case 0:{
                cout<<"\nOHK BEI:)))\n"; 
                exit(0);
            }

            default:{
                cout<<"INVALID CHOICE!";
                break;
            }
        }
    }
}
