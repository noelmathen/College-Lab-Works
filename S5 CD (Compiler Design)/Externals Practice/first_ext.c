//NOEL FIRST
#include<stdio.h>
#include<string.h>

typedef struct{
    char lhs;
    char rhs[100];
}Rules;

typedef struct{
    char lhs;
    char first[100];
    int count;
}FirstSet;

int firstSetCount=0, ruleCount=0;
Rules rules[100];
FirstSet firstSet[100];

void addRule(char lhs, char *rhs){
    rules[ruleCount].lhs = lhs;
    strcpy(rules[ruleCount].rhs, rhs);
    ruleCount++;
}

void addToFirstSet(char lhs, char symbol){
    for(int i=0; i<firstSetCount; i++){
        if(firstSet[i].lhs == lhs){
            for(int j=0; j<firstSet[i].count; j++){
                if(firstSet[i].first[j] == symbol)
                    return;
            }
            firstSet[i].first[firstSet[i].count++] = symbol;
            return;
        }
    }
    firstSet[firstSetCount++] = (FirstSet){lhs, "", 0};
    firstSet[firstSetCount-1].first[firstSet[firstSetCount-1].count++] = symbol;
}

void printFirstSets(){
    for(int i=0; i<firstSetCount; i++){
        printf("\nFirst(%c) = { ", firstSet[i].lhs);
        for(int j=0; j<firstSet[i].count; j++){
            printf("%c, ", firstSet[i].first[j]);
        }
        printf(" }");
    }
}

void findFirstSets(){
    for(int i=0; i<ruleCount; i++){
        if(rules[i].rhs[0] != rules[i].lhs)
            addToFirstSet(rules[i].lhs, rules[i].rhs[0]);
    }
}


void main(){
    addRule('E', "TG");
    addRule('G', "+TG");
    addRule('G', "e");
    addRule('T', "FH");
    addRule('H', "*FH");
    addRule('H', "e");
    addRule('F', "(E)");
    addRule('F', "i");
    
    findFirstSets();
    printFirstSets();
}