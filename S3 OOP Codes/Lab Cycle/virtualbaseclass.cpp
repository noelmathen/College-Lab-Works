#include<iostream> 
#include<stdlib.h> 
#include<string> 
using namespace std; 
static int count=1; 

class student 
{ 
	public: 
		string name; 
		int rno; 
		student() 
		{
			rno=count; 
			cout<<"\nEnter name of student: "; 
			getline(cin, name); 
		} 
}; 

class subject : virtual public student 
{ 
	public: 
	int n; 
	string subs[10]; 
	void getsub() 
	{ 
		cout<<"\nEnter number of subjects:";
		cin>>n; 
		for(int i=0; i<n; i++) 
		{ 
			cout<<"Enter subject:";
			cin>>subs[i];
		} 
	} 
	void putsub() 
	{ 
		for(int i=0; i<n; i++) 
		{ 
			cout<<"\nSubject "<<i+1<<": "; 
			cout<<subs[i]; 
		}
	} 
}; 
class language: virtual public student 
{ 
	public: 
		int k; 
		string lang[10]; 
		void getlang() 
		{ 
			cout<<"\n\nEnter number of languages: "; 
			cin>>k; 
			for(int i=0; i<k; i++) 
			{ 
				cout<<"Enter language:";
				cin>>lang[i]; 
			} 
		} 
		void putlang() 
		{ 
			for(int i=0; i<k; i++) 
			{ 
				cout<<"\nLanguage "<<i+1<<": "; 
				cout<<lang[i]; 
			} 
			cout<<"\n"; 
		} 
}; 
class result: public language, public subject 
{ 
	public: 
		float m[20]; 
		float total; 
		void putmarks() 
		{ 
			int i, j; 
			for(i=0, j=0; i<n; i++, j++) 
			{ 
				cout<<"Enter marks of "<<subs[i]<<": ";
				cin>>m[j];
			}
			for(i=0; i<k; i++, j++) 
			{ 
				cout<<"Enter marks of "<<lang[i]<<":";
				cin>>m[j]; 
			} 
		} 
		void calcmark() 
		{ 
			total=0; 
			int i; 
			for(i=0; i<n+k; i++) 
			{ 
				total+=m[i]; 
			} 
		} 
		void publish() 
		{ 
			cout<<"\nREPORT"; 
			cout<<"\nRoll no: "<<rno; 
			cout<<"\nName: "<<name; 
			cout<<"\nTotal marks: "<<total; 
			cout<<"\nAverage: "<<total/(n+k); int x=50*(n+k); 
			cout<<"\nPercentage: "<<(total/x)*100<<"%"; 
			cout<<"\n";
		}
}; 
  
 
int main() 
{ 
	result r; 
	r.getsub(); 
	r.putsub(); 
	r.getlang(); 
	r.putlang(); 
	cout<<"\n"; 
	r.putmarks(); 
	r.calcmark(); 
	r.publish(); 
}


