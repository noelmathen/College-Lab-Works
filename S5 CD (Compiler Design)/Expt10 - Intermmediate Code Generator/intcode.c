#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

typedef struct {
    char data[MAX_EXPR_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char item) {
    stack->data[++stack->top] = item;
}

char pop(Stack *stack) {
    return stack->data[stack->top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    initStack(&stack);

    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (isOperator(infix[i])) {
            while (!isOperator(stack.data[stack.top]) &&
                   getPrecedence(stack.data[stack.top]) >= getPrecedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        } else if (infix[i] == '(') {
            push(&stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (stack.data[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop '('
            i++;
        } else {
            // Invalid character in the infix expression
            printf("Invalid character in the infix expression: %c\n", infix[i]);
            exit(EXIT_FAILURE);
        }
    }

    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

void generateThreeAddressCode(char postfix[]) {
    Stack stack;
    initStack(&stack);

    int tempCount = 1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            push(&stack, postfix[i]);
        } else if (isOperator(postfix[i])) {
            char op = postfix[i];
            char tempVar[3];
            sprintf(tempVar, "t%d", tempCount++);
            printf("%c = %c %c %c\n", tempVar[0], pop(&stack), op, pop(&stack));
            push(&stack, tempVar[0]);
        }
    }
}

int main() {
    char infix[MAX_EXPR_SIZE];
    char postfix[MAX_EXPR_SIZE];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    printf("Three-address code:\n");
    generateThreeAddressCode(postfix);

    return 0;
}

/*
a+b*c
*/
