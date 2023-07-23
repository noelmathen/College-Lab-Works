/*Write a C Program to prepare a rank list of students using structure. Parameters required in student record are Roll No, Name of the Student,mark of subject1, mark of subject2, mark of subject3, Total Marks.*/

#include<stdio.h>

struct record
{
	int rollno;
	char fname[30];
	char sname[30];
	int subm1;
	int subm2;
	int subm3;
	int total;
};

void main()
{
	int n,i,j;
	printf("Enter no. of entries: ");
	scanf("%d",&n);
	
	struct record sr[n],temp[i];
	for(i=0;i<n;i++)
	{
		printf("\nEnter details of Student %d \n",i+1);
		printf("Enter Roll number: ");
		scanf("%d",&sr[i].rollno);
		printf("Enter First Name: ");
		scanf("%s",sr[i].fname);
		printf("Enter Last Name: ");
		scanf("%s",sr[i].sname);
		printf("Enter mark of Subject 1: ");
		scanf("%d",&sr[i].subm1);
		printf("Enter mark of Subject 2: ");
		scanf("%d",&sr[i].subm2);
		printf("Enter mark of Subject 3: ");
		scanf("%d",&sr[i].subm3);
		sr[i].total=sr[i].subm1+sr[i].subm2+sr[i].subm3;
	}
	printf("\nAfter sorting based on highest total marks, the rank list is as follows: \n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-i-1);j++)
			{
				if(sr[j].total<sr[j+1].total)
				{
					temp[j]=sr[j];
					sr[j]=sr[j+1];
					sr[j+1]=temp[i];
				}
			}
	}
		
	for(i=0;i<n;i++)
	{
		printf("Rank %d:\n",i+1);
		printf("Roll number of student is: %d \n",sr[i].rollno);
		printf("Name of student is: %s %s\n",sr[i].fname,sr[i].sname);
		printf("Mark of Subject 1 is: %d \n",sr[i].subm1);
		printf("Mark of Subject 2 is: %d \n",sr[i].subm2);
		printf("Mark of Subject 3 is: %d \n",sr[i].subm3);
		printf("Total marks are: %d \n",sr[i].total);
		printf("\n"); 
	}
}
