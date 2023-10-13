#include<iostream>
using namespace std;

static int count=1;

class employee{
	private:
			void compute()
			{
				DA=Basic*0.52;
				if(Basic<10000)
					IT=Basic*0;
				else if(Basic<20000)
					IT=Basic*0.1;
				else if(Basic<30000)
					IT=Basic*0.2;
				else if(Basic<40000)
					IT=Basic*0.3;
				NetSalary=(Basic+DA)-IT;
				cout<<"\nDearness Allowance: "<<DA;
				cout<<"\nIncome Tax: "<<IT;
				cout<<"\nNet salary: "<<NetSalary;
				
			}

	public:
			long int ENo;
			float Basic, DA, IT, NetSalary;
			string Ename;
			
			employee()
			{
				ENo=count++;
			}

			void getData()
			{
				cout<<"\nEnter Employee Name: ";
				cin>>Ename;
				cout<<"Enter Employee Number: "<<ENo;
				cout<<"\nEnter Basic Salary(Btw 1000 and 40000): ";
				cin>>Basic;
			}
			
			void putData()
			{
				cout<<"\n\n*********************************";
				cout<<"\nEmployee "<<ENo<<" Details:-";
				cout<<"\nEmployee Name: "<<Ename;
				cout<<"\nEmployee Number: "<<ENo;
				cout<<"\nBasic Salary: "<<Basic;
				compute();
			}
			
			
};

int main()
{
	int i, n;
	cout<<"Enter number of employees(less than 10): ";
	cin>>n;
	employee emp[n];
	for(i=0;i<n;i++)
	{
		emp[i].getData();
	}
	for(i=0;i<n;i++)
	{
		emp[i].putData();
	}
	cout<<"\n";
}

























