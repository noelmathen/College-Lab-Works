#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILED 0

char string[64];
int index = 0;

void printAction(const char *production) {
    printf("%-16s %s\n", string + index, production);
}

int matchTerminal(char terminal) {
    if (string[index] == terminal) {
        index++;
        return SUCCESS;
    }
    return FAILED;
}

int E();
int Edash();
int T();
int Tdash();
int F();

int E() {
    printAction("E -> T E'");
    return T() && Edash();
}

int Edash() {
    if (matchTerminal('+')) {
        printAction("E' -> + T E'");
        return T() && Edash();
    } else {
        printAction("E' -> $");
        return SUCCESS;
    }
}

int T() {
    printAction("T -> F T'");
    return F() && Tdash();
}

int Tdash() {
    if (matchTerminal('*')) {
        printAction("T' -> * F T'");
        return F() && Tdash();
    } else {
        printAction("T' -> $");
        return SUCCESS;
    }
}

int F() {
    if (matchTerminal('(')) {
        printAction("F -> ( E )");
        return E() && matchTerminal(')');
    } else if (matchTerminal('i')) {
        printAction("F -> i");
        return SUCCESS;
    }
    return FAILED;
}

int main() {
    printf("Kindly enter the string: ");
    scanf("%s", string);
    printf("\nInput      Action\n");
    printf("--------------------------------\n");

    if (E() && string[index] == '\0') {
        printf("--------------------------------\n");
        printf("String parsing success\n");
        return 0;
    } else {
        printf("--------------------------------\n");
        printf("String parsing failed\n");
        return 1;
    }
}
