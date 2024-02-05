#include<stdio.h>
#include<string.h>

char input[100];

void main(){
    while(1){
        printf("\nEnter the string: ");
        scanf("%s", input);
        int len = strlen(input);
        int flag=0;

        //Rule 1: a
        if(len==1 && input[0]=='a'){
            printf("Recognized under 'a'\n");
            flag=1;
        }

        // Rule 2: 'a*'
        int i;
        for (i = 0; i < len; i++) {
            if (input[i] != 'a')
                break;
        }
        if (i == len) {
            printf("Recognized under 'a*'\n");
            flag = 1;
        }

        //Rule 3: 'abb'
        if(len==3 && strcmp(input, "abb")==0){
            printf("Recognized under 'abb'\n");
            flag=1;
        }

        //Rule 4: a*b+
        int hasA=0, hasB=0, aCount=0, bCount=0;
        i=0;
        while(input[i]=='a' && i<len){
            hasA=1;
            aCount++;
            i++;
        }
        while(input[i]=='b' && i<len){
            hasB=1;
            bCount++;
            i++;
        }
        int count = aCount+bCount;
        if((hasA || !hasA) && hasB && count==len){
            printf("Recognized under 'a*b+'\n");
            flag=1;
        }

        //Exception: Not recognized
        if(flag==0)
            printf("Not recognized under any rules!\n");
    }
}