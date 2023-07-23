// #include<bits/stdc++.h> 
// using namespace std;

// int main()
// {
// 	string str1, str2, str3, str4, str5, str6, str7, str8;
// 	int index;
// 	cout<<"Enter main string: ";
// 	getline(cin,str1);
	
// 	cout<<"Enter the substring to be removed: ";
// 	getline(cin,str2);
	
// 	/*str3=str1+str2;
// 	cout<<"\n\nThe concatenated string is: "<<str3;
	
// 	str4=str3;
// 	cout<<"\nString copy(3 to 4); "<<str4;
	
// 	if(str1==str2)
// 	{
// 		cout<<"\n\nThe srings are same!";
// 	}
// 	else
// 	{
// 		cout<<"\n\nThe string are not same";
// 	}
	
// 	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
// 	cout<<"\n\nString to upper case: "<<str1;
	
// 	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
// 	cout<<"\n\nString to upper case: "<<str2;
	
// 	cout<<endl<<"Size of string is: "<<str1.length();
// 	*/
	
// 	str3=str1;
// 	index=str3.find(str2);
	
// 	if(index != string::npos)
// 	{
// 		str3.erase(index,str2.length());
// 		cout<<"The string after removal is: "<<str3;
// 	}
// 	else
// 	{
// 		cout<<"The entered substring is not present in the main string!";
// 	}
	
	
// 	cout<<"\n";
// } 

// /* #include<bits/stdc++.h> 
// using namespace std;

// class strng{
// 	public: 
// 		string str;
		
// 		void readString()
// 		{
// 			cout<<"\n\nEnter your string: ";
// 			getline(cin,str);
// 		}
		
// 		void putString()
// 		{
// 			cout<<"The entered string is: "<<str;
// 		}
		
// 		strng operator +(strng const &obj)
// 		{
// 			strng newstr;
// 			newstr.str = this->str + obj.str;
// 			return newstr;
// 		}
		
// 		strng operator =(strng const &obj)
//         {
//         	strng newstr;
//         	newstr.str=this->str;
//         	return newstr;
//         }
// };

// int main()
// {
// 	strng obj1, obj2, obj3, obj4;
// 	int ch;
	
        
	
// 	cout<<"OPERATOR OVERLOADING FOR STRING FUNCTIONS!\n\n";
// 	cout<<"MENU:-\n1. CONCATENATION(+)\n2. COPY(=)\n3. SUBSTRING REMOVAL(-)\n4. COMPARE(<=)\n5. TO UPPERCASE(++)\n6. TO LOWERCASE(--)\n7. DISPLAY LENGTH\n0. EXIT";
	
// 	while(1)
// 	{
// 		cout<<"\n\nEnter your choice: ";
//         cin>>ch;
//         cin.ignore();
//         if(ch==1)
//         {
//         	obj1.readString();
// 			obj1.putString();
// 			obj2.readString();
// 			obj2.putString();
// 			obj3 = obj1 + obj2;
// 			cout<<endl<<"After concatenation: ";
// 			obj3.putString();
// 			break;
//         }
        
//         if(ch==2)
//         {
//         	obj1.readString();
// 			obj1.putString();
// 			obj2 = obj1;
// 			cout<<endl<<"After concatenation: ";
// 			obj2.putString();
//         }
        
//         else if(ch==0)
//         {
//         	cout<<"OHK BEI:)))\n"; 
//             exit(0);
//         }
        
//         else
//         {
//         	cout<<"INVALID CHOICE!";
//         }
// 	}
	
// 	cout<<"\n";
// }
// */

// #include<iostream>
// using namespace std;
// class array
// {
// 	public:
// 		int ar[5], i;
// 		array()
// 		{
// 			for(i=0;i<5;i++)
// 			{
// 				ar[i]=0;
// 			}
// 		}
// 		array operator +(array const &obj)
// 		{
// 			array z;
// 			for(i=0;i<5;i++)
// 			{
// 				z.ar[i]=ar[i]+obj.ar[i];
// 			}
// 				return z;

// 		}
// 		void putArray()
// 		{
// 			for(i=0;i<5;i++)
// 			{
// 				cout<<"  "<<ar[i];
// 			}
// 		}

// 		void getArray()
// 		{
// 			for(i=0;i<5;i++)
// 			{
// 				cin>>ar[i];
// 			}
// 		}
// };

// int main()
// {
// 	array a, b, c;
// 	a.getArray();
// 	b.getArray();
// 	c = a + b;
// 	c.putArray();
// }

// // C++ program for function overriding
// #include <bits/stdc++.h>
// using namespace std;

// class base {
// public:
// 	virtual void print()
// 	{
// 		cout << "print base class" <<
// 				endl;
// 	}

// 	 void show()
// 	{
// 	cout << "show base class" <<
// 			endl;
// 	}
// };

// class derived : public base {
// public:

// 	// print () is already virtual function in
// 	// derived class, we could also declared as
// 	// virtual void print () explicitly
// 	void print()	
// 	{
// 		cout << "print derived class" <<
// 				endl;
// 	}

// 	void show()
// 	{
// 	cout << "show derived class" <<
// 			endl;
// 	}
// };

// // Driver code
// int main()
// {
// 	base b;
// 	base* bptr;
// 	derived d;
// 	bptr = &d;

// 	// Virtual function, binded at
// 	// runtime (Runtime polymorphism)
// 	bptr->print();

// 	// Non-virtual function, binded
// 	// at compile time
// 	bptr->show();
// 	b.show();

// 	return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// class base {
// 	public:
// 	void show()
// 	{
// 		cout<<"Base class";
// 	}
// };

// class derived : public base {
// 	public:
// 	void show()
// 	{
// 		cout<<"\nDerived class";
// 	}
// };

// int main()
// {
// 	base A;
// 	derived B;
// 	A.show();
// 	B.show();
// }

// #include <bits/stdc++.h>
// using namespace std;

// class base {
// public:
// 	int a;
// 	virtual void print()=0;
// 	void sum()
// 	{
// 		cout<<"\nSum!";
// 	}
	
// };

// class derived : public base {
// 	public:
// 	void print()
// 	{
// 		cout<<"\nDerived class";
// 	}
// };

// int main()
// {
// 	base a;
// 	derived b;
// 	b.print();
// }

// #include <bits/stdc++.h>
// using namespace std;

// class A{
// 	public:
// 		int a;
// 		void hello()
// 		{
// 			cout<<"Hello";
// 		}
// };

// class B : virtual public A{

// };

// class C : virtual public A{

// };

// class D : public B, public C{

// };

// int main()
// {
// 	D obj1;
// 	obj1.hello();
// }

// #include <bits/stdc++.h>
// using namespace std;

// class SA;
// class CA;
// class LA;

// class SA{
// 	private:
// 		int SA_Amt;
// 	public:
// 		SA()
// 		{
// 			SA_Amt=1000;
// 		}
// 	friend void showBalance(SA , CA , LA );
// };

// class CA{
// 	private:
// 		int CA_Amt;
// 	public:
// 		CA()
// 		{
// 			CA_Amt=2000;
// 		}
// 	friend void showBalance(SA , CA , LA );
// };

// class LA{
// 	private:
// 		int LA_Amt;
// 	public:
// 		LA()
// 		{
// 			LA_Amt=3000;
// 		}
// 	friend void showBalance(SA , CA , LA );
// };

// void showBalance(SA a, CA b, LA c)
// {
// 	cout<<a.SA_Amt<<endl;
// 	cout<<b.CA_Amt<<endl;
// 	cout<<c.LA_Amt<<endl;
// }


// int main()
// {
// 	SA obj1;
// 	CA obj2;
// 	LA obj3;
// 	showBalance(obj1, obj2, obj3);
// }

// C++ program to create a global function as a friend
// function of some class
// #include <iostream>
// using namespace std;

// class base {
// private:
// 	int private_variable;

// protected:
// 	int protected_variable;

// public:
// 	base()
// 	{
// 		private_variable = 10;
// 		protected_variable = 99;
// 	}
	
// 	// friend function declaration
// 	friend void friendFunction(base);
// };


// // friend function definition
// void friendFunction(base obj)
// {
// 	cout << "Private Variable: " << obj.private_variable
// 		<< endl;
// 	cout << "Protected Variable: " << obj.protected_variable;
// }

// // driver code
// int main()
// {
// 	base object1;
// 	friendFunction(object1);

// 	return 0;
// }

// #include<iostream>
// using namespace std;

// int main()
// {
// 	int a, b, c;
// 	cin>>a;
// 	cin>>b;
// 	try
// 	{
// 		if(b==0)
// 		{
// 			throw 2;
// 		}
// 		else
// 		{
// 			c=a/b;
// 			cout<<c;
// 		}
// 	}
// 	catch(const char *msg)
// 	{
// 		cerr<<msg<<endl;
// 	}
// 	catch(...)
// 	{
// 		cerr<<"err";
// 	}
// }

#include<iostream>
#include<exception>
using namespace std;
int main()
{	
	int a, b, c;
	cin>>a;
	cin>>b;
	try{
		if(b==0){
			throw exception();
		}
		else
		{
			cout<<(a/b);
		}
	}
	catch(exception &e)
	{
		cerr<<e.what();
	}

	catch(...)
	{
		cerr<<"ERR";
	}
}


// #include<iostream>
// #include<stdlib.h>  //used for exit(0) function
// #include<string>    //used for getline() function
// #include<algorithm>  //used for the transform()s function
// using namespace std;

// class strng{
//     public:
//         string str;
        
//         void readString()
//         {
//             getline(cin, str);
//         }

//         void putString()
//         {
//             cout<<str;
//         }

//         strng operator +(strng const &obj)
// 		{
// 			strng newstr;
// 			newstr.str = this->str + obj.str;
// 			return newstr;
// 		}
		
// 		strng operator -(strng const &obj)
// 		{
// 			strng newstr;
// 			int index;
// 			newstr.str = this->str;
// 			index = newstr.str.find(obj.str);
// 			if(index != string::npos)
// 			{
// 				newstr.str.erase(index, obj.str.length());
// 			}
// 			return newstr;
// 		}

// 		strng operator =(strng const &obj)
// 		{
// 			strng newstr;
// 			this->str = obj.str;
// 			return newstr;
// 		}

// 		void operator ++()
// 		{
// 			transform(this->str.begin(), this->str.end(), this->str.begin(), ::toupper);
// 		}

// 		void operator --()
// 		{
// 			transform(this->str.begin(), this->str.end(), this->str.begin(), ::tolower);
// 		}
// };


// int main()
// {
//     int ch;
//     strng obj1, obj2, obj3;
//     cout<<"OPERATOR OVERLOADING FOR STRING FUNCTIONS!\n\n";
// 	cout<<"MENU:-\n1. CONCATENATION(+)\n2. COPY(=)\n3. SUBSTRING REMOVAL(-)\n4. COMPARE(<=)\n5. TO UPPERCASE(++)\n6. TO LOWERCASE(--)\n7. DISPLAY LENGTH\n0. EXIT\n";
//     while(1)
//     {
//         cout<<"\n\nEnter your choice: ";
//         cin>>ch;
//         cin.ignore();
        
//         switch(ch)
//         {
//             case 1:{
//                 cout<<"Enter the first string: ";
//                 obj1.readString();
//                 cout<<"Enter the second string: ";
//                 obj2.readString();
//                 obj3 = (obj1 + obj2);
//                 cout<<"The strings after concatenation is: ";
//                 obj3.putString();
//                 break;
//             }

//             case 2:{
//                 cout<<"Enter the string to be copied: ";
//                 obj1.readString();
//                 obj2 = obj1;
//                 cout<<"The copied string is: ";
//                 obj2.putString();
//                 break;
//             }
            
//             case 3:{
//                 cout<<"Enter the main string: ";
//             	obj1.readString();
//                 cout<<"Enter the substring to be removed from main string: ";
//             	obj2.readString();
//             	obj3 = obj1 - obj2;
//                 cout<<"String after substring removal: ";
//             	obj3.putString();
//             	break;    
//             }
            
//             case 4:{
//             	cout<<"Enter the first string: ";
//                 obj1.readString();
//                 cout<<"Enter the second string: ";
//                 obj2.readString();
//                 // obj1 <= obj2;         
//             	break;    
//             }

// 			case 5:{
//                 cout<<"Enter the string: ";
//             	obj1.readString();
//                 ++obj1;
//                 cout<<"String in uppercases: ";
//                 obj1.putString();        
//             	break;    
//             }

// 			case 6:{
//                 cout<<"Enter the string: ";
//             	obj1.readString();
//                 --obj1;  
//                 cout<<"String in lowercases: "; 
//                 obj1.putString();       
//             	break;    
//             }
            
//             case 7:{
//                 cout<<"Enter the string: ";
//             	obj1.readString();

//             	// obj1.displayLength();     
//             	break;    
//             }
            
//             case 0:{
//                 cout<<"OHK BEI:)))\n"; 
//                 exit(0);
//             }

//             default:{
//                 cout<<"INVALID CHOICE!";
//                 break;
//             }
//         }
//     }
// }


