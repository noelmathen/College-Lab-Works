#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char buffer[])
{
	char keywords[32][10] = 
	{"auto","break","case","char","const","continue","default",
		"do","double","else","enum","extern","float","for","goto",
		"if","int","long","register","return","short","signed",
		"sizeof","static","struct","switch","typedef","union",
		"unsigned","void","volatile","while"};
	int i, flag = 0;
	for(i = 0; i < 32; ++i)
	{
		if(strcmp(keywords[i], buffer) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
 
int main()
{
	char ch, buffer[15], operators[] = "+-*/%=";
	int newline=1;
	FILE *fp;
	int i,j=0, f=0;
	fp = fopen("expression.txt","r");
	printf("\nLexeme\tTokens\t\tLine number\n\n");
	if(fp == NULL)
	{
		printf("error while opening the file\n");
		exit(0);
	}
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n'){
			newline++;
		}
		if(isalnum(ch))
		{
				buffer[j++] = ch;
				if(isdigit(buffer[0])){
					printf("Invald expression!\n");
					exit(0);
				}
		}
		else if((ch == ' ' || f == 1) && (j != 0))
		{
				if(ch == '\n'){
					newline++;
				}
				buffer[j] = '\0';
				j = 0;
				f=0;

				if(isKeyword(buffer) == 1)
						printf("%s\tkeyword\t\t%d\n", buffer, newline);
				else
						printf("%s\tidentifier\t%d\n", buffer, newline);
				// printf("\t\t%d", newline);
		}
		else if(ch == ';'){
			printf("%c\tpunctuation\t%d\n", ch, newline);
		}
		for(i = 0; i < 6; ++i)
		{
			if(ch == operators[i])
				printf("%c\toperator\t%d\n", ch, newline);
				f=1;
		}
	}
	fclose(fp);
	return 0;
}
