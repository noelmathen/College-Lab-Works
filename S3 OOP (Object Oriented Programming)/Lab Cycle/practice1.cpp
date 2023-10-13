// #include<iostream>
// using namespace std;
// class A{
//     public:
//         int x;
//         A(){
//             x=10;
//         }
//         void printData()
//         {
//             cout<<"\n"<<x;
//         }
//         friend void access(A &obj1);
// };

// void access(A &obj1)
// {
//     obj1.x++;
//     cout<<"\n"<<obj1.x;
// }

// int main()
// {
//     A object;
//     object.printData();
//     access(object);
// }

// #include<iostream>
// using namespace std;

// class complex{
//     public:
//         int imag;
//         int real;

//         complex(int x, int y)
//         {
//             real=x;
//             imag=y;
//         }
//         complex operator + (complex const &obj)
//         {
//             complex result(0,0);
//             result.real=real+obj.real;
//             result.imag=imag+obj.imag;
//             return result;
//         }
//         void printData()
//         {
//             cout<<real<<"  "<<imag;
//         }

// };

// int main()
// {
//     complex a(1,1);
//     complex b(2,2);
//     complex c(0,0);
//     c=a+b;
//     c.printData();
// }



#include<iostream>
#include<string>
#include<stdlib.h>
#include<algorithm>
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
        strng operator+ (strng const &obj)
        {
            strng newstr;
            newstr.str=str+obj.str;
            return newstr;
        }

        strng operator = (strng const &obj)
        {
            strng newstr;
            this->str=obj.str;
            return newstr;
        }

        strng operator - (strng const &obj)
        {
            strng newstr;
            int index;
            newstr.str=this->str;
            index=(newstr.str).find(obj.str);
            if(index!=string::npos)
            {
                (newstr.str).erase(index,(obj.str).length());
            }
            return newstr;
        }

        void operator ++()
        {
            transform(this->str.begin(),this->str.end(),this->str.begin(), ::toupper);
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
            
            // case 4:{
            // 	cout<<"Enter the first string: ";
            //     obj1.readString();
            //     cout<<"Enter the second string: ";
            //     obj2.readString();
            //     obj1 <= obj2;         
            // 	break;    
            // }

			case 5:{
                cout<<"Enter the string: ";
            	obj1.readString();
                ++obj1;
                cout<<"String in uppercases: ";
                obj1.putString();        
            	break;    
            }

			// case 6:{
            //     cout<<"Enter the string: ";
            // 	obj1.readString();
            //     --obj1;  
            //     cout<<"String in lowercases: "; 
            //     obj1.putString();       
            // 	break;    
            // }
            
            // case 7:{
            //     cout<<"Enter the string: ";
            // 	obj1.readString();

            // 	obj1.displayLength();     
            // 	break;    
            // }
            
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
