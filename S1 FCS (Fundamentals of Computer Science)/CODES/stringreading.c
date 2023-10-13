/* Program to count the number of words, characters and sentences in a given text */
#include<stdio.h>
void main()
{
		char a[1000];
		int sent=0,word=1,charct=1,i=0;
		printf("Rules for entering text:- \n1. Enter fullstop after finishing the text.\n2. Enter fullstop after every sentences.\n3. Enter space after fullstop before startng next sentence.\n\n");
		printf("Enter text: ");
		fgets(a,sizeof(a),stdin);
		for(i=0;i<sizeof(a);i++)
		{
			if(a[i]=='\0')
			{
				break;
			}
			if(a[i]=='.' || a[i]=='!' || a[i]=='?')
			{
				sent++;
			}
			if(a[i]==' ')
			{
				word++;
			}
			else
			{
				charct++;	
			}
		}
		printf("The number of words is : %d\n",word);
		printf("The number of characters is: %d\n",charct);
		printf("The number of sentences is: %d\n",sent);
}
