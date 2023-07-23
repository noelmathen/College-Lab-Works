#include<iostream>
#include<string>
using namespace std;

class employee{
	public:
			string name;
			int year;
			int salary;
			string address;
			
			void getdetails()
			{
				cout<<"Enter employee name: ";
				cin>>name;
				cout<<"Enter employee year of joining: ";
				cin>>year;
				cout<<"Enter employee salary: ";
				cin>>salary;
				cout<<"Enter employee address: ";
				cin>>address;
			}
			
			void putdetails()
			{
				cout<<"\n"<<name<<"\t"<<year<<"\t\t"<<salary<<"\t"<<address<<endl;
			}
};

int main()
{
	employee e1,e2,e3;
	cout<<"\nEMPLOYEE 1:\n";
	e1.getdetails();
	cout<<"\nEMPLOYEE 2:\n";
	e2.getdetails();
	cout<<"\n``EMPLOYEE 3:\n";
	e3.getdetails();
	
	cout<<"EMPLOYEE DETAILS:\n\nName\tYear of Joining\tSalary\tAddress";
	e1.putdetails();
	e2.putdetails();
	e3.putdetails(); 
}
