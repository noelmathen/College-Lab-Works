#include<iostream>
using namespace std;
class Student{
	public:
			long int RNo, Contact;
			string Sname, Email;
			float SemGPA[8], TotalCGPA;
			void getData()
			{ 
				cout<<"\nEnter Name: ";
				cin>>Sname;
				cout<<"\nEnter Roll Number: ";
				cin>>RNo;
				cout<<"\nEnter Contact Number: ";
				cin>>Contact;
				cout<<"\nEnter Email Address: ";
				cin>>Email;
				for(int i=0;i<8;i++)
				{
					cout<<"\nEnter Semester"<<i+1<<" GPA: ";
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
			}
			
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
};

int main()
{
	Student s1;
	s1.getData();
	s1.putData();
	s1.compute();
	cout<<"\n";
}
		
