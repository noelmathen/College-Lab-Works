#include<iostream>
#include<stdlib.h>  //used for exit(0) function
#include<string>    //used for getline() function
#include<algorithm>  //used for the transform()s function

using namespace std;
class strng{
    public:
        string str;
        
        void readString()
        {
            getline(cin, str);
        }

        void putString()
        {
            cout<<str;
        }

        strng operator +(strng const &obj)
        {
        	strng newstr;
			newstr.str = this->str + obj.str;   //here, this->str is the 1st string(string passed from obj1) and obj.str is the 2nd string(string passed from obj2)
			return newstr;
        }
        
        strng operator -(strng const &obj)
        {
        	strng newstr;
        	int index;
        	newstr.str=this->str;   //copies 1st string to newstr
        	index=(newstr.str).find(obj.str);   //finding the index(beginning position) of occurence of 2nd string in 1st string
        	if(index != string::npos)   //string::npos is the value returned when there is no occurence of the substring in the main string. as long as there IS AN occurence, the code inside if will be executed.
        	{
        		(newstr.str).erase(index,(obj.str).length());   //for understanding => mainstring.erase(a,b) where a is the index mentioned above and b is the length of the substring.
        	}
			return newstr;
        }
        
        strng operator =(strng const &obj)
        {
        	strng newstr;
        	this->str=obj.str;
        	return newstr;
        }
        
        strng operator <=(strng const &obj)
        {
        	strng newstr;
        	if(this->str == obj.str)
        	{
        		cout<<"The srings are same!";
        	}
        	else
			{
				cout<<"The strings are not same!";
			}
			return newstr;
        }
        
        void operator ++()  //there is no other return type for unary operator overloading
        {
        	transform(this->str.begin(), this->str.end(), this->str.begin(), ::toupper);    //byheart peebols
        }
        
        void operator --()  
        {
        	transform(this->str.begin(), this->str.end(), this->str.begin(), ::tolower); //this also byheart peebols
        }
        
        void displayLength()
        {
        	cout<<"The length of the string is: "<<this->str.length();
        }
		
};



int main()
{
    int ch;
    strng obj1, obj2, obj3;
    cout<<"OPERATOR OVERLOADING FOR STRING FUNCTIONS!\n\n";
	cout<<"MENU:-\n1. CONCATENATION(+)\n2. COPY(=)\n3. SUBSTRING REMOVAL(-)\n4. COMPARE(<=)\n5. TO UPPERCASE(++)\n6. TO LOWERCASE(--)\n7. DISPLAY LENGTH\n0. EXIT\n";
    while(1)
    {
        cout<<"\n\nEnter your choice: ";
        cin>>ch;
        cin.ignore();
        
        switch(ch)
        {
            case 1:{
                cout<<"Enter the first string: ";
                obj1.readString();
                cout<<"Enter the second string: ";
                obj2.readString();
                obj3 = (obj1 + obj2);
                cout<<"The strings after concatenation is: ";
                obj3.putString();
                break;
            }

            case 2:{
                cout<<"Enter the string to be copied: ";
                obj1.readString();
                obj2 = obj1;
                cout<<"The copied string is: ";
                obj2.putString();
                break;
            }
            
            case 3:{
                cout<<"Enter the main string: ";
            	obj1.readString();
                cout<<"Enter the substring to be removed from main string: ";
            	obj2.readString();
            	obj3 = obj1 - obj2;
                cout<<"String after substring removal: ";
            	obj3.putString();
            	break;    
            }
            
            case 4:{
            	cout<<"Enter the first string: ";
                obj1.readString();
                cout<<"Enter the second string: ";
                obj2.readString();
                obj1 <= obj2;         
            	break;    
            }

			case 5:{
                cout<<"Enter the string: ";
            	obj1.readString();
                ++obj1;
                cout<<"String in uppercases: ";
                obj1.putString();        
            	break;    
            }

			case 6:{
                cout<<"Enter the string: ";
            	obj1.readString();
                --obj1;  
                cout<<"String in lowercases: "; 
                obj1.putString();       
            	break;    
            }
            
            case 7:{
                cout<<"Enter the string: ";
            	obj1.readString();

            	obj1.displayLength();     
            	break;    
            }
            
            case 0:{
                cout<<"OHK BEI:)))\n"; 
                exit(0);
            }

            default:{
                cout<<"INVALID CHOICE!";
                break;
            }
        }
    }
}


