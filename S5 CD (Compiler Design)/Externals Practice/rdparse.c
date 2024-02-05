#include<stdio.h>

#define SUCCESS 1
#define FAILURE 0

char string[100];
int index =0;

void printAction(const char *prod){
    printf("%-16s %s\n", string + index, prod);
}

int matchTerminal(int terminal){
    if(string[index]==terminal){
        index++;
        return SUCCESS;
    }
    return FAILURE;
}

int E();
int Edash();
int T();
int Tdash();
int F();

int E(){
    printAction("E -> TE'");
    return T() && Edash();
}

int Edash(){
    if(matchTerminal('+')){
        printAction("E' -> +TE'");
        return T() && Edash();
    }
    else{
        printAction("E -> $");
        return SUCCESS;
    }
}

int T(){
    printAction("T -> FT'");
    return F() && Tdash();
}

int Tdash(){
    if(matchTerminal('*')){
        printAction("T' -> *FT'");
        return F() && Tdash();
    } else{
        printAction("T' -> $");
        return SUCCESS;
    }
}

int F(){
    if(matchTerminal('(')){
        printAction("F -> (E)");
        return E();
    } else{
        if(matchTerminal('i')){
            printAction("F -> i");
            return SUCCESS;
        }
    }
    return FAILURE;
}

void main(){
    printf("Enter the input string: ");
    scanf("%s", string);

    printf("\nInput      Action\n");
    printf("--------------------------------\n");

    if(E() && string[index]=='\0'){
        printf("------------------------------");
        printf("\nInput string processed successfully!");
    } else{
        printf("------------------------------");
        printf("\nInput string processed not successfully!");
    }
}