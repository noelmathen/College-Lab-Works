%{
#include <stdio.h>
%}
%option noyywrap
%%

[ \t]+   ;
[\n] {yylineno++;}
auto|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {printf("%s\t\tKeyword\t\t\t%d\n",yytext, yylineno);}
[+-/*<>=^]     {printf("%s\t\tOperator\t\t%d\n", yytext, yylineno);}
[0-9]+     {printf("%s\t\tNumber\t\t%d\n", yytext, yylineno);}
main|stdio|h|printf	{printf("%s\t\tIdentifier\t\t%d\n", yytext, yylineno);}
[a-zA-Z]+  {printf("%s\t\tString\t\t\t%d\n", yytext, yylineno);}
[.,;:?!|&`~'\"]      {printf("%s\t\tPunctuation\t\t%d\n", yytext, yylineno);}
[\[({] 	{printf("%s\t\tOpening Brackets\t%d\n", yytext, yylineno);}
[)}\]] 	{printf("%s\t\tClosing Brackets\t%d\n", yytext, yylineno);}
[.#] {printf("%s\t\tSpecial Symbols\t\t%d\n", yytext, yylineno);}
.          {printf("%s\t\tInvalid\t\t%d\n", yytext, yylineno);}

%%

int main() {
    yyin = fopen("source1.txt", "r"); 
    printf("Lexeme\t\tToken\t\tLine No.\n");
    printf("---------------------------------------------\n");
    yylex();
    fclose(yyin);
    return 0;
}
