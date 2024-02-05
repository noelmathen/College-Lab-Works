//INTERMEDIATE CODE GENERATION
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 100

int top = -1;
char stack[maxsize], infix[maxsize], postfix[maxsize];

void push(char operator) { 
    stack[++top] = operator; 
}

char pop() { 
    return stack[top--]; 
}

int isoperator(char symbol) { 
    return (symbol == '^' || symbol == '*' || symbol == '+' || symbol == '-' || symbol == '/'); 
}

int precedence(char symbol) {
    if (symbol == '^') return 3;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return 0;
}

void infixToPostfix() {
    int i = 0, j = 0;
    while (infix[i]) {
        char c = infix[i++];
        if (isalpha(c) || isdigit(c)) 
            postfix[j++] = c;
        else if (c == '(') 
            push(c);
        else if (c == ')') {
            while ( top != -1 && stack[top] != '(' ) 
                postfix[j++] = pop();
            pop();
        } 
        else {
            while (top != -1 && isoperator(stack[top]) && precedence(c) <= precedence(stack[top])) 
                postfix[j++] = pop();
            push(c);
        }
    }
    while (top != -1) 
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("\nPostfix Expression: %s", postfix);
}

void postfixToThreeAddress() {
    int i = 0, t = 0;
    char result[maxsize], op;
    printf("\n\nThree-Address Code:\n");
    while (postfix[i]) {
        char c = postfix[i++];
        if (isalpha(c) || isdigit(c)) 
            push(c);
        else if (isoperator(c)) {
            char arg2 = pop(), arg1 = pop();
            op = c;
            snprintf(result, sizeof(result), "%c", 'A' + t++);
            printf("%c = %c %c %c\n", result[0], arg1, op, arg2);
            push(result[0]);
        }
    }
}

void postfixToQuadruple() {
    int i = 0, t = 0;
    char result[maxsize], op;
    printf("\nQuadruple Format:\n");
    printf("| %-6s | %-10s | %-10s | %-10s | %-10s |\n", "LineNo", "Operator", "Argument1", "Argument2", "Result");
    printf("|--------|------------|------------|------------|------------|\n");

    while (postfix[i]) {
        char c = postfix[i++];
        if (isalpha(c) || isdigit(c)) 
            push(c);
        else if (isoperator(c)) {
            char arg2 = pop(), arg1 = pop();
            op = c;
            snprintf(result, sizeof(result), "%c", 'A' + t++);
            printf("| %-6d | %-10c | %-10c | %-10c | %-10c |\n", t - 1, op, arg1, arg2, result[0]);
            push(result[0]);
        }
    }
}

int main() {
    printf("\nEnter Infix Expression: ");
    scanf("%s", infix);
    infixToPostfix();
    postfixToThreeAddress();
    postfixToQuadruple();
    return 0;
}

/*
a+b*c
a*b+c
a*b+c-d
(a*b+c)-d
a-b+c*d
a-(b+c)*d
*/

