#include <stdio.h>
#include <string.h>

typedef struct
{
    char lhs;
    char rhs[100];
} Rule;

typedef struct
{
    char lhs;
    char firstSet[100];
    int count;
} FirstSet;

Rule rules[100];
FirstSet firstSets[100];
int ruleCount = 0;
int firstSetCount = 0;

void addRule(char lhs, char *rhs)
{
    rules[ruleCount].lhs = lhs;
    strcpy(rules[ruleCount].rhs, rhs);
    ruleCount++;
}

int getFirstSetIndex(char lhs)
{
    for (int i = 0; i < firstSetCount; i++)
    {
        if (firstSets[i].lhs == lhs)
        {
            return i;
        }
    }
    firstSets[firstSetCount].lhs = lhs;
    firstSets[firstSetCount].count = 0;
    return firstSetCount++;
}

void addToFirstSet(char lhs, char symbol)
{
    int index = getFirstSetIndex(lhs);
    for (int i = 0; i < firstSets[index].count; i++)
    {
        if (firstSets[index].firstSet[i] == symbol)
        {
            return;
        }
    }
    // C

    int currentCount = firstSets[index].count;

    firstSets[index].firstSet[currentCount] = symbol;
    firstSets[index].count = currentCount + 1;
}

void findFirstSets()
{
    for (int i = 0; i < ruleCount; i++)
    {
        if (rules[i].rhs[0] != rules[i].lhs)
        {
            addToFirstSet(rules[i].lhs, rules[i].rhs[0]);
        }
    }
    // for (int i = 0; i < ruleCount; i++)
    // {
    //     if (rules[i].rhs[0] == rules[i].lhs)
    //     {
    //         int index = getFirstSetIndex(rules[i].rhs[0]);
    //         for (int j = 0; j < firstSets[index].count; j++)
    //         {
    //             addToFirstSet(rules[i].lhs, firstSets[index].firstSet[j]);
    //         }
    //     }
    // }
}

void printFirstSets()
{
    for (int i = 0; i < firstSetCount; i++)
    {
        printf("First(%c) = { ", firstSets[i].lhs);
        for (int j = 0; j < firstSets[i].count; j++)
        {
            printf("%c ", firstSets[i].firstSet[j]);
        }
        printf("}\n");
    }
}

int main()
{
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

/*
5
E=TE`
E`=+TE`/#
T=FT`
T`=*FT`/#
F=(E)/#

1)E=>TE`
2)E`=>+TE`
3)T=>FT`
4)T`=>*FT`
5)F=>(E)
6)E`=>#
7)T`=>#
8)F=>i

5
E=TX
X=+TX/#
T=FY
Y=*FY/#
F=(E)/i

3
S=Bb/Cd
B=aB/#
C=cC/#

6
S=ABCDE
A=a/#
B=b/#
C=c
D=d/#
E=e/#

*/