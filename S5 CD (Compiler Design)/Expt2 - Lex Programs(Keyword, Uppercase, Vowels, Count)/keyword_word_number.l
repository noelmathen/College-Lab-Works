/* keywords_word_number.l */
%{ 
	#include<stdio.h>
%}

%%
if|else|printf|do|while {printf("%s is a keyword\n",yytext);}
[0-9]+ {printf("%s is a number\n",yytext);}
[a-zA-Z]+ {printf("%s is a word\n",yytext);}

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

