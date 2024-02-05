// FIRST ROSHNI
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_SYMBOLS 100

// Structure to represent a grammar rule
struct Rule
{
    char nonTerminal;
    char production[MAX_SYMBOLS];
};

// Structure to represent a set of symbols
struct SymbolSet
{
    int count;
    char symbols[MAX_SYMBOLS];
};

// Function to add a symbol to a SymbolSet
void addSymbol(struct SymbolSet *set, char symbol)
{
    if (set->count < MAX_SYMBOLS)
    {
        set->symbols[set->count++] = symbol;
    }
}

// Function to check if a symbol is in a SymbolSet
int containsSymbol(struct SymbolSet set, char symbol)
{
    for (int i = 0; i < set.count; i++)
    {
        if (set.symbols[i] == symbol)
        {
            return 1;
        }
    }
    return 0;
}

void clearSymbolSet(struct SymbolSet *set)
{
    set->count = 0;
}

// Function to compute the First set for a given non-terminal
void computeFirst(struct Rule rules[MAX_RULES], int numRules, char nonTerminal, struct SymbolSet *firstSet)
{
    for (int i = 0; i < numRules; i++)
    {
        if (rules[i].nonTerminal == nonTerminal)
        {
            char firstSymbol = rules[i].production[0];
            if (isupper(firstSymbol))
            {
                // First symbol is a non-terminal
                computeFirst(rules, numRules, firstSymbol, firstSet);
            }
            else if (firstSymbol != '\0')
            {
                // First symbol is a terminal
                addSymbol(firstSet, firstSymbol);
            }
            else
            {
                // Production is empty, add epsilon ('e') to First set
                addSymbol(firstSet, 'e');
            }
        }
    }
}

int main()
{
    int numRules;
    struct Rule rules[MAX_RULES];
    printf("Enter the number of grammar rules: ");
    scanf("%d", &numRules);
    getchar(); // Consume the newline character

    printf("Enter the grammar rules in the format 'NonTerminal -> Production':\n");
    for (int i = 0; i < numRules; i++)
    {
        char input[256];
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, " %c -> %s", &rules[i].nonTerminal, rules[i].production) != 2)
        {
            printf("Invalid input. Please follow the format 'NonTerminal -> Production'\n");
            return 1;
        }
    }

    // Create a set to keep track of processed non-terminals
    struct SymbolSet processedNonTerminals;
    processedNonTerminals.count = 0;

    // Compute and print the First and Follow sets
    for (int i = 0; i < numRules; i++)
    {
        if (!containsSymbol(processedNonTerminals, rules[i].nonTerminal))
        {
            struct SymbolSet firstSet;
            computeFirst(rules, numRules, rules[i].nonTerminal, &firstSet);

            printf("First(%c): { ", rules[i].nonTerminal);
            for (int j = 0; j < firstSet.count; j++)
            {
                printf("%c ", firstSet.symbols[j]);
            }
            printf("}\n");

            addSymbol(&processedNonTerminals, rules[i].nonTerminal);
            clearSymbolSet(&firstSet);
        }
    }

    return 0;
}

/*
INPUT
8
E->TX
X->+TX
X->e
T->FR
R->*FR
R->e
F->(E)
F->
*/