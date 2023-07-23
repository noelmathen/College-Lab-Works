#include<stdio.h>
#include<string.h>
void main()
{
  char str[1000], sub[500], temp[500];
  int i, j, pos;
  printf("Enter the text: ");
  fgets(str,sizeof(str),stdin);
  printf("Enter the substring: ");
  fgets(sub,sizeof(sub),stdin);
  printf("Enter the position in the string where the substring is to be enterd: ");
  scanf("%d",&pos);
  for(i=0,j=0; i<strlen(str),j<strlen(sub); i++,j++)
  {
    temp[i]=str[pos];
    str[pos]=sub[j];
    pos++;
  }
  for(i=0;i<strlen(temp);i++)
  {
    str[pos]=temp[i];
    pos++;
  }
  printf("\nThe moddified string is: ");
  for(i=0;i<strlen(str);i++)
  {
    if(str[i]!='\n')
    {
      printf("%c",str[i]);
    }
  }
  printf("\n");
}
