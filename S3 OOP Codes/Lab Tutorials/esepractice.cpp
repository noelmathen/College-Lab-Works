// #include <iostream>
// using namespace std;

// int global_var = 10;  // Global variable

// int main() {
//    int local_var = 5;  // Local variable
//    cout << "Global variable value: " << global_var << endl;  // Using scope resolution operator to access global variable
//    cout << "Local variable value: " << local_var << endl;
//    return 0;
// }


// // C++ program to create a member function of another class
// // as a friend function
// #include <iostream>
// using namespace std;

// class base; // forward definition needed
// // another class in which function is declared
// class anotherClass {
// public:
// 	void memberFunction(base &obj);
// };

// // base class for which friend is declared
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
// 	friend void anotherClass::memberFunction(base &obj);
// };

// // friend function definition
// void anotherClass::memberFunction(base& obj)
// {
// 	cout << "Private Variable: " << obj.private_variable
// 		<< endl;
// 	cout << "Protected Variable: " << obj.protected_variable;
// }

// // driver code
// int main()
// {
// 	base object1;
// 	anotherClass object2;
// 	object2.memberFunction(object1);
// 	return 0;
// }

// #include <iostream>
// using namespace std;

// class A;

// class B{
//    public:
//       void accessFunction(A &obj);
// }; 

// class A{
//    private:
//       int x;
//    protected:
//       int y;
//    public:
//       A()
//       {
//          x=10;
//          y=20;
//       }
//       friend void B :: accessFunction(A &obj);
// };

// void B :: accessFunction(A &obj)
// {
//    cout<<"Private element: "<<obj.x;
//    cout<<"Private element: "<<obj.y;
// }

// int main()
// {
//    B ob2;
//    A ob1;
//    ob2.accessFunction(ob1);
// }

// #include<iostream>
// #include<exception>
// using namespace std;
// int main()
// {	
// 	int a, b, c;
// 	cin>>a;
// 	cin>>b;
// 	try{
// 		if(b==0){
// 			throw exception();
// 		}
// 		else
// 		{
// 			cout<<(a/b);
// 		}
// 	}
// 	catch(exception &e)
// 	{
// 		cerr<<e.what();
// 	}

// 	catch(...)
// 	{
// 		cerr<<"ERR";
// 	}
// }


// #include<iostream>
// using namespace std;
// void swap(int &a, int &b)
// {
//     int temp;
//     temp=a;
//     a=b;
//     b=temp;
//     cout<<"Inside function: "<<a<<", "<<b;

// }
// int main()
// {
//     int x=3;
//     int y=4;
//     swap(x,y);
//     printf("\ninside main: %d, %d",x,y);
// }



// #include<iostream>
// using namespace std;
// void incr(int *arr)
// {
//     for(int i=0;i<5;i++)
//     {
//         *(arr+i)=2;
//     }
// }

// int main()
// {
//     int arr[5]={1,2,3,4,5};
//     incr(arr);
//     for(int i=0;i<5;i++)
//     {
//         cout<<" "<<arr[i];
//     }
// }



// #include <iostream>
// using namespace std;
// int main()
// {
// 	float f = 3.5;
// 	int a = f; // this is how you do in C
// 	int b = static_cast<int>(f);
// 	cout << a;
// }



// #include <iostream>
// using namespace std;
// class strng{
//     public:
//         string str;
//         strng(string msg)
//         {
//             str=msg;
//         }
//         void putString()
//         {
//             cout<<endl<<str;
//         }
//         strng(){};

//         strng operator +(strng const &obj)
//         {
//             strng newstr;
//             newstr.str = this->str + obj.str;
//             return newstr;
//         }
//         strng operator =(strng const &obj)
//         {
//             strng newstr;
//             this->str=obj.str;
//             return newstr;
//         }
// };


// int main()
// {
//     strng obj1("Noel");
//     strng obj2(" Mathen");
//     strng obj3("aa");
//     obj1.putString();
//     obj2.putString();
//     obj3=obj1 + obj2;
//     obj3.putString();
// }




// #include<iostream>
// using namespace std;

// class student{
//     public:
//         int m1, m2, tot;
//         void display()
//         {
//             cout<<"Mark 1: "<<m1<<endl;
//             cout<<"Mark 2: "<<m2<<endl;
//             cout<<"Total: "<<tot<<endl;
//         }
//         friend class teacher;
// };

// class teacher{
//     public:
//         void enterMarks(student &obj)
//         {
//             cout<<"Enter mark 1: ";
//             cin>>obj.m1;
//             cout<<"Enter mark 2: ";
//             cin>>obj.m2;
//             obj.tot = obj.m1 + obj.m2;
//         }

//         void topper(student stud[])
//         {
//             student large = stud[0];
//             for(int i=0;i<3;i++)
//             {
//                 if(large.tot < stud[i].tot)
//                 {
//                     large = stud[i+1];
//                 }
//             }          
//             cout<<endl<<"Topper is: "<<large.tot;
//         }
// };

// int main()
// {
//     student stud[3];
//     teacher binu;
//     int i;
//     for(i=0;i<3;i++)
//     {
//         binu.enterMarks(stud[i]);
//     }
//     for(i=0;i<3;i++)
//     {
//         stud[i].display();
//     }

//     binu.topper(stud);
    
// }



// #include<iostream>
// using namespace std;

// class Shape {
//     public:
//         virtual void draw() {
//             cout << "This is a shape." << endl;
//         }
// };

// class Circle : public Shape {
//     public:
//         void draw() {
//             cout << "This is a circle." << endl;
//         }
// };

// int main() {
//     Shape* ptr;

//     Circle c;
//     ptr = &c;
//     ptr->draw(); // Compile-time binding, calls Shape::draw()

//     Circle* cptr = new Circle();
//     ptr = cptr;
//     ptr->draw(); // Runtime binding, calls Circle::draw()

//     delete cptr;

//     return 0;
// }



// #include<iostream>
// #include<exception>
// using namespace std;
// int main()
// {
//     try{
//         int* arr = new int[10000000000000000];
//     }
//     catch(exception &e)
//     {
//         cout<<e.what();
//     }
// }



// #include <iostream>
// using namespace std;

// void bubbleSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     bubbleSort(arr, n);
//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;

// namespace np1{
//     void print()
//     {
//         cout<<"First function";
//     }
// }

// namespace np2{
//     void print()
//     {
//         cout<<"\nSenond function";
//     }
// }

// int main()
// {
//     np1::print();
//     np2::print();
// }



#include <iostream>
#include <string>
#include <cctype>

bool is_alphanumeric(const std::string& str) {
    for (char c : str) {
        if (!std::isalnum(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string s = "iaeucri";
    if (is_alphanumeric(s)) {
        std::cout << "The string is alphanumeric" << std::endl;
    } else {
        std::cout << "The string is not alphanumeric" << std::endl;
    }
    return 0;
}












