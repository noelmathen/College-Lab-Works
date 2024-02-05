#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define size 100
char infix[size], postfix[size], stack[size];
int top = -1;

void push(char op){
    stack[++top] = op;
}

char pop(){
    return stack[top--];
}

int IsOperator(char op){
    return (op=='^' || op=='+' || op=='-' || op=='*' || op=='/');
}

int Presedence(char op){
    if(op=='^') return 3;
    else if(op=='*' || op=='/') return 2;
    else if(op=='+' || op=='-') return 1;
    else printf("\nInvalid Operator!\n");
}

void InfixToPostfix(){
    int i=0, j=0;
    while(infix[i]){
        char c = infix[i++];
        if(isalpha(c) || isdigit(c))
            postfix[j++] = c;
        else if(c=='(')
            push(c);
        else if(c==')'){
            while(top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else{
            while(top != -1 && IsOperator(stack[top]) && Presedence(c) <= Presedence(stack[top]))
                postfix[j++] = pop();
            push(c);
        }
    }
    while(top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("\nThe postfix expression is: %s\n", postfix);
}

void PostfixToThreeAddress(){
    int i=0, j=0, t=0;
    char result[size];
    printf("\nThree Address code is:\n");
    while(postfix[i]){
        char c = postfix[i++];
        if(isdigit(c) || isalpha(c))
            push(c);
        else if(IsOperator(c)){
            char arg2 = pop();
            char arg1 = pop();
            snprintf(result, sizeof(result), "%c", 'A' + t++);
            printf("%c = %c %c %c\n", result[0], arg1, c, arg2);
            push(result[0]);
        }
    }
}

void PrintQuadrapleForm(){
    int i=0, j=0, t=0;
    char result[size];
    printf("\nQuidraple format is:\n");
    printf("| %-6s | %-10s | %-10s | %-10s | %-10s |\n", "Lineno", "Operator", "Argument1", "Argument2", "Result");
    printf("|--------|------------|------------|------------|------------|\n");
    while(postfix[i]){
        char c = postfix[i++];
        if(isdigit(c) || isalpha(c))
            push(c);
        else if(IsOperator(c)){
            char arg2 = pop();
            char arg1 = pop();
            snprintf(result, sizeof(result), "%c", 'A' + t++);
            push(result[0]);
            
            printf("| %-6d | %-10c | %-10c | %-10c | %-10c |\n", t, c, arg1, arg2, result[0]);
        }
    }
}

void main(){
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    InfixToPostfix();
    PostfixToThreeAddress();
    PrintQuadrapleForm();
}

/*
a+b*c
a*b+c
a*b+c-d
(a*b+c)-d
a-b+c*d
a-(b+c)*d
*/