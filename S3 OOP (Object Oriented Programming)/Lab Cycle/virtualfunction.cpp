#include<iostream> 
#include<stdlib.h> 
#include<string> 
using namespace std; 

class student 
{ 
	public: 
	int rno; 
	float mark1, mark2, total; 
	string name; 
	student() 
	{ 
		cout<<"\nEnter roll number: "; 
		cin>>rno; 
		cin.ignore(); 
		cout<<"Enter name: "; 
		getline(cin,name); 
		cout<<"Enter mark 1: "; 
		cin>>mark1; 
		cout<<"Enter mark 2: "; 
		cin>>mark2; 
		total=mark1+mark2; 
	} 
	
	virtual void showdata() 
	{ 
		cout<<"\nRoll number: "<<rno; 
		cout<<"\nName: "<<name; 
		cout<<"\nMark 1: "<<mark1; 
		cout<<"\nMark 2: "<<mark2; 
		cout<<"\nTotal: "<<total; 
		cout<<"\n"; 
	} 
}; 
class minor: public student 
{ 
	public: 
	float m1, m2, m3; 
	minor( ) 
	{ 
		cout<<"\nEnter minor mark 1: "; 
		cin>>m1; 
		cout<<"Enter minor mark 2: ";
		cin>>m2; 
		cout<<"Enter minor mark 3: ";
		cin>>m3; 
	} 
	
	void showdata() 
	{ 
		cout<<"\nRoll number: "<<rno; 
		cout<<"\nName: "<<name; 
		cout<<"\nMinor mark 1: "<<m1; 
		cout<<"\nMinor mark 2: "<<m2; 
		cout<<"\nMinor mark 3: "<<m3; 
		total=m1+m2+m3; 
		cout<<"\n\nTotal of minor marks: "<<total; 
	} 
};

int main() 
{ 
	minor m; 
	student  *ptr; 
	ptr=&m; 
	ptr->showdata(); 
	// m.showdata(); accessing without base pointer
	cout<<endl; 
}

