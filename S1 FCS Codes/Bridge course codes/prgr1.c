/* Program to add two numbers using pointers */
#include<stdio.h>
void main()
{
  int a, b, c, *p1, *p2;
  printf("Enter two numbers: ");
  scanf("%d %d",&a,&b);
  p1=&a;
  p2=&b;
  c = *p1 + *p2;
  printf("Then sum is %d",c);
}