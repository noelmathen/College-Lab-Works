#include<iostream>
using namespace std;

class student{
    public:
        int Rno;
        string name;

        void getStudentData()
        {
            cout<<"\nEnter student Roll Number: ";
            cin>>Rno;
            cout<<"Enter student Name: ";
            cin>>name;
        }
};

class test : public student{
    public:
        float markSub1, markSub2, markSub3;

        void getMarks()
        {
            cout<<"\nEnter mark of Subject 1: ";
            cin>>markSub1;
            cout<<"Enter mark of Subject 2: ";
            cin>>markSub2;
            cout<<"Enter mark of Subject 3: ";
            cin>>markSub3;
        }
};

class result : public test{
    public:
        float total;

        void putResult()
        {
            total=markSub1+markSub2+markSub3;
            cout<<"\nName: "<<name;
            cout<<"\nRoll number: "<<Rno;
            cout<<"\nTotal Marks: "<<total;
        }
};

int main()
{
    // student stud1;
    // test t1;
    // result r1;

    // stud1.getStudentData();
    // t1.getMarks();
    // r1.putResult();
    // cout<<"\n";

    result stud1;

    stud1.getStudentData();
    stud1.getMarks();
    stud1.putResult();
    cout<<"\n";
}