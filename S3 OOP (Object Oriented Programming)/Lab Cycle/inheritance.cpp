#include<iostream>
using namespace std;
class employee{
	public:
			string name;
			long int age, phone;
			int salary;

			employee()
			{
				cout<<"Enter name: ";
				cin>>name;
				cout<<"Enter age: ";
				cin>>age;
				cout<<"Enter phone number: ";
				cin>>phone;
				cout<<"Enter salary: ";
				cin>>salary;			
			}
			void printSalary()
			{
				cout<<salary;
			}
};


class officer : public employee{
	public:
			string spec;
			
			officer()
			{
				cout<<"Enter area of specialization: ";
				cin>>spec;
			}
			
			void putDetailsofofficer()
			{
				cout<<"\n\nDetails of Officer:-";
				cout<<"\nName: "<<name;	
				cout<<"\nAge: "<<age;	
				cout<<"\nPhone number: "<<phone;	
				cout<<"\nSalary: "<<salary;
				cout<<"\nArea of specialization: "<<spec;			
			}
};

class manager : public employee{
	public:
			string dept;
			
			manager()
			{
				cout<<"Enter department of management: ";
				cin>>dept;
			}
			
			void putDetailsofmanager()
			{
				cout<<"\n\nDetails of Manager:-";
				cout<<"\nName: "<<name;	
				cout<<"\nAge: "<<age;	
				cout<<"\nPhone number: "<<phone;	
				cout<<"\nSalary: "<<salary;
				cout<<"\nDepartment managing: "<<dept;			
			}
};

int main()
{
	cout<<"Enter details of Officer:-\n";
	officer ofc;
	cout<<"\nEnter details of Manager:-\n";
	manager mgr;	
	ofc.putDetailsofofficer();
	mgr.putDetailsofmanager();
	cout<<"\n\nOfficer Salary: ";
	ofc.printSalary();
	cout<<"\nManager Salary: ";
	mgr.printSalary();
	cout<<"\n";
}
