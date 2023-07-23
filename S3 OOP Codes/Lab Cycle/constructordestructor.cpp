#include<iostream>
using namespace std;

static int count=1;
	
class Student{
	private:
			long int Contact;
			string Email;
			float SemGPA[8], TotalCGPA;
			
			void compute()
			{
				float sum=0;
				for(int i=0;i<8;i++)
				{
					sum=sum+SemGPA[i];
				}
				TotalCGPA=sum/8;
				cout<<"\n\nThe CGPA is: "<<TotalCGPA;
			}

	public:
			long int RNo;
			string Sname;
		
			Student()
			{
				RNo=count++;
			}
			
			void getData()
			{ 
				cout<<"\nEnter Name: ";
				cin>>Sname;
				cout<<"Roll Number: "<<RNo;
				cout<<"\nEnter Contact Number: ";
				cin>>Contact;
				cout<<"Enter Email Address: ";
				cin>>Email;
				for(int i=0;i<8;i++)
				{
					cout<<"Enter Semester"<<i+1<<" GPA: ";
					cin>>SemGPA[i];
				}
			}
			
			void putData()
			{
				cout<<"\n\nName: "<<Sname;
				cout<<"\nRoll Number: "<<RNo;
				cout<<"\nContact number: "<<Contact;
				cout<<"\nEmail Address: "<<Email;
				for(int i=0;i<8;i++)
				{
					cout<<"\nSemester "<<i+1<<"GPA: "<<SemGPA[i];
				}
				compute();
			}
			
			
};


int main()
{
	int i, n;
	cout<<"Enter number of students(less than 10): ";
	cin>>n;
	Student s[n];
	
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter details of student "<<i+1<<":-";
		s[i].getData();
	}
	for(i=0;i<n;i++)
	{
		cout<<"\n\nDetails of student "<<i+1<<";";
		s[i].putData();
	}
	cout<<"\n";
}







































