/* Program to find the length of the string using Pointer */
#include<stdio.h>
void main()
{
    char a[1000];
    int i,len=-1;
    int *p;
    printf("Enter a string: ");
    fgets(a,sizeof(a),stdin);
    for(i=0;i<sizeof(a);i++)
    {
      if(a[i]=='\0')
      {
        break;
      }
      else
      {
        len++;
      }
    }
    p=&len;
    printf("The lentgh of the string is: %d\n",*p);
}