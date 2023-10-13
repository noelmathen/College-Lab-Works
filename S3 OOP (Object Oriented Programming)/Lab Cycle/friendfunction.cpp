#include <iostream>
#include <stdlib.h>
using namespace std;
class cust {
	public: 
		string name;
		long int accno; 
		string acctype;
		cust()
		{
			name="Noel";
			accno=12345678;
		}
};

class curacct: public cust {
	public:
		float camt;
		curacct()
		{
			acctype="Current";
			camt=0;
		}
	friend void display(curacct &a);
	friend void deposit(curacct &a,float amt);
	friend void withdraw(curacct &a, float amt);
};

class savacct: public cust {
	public: 
		float samt;
		float intrate;
		savacct()
		{
			acctype="Savings";
			samt=0;
			intrate=0.05;
			
		}
	friend void display(savacct &a);
	friend void deposit(savacct &a,float amt);
	friend void interest(savacct &a);
	friend void withdraw(savacct &a, float amt);
};	

void display(curacct &a)
{
	cout<<"\nAccount Owner: "<<a.name<<endl<<"Account No: "<<a.accno<<"\nCurrent Account Balance: "<<a.camt<<endl;
}
void display(savacct &a)
{
	cout<<"\nAccount Owner: "<<a.name<<endl<<"Account No: "<<a.accno<<"\nSavings Account Balance: "<<a.samt<<endl;
}
void deposit(curacct &a,float amt)
{
	a.camt+=amt;
	cout<<"\nAmount Deposited in Current Account\n";
}
void deposit(savacct &a,float amt)
{
	a.samt+=amt;
	cout<<"\nAmount Deposited in Savings Account\n";
}
void interest(savacct &a)
{
	cout<<"\nInterest Rate: "<<a.intrate<<endl;
	a.samt+=(a.samt*a.intrate);
	cout<<"\nInterest Deposited\n";
}
void withdraw(curacct &a, float amt)
{
	if(a.camt<amt)
		cout<<"\nInsufficient Funds!!!\n";
	else
	{	
		a.camt-=amt;
		cout<<"\nCash is withdrawn from Current Account\n";
	}
}
void withdraw(savacct &a, float amt)
{
	if(a.samt<amt)
		cout<<"\nInsufficient Funds!!!\n";
	else
	{	
		a.samt-=amt;
		cout<<"\nCash is withdrawn from Savings Account\n";
	}
}

int main()
{
	curacct current;
	savacct savings;
	int ch;
	while(1)
	{
		cout<<"1. DISPLAY BALANCE\n2. DEPOSIT CASH\n3. DEPOSIT INTEREST\n4. WITHDRAW CASH\n0. EXIT\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				int a;
				cout<<"Select type of account to be displayed\n1. Current\n2. Savings\nEnter Choice: ";
				cin>>a;
				switch(a)
				{
					case 1:
					{
						display(current);
						break;
					}
					case 2:
					{
						display(savings);
						break;
					}
				}
				break;
			}
			case 2:
			{
				int a;
				cout<<"Select account type for depositing\n1.Current\n2. Savings\nEnter Choice: ";
				cin>>a;
				switch(a)
				{
					case 1:
					{
						int dep;
						cout<<"Enter amount to be depostied: ";
						cin>>dep;
						deposit(current,dep);
						break;
					}
					case 2:
					{
				
						int dep;
						cout<<"Enter amount to be depostied: ";
						cin>>dep;
						deposit(savings,dep);
						break;
					}
				}
				break;
			}
			case 3:
			{
				interest(savings);
				break;
			}
			case 4:
			{
				int a;
				cout<<"Select account type for depositing withdrawal\n1.Current\n2. Savings\nEnter Choice: ";
				cin>>a;
				switch(a)
				{
					case 1:
					{
						int take;
						cout<<"Enter amount for withdrawal? ";
						cin>>take;
						withdraw(current,take);
						break;
					}
					case 2:
					{
				
						int take;
						cout<<"Enter amount for withdrawal? ";
						cin>>take;
						withdraw(savings,take);
						break;
					}
				}
				break;
			}
			case 0:
			{
                cout<<"\nOHK BEI\n";
				exit(0);
			}
            default:
            {
                cout<<"\nINVALID CHOICE!";
            }
		}
		cout<<"\n\n";
	}
}
