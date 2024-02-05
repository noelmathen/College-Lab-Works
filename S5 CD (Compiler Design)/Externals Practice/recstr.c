#include<stdio.h>
#include <string.h>
char input[10];

int main(){
    while(1){
        printf("\nEnter string:");
        scanf("%s",input);
        int len=strlen(input);
        int flag=0;
        if(len==1&&input[0]=='a'){
            printf("\nRecognized under a");
            flag=1;
            
        }
        int i;
        for(i=0;i<len;i++){
            if(input[i]!='a')
                break;
        }
        
        if(len==i){
            printf("\nrecognised under a*");
            flag=1;
        }
        if(len==3&&strcmp(input,"abb")==0){
            printf("\nrecognised under abb");
            flag=1;
        }
        int hasA=0,hasB=0,acount=0,bcount=0,c=0;
        while(input[c]=='a'&&c<len){
            hasA=1;
            acount++;
            c++;
        }
        while(input[c]=='b'&&c<len){
            hasB=1;
            bcount++;
            c++;
        }
        int count=acount+bcount;
        if((hasA||!hasA)&&hasB&&len==count){
            printf("\nrecognised under a*b+");
            flag=1;
        }
        if(flag==0)
            printf("\nnot recognised under any rule");
    }
}