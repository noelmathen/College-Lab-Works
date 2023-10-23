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

