/*#include <iostream>
using namespace std;

int main() {
  char str[30];

  cout << "Enter your city name: ";

  cin.get(str,30);
  // The user input will be stored in the str variable 

  cout << "You have entered: " << str<<endl;

  return 0;
}*/

// #include<iostream>
// #include<string.h>
// #include<stdlib.h>
// #include<cwctype>
// using namespace std;

// int main()
// {
// 	int l1,l2,l3;
//     string str;
//     cout<<"Enter string: ";
// 	cin>>str;
// 	l1=str.length();
//     cout << "size: " <<l1<<endl;

// 	if(iswalnum(str))
// 	{
// 		cout<<"aerbarb";
// 	}
//     return 0;
// }

#include<iostream>
#include<string.h>
using namespace std;
class str
{
public:
char s[25];
str() { }
str(char st[])
{
strcpy(this->s, st);
}
str operator +(str const &obj)
{
str s3;
strcpy(s3.s, this->s);
strcat(s3.s, obj.s);
return s3;
}
str operator =(str const &obj)
{
strcpy(this->s, obj.s);
return obj;
}
void operator <=(str const &obj)
{
int n=strlen(this->s), i, m=strlen(obj.s),l, f=0;
if(m>n)
l=m;
else
l=n;
for (i=0; i<l; i++)
{
if(this->s[i]!=obj.s[i])
{
cout<<"\n not equal\n";
f=1;
break;
}
}
if(f==0)
cout<<"equal";
}
void operator ++ ()
{
for(int i=0; i<strlen(this->s); i++)
{
this->s[i]=toupper(this->s[i]);
}
}
void operator -- ()
{
for(int i=0; i<strlen(this->s); i++)
{
this->s[i]=tolower(this->s[i]);
}
}
void len()
{
cout<<"\nLength of given string is: "<<strlen(this->s);
}
void print()
{
cout<<endl;
for(int i=0; i<strlen(this->s); i++)
{
cout<<s[i];
}
}
};
int main()
{
int ch;
cout<<"\nMain Menu\n1.Concatenation\n2.String Copy\n3.Comparison String\n4.Uppercase\n5.Lowercase\n6.Length\nEnter your choice: ";
cin>>ch;
switch(ch)
{
case 1: {
char s1[20], s2[20];
cout<<"\nEnter your strings: ";
cin.ignore();
cin.getline(s1,20);
cin.getline(s2,20);
str o1(s1);
str o2(s2);
str o3;
o3=o1+o2;
o3.print();
break;
}
case 2: {
char s1[20], s2[20];
cout<<"\nEnter your string: ";
cin.ignore();
cin.getline(s1,20);
str o1;
o1=s1;
o1.print();
break;
}
case 3: {
char s1[20], s2[20];
cout<<"\nEnter your strings: ";
cin.ignore();
cin.getline(s1,20);
cin.getline(s2,20);
str o1(s1);
str o2(s2);
o1<=o2;
break;
}
case 4: {
char s1[20];
cout<<"\nEnter your string in lowercase: ";
cin.ignore();
cin.getline(s1,20);
str o1(s1);
++o1;
break;
}
case 5: {
char s1[20];
cout<<"\nEnter your string in lowercase: ";
cin.ignore();
cin.getline(s1,20);
str o1(s1);
--o1;
break;
}
case 6: {
char s1[20];
cout<<"\nEnter your string in lowercase: ";
cin.ignore();
cin.getline(s1,20);
str o1(s1);
o1.len();
break;
}
default: cout<<"\nWRONG CHOICE!";
break;
}
}