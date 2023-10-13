#include<iostream>
using namespace std;

class matrix{
	public:
			int mat[2][2];
			
			matrix()
			{
				mat[0][0]=0;
				mat[0][1]=0;
				mat[1][0]=0;
				mat[1][1]=0;
			}
			
			matrix(int a, int b, int c, int d)
			{
				mat[0][0]=a;
				mat[0][1]=b;
				mat[1][0]=c;
				mat[1][1]=d;
			}
			
			matrix addmatrix(matrix a, matrix b)
			{
				matrix c;
				c.mat[0][0]=a.mat[0][0]+b.mat[0][0];
				c.mat[0][1]=a.mat[0][1]+b.mat[0][1];
				c.mat[1][0]=a.mat[1][0]+b.mat[1][0];
				c.mat[1][1]=a.mat[1][1]+b.mat[1][1];
				return c;
			}
			
			void display()
			{
				cout<<mat[0][0]<<"  "<<mat[0][1];
				cout<<"\n";
				cout<<mat[1][0]<<"  "<<mat[1][1];
			}
			
			~matrix()
			{
				
			}


};

int main()
{
	matrix m1(2,2,4,4);
	matrix m2(1,1,2,2);
	matrix m3;
	cout<<"The first matrix is: \n";
	m1.display();
	cout<<"\n\nThe second matrix is: \n";
	m2.display();
	m3=m3.addmatrix(m1,m2);
	cout<<"\n\nThe matrix addition is: \n";
	m3.display();
	cout<<"\n";
}












