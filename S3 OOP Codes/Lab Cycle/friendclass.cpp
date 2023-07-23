#include<iostream>
using namespace std;
static int count1=1, count2=1, count3=1;

class student{
	public:
			string name, email;
			long long int stdid, phone;
			float Subject1_IA, Subject2_IA, Subject3_IA, Subject1_ESE, Subject2_ESE, Subject3_ESE, Subject1_Attendance, Subject2_Attendance, Subject3_Attendance, Total, CGPA;
			bool eligibleStatus;
			
			student()
			{
				stdid=count1++;
				Subject1_IA=0; 
				Subject2_IA=0; 
				Subject3_IA=0;
				Subject1_ESE=0; 
				Subject2_ESE=0; 
				Subject3_ESE=0;
				Subject1_Attendance=0;
				Subject2_Attendance=0;
				Subject3_Attendance=0;
			}
			
			void getData()
			{
				cout<<"\nEnter student name: ";
				cin>>name;
				cout<<"Student ID: "<<stdid;
				cout<<"\nEnter phone number: ";
				cin>>phone;
				cout<<"Enter email id: ";
				cin>>email;
			}
			
			void displayCard()
			{
				cout<<"\nName: "<<name;
				cout<<"\nStudent ID: "<<stdid;
				cout<<"\nPhone number: "<<phone;
				cout<<"\nEmail id: "<<email;
				cout<<"\nSubject 1 Internal Marks(IA): "<<Subject1_IA;
				cout<<"\nSubject 1 ESE Marks: "<<Subject1_ESE;
				cout<<"\nSubject 1 Attendance: "<<Subject1_Attendance;
				cout<<"\nSubject 2 Internal Marks(IA): "<<Subject2_IA;
				cout<<"\nSubject 2 ESE Marks: "<<Subject2_ESE;
				cout<<"\nSubject 2 Attendance: "<<Subject2_Attendance;
				cout<<"\nSubject 3 Internal Marks(IA): "<<Subject3_IA;
				cout<<"\nSubject 3 ESE Marks: "<<Subject3_ESE;
				cout<<"\nSubject 3 Attendance: "<<Subject3_Attendance;
				cout<<"\nTotal Marks: "<<Total;
				cout<<"\nTotal CGPA: "<<CGPA;
				cout<<"\nEligibility Status: "<<eligibleStatus;
			}
			friend class Class_Teacher;
			friend class Subject_Teacher;
};

class Class_Teacher{
	public:
		long int phone, empid;
		string name, email;
		
		Class_Teacher()
		{
			empid=count2++;
		}
		
		void getData()
		{
			cout<<"\nEnter details of Class teacher:- ";
			cout<<"\nEnter class teacher name: ";
			cin>>name;
			cout<<"Class teacher ID: "<<empid;
			cout<<"\nEnter phone number: ";
			cin>>phone;
			cout<<"Enter email id: ";
			cin>>email;
		}
		
		void calculateTotal(student &val,int x)
		{
				val.Total=(val.Subject1_IA+val.Subject1_ESE+val.Subject1_Attendance+val.Subject2_IA+val.Subject2_ESE+val.Subject2_Attendance+val.Subject3_IA+val.Subject3_ESE+val.Subject3_Attendance);

		}
		
		void calculateCGPA(student &val, int x)
		{
				val.CGPA=val.Total/30;
		}
		void eligibility(student &val, int x)
		{
			if((val.Subject1_Attendance+val.Subject2_Attendance+val.Subject3_Attendance)/3 >= 7)
			{	
				val.eligibleStatus=true;
			}
			else
				val.eligibleStatus=false;
		}
		void showRanklist(student st[], int n)
		{
			int i, j;
			student temp;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n-i-1;j++)
				{
					if(st[j].CGPA<st[j+1].CGPA)
					{
						temp=st[j];
						st[j]=st[j+1];
						st[j+1]=temp;
					}
				}
			}
			cout<<"\n\nRANKLIST:- ";
			for(i=0;i<n;i++)
			{
				cout<<"\n";
				cout<<"\nRANK "<<i+1<<":- ";
				st[i].displayCard();
			}
		}
};


class Subject_Teacher{
	public:
		long int phone, empid;
		string name, email;
		
		Subject_Teacher()
		{
			empid=count3++;
		}

		void getData()
		{
			cout<<"\nEnter subject teacher name: ";
			cin>>name;
			cout<<"Subject teacher ID: "<<empid;
			cout<<"\nEnter phone number: ";
			cin>>phone;
			cout<<"Enter email id: ";
			cin>>email;
		}

		void enterMarks(student &val1, int x)
		{
			if(empid==1)
			{
				cout<<"\nEnter mark details of student "<<x<<":- ";
				cout<<"\nEnter Internal Assessment(IA) mark: ";
				cin>>val1.Subject1_IA;
				cout<<"Enter End Sem Examination(ESE) mark: ";
				cin>>val1.Subject1_ESE;
			}
			
			if(empid==2)
			{
				cout<<"\nEnter mark details of student "<<x<<":- ";
				cout<<"\nEnter Internal Assessment(IA) mark: ";
				cin>>val1.Subject2_IA;
				cout<<"Enter End Sem Examination(ESE) mark: ";
				cin>>val1.Subject2_ESE;
			}
			
			if(empid==3)
			{
				cout<<"\nEnter mark details of student "<<x<<":- ";
				cout<<"\nEnter Internal Assessment(IA) mark: ";
				cin>>val1.Subject3_IA;
				cout<<"Enter End Sem Examination(ESE) mark: ";
				cin>>val1.Subject3_ESE;
			}
		}

		void enterAtt(student &val2,int y)
		{
			if(empid==1)
			{
				cout<<"Enter attendance of student "<<y<<":- ";
				cin>>val2.Subject1_Attendance;
			}
			
			if(empid==2)
			{
				cout<<"Enter attendance of student "<<y<<":- ";
				cin>>val2.Subject2_Attendance;
			}
			
			if(empid==3)
			{
				cout<<"Enter mark attendance of student "<<y<<":- ";
				cin>>val2.Subject3_Attendance;
			}
		}
		
};



int main()
{
	int i, j;
	student stud[5];
	Class_Teacher Ctchr;
	Subject_Teacher Stchr[3];
	for(i=0;i<5;i++)
	{
		cout<<"\nEnter details of student "<<i+1<<":- ";
		stud[i].getData();
	}
	
	Ctchr.getData();
	
	for(i=0;i<3;i++)
	{
		cout<<"\nEnter details of subject teacher "<<i+1<<":- ";
		Stchr[i].getData();
	}


	for(i=0;i<3;i++)
	{
		cout<<"\nFor subject teacher "<<i+1<<":- \n";
		for(j=0;j<5;j++)
		{
			Stchr[i].enterMarks(stud[j],j+1);
			Stchr[i].enterAtt(stud[j],j+1);
		}
	}
	for(i=0;i<5;i++)
	{
		Ctchr.calculateTotal(stud[i],i+1);
		Ctchr.calculateCGPA(stud[i],i+1);
		Ctchr.eligibility(stud[i],i+1);
	}

	for(i=0;i<5;i++)
	{
		cout<<"\n\nDETAILS OF STUDENT "<<i+1<<":-\n ";
		stud[i].displayCard();
	}
	Ctchr.showRanklist(stud,5);
	cout<<"\n";
}





