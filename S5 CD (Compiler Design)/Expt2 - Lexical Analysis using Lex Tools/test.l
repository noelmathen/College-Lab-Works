%{
#include<stdio.h>
#undef yywrap
%}

%%
"abc" {printf("Goodbye");}
%%

int main(){
	printf("Enter string: ");
	yylex();
}

int yywrap(){
	return 1;
}

