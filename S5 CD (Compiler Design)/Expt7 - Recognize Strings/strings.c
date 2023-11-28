#include <stdio.h>
#include <string.h>
int main() {
    char input[100];
    while(1){
        int flag=0;
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        int len = strlen(input);
        int i = 0;
        if (len == 0) {
            printf("String recognized under 'a*'\n");
            flag=1;
        }
        for (i = 0; i < len; i++) {
            if (input[i] != 'a') {
                break;
            }
        }
        if (i == len) {
            printf("String recognized under 'a*'\n");
            flag=1;
        }
        if (len == 3 && strcmp(input, "abb") == 0) {
            printf("String recognized under 'abb'\n");
            flag=1;
        }
        int hasA = 0, hasB = 0;
        for (i = 0; i < len; i++) {
            if (input[i] == 'a') {
                hasA = 1;
            } else if (input[i] == 'b') {
                hasB = 1;
            } else {
                break;
            }
        }

        if ((hasA || !hasA) && hasB) {
            printf("String recognized under 'a*b+'\n");
            flag=1;
        }

        if(flag!=1)
            printf("String not recognized under any pattern\n");
    }
    return 0;
}
