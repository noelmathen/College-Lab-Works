#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char icode[10][30], str[20], opr[10];
    int i = 0;

    printf("\nEnter the set of intermediate code (terminated by exit):\n");

    // Input 3-address code
    do {
        scanf("%s", icode[i]);
    } while (strcmp(icode[i++], "exit") != 0);

    printf("\nTarget code generation");
    printf("\n************************");

    i = 0;

    // Generate target code
    do {
        strcpy(str, icode[i]);

        switch (str[3]) {
            case '+':
                strcpy(opr, "ADD");
                break;
            case '-':
                strcpy(opr, "SUB");
                break;
            case '*':
                strcpy(opr, "MUL");
                break;
            case '/':
                strcpy(opr, "DIV");
                break;
            default:
                printf("Invalid operator in intermediate code\n");
                return 1;  // Indicate an error
        }

        printf("\n\tMov R%d,%c", i, str[2]);
        printf("\n\t%s R%d,%c", opr, i, str[4]);
        printf("\n\tMov %c,R%d", str[0], i);

        i++;
    } while (strcmp(icode[i], "exit") != 0);

    printf("\n");
    return 0;
}

/*
t=b*c
t=a+t
exit
*/