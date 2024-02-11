//DO NOT KNOW WHETHER THIS IS CORRECT OR NOT! TRY IT YOURSELF
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

// Function to compute the Follow set for a given non-terminal
void computeFollow(struct Rule rules[MAX_RULES], int numRules, char nonTerminal, struct SymbolSet *followSet)
{
    if (nonTerminal == rules[0].nonTerminal)
    {
        // Start symbol
        addSymbol(followSet, '$');
    }

    for (int i = 0; i < numRules; i++)
    {
        char *production = rules[i].production;
        int len = strlen(production);

        for (int j = 0; j < len; j++)
        {
            if (production[j] == nonTerminal)
            {
                // Non-terminal found in the production
                if (j == len - 1)
                {
                    // The non-terminal is at the end of the production
                    if (rules[i].nonTerminal != nonTerminal)
                    {
                        // Prevent left recursion
                        struct SymbolSet tempSet;
                        computeFollow(rules, numRules, rules[i].nonTerminal, &tempSet);
                        for (int k = 0; k < tempSet.count; k++)
                        {
                            addSymbol(followSet, tempSet.symbols[k]);
                        }
                    }
                }
                else
                {
                    // The non-terminal is followed by a symbol
                    char nextSymbol = production[j + 1];
                    struct SymbolSet firstSet;
                    computeFirst(rules, numRules, nextSymbol, &firstSet);

                    if (containsSymbol(firstSet, 'e'))
                    {
                        // Remove epsilon ('e') and continue
                        addSymbol(&firstSet, 'e');
                        for (int k = 0; k < firstSet.count; k++)
                        {
                            addSymbol(followSet, firstSet.symbols[k]);
                        }
                        struct SymbolSet tempSet;
                        computeFollow(rules, numRules, rules[i].nonTerminal, &tempSet);
                        for (int k = 0; k < tempSet.count; k++)
                        {
                            addSymbol(followSet, tempSet.symbols[k]);
                        }
                    }
                    else
                    {
                        // Add the first set symbols to the follow set
                        for (int k = 0; k < firstSet.count; k++)
                        {
                            addSymbol(followSet, firstSet.symbols[k]);
                        }
                    }
                }
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

            // struct SymbolSet followSet;
            // computeFollow(rules, numRules, rules[i].nonTerminal, &followSet);

            addSymbol(&processedNonTerminals, rules[i].nonTerminal);
            clearSymbolSet(&firstSet);
        }
    }

    return 0;
}