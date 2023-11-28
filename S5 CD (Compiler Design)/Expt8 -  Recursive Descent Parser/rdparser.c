#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILED 0

const char *cursor;
char string[64];

void inputProduction(char *non_terminal, char *production_rule) {
    printf("Enter production rule for %s: ", non_terminal);
    scanf("%s", production_rule);
}

void printCurrent(const char* rule_name) {
    printf("In %s: \t\tcurrent char: %c\n", rule_name, *cursor);
}

int E(const char* E_rule, const char* Edash_rule, const char* T_rule, const char* Tdash_rule, const char* F_rule) {
    printCurrent("E");
    if (T(T_rule, Tdash_rule, F_rule)) {
        if (Edash(Edash_rule, T_rule, Tdash_rule, F_rule))
            return SUCCESS;
        else
            return FAILED;
    } else
        return FAILED;
}

int Edash(const char* Edash_rule, const char* T_rule, const char* Tdash_rule, const char* F_rule) {
    if (*cursor == '+' || *cursor == '-') {
        printCurrent("E'");
        cursor++;
        if (T(T_rule, Tdash_rule, F_rule)) {
            if (Edash(Edash_rule, T_rule, Tdash_rule, F_rule))
                return SUCCESS;
            else
                return FAILED;
        } else
            return FAILED;
    } else {
        printCurrent("E'");
        return SUCCESS;
    }
}

int T(const char* T_rule, const char* Tdash_rule, const char* F_rule) {
    printCurrent("T");
    if (F(F_rule)) {
        if (Tdash(Tdash_rule, F_rule))
            return SUCCESS;
        else
            return FAILED;
    } else
        return FAILED;
}

int Tdash(const char* Tdash_rule, const char* F_rule) {
    if (*cursor == '*' || *cursor == '/') {
        printCurrent("T'");
        cursor++;
        if (F(F_rule)) {
            if (Tdash(Tdash_rule, F_rule))
                return SUCCESS;
            else
                return FAILED;
        } else
            return FAILED;
    } else {
        printCurrent("T'");
        return SUCCESS;
    }
}

int F(const char* F_rule) {
    printCurrent("F");
    if (*cursor == '(') {
        cursor++;
        if (E(F_rule, F_rule, F_rule, F_rule, F_rule)) {
            if (*cursor == ')') {
                cursor++;
                return SUCCESS;
            } else
                return FAILED;
        } else
            return FAILED;
    } else if (*cursor == 'i') {
        printCurrent("F");
        cursor++;
        return SUCCESS;
    } else
        return FAILED;
}

int main() {
    char E_rule[20], Edash_rule[20], T_rule[20], Tdash_rule[20], F_rule[20];

    inputProduction("E", E_rule);
    inputProduction("E'", Edash_rule);
    inputProduction("T", T_rule);
    inputProduction("T'", Tdash_rule);
    inputProduction("F", F_rule);

    puts("Enter the string");
    scanf("%s", string);
    cursor = string;
    puts("");
    puts("Input                     Action");
    puts("--------------------------------");

    if (E(E_rule, Edash_rule, T_rule, Tdash_rule, F_rule) && *cursor == '\0') {
        puts("--------------------------------");
        puts("String is successfully parsed");
        return 0;
    } else {
        puts("--------------------------------");
        puts("Error in parsing String");
        return 1;
    }
}