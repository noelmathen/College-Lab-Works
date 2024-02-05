// CODE GENERATION
#include<stdio.h>
#include<string.h>

char intcode[10][10], operator[10];
int count=0;

void main(){
    printf("Enter the number of statements:");
    scanf("%d", &count);

    for(int i=0; i<count; i++){
        scanf("%s", intcode[i]);
    }

    printf("\nThe corresponding three address code of the given statements are: \n");

    for(int i=0; i<count; i++){
        switch (intcode[i][3]) {
            case '+': 
                strcpy(operator, "ADD");
                break;

            case '-': 
                strcpy(operator, "SUB");
                break;

            case '*': 
                strcpy(operator, "MUL");
                break;

            case '/': 
                strcpy(operator, "DIV");
                break;
            
            default:
                printf("\nInvalid operator!\n");
                break;
        }
        printf("MOV R%d, %c\n", i, intcode[i][2]);
        printf("%s R%d, %c\n", operator, i, intcode[i][4]);
        printf("MOV %c, R%d\n", intcode[i][0], i);
    }
}

/*
t=b*c
t=a+t
*/
