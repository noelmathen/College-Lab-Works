/* vowels.l */
%{
	#include<stdio.h>
%}
%%
a|e|i|o|u|A|E|I|O|U {printf("%s is a vowel\n",yytext);}
[a-z]|[A-Z] {printf("%s is a consonent\n",yytext);}
%%

int main()
{
	printf("Enter string:\n");
	yylex();

}

int yywrap()
{ 
	return 1;
}
