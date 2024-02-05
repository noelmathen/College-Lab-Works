/* whitespace_and_comments.l */
%{
    #include<stdio.h>
%}

%option noyywrap

%%
[ \t]+    {}
"//"([^'\n'])*\n  {}
"/*"([^*]|\*+[^*/])*\*+"/"\n  {}
"/*"([^*]|\*+[^*/])*\*+"/"  {}
.       { printf("%s", yytext); }
%%

int main()
{
    FILE *file = fopen("source.txt", "r");

    if (!file) {
        fprintf(stderr, "Failed to open input file.\n");
        return 1;
    }
    yyin = file;
    yylex();
    fclose(file);
    printf("\n");
    return 0;
}




//BHARATS
%{
#include <stdio.h>
%}

%%
[ \t\n]+    { /* skip white spaces and newlines */ }
"//"(.*)    { /* skip C++ style comments */ }
"/*"([^*]|[*][^/])*"*/"    { /* skip C-style comments */ }
.    { putchar(yytext[0]); }    /* print all other characters */
%%

int main() {
    yylex();    // Start lexical analysis
    return 0;
}
int yywrap() {
    return 1;  // Indicate no more input
}




//AADARSHS
%{
#include <stdio.h>
%}
%option noyywrap
%%
"/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+"/" 
"//"(.*)[\r\n]   
[ \t]+  
.   { printf("%c", yytext[0]); }
%%

int main() {
    yyin = fopen("pgm1.txt", "r");
    yylex();
    fclose(yyin);
    return 0;
}
