#include<iostream>
using namespace std;
class Student{
    public:
            string name;
            int Rno;
};

class Internal : public Student{
    public:
            float IA1, IA2, IA3;
            friend class Result;
};

class External : public Student{
    public:
            float ESE;
            friend class Result;
};

class Result{
    public:
            float Total;
            void calcTotal(Internal &x, External &y)
            {
                Total = x.IA1 + x.IA2 + x.IA3 + y.ESE;
                cout<<"\nTotal = "<<Total;
            }
};

int main()
{
    Student stud;
    Internal intAss;
    External EndSem;
    Result rslt;
    intAss.name="Noel";
    EndSem.Rno=1;
    intAss.IA1=50;
    intAss.IA2=40;
    intAss.IA3=30;
    EndSem.ESE=100;
    cout<<"\nName: "<<intAss.name;
    cout<<"\nRoll Number: "<<EndSem.Rno;
    cout<<"\nIA1: "<<intAss.IA1;
    cout<<"\nIA2: "<<intAss.IA2;
    cout<<"\nIA3: "<<intAss.IA3;
    cout<<"\nESE: "<<EndSem.ESE;
    rslt.calcTotal(intAss, EndSem);
}
