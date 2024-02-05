/* vowels.l */
%{ 
	#include<stdio.h>
%}

%%
[aeiouAEIOU] {printf("%s is a vowel\n",yytext);}
[a-zA-Z] {printf("%s is a consonant\n",yytext);}

[\t|\n];
%%

int main()
{
	printf("Enter string: ");
	yylex();
}

int yywrap()
{
	return 1;
}
