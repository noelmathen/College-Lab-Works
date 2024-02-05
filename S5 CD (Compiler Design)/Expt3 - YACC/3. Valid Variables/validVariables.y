/* valid_variables.y */
%{
#include <stdio.h>
#include <string.h>
%}

%token VAR

%%

program: variable '\n' {
    printf("Valid variable\n");
}
       | '\n'
       ;

variable: VAR
        | VAR variable
        ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Invalid variable\n");
}

int main() {
    yyparse();
    return 0;
}

int yylex() {
    int c = getchar();
    if (c == EOF) return 0;
    if (isalpha(c) || c == '_') { // Allow variables to start with a letter or underscore
        char var[256];
        int i = 0;
        var[i++] = c;
        while ((c = getchar()) != EOF && (isalnum(c) || isalpha(c) || c == '_') && i < 255) {
            var[i++] = c;
        }
        var[i] = '\0';
        ungetc(c, stdin);
        yylval = strdup(var);
        return VAR;
    }
    return c;
}

