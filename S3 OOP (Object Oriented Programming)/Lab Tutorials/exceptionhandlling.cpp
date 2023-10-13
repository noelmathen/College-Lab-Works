#include <iostream>
#include <string>
using namespace std;
int main()
{

    char email[25];
    string password;
    long int phone;
    int i,flag=0;
    cout<<"\n-------------------------------------------------------";
    flag=0;
    do
    {
        cout<<"\nEMAIL";
        cout<<"\nEnter email address: ";
        cin>>email;
        try
        {
            for(i=0;i<25;i++)
            {
                if(email[i]=='@')
                    flag=1;
            }
            if(flag==1)
            {
                cout<<"Email saved";
                cout<<"\n-------------------------------------------------------";
            }
            else
                throw "Invalid Email. Try Again!";
        }
        catch(const char *msg)
        {
            cerr<<msg<<endl;
        }
    }while(flag==0);


    flag=0;
    do
    {
        cout<<"\n\nPASSWORD";
        cout<<"\nEnter Password:";
        cin>>password;

        try
        {
            int size=password.size();
            int letters=0,num=0;
            for (int i=0;i<size;i++)
            {
                if((password[i]>='a' && password[i]<='z' )||(password[i]>='A' && password[i]<='Z' ))
                {
                    letters=1;
                    break;
                }
            }
            for (int i=0;i<size;i++)
            {
                if(password[i]>=48 && password[i]<=57)
                {
                    num=1;
                    break;
                }
            }

            if((password.size()>=6) && (num==1) && (letters==1))
            {
                cout<<"Password is valid";
                cout<<"\n-------------------------------------------------------";
                flag=1;
            }
            else if(num!=1 || letters!=1)
                throw "Password must be alhpamueric. Try Again!";
                
            else if(password.size()<6)
                throw "Password must be at least 6 characters long. Try Again!. Try Again!";

            else
                throw "Password must be 6 characters long and alphanumeric. Try Again!. Try Again!";
        }
        catch(const char *msg)
        {
            cerr<<msg<<endl;
        }
    }while(flag==0);



    flag=0;
    while(flag==0)
    {
        cout<<"\n\nMOBILE NUMBER";
        cout<<"\nEnter Mobile Number: ";
        cin>>phone;
        try
        {
            string num=to_string(phone);
            if(num.size()==10)
            {
                cout<<"Phone number is valid";
                cout<<"\n-------------------------------------------------------";
                flag=1;
            }
            else
            {
                throw "Phone number is invalid. Try again!";
                flag=0;
            }
        }
        catch(const char *msg)
        {
            cerr<<msg<<endl;
        }
    }
}

