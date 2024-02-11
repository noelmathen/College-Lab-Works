//FIRST (BHARAT). This code, i think, works only for this grammar. I did this for the externals and still got output. so......
#include <stdio.h>
#include <string.h>

typedef struct {
    char lhs;
    char first[100];  // Change from firstSet to first
    int count;
} FirstSet;

typedef struct {
    char lhs;
    char rhs[100];
} Rule;

Rule rules[100];
FirstSet firstSets[100];

int ruleCount = 0;
int firstSetCount = 0;

void addRule(char lhs, char *rhs) {
    rules[ruleCount].lhs = lhs;
    strcpy(rules[ruleCount].rhs, rhs);
    ruleCount++;
}

void addToFirstSet(char lhs, char symbol) {
    // Check if lhs is already present in firstSets
    for (int i = 0; i < firstSetCount; i++) {
        if (firstSets[i].lhs == lhs) {
            // Check if symbol is already in the first set
            for (int j = 0; j < firstSets[i].count; j++) {
                if (firstSets[i].first[j] == symbol) {
                    return; // Symbol is already present, no need to add it again
                }
            }

            // Add symbol to the first set
            firstSets[i].first[firstSets[i].count++] = symbol;
            return;
        }
    }

    // If lhs is not present, add it to firstSets
    firstSets[firstSetCount++] = (FirstSet){lhs, "", 0};
    // Add symbol to the first set of lhs
    firstSets[firstSetCount - 1].first[firstSets[firstSetCount - 1].count++] = symbol;
}

void findFirstSets() {
    for (int i = 0; i < ruleCount; i++) {
        if (rules[i].rhs[0] != rules[i].lhs) {
            addToFirstSet(rules[i].lhs, rules[i].rhs[0]);
        }
    }
}

void printFirstSets() {
    for (int i = 0; i < firstSetCount; i++) {
        printf("First(%c) = { ", firstSets[i].lhs);
        for (int j = 0; j < firstSets[i].count; j++) {
            printf("%c ", firstSets[i].first[j]);
        }
        printf("}\n");
    }
}

int main() {
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

    return 0;
}